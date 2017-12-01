//
//  AYVideoMeetingInterface.h
//  AYVideoMeeting
//
//  Created by Clintlin on 2017/7/12.
//  Copyright © 2017年 Clintlin. All rights reserved.
//



#import "AG_ScreenRecorder_c_warpper.h"
#import "SRBaseApi.h"

extern NSString * VMVideoShapeDidChange;

typedef NS_ENUM(NSInteger, SRErrorType) {
    SRErrorTypeNormalError = -1,
    SRErrorTypeStringMissingParameter = -1000, //缺少参数
    SRErrorTypeUnexpectedResponseType = -1001, // 意外的回调 （来自服务器）
    SRErrorTypeInvalidRequestParameters = -1002, // 非法的请求
    SRErrorTypeConnectOnFail = -1003, // 连接失败
    SRErrorTypeMissingLocalUser = -1004, // 缺少本地用户 （未初始化本地用户）
};


typedef NS_ENUM(NSInteger, SRWarningType) {
    
    SRWarningTypeImplementAPIsWithoutInit = -2001, // 调用API的时候，并没有初始化
    SRWarningTypeUnexpectedUnmuteVideo = -2002, // 视频开启的时候，调用视频开启
    SRWarningTypeOpreateCameraWithoutEnabled = -2003, // 未开启摄像头就开始操作
    SRWarningTypeAlreadyLeaveVideoChatRoom = -2004 // 退出视频聊天房间不存在
};


// 缺少必要字段，
// 非法请求数据
//



@interface SRApi : SRBaseApi
@property (nonatomic, strong) void(^GameCallback)(NSString * className, NSString * method, NSString * jsonResult);
@property (nonatomic, assign) CGSize defaultVideoSize;

@property (nonatomic, strong) NSString * gameId;
@property (nonatomic, strong) NSString * serverId;
@property (assign, nonatomic) SRVideoShapeType videoShape;

+ (SRApi *)shareInstance;
- (void)startRecording;
- (void)stopRecording;
- (void)cancelRecording;

@end



@interface SRApi(APIs)


@end




    
    
    



