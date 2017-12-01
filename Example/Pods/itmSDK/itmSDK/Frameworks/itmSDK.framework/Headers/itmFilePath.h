//
//  itmFilePath.h
//  AYMovePanel
//
//  Created by Clintlin on 2017/7/21.
//  Copyright © 2017年 zhangxinming. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface itmFilePath : NSObject
/**
 @abstract Get File from the disk.
 @discussion if not, return nil.
 
 param cacheFilePath cache of native path
 @return cached image.
 */
+ (NSString *)getCacheFileDirectory;
@end
