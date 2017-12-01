//
//  AYVideoMeetingInterface.m
//  AYVideoMeeting
//
//  Created by Clintlin on 2017/7/12.
//  Copyright © 2017年 Clintlin. All rights reserved.
//

#import "SRApi.h"
#import <itmSDK/itmSDK.h>
#import "Masonry.h"

#import "SRPopPreviewView.h"
#import <AGSocial/AGSocial.h>
#import "SRCamaraPanel.h"
#import "AGCScreenRecorder.h"



NSString * SRDomain_SetCallback = @"AGSR_SetCallback";
NSString * SRDomain_Init = @"AGSR_Init";
NSString * SRDomain_Start = @"AGSR_Start";
NSString * SRDomain_Stop = @"AGSR_Stop";
NSString * SRDomain_VideoWillSave = @"AGSR_VideoWillSave";
NSString * SRDomain_VideoDidSave = @"AGSR_VideoDidSave";
NSString * SRDomain_VideoShareCancel = @"AGSR_VideoShareCancel";
NSString * SRDomain_VideoShareSuccess = @"AGSR_VideoShareSuccess";
NSString * SRDomain_Cancel = @"AGSR_Cancel";
NSString * SRDomain_SetVideoPreviewHidden = @"AGSR_SetVideoPreviewHidden";


NSString * NSStringFromChar(const char *cString){
    if (cString == NULL) {
        return nil;
    }
    return [NSString stringWithCString:cString encoding:NSUTF8StringEncoding];
}


int kErrorCode = -1;
int kAllGreen = 0;

@interface SRApi()

@property (strong, nonatomic) NSMutableArray    * videoSessions;

- (void)setSRPreviewViewHidden:(BOOL) hidden;
@end

@implementation SRApi{
    
    
}

+ (SRApi *)shareInstance {
    static SRApi *instance = nil;
    static dispatch_once_t predicate;
    dispatch_once(&predicate, ^{
        instance = [[[self class] alloc] init];
    });
    return instance;
}


- (instancetype)init{
    if (self = [super init]) {
        
    }
    return self;
}


- (void)setSRPreviewViewHidden:(BOOL) hidden {

    if([SRCamaraPanel sharedCamera].superview == nil){
        [SRCamaraPanel showInView:AGSR_getCurrentRootController().view];
    }
    [[SRCamaraPanel sharedCamera] setHidden:hidden];
    if (hidden) {
        [[SRCamaraPanel sharedCamera] stopCAP];
    }else{
        [[SRCamaraPanel sharedCamera] startCAP];
    }
    [[SRApi shareInstance] successWithObjectName:SRDomain_SetVideoPreviewHidden];
}


- (void)setVideoShapeWithType:(SRVideoShapeType)type {
    
    switch (type) {
        case SRVideoShapeTypeSquare:{
            [SRCamaraPanel sharedCamera].layer.cornerRadius = 0.f;
            break;
        }
        case SRVideoShapeTypeCircle:{
            [SRCamaraPanel sharedCamera].layer.cornerRadius = [SRCamaraPanel sharedCamera].width * 0.5;
            break;
        }
        default:
            [SRCamaraPanel sharedCamera].layer.cornerRadius = 3.f;
            break;
    }

}


- (CGSize)defaultVideoSize{
    if (CGSizeEqualToSize(_defaultVideoSize, CGSizeZero)) {
        return CGSizeMake(itmConverToPtFromPx(145), itmConverToPtFromPx(195));
    }
    return _defaultVideoSize;
}


