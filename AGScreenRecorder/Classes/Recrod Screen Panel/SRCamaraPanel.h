//
//  RSCamaraPanel.h
//  AYMovePanel
//
//  Created by HeXingang on 2017/9/11.
//  Copyright © 2017年 zhangxinming. All rights reserved.
//

#import "SRBaseView.h"

//@protocol SRCamaraPanelDelegate <NSObject>
//
//- (void)RSCamaraPanel;
//
//@end

@interface SRCamaraPanel : SRBaseView

+ (instancetype)sharedCamera;
+ (instancetype)showInView:(UIView *)view;

- (void)startCAP;
- (void)stopCAP;
- (void)destroy;
- (void)showCamara:(BOOL)show;

@end
