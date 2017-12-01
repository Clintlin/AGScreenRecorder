//
//  itmColor.h
//  itmSDK
//
//  Created by HeXingang on 2017/7/25.
//  Copyright © 2017年 AiYou. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface itmColor : NSObject {
    CGFloat   hue_;
    CGFloat   saturation_;
    CGFloat   brightness_;
    CGFloat   alpha_;
}

@property (nonatomic, readonly) CGFloat hue;
@property (nonatomic, readonly) CGFloat saturation;
@property (nonatomic, readonly) CGFloat brightness;
@property (nonatomic, readonly) CGFloat alpha;
@property (nonatomic, readonly) float red;
@property (nonatomic, readonly) float green;
@property (nonatomic, readonly) float blue;

+ (itmColor *) randomColor;
+ (itmColor *) colorWithHue:(CGFloat)hue saturation:(CGFloat)saturation brightness:(CGFloat)brightness alpha:(CGFloat)alpha;
+ (itmColor *) colorWithWhite:(float)white alpha:(CGFloat)alpha;
+ (itmColor *) colorWithRed:(float)red green:(float)green blue:(float)blue alpha:(CGFloat)alpha;
- (itmColor *) initWithHue:(CGFloat)hue saturation:(CGFloat)saturation brightness:(CGFloat)brightness alpha:(CGFloat)alpha;
+ (itmColor *)colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;

+ (itmColor *) colorWithDictionary:(NSDictionary *)dict;
- (NSDictionary *) dictionary;

+ (itmColor *) colorWithData:(NSData *)data;
- (NSData *) colorData;

- (UIColor *) UIColor;
- (UIColor *) opaqueUIColor;

- (CGColorRef) CGColor;
- (CGColorRef) opaqueCGColor;

- (void) set;

- (itmColor *) adjustColor:(itmColor * (^)(itmColor *color))adjustment;
- (itmColor *) colorBalanceRed:(float)rShift green:(float)gShift blue:(float)bShift;
- (itmColor *) adjustHue:(float)hShift saturation:(float)sShift brightness:(float)bShift;
- (itmColor *) inverted;
- (itmColor *) desaturated;
- (itmColor *) colorWithAlphaComponent:(float)alpha;

+ (itmColor *) blackColor;
+ (itmColor *) grayColor;
+ (itmColor *) whiteColor;
+ (itmColor *) cyanColor;
+ (itmColor *) redColor;
+ (itmColor *) magentaColor;
+ (itmColor *) greenColor;
+ (itmColor *) yellowColor;
+ (itmColor *) blueColor;
+ (itmColor *) defaultColor;
+ (itmColor *) clearColor;

- (NSString *) hexValue;

- (itmColor *) complement;
- (itmColor *) blendedColorWithFraction:(float)fraction ofColor:(itmColor *)color;

- (void) drawEyedropperSwatchInRect:(CGRect)rect;


@end
