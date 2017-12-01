//
//  VMBaseApi.m
//  AYVideoMeeting
//
//  Created by Clintlin on 2017/9/4.
//  Copyright © 2017年 Clintlin. All rights reserved.
//

#import "SRBaseApi.h"
#import <itmSDK/itmSDK.h>
#include <dlfcn.h>


NSString *const kVMApiUserIdKey = @"userId";
NSString *const kVMApiSizeKey = @"size";
NSString *const kVMApiPositionKey = @"CGPoint";
NSString *const kVMApiCGRectKey = @"CGRect";

#ifdef __cplusplus
extern "C" {
//#endif
    // Unity定义的。。。。
    extern void UnitySendMessage(const char* obj, const char* method, const char* msg);

//#ifdef __cplusplus
}
#endif



NSInteger kVCTimeout = 10;

@implementation SRBaseApi{
    NSTimer     * timeoutTimer;
    NSDate      * timeoutTimerStartTime;
}

- (instancetype)init{
    if (self = [super init]) {
        self.messageObj = [[AGSRUnityMsgObj alloc] init];
    }
    
    return self;
}

- (void)onFailureWithError:(NSError *)error{
    
    if (!error) {
        return;
    }
    [self sendCallbackWithName:error.domain code:(int)error.code info:error.userInfo successed:NO];
}

- (void)successWithObjectName:(NSString *)name userInfo:(NSDictionary *)userInfo{
    [self sendCallbackWithName:name code:0 info:userInfo successed:YES];
}

- (void)successWithObjectName:(NSString *)name{
    [self sendCallbackWithName:name code:0 info:nil successed:YES];
}


// 发送消息给Unity之前，进行简单的拼装，看情况要不要改
- (void)sendCallbackWithName:(NSString *)name code:(int)msgcode info:(NSDictionary *)info successed:(BOOL)yesOrNo
{
    if (!_callbackForGame) {
        return;
    }
    
    NSMutableDictionary * jsonDict = @{}.mutableCopy;
    
    [jsonDict setValue:name forKey:@"callBackFun"];
    
    // 如果info为空
    if (info != nil) {
        [jsonDict setValue:info forKey:@"retMsg"];
    }
    
    // 如果失败
    if ( !yesOrNo )
    {
        [jsonDict setValue:@(msgcode) forKey:@"errorCode"];
    }
    
    
    
    NSString *strtomsg = [NSString jsonWithDictionary:jsonDict];
    [self send:yesOrNo msg:[strtomsg UTF8String]];
}


// 最终发给Unity
- (void)send:(BOOL)issucceed msg:(const char *)msg{
    const char *cunityObj = [self.messageObj.className UTF8String];
    const char *unityFunSucces = [self.messageObj.onSucces UTF8String];
    const char *unityFunFail = [self.messageObj.onFail UTF8String];
    
    if (self.callbackForGame)
    {
        if (issucceed)
        {
            self.callbackForGame(cunityObj,unityFunSucces, msg);
        }
        else
        {
            
            self.callbackForGame(cunityObj,unityFunFail, msg);
        }
        
    }
    
#ifdef __cplusplus
    extern "C" {
//#endif

        if (issucceed)
        {
            UnitySendMessage(cunityObj,unityFunSucces, msg);
        }
        else
        {
            UnitySendMessage(cunityObj,unityFunFail, msg);
        }

//#ifdef __cplusplus
    }
#endif

}



- (void)startTimeoutTimer{
    if (timeoutTimer) {
        [timeoutTimer invalidate];
        timeoutTimer = nil;
    }
    timeoutTimerStartTime = [NSDate date];
    timeoutTimer = [NSTimer scheduledTimerWithTimeInterval:2.5f target:self selector:@selector(handleTimeout:) userInfo:@{@"last":@(kVCTimeout)} repeats:YES];
}


- (void)stopTimeoutTimer {
    [timeoutTimer invalidate];
    timeoutTimer = nil;
}

- (void)handleTimeout:(NSTimer *)timer{
    NSTimeInterval timeGap = timer.fireDate.timeIntervalSince1970 - timeoutTimerStartTime.timeIntervalSince1970;
    if (timeGap>=[timer.userInfo[@"last"] integerValue]) {
        [self stopTimeoutTimer];
        [self onTimeout];
    }
}

- (void)onTimeout{
    
}



@end

#pragma mark - c

@implementation AGSRUnityMsgObj
- (void)dealloc
{
    self.functionName = nil;
    self.className = nil;
    self.onSucces = nil;
    self.onFail = nil;
    self.serverip = nil;
    self.username = nil;
}



@end



#pragma mark - aaaa


UIViewController * AGSR_getCurrentRootController(void){
    UIViewController *rootvc = nil;
    
    UIWindow * window = [[UIApplication sharedApplication] keyWindow];
    if (window.windowLevel != UIWindowLevelNormal)
    {
        NSArray *windows = [[UIApplication sharedApplication] windows];
        for(UIWindow * tmpWin in windows)
        {
            if (tmpWin.windowLevel == UIWindowLevelNormal)
            {
                window = tmpWin;
                break;
            }
        }
    }
    
    rootvc = window.rootViewController;
    return rootvc;
}
