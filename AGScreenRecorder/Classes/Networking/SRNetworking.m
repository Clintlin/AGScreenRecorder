//
//  SRNetworking.m
//  AFNetworking
//
//  Created by Clintlin on 2017/9/26.
//

#import "SRNetworking.h"
#import "SRApi.h"
NSString * SRAPIBaseUrlString = @"http://192.168.111.153:9992/";
//／／ https://fastdfs.aigamecloud.com/
@implementation SRNetworking{
    AFNetworkReachabilityManager *reachabilityManager;
}

+ (instancetype)sharedClient {
    static SRNetworking *_sharedClient = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _sharedClient = [[SRNetworking alloc] initWithBaseURL:[NSURL URLWithString:SRAPIBaseUrlString]];
        _sharedClient.securityPolicy = [AFSecurityPolicy policyWithPinningMode:AFSSLPinningModeNone];
        _sharedClient->reachabilityManager = [AFNetworkReachabilityManager sharedManager];
        [_sharedClient->reachabilityManager startMonitoring];
    });
    
    return _sharedClient;
}

- (void)defaultSetting {
    
//    AYCenterAccount * a = [AYUserCenterManager shareInstance].defaultAccount;
//
//    // 头部放入服务器端需要的数据
//    [self.requestSerializer setValue:tempUserId!=nil?tempUserId:a.accountId forHTTPHeaderField:@"userId"];
//
//
    // 基本设置
    self.requestSerializer.timeoutInterval = 20;
    self.responseSerializer.acceptableContentTypes = [NSSet setWithObjects:@"application/json", @"text/json", @"text/javascript", @"text/plain", nil];
    self.requestSerializer.HTTPShouldHandleCookies = YES;
}


NSString * kSRNetworkingUploadVideo = @"AGScreenRecorderVideoUpload";
NSString * kSRNetworkingUploadVideoProgess = @"AGScreenRecorderVideoUploadProgess";
+ (void)uploadVideoWithVideoData:(NSData *)videoData
                       imageData:(NSData *)imageData
                  videoExtension:(NSString *)ext
                  uploadProgress:(void (^)(NSProgress * ))uploadProgress
               completionHandler:(void (^)(SRHttpObject * response,NSError* err))completionHandler{
    
    if (videoData == nil) {
        NSError * error = [NSError errorWithDomain:kSRNetworkingUploadVideo code:SRErrorTypeStringMissingParameter userInfo:@{@"message":@"视频数据丢失"}];
        return completionHandler(nil, error);
    }
    
    if (imageData == nil) {
        NSError * error = [NSError errorWithDomain:kSRNetworkingUploadVideo code:SRErrorTypeStringMissingParameter userInfo:@{@"message":@"图片数据丢失"}];
        return completionHandler(nil, error);
    }
    
    SRNetworking * networkTool = [SRNetworking sharedClient];
    [networkTool defaultSetting];

    __block NSString * name = [NSString stringWithFormat:@"%.0f",[[NSDate date] timeIntervalSince1970]];
    NSDictionary * params = @{@"videoPath":[name stringByAppendingFormat:@".%@",ext],
                              @"picturePath":[name stringByAppendingFormat:@".%@",@"png"]
                              };
    [networkTool POST:@"singleFileUploadForVideo" parameters:params constructingBodyWithBlock:^(id<AFMultipartFormData> formData)
    {

        [formData appendPartWithFileData:videoData
                                    name:@"videoPath"
                                fileName:[name stringByAppendingFormat:@".%@",ext]
                                mimeType:@"video/mp4"];

        [formData appendPartWithFileData:imageData
                                    name:@"picturePath"
                                fileName: [name stringByAppendingFormat:@".%@",@"png"]
                                mimeType:@"image/png"];

    } progress:uploadProgress success:^(NSURLSessionDataTask * task, id responseObject) {
        if (![responseObject isKindOfClass:[NSDictionary class]]) {
            NSError * error = [NSError errorWithDomain:kSRNetworkingUploadVideo code:SRErrorTypeNormalError userInfo:@{@"message":@"发生未知错误"}];
            return completionHandler(nil, error);
        }
        
        SRHttpObject * object = [SRHttpObject object];
        object.data = responseObject;
        
        if (completionHandler) {
            return completionHandler(object,nil);
        }
    } failure:^(NSURLSessionDataTask * task, NSError * error) {
        if (error && completionHandler) {
            NSMutableDictionary * userInfo = @{@"message":@"发生未知错误"}.mutableCopy;
            [userInfo setDictionary:error.userInfo];
            
            NSError * error = [NSError errorWithDomain:kSRNetworkingUploadVideo code:SRErrorTypeNormalError userInfo:userInfo];
            completionHandler(nil, error);
        }
    }];
}

//static NSString * SRCreateMultipartFormBoundary() {
//    return [NSString stringWithFormat:@"Boundary+%08X%08X", arc4random(), arc4random()];
//}

- (SRHttpObject *)handleResponse:(id)responseObject {
    if (![responseObject isKindOfClass:[NSDictionary class]]) {
        //可能json解析失败，或者服务器500
        return nil;
    }
    
//    NSArray * keys = [responseObject allKeys];
//    if (![keys containsObject:@"code"]
//        && ![keys containsObject:@"data"]
//        && ![keys containsObject:@"msg"]) {
//        NSLog(@"不规则的Json %@",responseObject);
//        return nil;
//    }
    
    SRHttpObject * object = [[SRHttpObject alloc] init];
    object.code = [responseObject valueForKey:@"code"];
    object.data = [responseObject valueForKey:@"data"];
    object.msg = [responseObject valueForKey:@"msg"];
    return object;
}
@end

@implementation SRHttpObject
+ (instancetype)object {
    return [[[self class] alloc] init];
}
@end

