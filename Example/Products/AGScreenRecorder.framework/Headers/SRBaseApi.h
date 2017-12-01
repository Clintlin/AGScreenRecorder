//
//  VMBaseApi.h
//  AYVideoMeeting
//
//  Created by Clintlin on 2017/9/4.
//  Copyright © 2017年 Clintlin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AG_ScreenRecorder_c_warpper.h"



extern NSString *const kVMApiUserIdKey;
extern NSString *const kVMApiSizeKey;
extern NSString *const kVMApiPositionKey;
extern NSString *const kVMApiCGRectKey;



@interface AGSRUnityMsgObj: NSObject
@property(nonatomic,retain)NSString *functionName;
@property(nonatomic,retain)NSString *className;
@property(nonatomic,retain)NSString *onSucces;
@property(nonatomic,retain)NSString *onFail;
@property(nonatomic,retain)NSString *serverip;
@property(nonatomic,retain)NSString *username;
@end



// 正经的API
@interface SRBaseApi : NSObject
@property AGSRUnityMsgObj * messageObj;
@property SRGameCallback callbackForGame;

/**
 错误的回调
 */
- (void)onFailureWithError:(NSError *)error;

/**
 成功的回调
 */
- (void)successWithObjectName:(NSString *)name userInfo:(NSDictionary *)userInfo;
- (void)successWithObjectName:(NSString *)name;

- (void)startTimeoutTimer;
- (void)stopTimeoutTimer;
- (void)onTimeout;

@end



// 其他
UIViewController * AGSR_getCurrentRootController(void);
