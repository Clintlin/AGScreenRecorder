//
//  AYBaseMainPanel.m
//  AYMovePanel
//
//  Created by Clintlin on 2017/5/31.
//  Copyright © 2017年 zhangxinming. All rights reserved.
//

#import "SRBaseMainPanel.h"
#import <itmSDK/itmSDK.h>

float SRPanelAnimationDuration = itm_kAnimationDefaultDruation;
float kSRMainMenuDefaultWidth = 36.f;
float kSRMainMenuDefaultGap = 19.f;



@implementation SRBaseMainPanel{
    CGPoint _preivousCenter;
    BOOL _isShowing;
    
}

#define kScreenWidth [[UIScreen mainScreen] bounds].size.width
#define kScreenHeight [[UIScreen mainScreen] bounds].size.height
#define kPanleMagin itmConverToPtFromPx(40.f)
- (instancetype)initWithFrame:(CGRect)frame{
    
    if (self = [super initWithFrame:frame]) {
        self.position = SRPanelPositionUnknow;
        _isShowing = NO;
        [super setupSubviews];
        UIPanGestureRecognizer * pan = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(panHandle:)];
        [self addGestureRecognizer:pan];
        
        self.itemGap = kSRMainMenuDefaultGap;
        self.itemWidth = kSRMainMenuDefaultWidth;
        self.menuAnimationDuration = SRPanelAnimationDuration;
    }
    return self;
}

- (void)resetTimer{
    self.displayTimer = [NSTimer scheduledTimerWithTimeInterval:0.3 target:self selector:@selector(handleTimer:) userInfo:nil repeats:YES];
    self.timerCounting = 0;
}

- (void)handleTimer:(NSTimer *)timer{
    self.timerCounting += timer.timeInterval;
    if (self.timerCounting >= itm_kAnimationDefaultDruation) {
        // 隐藏
        [self displayEnd];
        [timer invalidate];
        timer = nil;
    }
}

- (void)displayEnd{
    
}

- (void)addToRootViewController{
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
    
    UIView *frontView = [[window subviews] objectAtIndex:0];
    id nextResponder = [frontView nextResponder];
    
    if ([nextResponder isKindOfClass:[UIViewController class]])
        rootvc = nextResponder;
    else
        rootvc = window.rootViewController;
    
    [rootvc.view addSubview:self];
}

- (void)hideToBorder{
    [self handleMoveEnd];
}

- (void)hideToBorderWithoutCheck{
    [self handleMoveEndWithCheck:NO];
}


- (void)show:(BOOL)animated{
    [super show:animated];
}


- (void)hide:(BOOL)animated{
    [super hide:animated];
    [self hideMenu];
}

- (void) panHandle:(UIPanGestureRecognizer *)pan {
    
    CGPoint currentPoint = [pan locationInView:self.superview];
    
    if (pan.state == UIGestureRecognizerStateBegan) {
        _preivousCenter = currentPoint;
    }else if (pan.state == UIGestureRecognizerStateChanged) {
        self.timerCounting = 0;
        // 当前触摸点
        CGPoint currentPoint = [pan locationInView:self.superview];
        
        // 当前view的中点
        CGPoint center = self.center;
        
        center.x += (currentPoint.x - _preivousCenter.x);
        center.y += (currentPoint.y - _preivousCenter.y);
        
        // 修改当前view的中点(中点改变view的位置就会改变)
        self.center = center;
        _preivousCenter = currentPoint;
        
        
    }else if (pan.state == UIGestureRecognizerStateEnded){
        [self handleMoveEnd];
    }
}

// check 上左下右
- (void)handleMoveEndWithCheck:(BOOL)yesOrNo{
    // ????
    if (self == nil) {
        return;
    }
    
    if (yesOrNo) {
        self.position = [self recognizePosition:self.center];
    }
    
    CGPoint center = self.center;
    
    switch (self.position) {
        case SRPanelPositionLeftTop:{
            center.x = self.frame.size.width * 0.5 + kPanleMagin;
            center.y = self.frame.size.height * 0.5 + kPanleMagin;
            break;
        }
        case SRPanelPositionLeftBottom:{
            center.x = self.frame.size.width * 0.5 + kPanleMagin;
            center.y = kScreenHeight - self.frame.size.height * 0.5 - kPanleMagin;
            break;
        }case SRPanelPositionRightTop:{
            center.x = kScreenWidth - self.frame.size.width * 0.5 - kPanleMagin;
            center.y = self.frame.size.height * 0.5 + kPanleMagin;
            break;
        }case SRPanelPositionRightBottom:{
            center.x = kScreenWidth - self.frame.size.width * 0.5 - kPanleMagin;
            center.y = kScreenHeight - self.frame.size.height * 0.5 - kPanleMagin;
            break;
        }case SRPanelPositionUnknow:{
            center.x = self.frame.size.width * 0.5 + kPanleMagin;
            center.y = kScreenHeight - self.frame.size.height * 0.5 - kPanleMagin;
            break;
        }
            
            
        default:
            break;
    }
    [UIView animateWithDuration:itm_kAnimationDefaultDruation animations:^{
        self.center = center;
    }];
}

