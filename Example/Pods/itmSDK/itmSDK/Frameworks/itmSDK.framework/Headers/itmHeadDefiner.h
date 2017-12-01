//
//  itmHeadDefiner.h
//  itmSDK
//
//  Created by HeXingang on 2017/7/25.
//  Copyright © 2017年 AiYou. All rights reserved.
//

#ifndef itmHeadDefiner_h
#define itmHeadDefiner_h

#define itm_DEPRECATED_WILL_BE_REMOVED_IN_PLEASE_USE(name) __attribute__((deprecated("Use `" name "` instead.")))
#define WEAKSELF(weakSelf)      __weak __typeof(&*self)weakSelf = self;
#define WEAK(id,weakSelf)       __weak __typeof(&*id)weakSelf = id;


#define itm_iOS7Later               ([UIDevice currentDevice].systemVersion.floatValue >= 7.0f)
#define itm_iOS8Later               ([UIDevice currentDevice].systemVersion.floatValue >= 8.0f)
#define itm_iOS9Later               ([UIDevice currentDevice].systemVersion.floatValue >= 9.0f)
#define itm_iOS9_1Later             ([UIDevice currentDevice].systemVersion.floatValue >= 9.1f)
#define itm_iOS10Later              ([UIDevice currentDevice].systemVersion.floatValue >= 10.f)
#define itm_iOS11Later              ([UIDevice currentDevice].systemVersion.floatValue >= 11.f)

#define itm_DEFAULTS                [NSUserDefaults standardUserDefaults]

#define itm_kPanelDisplayDruation 3.f
#define itm_kAnimationDefaultDruation 0.35f

#define kScreenWidth                [[UIScreen mainScreen] bounds].size.width
#define kScreenHeight               [[UIScreen mainScreen] bounds].size.height
#define kScreenStatusBarHeight      ([[UIApplication sharedApplication] statusBarFrame].size.height)

#define RGBACOLOR(r,g,b,a)          [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:a]
#define RGBCOLOR(r,g,b)             [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0f]


#endif /* itmHeadDefiner_h */
