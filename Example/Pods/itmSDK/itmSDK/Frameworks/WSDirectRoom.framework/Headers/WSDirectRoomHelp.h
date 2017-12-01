//
//  AIYOUWebSocketHelp.h
//  testDirectRoom
//
//  Created by zhangxinming on 2017/4/17.
//  Copyright © 2017年 zhangxinming. All rights reserved.
//

#import <Foundation/Foundation.h>
@class SRWebSocket;
#import "Message.pbobjc.h"
#import "SystemCommand.pbobjc.h"
#import "LiveMessage.pbobjc.h"
#import "BigTalkMessage.pbobjc.h"
 

@protocol WSDirectRoomDelegate <NSObject>
//返回的类对象和协议id，如果object为nil则认为调用失败
- (void)reciveCommand:(NSData* )msgData commandid:(int)commandid;

//返回登录服务器返回的状态码
- (void)systemLoginCode:(int)code ;
//返回服务器的连接状态 0 连接成功，1断开连接 2 正在连接 3连接失败（连接失败内部会继续连接服务器）
- (void)systemConnectCode:(int)code ;
@end

@interface WSDirectRoomHelp : NSObject
{
    
}

@property (nonatomic, weak) id <WSDirectRoomDelegate> delegate;
+ (instancetype)shareHandle;

- (void)initWithURL:(NSString *)URL;
- (void)closeServer;
//登录服务器
- (void)logInLiveServer: (NSString *)gameId serverId:(NSString *)serverId ticket:(NSString*)ticket
                  token:(NSString*)token baseUserInfo:(BaseUserInfo *)baseUserInfo;

//开始直播 返回对象 response_40001
- (void)getLiveAddress;

//开始直播 返回对象 response_40002

- (void)beginLive;
//结束直播 返回对象 response_40003
- (void)endLive;

 /** 获取直播列表 返回response_40004*/
- (void)getLiveList:(NSString*)gameId status:(int32_t)status pageNumber:(int32_t)pageNumber size:(int32_t)size;

/** 看直播 返回response_40005*/
- (void)enterLiveroom:(NSString*)roomId;

///** 离开直播间 返回 response_40006*/
- (void)leaveLiveroom:(NSString*)roomId;

//
///** 观众发表评论返回 response_40007 */
- (void)addLiveComment:(Comment *)comment  ;
///** 推送给其他观众的评论 response_40008*/
///** 推送给主播的评论 response_40009*/

//
///** 如果客户端发现直播间，不能正常播放，客户端上报，服务端将此直播间关闭  response_40010*/
- (void)clientEndLive:(NSString *)roomId;

//
///** 主播获取观众列表 response_40011*/
- (void)getAudienceList:(NSString*)roomId pageNo:(int32_t)pageNo pageSize:
(int32_t)pageSize;

//只有嘉宾才有对讲的权限
///** 主播设置某观众为嘉宾 response_40012*/
- (void)setHonor:(NSString*)roomId serverId:(NSString*)serverId ticketId:
(NSString*)ticketId;

//
///** 主播取消设置某观众为嘉宾 */
- (void)cancelHonor:(NSString*)roomId serverId:(NSString*)serverId ticketId:
(NSString*)ticketId;

//
///** 观众数变化时，通知主播 */
//ECommandId_MsgAudienceUpdate = 41000,
//
///** 某个观众，获得嘉宾资格 */
//ECommandId_MsgGetHonor = 41001,
//
///** 某个观众，被取消嘉宾资格 */
//ECommandId_MsgCancelHonor = 41002,
//
///** 主播停止直播广播消息 */
//ECommandId_EndLiveBroadcast = 41003,

//邀请好友看直播
- (void)inviteFriendIntoLive:(NSString*)roomId   ticketList:
(NSMutableArray*)ticketList;

/////////////////////////////////////////////////
//视频会议
///////////////////
#pragma mark - 视频聊天
//获取会议室信息，返回response_40014对象
- (void)GetMeetingRoomInfo __attribute__((deprecated("Use 'createWithRoomNo:' instead.")));
//创建会议室，会议室ID选填，返回response_40014对象
- (void)createWithRoomNo:(NSString *)roomNo;

//开始视频会议，返回response_40015对象
- (void)BeginMeeting:(NSString*)roomNo;
//开始视频会议，返回response_40016对象
- (void)JoinMeetingWithCode:(NSString*)invitationCode;


//开始视频会议，返回response_40016对象
- (void)ExitMeetingRoom;
//邀请好友加入视频会议
- (void)inviteFriendIntoMeeting:(NSString*)invitationCode ticketIds:(NSMutableArray*)ticketList;
//踢出视频会议的某个成员
- (void)kickMeetingMember:(NSString*)meetingRoomNo ticketId:(NSString*)ticketId;
//关闭视频会议
- (void)colseMeeting:(NSString*)meetingRoomNo;
//获取视频会议成员列表
- (void) getMeetingMemberList:(NSString*)meetingRoomNo;
//视频会议设置，返回response_40023对象
- (void)SetMeetingMode:(NSString*)RoomNo meetingState:(int)meetingState;


/**
 返回response_40026对象
 创建视频会议，带成员
 @param roomId 房间id 若不传则服务器自动生成一个唯一字符串
 @param userIds 用户id字符串逗号分隔 如："userid,userid"
 */
- (void)CreateMeetingWithRoomId:(NSString *)roomId userIds:(NSArray <NSString *> *)userIds;

/**
 返回40027对象 
 加入视频会议,视频会议房间不存在，则创建返回40014
 @param roomId 房间id 若不传则服务器自动生成一个唯一字符串
 */
- (void)JoinMeetingWithRoomId:(NSString *)roomId;

#pragma mark - 视频聊天 end

//申请连麦，返回response_41008对象
- (void)requestLinkMic:(NSString*)RoomId;

//释放连麦，返回response_41008对象
- (void)freeLinkMic:(NSString*)RoomId;


- (void)audioChatCreat:(NSString*)btid membersArray:(NSMutableArray*)membersArray;

- (void)audioChatInviteUser:(NSString*)name membersArray:(NSArray*)membersArray;



- (void)audioChatExit:(NSString*)name;

- (void)audioChatSendMsg:(NSString*)name chat:(Chat *)chat;

- (void)audioChatJoin:(NSString*)btId;

@end
