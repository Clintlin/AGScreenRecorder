//
//  DSUtilities.h
//  I TALK I DRAW
//
//  Created by Clintlin on 16/2/2.
//  Copyright © 2016年 JoinUs.Clint.Lin. All rights reserved.
//

#import <UIKit/UIKit.h>


// 颜色转换
void itm_HSVtoRGB(float h, float s, float v, float *r, float *g, float *b);
void itm_RGBtoHSV(float r, float g, float b, float *h, float *s, float *v);

// 正弦曲线
float itm_SineCurve(float input);

// 画一个checker
void itm_DrawCheckersInRect(CGContextRef ctx, CGRect dest, int size);

// 画一个Diamond
void itm_DrawTransparencyDiamondInRect(CGContextRef ctx, CGRect dest);

// 随机10000分之几
float itm_RandomFloat(void);

// 判断是否共线
BOOL itm_Collinear(CGPoint a, CGPoint b, CGPoint c);

//#define FileHashDefaultChunkSizeForReadingData 1024*8
//CFStringRef FileMD5HashCreateWithPath(CFStringRef filePath,size_t chunkSizeForReadingData);


/******************************
 * static inline functions
 *****************************/

// 将两个rect合并
static inline CGRect itm_UnionRect(CGRect a, CGRect b){
    if (CGRectEqualToRect(a, CGRectZero)) {
        return b;
    } else if (CGRectEqualToRect(b, CGRectZero)) {
        return a;
    }
    
    return CGRectUnion(a, b);
}

static inline UIImage * itmCaptureScreenshot() {
    UIWindow * window = [UIApplication sharedApplication].keyWindow;
    
    UIGraphicsBeginImageContextWithOptions(window.bounds.size, NO, [UIScreen mainScreen].scale);
    
    NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:
                                [window methodSignatureForSelector:
                                 @selector(drawViewHierarchyInRect:afterScreenUpdates:)]];
    [invocation setTarget:window];
    [invocation setSelector:@selector(drawViewHierarchyInRect:afterScreenUpdates:)];
    CGRect arg2 = window.bounds;
    BOOL arg3 = NO;
    [invocation setArgument:&arg2 atIndex:2];
    [invocation setArgument:&arg3 atIndex:3];
    [invocation invoke];
    
    UIImage *screenshot = UIGraphicsGetImageFromCurrentImageContext();
    
    UIGraphicsEndImageContext();
    
    return screenshot;
}


// 将设计图的尺寸根据屏幕百分比缩放
/**
 @prama width 设计图上屏幕竖屏的宽
 @prama px 设计图上的像素
 
 */
static inline float itmConverSize(float width,float px) {
    CGSize size_ = [UIScreen mainScreen].bounds.size;
    
    float p = MIN(size_.width,size_.height)/width;
    
    return round(px * p);
}

// 默认设计图上屏幕竖屏的宽为750
static inline float itmConverToPtFromPx(float px){
    return itmConverSize(750.f, px);
}

static inline CGPoint DSSubtractPoints(CGPoint a, CGPoint b) {
    return CGPointMake(a.x - b.x, a.y - b.y);
}
static inline CGPoint DSAddPoints(CGPoint a, CGPoint b) {
    return CGPointMake(a.x + b.x, a.y + b.y);
}
static inline CGPoint DSMultiplyPointScalar(CGPoint p, float s) {
    return CGPointMake(p.x * s, p.y * s);
}

static inline float DSDistance(CGPoint a, CGPoint b) {
    float xd = (a.x - b.x);
    float yd = (a.y - b.y);
    
    return sqrt(xd * xd + yd * yd);
}

static inline float itmClamp(float min, float max, float value) {
    return (value < min) ? min : (value > max) ? max : value;
}
