//
//  ScreenshotAlert.m
//  AYMovePanel
//
//  Created by HeXingang on 2017/9/25.
//  Copyright © 2017年 zhangxinming. All rights reserved.
//

#import "SRPopPreviewView.h"
#import "SRApi.h"
#import "SRCommonMacros.h"
#import "SRNetworking.h"
#import <itmSDK/itmSDK.h>
#import <AGSocial/AGSocial.h>
#import <AVFoundation/AVFoundation.h>

@interface SRPopPreviewView()
{
    UIControl *_backgroundView;
}


@property (nonatomic, strong) UIImageView*  logoImageView;

@property (nonatomic, strong) UIButton*     shareBtn;
@property (nonatomic, strong) UIButton*     deleteBtn;

@end

CGFloat  kScreenshotAlertLogoImageHeight;
CGFloat kScreenshotAlertShadeViewHeight;
CGFloat kScreenshotAlertButtonWidth;


@implementation SRPopPreviewView{
    NSURL * _videoURL;
    UIImage * _thumbnail;
}

+ (instancetype)showInView:(UIView *)view videoURL:(NSURL *)videoURL
{
    SRPopPreviewView* alert = [[SRPopPreviewView alloc] init];
    [view addSubview:alert];
    
    kScreenshotAlertLogoImageHeight = itmConverToPtFromPx(200);
    kScreenshotAlertShadeViewHeight = itmConverToPtFromPx(60);
    kScreenshotAlertButtonWidth = itmConverToPtFromPx(120);
    
    alert->_videoURL = videoURL;
    alert->_thumbnail = [alert thumbnailOfVideoURL:videoURL];
    
    [alert setupSubviews];
    
    return alert;
}

- (instancetype)init
{
    if(self = [super init]){
        
        CGFloat kScreenshotAlertWidth  = MIN( kScreenWidth, kScreenHeight) - itmConverToPtFromPx(40.f);
        CGFloat kScreenshotAlertHeight = kScreenshotAlertWidth* 5.f/6.f;
        [self setFrame:CGRectMake(0, 0, kScreenshotAlertWidth, kScreenshotAlertHeight)];
        [self setBackgroundColor:[UIColor clearColor]];
    }
    
    return self;
}

