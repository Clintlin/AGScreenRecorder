//
//  AGScreenRecorder.m
//  AGScreenRecorder
//
//  Created by Clintlin on 2017/9/29.
//

#import "AGCScreenRecorder.h"
#import "SRApi.h"
#import <itmSDK/itmSDK.h>
#import <AVFoundation/AVFoundation.h>
#import <ReplayKit/ReplayKit.h>

@interface AGCScreenRecorder()<RPPreviewViewControllerDelegate>
@property (nonatomic, assign) BOOL hasSaved;

@property (nonatomic, strong) void(^stopRecordHandler)(NSError * error);
@end

@implementation AGCScreenRecorder

+ (instancetype)shareRecorder{
    static AGCScreenRecorder *instance = nil;
    static dispatch_once_t predicate;
    dispatch_once(&predicate, ^{
        instance = [[[self class] alloc] init];
    });
    return instance;
}


#pragma mark - 录屏事件

- (void) startRecording:(void (^)(NSError * _Nullable))completaion{
    
    void (^startRecordingHandler)(NSError *) = ^(NSError * _Nullable error) {
        NSLog(@"startRecording error :%@",error);
        if (completaion) {
            completaion(error);
        }
    };
    
    
    if(itm_iOS11Later){
        if (![RPScreenRecorder sharedRecorder].available) {
            return NSLog(@"[RPScreenRecorder sharedRecorder].available == false");
        }
        [self cancel:nil];
        
        [[RPScreenRecorder sharedRecorder] startRecordingWithHandler:startRecordingHandler];
    }else if(itm_iOS9Later){
        [[RPScreenRecorder sharedRecorder] startRecordingWithMicrophoneEnabled:YES handler:startRecordingHandler];
    } else{
        //        MediaStartRecordScreenVideo();
    }
}

- (void)stopRecord:(void (^)(NSError * _Nullable))completaion{
    
    self.stopRecordHandler = completaion;

    if(itm_iOS9Later){
        
        [[RPScreenRecorder sharedRecorder] stopRecordingWithHandler:^(RPPreviewViewController * previewViewController, NSError * error){
            if (error) {
                [self didStopRecordingWithUserInfo:nil error:error];
                return ;
            }
            
            ////////////////////////////////////////////////////////////////////
            AVAudioSession* session = [AVAudioSession sharedInstance];
            [session setCategory:AVAudioSessionCategoryPlayback withOptions:AVAudioSessionCategoryOptionInterruptSpokenAudioAndMixWithOthers error:&error];
            [self showVideoPreviewController:previewViewController withAnimation:YES];
        }];
    }
    else
    {
        //        MediaStopRecordScreenVideo();
    }
}

- (void)cancel:(void (^)())completaion{
    if(itm_iOS9Later){
        void (^stopHandler)(RPPreviewViewController *,NSError *) = ^(RPPreviewViewController * previewViewController, NSError * error){
            [[RPScreenRecorder sharedRecorder] discardRecordingWithHandler:^{
                if (completaion) {
                    completaion();
                }
            }];
        };
        
        [[RPScreenRecorder sharedRecorder] stopRecordingWithHandler:stopHandler];
    }else{
        //        MediaCancelRecordScreenVideo();
    }
}




- (void)didStopRecordingWithUserInfo:(NSDictionary *)userInfo error:(NSError *)error{
    _hasSaved = NO;
    if (self.stopRecordHandler) {
        self.stopRecordHandler(error);
    }
}

- (void)showVideoPreviewController:(RPPreviewViewController *)previewController withAnimation:(BOOL)animation {
    
    [self didStopRecordingWithUserInfo:@{@"message":@"录制完成"} error:nil];
    
    // 没有movieURL，所以我们得自己想办法
    previewController.previewControllerDelegate = self;
    UIViewController * rootVC = AGSR_getCurrentRootController();
    [rootVC presentViewController:previewController animated:animation completion:nil];
}


#pragma mark - RPPreviewViewControllerDelegate

//选择了某些功能的回调（如分享和保存）
- (void)previewController:(RPPreviewViewController *)previewController didFinishWithActivityTypes:(NSSet <NSString *> *)activityTypes {
    
    
    if ([activityTypes containsObject:@"com.apple.UIKit.activity.SaveToCameraRoll"]) {
        _hasSaved = YES;
        dispatch_async(dispatch_get_main_queue(), ^{
            if (self.videoShareBlock) {
                self.videoShareBlock(SRVideoPreviewActionSave);
            }
        });
    }

}

- (void)previewControllerDidFinish:(RPPreviewViewController *)previewController {
    
    AVAudioSession* session = [AVAudioSession sharedInstance];
    
    [session setCategory:AVAudioSessionCategoryPlayAndRecord withOptions:AVAudioSessionCategoryOptionDefaultToSpeaker error:nil];
    
    [self hideVideoPreviewController:previewController withAnimation:YES];
}

- (void)hideVideoPreviewController:(RPPreviewViewController *)previewController withAnimation:(BOOL)animation {
    
    if (!_hasSaved) {
        //        用户取消
        if (self.videoShareBlock) {
            self.videoShareBlock(SRVideoPreviewActionCancel);
        }
    }
    
    [previewController dismissViewControllerAnimated:animation completion:nil];
}
@end
