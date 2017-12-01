//
//  itmPoint.h
//  itmSDK
//
//  Created by Clintlin on 2017/7/31.
//  Copyright © 2017年 AiYou. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface itmPoint : NSObject

@property (nonatomic ,strong) NSDate * date;
@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat z;


+ (instancetype) pointWithCGPoint:(CGPoint)point z:(CGFloat) z;
+ (instancetype) pointWithX:(CGFloat)x y:(CGFloat)y z:(CGFloat)z;
- (instancetype) initWithX:(CGFloat)x_ y:(CGFloat)y_ z:(CGFloat)z_;

- (CGPoint)CGPoint;

//
- (itmPoint *) transfrom:(CGAffineTransform)tx;
- (CGFloat) distanceToPoint:(itmPoint *)pt;
- (itmPoint *) addPoint:(itmPoint *)pt;
- (itmPoint *) subtractPoint:(itmPoint *)pt;
- (CGFloat) dotPoint:(itmPoint *)pt;
- (itmPoint *)abs;
- (itmPoint *) unitVectorWithTransfrom:(CGAffineTransform)tx; // 有点问题要重新弄一下
- (itmPoint *)normalize;
- (itmPoint *)multiplyByScalar:(CGFloat)scalar;
- (CGFloat) magnitude;
- (BOOL) isZero;
- (void) setCGPoint:(CGPoint)pt;
- (BOOL) isDegenerate;
- (BOOL) isEqual:(id)object;
- (id) copy;
- (NSString *) description;


@end
