//
//  UIView+Additions.h
//  AYGameBox
//
//  Created by Clintlin on 2017/3/24.
//  Copyright © 2017年 Clintlin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (itmAdditions)

@property (nonatomic, assign) CGSize size;
@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;
@property (nonatomic, assign) CGPoint leftTop;
@property (nonatomic, assign) CGPoint rightTop;
@property (nonatomic, assign) CGPoint leftBottom;
@property (nonatomic, assign) CGPoint rightBottom;

- (CGFloat)minX;
- (CGFloat)midX;
- (CGFloat)maxX;
- (CGFloat)minY;
- (CGFloat)midY;
- (CGFloat)maxY;

/**
 圆角优化，每次使用将添加一个UIImageView到view上
 
 */
- (void)addCornerWithRadius:(CGFloat)radius
             backgoundColor:(UIColor*)backgroundColor;


- (void) addDashLineWithSize:(CGSize)size gap:(CGFloat)gap color:(UIColor *)color;
//获取当前view的截图
- (UIImage *)renderAsImage;
//高斯模糊
+ (UIVisualEffectView *)blurViewWithFrame:(CGRect)frame style:(UIBlurEffectStyle)style;

+ (__kindof UIView *)loadNibNamed:(NSString *)name bundle:(NSString *)bundle owner:(id)owner;

@end