- (void)handleMoveEnd{
    [self handleMoveEndWithCheck:YES];
}

// point is center
- (SRPanelPosition)recognizePosition:(CGPoint)point{
    //    将superview分为4个部分
    //
    //
    CGSize fullSize = self.superview.frame.size;
    
    // 左上角
    CGRect rectLeftTop = CGRectMake(-fullSize.width, 0, fullSize.width * 0.5 + fullSize.width,
                                    fullSize.height * 0.5);
    
    if (CGRectContainsPoint(rectLeftTop, point)) {
        return SRPanelPositionLeftTop;
    }
    
    CGRect rectRightTop = CGRectMake(fullSize.width * 0.5, 0,
                                     fullSize.width * 0.5 + fullSize.width,
                                     fullSize.height * 0.5);
    if (CGRectContainsPoint(rectRightTop, point)){
        return SRPanelPositionRightTop;
    }
    
    CGRect rectLeftBottom = CGRectMake(-fullSize.width, fullSize.height * 0.5,
                                       fullSize.width * 0.5 + fullSize.width,
                                       fullSize.height * 0.5);
    
    if (CGRectContainsPoint(rectLeftBottom, point)){
        return SRPanelPositionLeftBottom;
    }
    
    CGRect rectRightBottom = CGRectMake(fullSize.width * 0.5, fullSize.height * 0.5,
                                        fullSize.width * 0.5 + fullSize.width, fullSize.height * 0.5);
    if (CGRectContainsPoint(rectRightBottom, point)){
        return SRPanelPositionRightBottom;
    }
    
    return SRPanelPositionUnknow;
}

- (void)didResize{
    [super didResize];
}



#pragma mark -
- (BOOL)isShowing {
    return _isShowing;
}


- (void)showMenu {
    if (_isShowing == YES) {
        return;
    }
    _isShowing = YES;
    
    [self handleMoveEndWithCheck:YES];
}

- (void)hideMenu{
    if (_isShowing == NO) {
        return;
    }
    _isShowing = NO;
    
    // 将最下面那个放到最上面, 其他隐藏
    for (int i = (int)self. mainMenuItems.count-1; i>=0; i--) {
        [self animateMenuItem:self. mainMenuItems[i] atIndex:i show:NO];
    }
}

- (void)animateMenuItem:(UIView *)item atIndex:(NSInteger)index show:(BOOL)showing {
    float itemStartTime = self.menuAnimationDuration * ((float)index/(float)_mainMenuItems.count);
    float delayTime = showing ? self.menuAnimationDuration - itemStartTime : itemStartTime;
    float durationTime = showing ? delayTime : self.menuAnimationDuration;
    
    // 要隐藏的话
    if (!showing) item.alpha = 1;
    [UIView animateWithDuration:durationTime delay:delayTime options:UIViewAnimationOptionCurveEaseOut animations:^{
        [self repostionMainMenuItem:item atIndex:index];
        if (showing) {
            item.alpha = 1;
        }else{
            item.alpha = 0;
        }
        
    } completion:nil];
}


- (void)repostionMainMenuItem:(UIView *)item atIndex:(NSInteger)index{
    
    BOOL isOnBottom = self.position == SRPanelPositionLeftBottom || self.position == SRPanelPositionRightBottom;
    
    CGRect rect = item.frame;
    
    if (isOnBottom) {
        
        if (!_isShowing) {
            rect.origin.y = self.y;
        }else{
            rect.origin.y = self.minY - item.frame.size.height - index * (item.frame.size.height + self.itemGap) - self.itemGap * 0.5;
        }
    }else{
        if (!_isShowing) {
            rect.origin.y = self.y;
        }else{
            rect.origin.y = self.maxY + index * (item.frame.size.height + self.itemGap) + self.itemGap * 0.5;
        }
    }
    item.frame = rect;
    item.center = CGPointMake(self.center.x, item.center.y) ;
    
}



- (void)cleanup{
    // 添加 items - 第一个永远在最下面
    for (int i = 0; i < self.mainMenuItems.count; i++) {
        UIView * menuItem = self. mainMenuItems[i];
        [menuItem removeFromSuperview];
    }
    [super removeFromSuperview];
}

- (void)removeFromSuperview{
    [self cleanup];
}

- (void)generateMainMenu:(void(^)(NSArray * items))itemsBlock{
    
    if (self.superview == nil) {
        NSLog(@"generateMainMenu superview is nil");
        return;
    }
    
    
    if (itemsBlock) {
        itemsBlock(self.mainMenuItems);
    }
}


@end
