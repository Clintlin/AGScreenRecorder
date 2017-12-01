//
//  AYMainMenuButton.h
//  AYMovePanel
//
//  Created by Clintlin on 2017/6/27.
//  Copyright © 2017年 zhangxinming. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    itmButtonTitleModeLeft,
    itmButtonTitleModeRight,
    itmButtonTitleModeUp,
    itmButtonTitleModeDown
} itmButtonTitleMode;


@interface itmButton : UIButton

@property (nonatomic, strong, readonly) UILabel *titleLabel;
@property (nonatomic, assign) CGFloat margin;
@property (nonatomic, assign) itmButtonTitleMode titleMode;
@end
