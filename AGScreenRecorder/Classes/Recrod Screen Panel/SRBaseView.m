//
//  AYBaseViewController.m
//  AYGameBox
//
//  Created by Clintlin on 2017/3/23.
//  Copyright © 2017年 Clintlin. All rights reserved.
//

#import "SRBaseView.h"
#import "MBProgressHUD.h"

@interface SRBaseView ()
@property (nonatomic, strong) MBProgressHUD * hud;
@end

@implementation SRBaseView{
}




- (MBProgressHUD *)hud {
    if (_hud == nil) {
        
        if (self.superview == nil) {
            return nil;
        }

        _hud = [MBProgressHUD showHUDAddedTo:self.superview animated:NO];
        _hud.mode = MBProgressHUDModeText;
        [_hud hideAnimated:NO];
        [self.superview addSubview:_hud];
    }
    [self bringSubviewToFront:_hud];
    return _hud;
}
- (void)alert:(NSString *)msg {
    
    if (_hud) {
        _hud = nil;
    }
    
    dispatch_async(dispatch_get_main_queue(), ^{
        //
        self.hud.label.text = msg;
        [self.hud showAnimated:YES];
        [self.hud hideAnimated:YES afterDelay:1.2f];
        
        [_hud removeFromSuperViewOnHide];
    });
    
}


+ (instancetype)showInView:(UIView *)view{
    SRBaseView * bv = [[[self class] alloc] init];
    [bv setup:view];
    [bv setupSubviews];
    return bv;
}

- (void)show:(BOOL)animated{
    
    if(animated){
        [self setHidden:NO];
        [itmAnimation animationWithType:itmAnimationTypePopUp andView:self completion:^(BOOL finished) {
            [self.superview bringSubviewToFront:self];
            if (finished) {
                
            }
        }];
        
        return;
    }
    
    if (self.alpha == 0.f) self.alpha = 1.f;
    [self setHidden:NO];
    [self.superview bringSubviewToFront:self];
}

- (void)hide:(BOOL)animated{
    if(animated){
        
        [itmAnimation animationWithType:itmAnimationTypePopOut andView:self completion:^(BOOL finished) {
            [self setHidden:YES];
        }];
        
        return;
    }
    [self setHidden:YES];
}

- (void)showLoading:(NSString *)msg{
    dispatch_async(dispatch_get_main_queue(), ^{
        if (_hud) {
            [self loadingEndAfter:CGFLOAT_MIN];
            _hud = nil;
        }
        
        self.hud.mode = MBProgressHUDModeIndeterminate;
        if (msg) {
            self.hud.label.text = msg;
        }
        
        [self.hud showAnimated:YES];
    });
    
}
- (void)loadingEndAfter:(float)sec{
    [self.hud hideAnimated:YES afterDelay:sec];
    [_hud removeFromSuperViewOnHide];
}


- (void)setup:(UIView * )superView{
    [superView addSubview:self];
    self.frame = superView.bounds;
    [self setBackgroundColor:[UIColor clearColor]];
}

- (void)setupSubviews {
    // 事件
    {
        [[NSNotificationCenter defaultCenter] addObserver:self
                                                 selector:@selector(reSize:)
                                                     name:UIDeviceOrientationDidChangeNotification
                                                   object:nil];
    }
}

- (void)reSize:(NSNotification *)notification {
    
    
    if (self.superview == nil) {
        return;
    }
    
    UIInterfaceOrientation orientation = [[UIApplication sharedApplication] statusBarOrientation];
    
    if (self.orientation == orientation) {
        return;
    }
    self.orientation = orientation;
    
    
//    [UIView animateWithDuration:0.25 animations:^{
//        [self willResize];
//
////        CGRect rect = self.frame;
////        if (self.orientation == UIInterfaceOrientationLandscapeRight
////            || self.orientation == UIInterfaceOrientationLandscapeLeft) {
////            rect.size.width = MAX(self.frame.size.width, self.frame.size.height);
////            rect.size.height = MIN(self.frame.size.width, self.frame.size.height);
////
////        }else{
////            rect.size.height = MAX(self.frame.size.width, self.frame.size.height);
////            rect.size.width = MIN(self.frame.size.width, self.frame.size.height);
////        }
//
////        self.frame = rect;
//        [self didResize];
//    }];
}


- (void)dealloc{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)willResize{
    
}

- (void)didResize{
    
}


@end
