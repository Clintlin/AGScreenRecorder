//
//  SRNetworking.h
//  AFNetworking
//
//  Created by Clintlin on 2017/9/26.
//
#import <AFNetworking/AFNetworking.h>

extern NSString const * kSRNetworkingUploadVideo;
extern NSString const * kSRNetworkingUploadVideoProgess;

@class VCServer;

typedef NS_ENUM(NSInteger, SRRequestMethodType){
    SRRequestMethodTypePost = 1,
    SRRequestMethodTypeGet
};


// http object - model
@interface SRHttpObject : NSObject
@property (nonatomic) NSString * code;
@property (nonatomic) NSDictionary * data;
@property (nonatomic) NSString * msg;

+ (instancetype)object;
@end

@interface SRNetworking : AFHTTPSessionManager

// video Upload Request
+ (void)uploadVideoWithVideoData:(NSData *)videoData
                       imageData:(NSData *)imageData
videoExtension:(NSString *)ext
uploadProgress:(void (^)(NSProgress * ))uploadProgress
completionHandler:(void (^)(SRHttpObject * response,NSError* err))completionHandler;

@end
