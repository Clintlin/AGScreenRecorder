//
//  AYBaseViewController.h
//  AYGameBox
//
//  Created by Clintlin on 2017/3/23.
//  Copyright © 2017年 Clintlin. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <itmSDK/itmSDK.h>

@interface SRBaseView : UIView

@property(nonatomic, assign) UIInterfaceOrientation orientation;
@property(nonatomic, assign) CGRect ordinalFrame;
@property(nonatomic, assign) UIInterfaceOrientation ordinalOrientation;




- (void)reSize:(NSNotification *)notification;

- (void)alert:(NSString *)msg;

+ (instancetype)showInView:(UIView *)view;
- (void)show:(BOOL)animated;
- (void)hide:(BOOL)animated;

- (void)showLoading:(NSString *)msg;
- (void)loadingEndAfter:(float)sec;
- (void)setup:(UIView * )superView;
- (void)setupSubviews;

- (void)willResize;
- (void)didResize;
@end
