//
//  DSTimer.h
//  I TALK I DRAW
//
//  Created by Clintlin on 16/4/8.
//  Copyright © 2016年 Northflag-Clint.Lin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface itmTimer : NSObject

// 私有
@property (nonatomic, readonly) NSTimer * timer;
@property (nonatomic, readonly) SEL func;
@property (nonatomic, readonly) id target;





@property (nonatomic) float count;
@property (nonatomic) float countEnd;

@property (nonatomic) double startTime;
@property (nonatomic) float timeInterval;

@property (nonatomic) CALayer *contentLayer;
- (instancetype)initWithInterval:(NSTimeInterval)ti
                          target:(id)t
                        selector:(SEL)s;

- (instancetype)initWithInterval:(NSTimeInterval)ti
                          target:(id)t
                        selector:(SEL)s
                          repeat:(BOOL)repeat;


- (void) fire;
- (void) invalidate;

- (instancetype)init;
@end
