//
//  PAnimation.h
//  I TALK I DRAW
//
//  Created by Clintlin on 15/5/6.
//  Copyright (c) 2015年 JoinUs.Clint.Lin. All rights reserved.
//
#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

static NSString *const defaultType = @"";
static NSString *const suckEffect = @"suckEffect";

static NSString *const kAnimationName = @"PAnimationCATransition";


//声明枚举
typedef enum{
    itmAnimationTypeDefault,
    itmAnimationTypeSuckEffect,
    itmAnimationTypePopUp,
    itmAnimationTypePopOut,
    
    // 右边
    itmAnimationTypeMoveInFromRight,
    itmAnimationTypeMoveOutToRight,
    
    // 从上方
    itmAnimationTypeMoveInFromTop,
    itmAnimationTypeMoveOutToTop,
    
    // 从下方
    itmAnimationTypeMoveInFromBottom,
    itmAnimationTypeMoveOutToBottom
    
}itmAnimationType;
#define kPAnimationTypeArray @[defaultType,suckEffect]

@interface itmAnimation : NSObject


@property (nonatomic,strong) CATransition * CAAnimation;
@property (nonatomic,strong) NSString * type;

@property (nonatomic) CGAffineTransform oldTransform;


+ (void)coolAnimation:(UIView *)itemView lineWidth:(NSInteger)lineWidth;

+ (void)wobbleAnimation:(UIView *)itemView;



//
+(void)animationWithType:(itmAnimationType)type andView:(UIView *)view completion:(void (^)(BOOL finished))completion;


// 基本方法
+ (instancetype)manager;
- (instancetype)initWithAnimationType:(itmAnimationType)type;

// CATransition 的动画
- (void)setAnimationWithView:(UIView *)view andPoint:(CGPoint)point;
- (void)setAnimationType:(NSString *)enumType withView:(UIView *)view andPoint:(CGPoint)point;

+ (void)fallDownAnimation:(UIView *)theView;
@end