- (void)startRecording {
    WEAKSELF(weakSelf);
    [[AGCScreenRecorder shareRecorder] startRecording:^(NSError * _Nullable error) {
        if (error) {
            
            NSError * err = [NSError errorWithDomain:SRDomain_Start code:SRErrorTypeNormalError userInfo:@{@"message":@"录制开始失败",@"description":error.localizedDescription}];
            
            return [weakSelf onFailureWithError:err];
        }
        [weakSelf successWithObjectName:SRDomain_Start];
    }];
    
    
    [AGCScreenRecorder shareRecorder].videoShareBlock = ^(SRVideoPreviewAction action) {
        switch (action) {
            case SRVideoPreviewActionSave:{
                NSDictionary * userInfo = @{@"message":@"保存成功"};
                [weakSelf successWithObjectName:SRDomain_VideoDidSave  userInfo:userInfo];
                break;
            }
                
            case SRVideoPreviewActionShare:{
                //                NSDictionary * userInfo = @{@"message":@"分享成功"};
                //                [weakSelf successWithObjectName:SRDomain_VideoShareSuccess  userInfo:userInfo];
                break;
            }
                
            case SRVideoPreviewActionCancel:{
                NSDictionary * userInfo = @{@"message":@"用户取消"};
                [weakSelf successWithObjectName:SRDomain_VideoShareCancel  userInfo:userInfo];
                break;
            }
                
                
            default:
                break;
        };

    };
    
}

- (void)stopRecording {
     WEAKSELF(weakSelf);
    [[AGCScreenRecorder shareRecorder] stopRecord:^(NSError * _Nullable error) {
        if (!error) {
            return [weakSelf successWithObjectName:SRDomain_Stop];
        }
        NSError * error1 = [NSError errorWithDomain:SRDomain_Stop
                                               code:SRErrorTypeNormalError
                                           userInfo:@{@"message":@"停止录制失败",@"description":error.localizedDescription}];
        [weakSelf onFailureWithError:error1];
    }];
}

- (void) cancelRecording {
    WEAKSELF(weakSelf);
    [[AGCScreenRecorder shareRecorder] cancel:^{
        [weakSelf successWithObjectName:SRDomain_Cancel];
    }];
}


@end







#pragma mark - APIs

@implementation SRApi(APIs)

- (void)setGameCallback:(void (^)(NSString *, NSString *, NSString *))GameCallback{
    _GameCallback = GameCallback;
}

void AGSR_SetCallback(SRGameCallback callback){
    
    [SRApi shareInstance].callbackForGame = callback;
    
    if (callback == NULL) {
        
        [[SRApi shareInstance] onFailureWithError:[NSError errorWithDomain:SRDomain_SetCallback code:SRErrorTypeStringMissingParameter userInfo:@{@"message":@"回调函数为空"}]];
    }else{
        [[SRApi shareInstance] successWithObjectName:SRDomain_SetCallback];
    }
}

void AGSR_Init(const char* gameKey, const char* objName, const char* onSucces, const char* onFailure){
    
    
    if (gameKey == NULL || objName == NULL || onSucces == NULL || onFailure == NULL) {
        NSError * error = [NSError errorWithDomain:SRDomain_Init code:SRErrorTypeStringMissingParameter userInfo:@{@"message":@"有参数为空"}];
        return [[SRApi shareInstance] onFailureWithError:error];
    }
    
    
    
    [SRApi shareInstance].gameId = NSStringFromChar(gameKey);
    
    AGSRUnityMsgObj * messageObj = [AGSRUnityMsgObj new];
    messageObj.className = NSStringFromChar(objName);
    messageObj.onSucces = NSStringFromChar(onSucces);
    messageObj.onFail = NSStringFromChar(onFailure);
    
    [SRApi shareInstance].messageObj = messageObj;
    
    [[SRApi shareInstance] successWithObjectName:SRDomain_Init];
}

void AGSR_Start() {
    [[SRApi shareInstance] startRecording];
}

void AGSR_Stop() {
    [[SRApi shareInstance] stopRecording];
}

void AGSR_Cancel() {
    [[SRApi shareInstance] cancelRecording];
}

void AGSR_SetVideoPreviewHidden(bool hidden) {
    [[SRApi shareInstance] setSRPreviewViewHidden:hidden];
}

void AGSR_SetVideoPreviewShape(SRVideoShapeType type){
    
}

@end