- (void)dealloc
{
    if(_backgroundView){
        [_backgroundView removeFromSuperview];
        _backgroundView = nil;
    }
    
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

- (void)setupSubviews
{
    [super setupSubviews];
    
    self.center = CGPointMake(self.superview.center.x, self.superview.center.y - kScreenshotAlertLogoImageHeight/4.f);
    
    _backgroundView = [[UIControl alloc] initWithFrame:self.superview.bounds];
    [self.superview addSubview:_backgroundView];
    [_backgroundView setBackgroundColor:[UIColor colorWithWhite:0.f alpha:0.4]];
    
    [self.superview bringSubviewToFront:self];
    
    UIView* bgView = [[UIView alloc] initWithFrame:CGRectMake(0, kScreenshotAlertLogoImageHeight/2.f, self.width, self.height - kScreenshotAlertLogoImageHeight/2.f)];
    [bgView setBackgroundColor:[UIColor whiteColor]];
    [self addSubview:bgView];
    
//    _logoImageView = [[UIImageView alloc] initWithFrame:CGRectMake(0,
//                                                                   0,
//                                                                   kScreenshotAlertLogoImageHeight,
//                                                                   kScreenshotAlertLogoImageHeight)];
//    _logoImageView.center = CGPointMake(self.width/2.f, kScreenshotAlertLogoImageHeight/2.f);
//    [_logoImageView setClipsToBounds:YES];
//    [_logoImageView setContentMode:UIViewContentModeScaleAspectFill];
//    [_logoImageView setBackgroundColor:[UIColor clearColor]];
//    [_logoImageView.layer setCornerRadius:_logoImageView.width/2.f];
//    [_logoImageView setImage:[UIImage PDFNamed:@"tanzhi" size:_logoImageView.size bundle:SR_BUNDLE_IDENTIFIER]];
//    [self addSubview:_logoImageView];
    
    CGFloat shotImageOffSetY = _logoImageView.y + _logoImageView.height + itmConverToPtFromPx(5);
    
    _thumbnailImageView = [[UIImageView alloc] initWithFrame:CGRectMake(itmConverToPtFromPx(5),
                                                                     shotImageOffSetY,
                                                                     self.width - itmConverToPtFromPx(5)*2,
                                                                     self.height - shotImageOffSetY)];
    [_thumbnailImageView setClipsToBounds:YES];
    [_thumbnailImageView setContentMode:UIViewContentModeScaleAspectFill];
    [_thumbnailImageView setBackgroundColor:[UIColor clearColor]];
    _thumbnailImageView.image = _thumbnail;
    [self addSubview:_thumbnailImageView];
    
    UIView* shadeView = [[UIView alloc] initWithFrame:CGRectMake(0, self.height - kScreenshotAlertShadeViewHeight, self.width, kScreenshotAlertShadeViewHeight)];
    [shadeView setBackgroundColor:RGBACOLOR(0, 0, 0, 0.5f)];
    [self addSubview:shadeView];
    
    _shareBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [_shareBtn setFrame:CGRectMake(shadeView.width - kScreenshotAlertButtonWidth*2, 0, kScreenshotAlertButtonWidth, shadeView.height)];
    [_shareBtn setBackgroundColor:[UIColor clearColor]];
    [_shareBtn setTitle:@"分享" forState:UIControlStateNormal];
    [_shareBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [_shareBtn.titleLabel setFont:[UIFont systemFontOfSize:14]];
    [shadeView addSubview:_shareBtn];
    
    [_shareBtn addTarget:self action:@selector(shareAction) forControlEvents:UIControlEventTouchUpInside];
    
    _deleteBtn = [UIButton buttonWithType:UIButtonTypeCustom];
    [_deleteBtn setFrame:CGRectMake(shadeView.width - kScreenshotAlertButtonWidth, 0, kScreenshotAlertButtonWidth, shadeView.height)];
    [_deleteBtn setBackgroundColor:[UIColor clearColor]];
    [_deleteBtn setTitle:@"删除" forState:UIControlStateNormal];
    [_deleteBtn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [_deleteBtn.titleLabel setFont:_shareBtn.titleLabel.font];
    [shadeView addSubview:_deleteBtn];
    
    [_deleteBtn addTarget:self action:@selector(deleteAction) forControlEvents:UIControlEventTouchUpInside];
    
    UIButton* close = [UIButton buttonWithType:UIButtonTypeCustom];
    [close setBackgroundColor:[UIColor clearColor]];
    [close setFrame:CGRectMake(self.width - itmConverToPtFromPx(60) - 2,
                               bgView.y + 2,
                               itmConverToPtFromPx(60),
                               itmConverToPtFromPx(60))];
    
    [close setImage:[UIImage PDFNamed:@"close"
                                 size:close.size
                               bundle:SR_BUNDLE_IDENTIFIER]
           forState:UIControlStateNormal];
    
    [self addSubview:close];
    [close addTarget:self action:@selector(closeAction) forControlEvents:UIControlEventTouchUpInside];
}


- (void)didResize
{
    [_backgroundView setFrame:self.superview.bounds];
    self.center = CGPointMake(self.superview.center.x, self.superview.center.y - kScreenshotAlertLogoImageHeight/4.f);
}

#pragma mark - actions
- (void)shareAction
{
    UIImage* image = _thumbnailImageView.image;
    if(image == nil){
        return;
    }
    
    
    // 上传
    NSData * imageData = UIImagePNGRepresentation(_thumbnail);
    NSData * videoData = [NSData dataWithContentsOfURL:_videoURL];
    
    if (videoData == nil) {
        NSError * error = [NSError errorWithDomain:@"AGScreenRecorderVideoShareEvent" code:SRErrorTypeNormalError userInfo:@{@"message":@"无法读取视频数据"}];
        return [[SRApi shareInstance] onFailureWithError:error];
    }
    
    [SRNetworking uploadVideoWithVideoData:videoData imageData:imageData videoExtension:@"MP4" uploadProgress:^(NSProgress * progess) {
        NSDictionary * userInfo = @{@"completedUnitCount":@(progess.completedUnitCount),
                                    @"totalUnitCount" : @(progess.totalUnitCount)};
        [[SRApi shareInstance] successWithObjectName:kSRNetworkingUploadVideoProgess.copy userInfo:userInfo];
        NSLog(@"---- uploading --- %f",((float)progess.completedUnitCount/(float)progess.totalUnitCount));
    } completionHandler:^(SRHttpObject *response, NSError *err) {
        if (err) {
            return [[SRApi shareInstance] onFailureWithError:err];
        }
        
        // 上传完毕的话 - 进行分享
        //
        NSArray * array = [response.data objectForKey:@"videoShortUrlList"];
        [self shareVideoWithTitle:@"" thumbnail:_thumbnail videoURL:array.firstObject];
//
//        AGSocial_ShareVideoToWXSessionWithTitle(@"a", _thumbnail, array.firstObject);
    }];
    
}

- (void)deleteAction
{
    [self closeAction];
    
    if(!itm_iOS9Later){
        
        NSString * videoPath = _videoURL.absoluteString;
        NSFileManager * fm = [NSFileManager defaultManager];
        if ([fm fileExistsAtPath: videoPath]){
            NSError * error;
            [fm removeItemAtPath:videoPath error:&error];
            if (error) {
                NSError * err = [NSError errorWithDomain:@"AGScreenRecorderVideoDelete"
                                                    code:SRErrorTypeNormalError
                                                userInfo:@{@"message":@"移除视频错误",
                                                           @"description":error.localizedDescription}];
                return [[SRApi shareInstance] onFailureWithError:err];
            }else{
                return [[SRApi shareInstance] successWithObjectName:@"AGScreenRecorderVideoDelete"
                                                           userInfo:@{@"message":@"移除视频成功"}];
            }
        }
    }
    
}

- (void)closeAction
{
    if(_backgroundView){
        [_backgroundView removeFromSuperview];
        _backgroundView = nil;
    }
    
    [self removeFromSuperview];
}

#pragma mark - methods
- (UIImage *)thumbnailOfVideoURL:(NSURL *)url {
    AVAsset *_asset = [AVAsset assetWithURL:url];
    AVAssetImageGenerator *generator = [AVAssetImageGenerator assetImageGeneratorWithAsset:_asset];
    
    generator.appliesPreferredTrackTransform = YES;
    
    generator.maximumSize = CGSizeMake(640, 480);
    NSError *error = nil;
    
    CGImageRef img = [generator copyCGImageAtTime:kCMTimeZero actualTime:NULL error:&error];
    
    if (error) {
        return nil;
    }
    
    return [UIImage imageWithCGImage: img];
}

- (void) shareVideoWithTitle:(NSString *)title thumbnail:(UIImage *)thumbnail videoURL:(NSURL *)videoURL {
    
    //在这里呢 如果想分享图片 就把图片添加进去  文字什么的通上
    NSArray *activityItems = @[title, thumbnail, _videoURL];
    UIActivityViewController *activityVC = [[UIActivityViewController alloc]initWithActivityItems:activityItems applicationActivities:nil];
    //不出现在活动项目
    activityVC.excludedActivityTypes = @[UIActivityTypePrint, UIActivityTypeCopyToPasteboard,UIActivityTypeAssignToContact,UIActivityTypeSaveToCameraRoll];
    
    
    UIViewController * vc = AGSR_getCurrentRootController();
    
    [vc presentViewController:activityVC animated:YES completion:nil];
    // 分享之后的回调
    activityVC.completionWithItemsHandler = ^(UIActivityType  _Nullable activityType, BOOL completed, NSArray * _Nullable returnedItems, NSError * _Nullable activityError) {
        if (completed) {
            return [[SRApi shareInstance] successWithObjectName:@"AGScreenRecorderShareSuccess"
                                                       userInfo:@{@"message":@"移除视频成功"}];
        } else  {
            return [[SRApi shareInstance] successWithObjectName:@"AGScreenRecorderShareCancel"
                                                       userInfo:@{@"message":@"移除视频成功"}];
        }
    };
}
@end
