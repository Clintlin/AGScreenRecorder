//
//  RecordScreenPanel.h
//  AYMovePanel
//
//  Created by HeXingang on 2017/9/4.
//  Copyright © 2017年 zhangxinming. All rights reserved.
//

#import "SRBaseMainPanel.h"


@interface SRPanel : SRBaseMainPanel

@property (nonatomic, strong) void (^startRecordingBlock)(NSString * message);
@property (nonatomic, strong) void (^didStopRecordingBlock)(NSDictionary * userInfo, NSError * error);
@property (nonatomic, strong) void (^cancelRecordingBlock)(NSString * message);

+ (instancetype)showInView:(UIView *)view;

- (void)setLocalVideoMuted:(BOOL)muted;


- (void)startRecord;
- (void)stopRecord;
- (void)cancelRecording;
@end
