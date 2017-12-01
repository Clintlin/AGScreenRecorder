//
//  NSDate+timeFrame.h
//  AYGameBox
//
//  Created by Clintlin on 2017/3/24.
//  Copyright © 2017年 Clintlin. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDate (itmAddtions)
/**
 返回当前时间戳
 */
+ (NSString *) timeStamp;

/**
 返回根据时间格式命名的文件名字，目前用于文件上传的图片命名
 \params ext 文件名的后缀
 */
+ (NSString *) nameWithExtentxion:(NSString *)ext;
@end
