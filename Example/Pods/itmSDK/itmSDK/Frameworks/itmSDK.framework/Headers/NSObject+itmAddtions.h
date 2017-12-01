//
//  NSObject+funs.h
//  I TALK I DRAW
//
//  Created by Clintlin on 16/7/19.
//  Copyright © 2016年 Northflag-Clint.Lin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (itmAddtions)
- (void)callFunctions:(void (^)(void))funs afterDelay:(float)delay;
- (void)callFunctions:(void(^)(void))func completed:(void(^)(void))completed;
@end
