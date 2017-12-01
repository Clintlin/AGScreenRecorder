//
//  UIImage+AYAdditions.h
//  AYGameBox
//
//  Created by Clintlin on 2017/3/24.
//  Copyright © 2017年 Clintlin. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (itmAdditions)

- (UIImage *)addCornerWithRadius:(CGFloat)radius
                            size:(CGSize)size;

+ (UIImage *)imageNamed:(NSString *)name bundle:(NSString *)identifiter;
/**
 name 传pdf的文件名，不带.pdf
 */
+ (UIImage *)PDFNamed:(NSString *)name size:(CGSize)size bundle:(NSString *)identifiter;
@end


