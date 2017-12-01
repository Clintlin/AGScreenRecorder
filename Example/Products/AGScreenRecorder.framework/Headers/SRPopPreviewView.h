//
//  ScreenshotAlert.h
//  AYMovePanel
//
//  Created by HeXingang on 2017/9/25.
//  Copyright © 2017年 zhangxinming. All rights reserved.
//

#import "SRBaseView.h"

@interface SRPopPreviewView : SRBaseView

@property (nonatomic, strong) UIImageView*  thumbnailImageView;

+ (instancetype)showInView:(UIView *)view videoURL:(NSURL *)videoURL;

@end
