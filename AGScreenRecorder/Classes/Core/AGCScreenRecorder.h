//
//  AGScreenRecorder.h
//  AGScreenRecorder
//
//  Created by Clintlin on 2017/9/29.
//

#import <UIKit/UIKit.h>

typedef enum : NSUInteger {
    SRVideoPreviewActionShare,
    SRVideoPreviewActionCancel,
    SRVideoPreviewActionSave,
} SRVideoPreviewAction;

@interface AGCScreenRecorder : NSObject

+ (instancetype _Nullable )shareRecorder;

@property (nonatomic, strong) void (^ _Nullable videoShareBlock)(SRVideoPreviewAction action);

- (void) startRecording:(nullable void(^)(NSError * _Nullable error))completaion;
- (void) stopRecord:(nullable void(^)(NSError * _Nullable error))completaion;
- (void) cancel:(void(^_Nullable)())completaion;
@end
