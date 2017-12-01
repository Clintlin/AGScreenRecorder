//
//  AYBaseMainPanel.h
//  AYMovePanel
//
//  Created by Clintlin on 2017/5/31.
//  Copyright © 2017年 zhangxinming. All rights reserved.
//

#import "SRBaseView.h"

typedef NS_ENUM(NSInteger, SRPanelPosition){
    SRPanelPositionUnknow,
    SRPanelPositionLeftTop,
    SRPanelPositionLeftBottom,
    SRPanelPositionRightTop,
    SRPanelPositionRightBottom
};


extern float SRPanelAnimationDuration;


@interface SRBaseMainPanel : SRBaseView

@property (nonatomic ,strong) NSTimer * displayTimer;
@property (nonatomic ,assign) double timerCounting;
@property (nonatomic ,assign) SRPanelPosition position;
@property (nonatomic ,assign) CGFloat itemWidth;
@property (nonatomic ,assign) CGFloat itemGap;

// 点击后显示的菜单
@property (nonatomic ,assign) CGFloat menuAnimationDuration;
@property (strong, nonatomic )NSArray <UIView *> * mainMenuItems;
@property (strong, nonatomic) NSArray <NSString *> * subItems;

- (instancetype)initWithFrame:(CGRect)frame;
- (void) panHandle:(UIPanGestureRecognizer *)pan;

- (void)displayEnd;
- (void)resetTimer;

- (void)addToRootViewController;

- (void)hideToBorder;
- (void)hideToBorderWithoutCheck;

// new
- (BOOL)isShowing;
- (void)showMenu;
- (void)hideMenu;
- (void)removeFromSuperview;

- (void)animateMenuItem:(UIView *)item atIndex:(NSInteger)index show:(BOOL)showing;
- (void)repostionMainMenuItem:(UIView *)item atIndex:(NSInteger)index;


- (void)generateMainMenu:(void(^)(NSArray * items))itemsBlock;
@end
