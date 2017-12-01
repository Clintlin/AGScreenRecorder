//
//  RSCamaraPanel.m
//  AYMovePanel
//
//  Created by HeXingang on 2017/9/11.
//  Copyright © 2017年 zhangxinming. All rights reserved.
//

#import "SRCamaraPanel.h"
#import "SRCommonMacros.h"

#import <Masonry/Masonry.h>
#import <AVFoundation/AVFoundation.h>
#import <itmSDK/itmSDK.h>

@interface SRCamaraPanel()<AVCaptureVideoDataOutputSampleBufferDelegate>
{
    CGPoint     _preivousCenter;
    CGSize      _absoluteSize;
}

@property (strong,nonatomic) UIImageView*                   imageView;

@property (strong,nonatomic) AVCaptureSession *             captureSession;//负责输入和输出设置之间的数据传递
@property (strong,nonatomic) AVCaptureVideoDataOutput *     videoOutput;
@property (strong,nonatomic) AVCaptureVideoPreviewLayer *   captureVideoPreviewLayer;//相机拍摄预览图层

@property (strong,nonatomic) AVCaptureDeviceInput*          frontCameraInput;
@property (strong,nonatomic) AVCaptureDeviceInput*          backCameraInput;

@property (strong, nonatomic) UIButton * leftTopButton;
@property (strong, nonatomic) UIButton * rightTopButton;
@property (strong, nonatomic) UIButton * leftBottomButton;
@property (strong, nonatomic) UIButton * rightBottomButton;

@property (strong, nonatomic) itmTimer*     menuDisplayTimer;
@property (assign, nonatomic) BOOL          isShowingMenu;
@property (assign, nonatomic) BOOL          isFront;

@end

#define kRSCamaraPanelMaxSize MIN([UIScreen mainScreen].bounds.size.height, [UIScreen mainScreen].bounds.size.width) * 0.6
#define kRSCamaraPanelDefaultSize  CGSizeMake(80, 80)

CGFloat kSRCamaraPanelButtonWidth;


@implementation SRCamaraPanel



+ (instancetype)sharedCamera {
    
    static SRCamaraPanel * camera = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        camera = [SRCamaraPanel new];
        kSRCamaraPanelButtonWidth = itmConverToPtFromPx(54.f);

    });
    
    return camera;
}


+ (instancetype)showInView:(UIView *)view
{
    SRCamaraPanel* panel = [SRCamaraPanel sharedCamera];
    [view addSubview:panel];
    [panel setupSubviews];
    
    return panel;
}

- (instancetype)init
{
    if(self = [super init]){
        [self setFrame:CGRectMake(50, 100, kRSCamaraPanelDefaultSize.width, kRSCamaraPanelDefaultSize.height)];
        self.clipsToBounds = YES;
        self.layer.cornerRadius = 3.f;
    
        UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc]
                                       initWithTarget:self action:@selector(tapAction:)];
        [self addGestureRecognizer:tap];
        
        _isFront = YES;
        
    }
    return self;
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
}

- (void)setupSubviews
{
    [super setupSubviews];
    
    if(!_imageView){
        _imageView = [[UIImageView alloc] initWithFrame:self.bounds];
        [_imageView setBackgroundColor:[UIColor clearColor]];
        _imageView.clipsToBounds = YES;
        _imageView.userInteractionEnabled = NO;
        [self addSubview:_imageView];
    }
    
    {
        
        CGFloat buttonWidth = kSRCamaraPanelButtonWidth;
        self.leftTopButton = [UIButton new];
        [self.leftTopButton setBackgroundColor:[UIColor clearColor]];
        [self addSubview:self.leftTopButton];
        [self.leftTopButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.top.equalTo(_imageView);
            make.width.height.mas_equalTo(buttonWidth);
        }];
        
//        UIImage * closeIcon = [UIImage PDFNamed:@"sr_camara_close"
//                                            size:CGSizeMake(kSRCamaraPanelButtonWidth,
//                                                            kSRCamaraPanelButtonWidth)
//                                          bundle:SR_BUNDLE_IDENTIFIER];
        
//        [self.leftTopButton setImage:closeIcon forState:UIControlStateNormal];
        
//        [self.leftTopButton addTarget:self action:@selector(closeCamara) forControlEvents:UIControlEventTouchUpInside];
        
        self.rightTopButton = [UIButton new];
        [self.rightTopButton setBackgroundColor:[UIColor clearColor]];
        [self addSubview:self.rightTopButton];
        [self.rightTopButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.right.top.equalTo(_imageView);
            make.width.height.mas_equalTo(buttonWidth);
        }];
        UIImage * pIcon = [UIImage PDFNamed:@"sr_camara_position"
                                            size:CGSizeMake(kSRCamaraPanelButtonWidth,
                                                            kSRCamaraPanelButtonWidth)
                                          bundle:SR_BUNDLE_IDENTIFIER];
        
        [self.rightTopButton setImage:pIcon forState:UIControlStateNormal];
        
        [self.rightTopButton addTarget:self action:@selector(switchCamara) forControlEvents:UIControlEventTouchUpInside];
        
        self.leftBottomButton = [UIButton new];
        [self.leftBottomButton setBackgroundColor:[UIColor clearColor]];
        [self addSubview:self.leftBottomButton];
        [self.leftBottomButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.bottom.equalTo(_imageView);
            make.width.height.mas_equalTo(buttonWidth);
        }];
        _leftBottomButton.hidden = YES;
        
        // 拖动改变size - 按钮
        self.rightBottomButton = [UIButton new];
        [self.rightBottomButton setBackgroundColor:[UIColor clearColor]];
        [self addSubview:self.rightBottomButton];
        [self.rightBottomButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.right.bottom.equalTo(_imageView);
            make.width.height.mas_equalTo(buttonWidth);
        }];
//        UIImage * sizingIcon = [UIImage PDFNamed:@"sr_camara_resizing"
//                                            size:CGSizeMake(kSRCamaraPanelButtonWidth,
//                                                            kSRCamaraPanelButtonWidth)
//                                          bundle:SR_BUNDLE_IDENTIFIER];
        
//        [self.rightBottomButton setImage:sizingIcon forState:UIControlStateNormal];
//        UIPanGestureRecognizer * pan = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(sizingPlaneOnPan:)];
//        [self.rightBottomButton addGestureRecognizer:pan];
    }
}

- (void)startCAP
{
    if(_captureSession )
    {
        [_captureSession stopRunning];
        _captureSession =nil;
    }
    
    _captureSession=[[AVCaptureSession alloc]init];
    if ([_captureSession canSetSessionPreset:AVCaptureSessionPreset352x288]) {//设置分辨率
        _captureSession.sessionPreset=AVCaptureSessionPreset352x288;
    }
    //获得输入设备
    AVCaptureDevice *captureDevice=[self getCameraDeviceWithPosition:AVCaptureDevicePositionFront];//取得后置摄像头
    if (!captureDevice) {
        NSLog(@"取得后置摄像头时出现问题.");
        return;
    }
    NSError *error = nil;
    self.frontCameraInput = [AVCaptureDeviceInput deviceInputWithDevice:captureDevice error:&error];
    if (!_frontCameraInput)
    {
        NSLog(@"Failed to get video input");
        
        return;
    }
    [ _captureSession addInput: _isFront ? self.frontCameraInput : self.backCameraInput];
    
    [  _captureSession beginConfiguration];
    [ captureDevice lockForConfiguration:&error];
    
    
    [captureDevice setActiveVideoMinFrameDuration:CMTimeMake(1, 12)];
    [captureDevice setActiveVideoMaxFrameDuration:CMTimeMake(1, 15)];
    
    [captureDevice unlockForConfiguration];
    [ _captureSession commitConfiguration];
    
    
    _videoOutput =  [[AVCaptureVideoDataOutput alloc] init]  ;
    _videoOutput.videoSettings = [[NSDictionary alloc] initWithObjectsAndKeys:
                                  [NSNumber numberWithUnsignedInt:kCVPixelFormatType_32BGRA], kCVPixelBufferPixelFormatTypeKey,nil];
    
    _videoOutput.alwaysDiscardsLateVideoFrames = YES;
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(reOrientation)
                                                 name:UIDeviceOrientationDidChangeNotification
                                               object:nil];
    
    dispatch_queue_t queue = dispatch_queue_create("video.move.capture.queue", NULL);
    
    [_videoOutput setSampleBufferDelegate: self queue: queue];
    [_captureSession addOutput:_videoOutput];
    
    
    
    if(![_captureSession isRunning]){
        [_captureSession startRunning];
    }
    
    [self reOrientation];
    [self resetMenuDisplayTimer];
}

- (void)stopCAP
{
    if(_captureSession && [_captureSession isRunning]){
        [_captureSession stopRunning];
    }
}

- (void)destroy {
    [self stopCAP];
    [self removeFromSuperview];
}

-(AVCaptureDevice *)getCameraDeviceWithPosition:(AVCaptureDevicePosition )position{
    NSArray *cameras= [AVCaptureDevice devicesWithMediaType:AVMediaTypeVideo];
    for (AVCaptureDevice *camera in cameras) {
        if ([camera position]==position) {
            return camera;
        }
    }
    return nil;
}

- (void)reOrientation
{
    
    NSLog(@"reOrientation ---- ");
    AVCaptureConnection *videoConnection = [_videoOutput connectionWithMediaType:AVMediaTypeVideo];
    // SET THE ORIENTATION HERE -------------------------------------------------
    
    
    UIInterfaceOrientation  tion=  [[UIApplication sharedApplication] statusBarOrientation];
    
    if (tion == UIInterfaceOrientationLandscapeLeft )
    {
        
        [videoConnection setVideoOrientation:AVCaptureVideoOrientationLandscapeLeft];
    }
    else if (tion == UIInterfaceOrientationLandscapeRight )
    {
        [videoConnection setVideoOrientation:AVCaptureVideoOrientationLandscapeRight];
        
    }
    else
    {
        [videoConnection setVideoOrientation:AVCaptureVideoOrientationPortrait];
    }
}


//后置摄像头输入
- (AVCaptureDeviceInput *)backCameraInput {
    if (_backCameraInput ==nil) {
        NSError *error;
        _backCameraInput = [[AVCaptureDeviceInput alloc] initWithDevice:[self getCameraDeviceWithPosition:AVCaptureDevicePositionBack]
                                                                  error:&error];
        if (error) {
            NSLog(@"获取后置摄像头失败~");
        }
    }
    return _backCameraInput;
}

//前置摄像头输入
- (AVCaptureDeviceInput *)frontCameraInput {
    if (_frontCameraInput ==nil) {
        NSError *error;
        _frontCameraInput = [[AVCaptureDeviceInput alloc] initWithDevice:[self getCameraDeviceWithPosition:AVCaptureDevicePositionFront]
                                                                   error:&error];
        if (error) {
            NSLog(@"获取前置摄像头失败~");
        }
    }
    return _frontCameraInput;
}

#pragma mark - - Others

- (void)closeCamara
{
    [self showCamara:NO];
}

- (void)switchCamara
{
    [self.captureSession beginConfiguration];
    
    if (!_isFront) {
        [self.captureSession removeInput:self.backCameraInput];
        if ([self.captureSession canAddInput:self.frontCameraInput]) {
            //[self changeCameraAnimation];
            [self.captureSession addInput:self.frontCameraInput];
        }
        _isFront = YES;
        
    }else {
        [self.captureSession removeInput:self.frontCameraInput];
        if ([self.captureSession canAddInput:self.backCameraInput]) {
            //[self changeCameraAnimation];
            [self.captureSession addInput:self.backCameraInput];
        }
        _isFront = NO;
    }
    [self.captureSession commitConfiguration];
}

- (void)showCamara:(BOOL)show
{
    self.hidden = !show;
}

- (void)hideButtons:(BOOL)hidden
{
    _leftTopButton.hidden = hidden;
    //_leftBottomButton.hidden = hidden;
    _rightTopButton.hidden = hidden;
    _rightBottomButton.hidden = hidden;
}

#pragma mark - - Timer

- (void)stopMenuDisplayTimer {
    if(self.menuDisplayTimer){
        [self.menuDisplayTimer invalidate];
        self.menuDisplayTimer = nil;
    }
}

- (void)resetMenuDisplayTimer {
    
    [self stopMenuDisplayTimer];
    
    self.menuDisplayTimer = [[itmTimer alloc] initWithInterval:3.f
                                                        target:self
                                                      selector:@selector(handleMenuDisplayTimer:)
                                                        repeat:NO];
    self.menuDisplayTimer.startTime = [[NSDate date] timeIntervalSince1970];
}

- (void) handleMenuDisplayTimer: (itmTimer *)timer {
    if(timer.startTime != _menuDisplayTimer.startTime){
        return;
    }
    
    [self hideButtons:YES];
}

#pragma mark - -


#pragma mark - 摄像头采集回调
- (UIImage *) imageFromSampleBuffer:(CMSampleBufferRef) sampleBuffer
{
    // Get a CMSampleBuffer's Core Video image buffer for the media data
    CVImageBufferRef imageBuffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    // Lock the base address of the pixel buffer
    CVPixelBufferLockBaseAddress(imageBuffer, 0);
    
    // Get the number of bytes per row for the pixel buffer
    void *baseAddress = CVPixelBufferGetBaseAddress(imageBuffer);
    
    // Get the number of bytes per row for the pixel buffer
    size_t bytesPerRow = CVPixelBufferGetBytesPerRow(imageBuffer);
    // Get the pixel buffer width and height
    size_t width = CVPixelBufferGetWidth(imageBuffer);
    size_t height = CVPixelBufferGetHeight(imageBuffer);
    
    // Create a device-dependent RGB color space
    CGColorSpaceRef colorSpace = CGColorSpaceCreateDeviceRGB();
    
    // Create a bitmap graphics context with the sample buffer data
    CGContextRef context = CGBitmapContextCreate(baseAddress, width, height, 8,
                                                 bytesPerRow, colorSpace, kCGBitmapByteOrder32Little | kCGImageAlphaPremultipliedFirst);
    // Create a Quartz image from the pixel data in the bitmap graphics context
    CGImageRef quartzImage = CGBitmapContextCreateImage(context);
    // Unlock the pixel buffer
    CVPixelBufferUnlockBaseAddress(imageBuffer,0);
    
    // Free up the context and color space
    CGContextRelease(context);
    CGColorSpaceRelease(colorSpace);
    
    // Create an image object from the Quartz image
    UIImage *image = [UIImage imageWithCGImage:quartzImage];
//        UIImage *image =nil;
    
//    UIInterfaceOrientation  tion=  [[UIApplication sharedApplication] statusBarOrientation];
//
//    if (!_isFront) {
//        if (tion == UIInterfaceOrientationLandscapeLeft )
//        {
//            image = [UIImage imageWithCGImage:quartzImage scale:1.0f orientation:UIImageOrientationLeft];
//        }
//        else if (tion == UIInterfaceOrientationLandscapeRight )
//        {
//            image = [UIImage imageWithCGImage:quartzImage scale:1.0f orientation:UIImageOrientationUp];
//        }
//        else
//        {
//            image = [UIImage imageWithCGImage:quartzImage scale:1.0f orientation:UIImageOrientationRight];
//        }
//    }else{
//        if (tion == UIInterfaceOrientationLandscapeLeft )
//        {
            image = [UIImage imageWithCGImage:quartzImage scale:1.0f orientation:UIImageOrientationUp];
//        }
//        else if (tion == UIInterfaceOrientationLandscapeRight )
//        {
//            image = [UIImage imageWithCGImage:quartzImage scale:1.0f orientation:UIImageOrientationRight];
//        }
//        else
//        {
//            image = [UIImage imageWithCGImage:quartzImage scale:1.0f orientation:UIImageOrientationUpMirrored];
//        }
//    }
    
    
    
    
    
    // Release the Quartz image
    CGImageRelease(quartzImage);
    
    return image;
    
}
-(void)captureOutput:(AVCaptureOutput *)captureOutput didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection
{
    @autoreleasepool {
//        @synchronized(self) {
            dispatch_sync(dispatch_get_main_queue(), ^{
                [self.imageView setImage:[self imageFromSampleBuffer:sampleBuffer]];
            });
//        }
    }
}

#pragma mark - - 手势

- (void)tapAction:(UITapGestureRecognizer*)gestureRecognizer
{
    [self hideButtons:NO];
    [self resetMenuDisplayTimer];
}

- (void)sizingPlaneOnPan:(UIPanGestureRecognizer *)pan{
    
    CGPoint pt = [pan locationInView:self];

    CGSize size = CGSizeMake(MAX(80, pt.x), MAX(80, pt.y));
    
    if (pan.state == UIGestureRecognizerStateChanged) {
        [self setSize:size animation:NO];
    }
}

- (CGSize)setSize:(CGSize)newSize animation:(BOOL)yesOrNo{
    
    newSize = [self convertSizeToFit:newSize];
    
    if (!yesOrNo) {
        [self updateAndDisplay:newSize];
        return newSize;
    }
    
    [UIView animateWithDuration:itm_kAnimationDefaultDruation animations:^{
        [self updateAndDisplay:newSize];
    } ];
    return newSize;
}

- (CGSize)convertSizeToFit:(CGSize)size{
    
    // 等比缩放
    CGSize convertedDefaultSize = [self sizeToFitOrientaion:kRSCamaraPanelDefaultSize];
    CGSize convertedNewSize = [self sizeToFitOrientaion:size];
    CGFloat ratio = convertedDefaultSize.height/convertedDefaultSize.width;

    
    // 如果宽的差值大于高，就用宽来做等比缩放
    convertedNewSize.height = convertedNewSize.width * ratio;
    
    // 如果求出来的高大于屏幕最小边界将返回最小边界 (横屏)
    if (convertedNewSize.width > kRSCamaraPanelMaxSize) {
        convertedNewSize.width = kRSCamaraPanelMaxSize;
        convertedNewSize.height = convertedNewSize.width * ratio;
    }
    
    return convertedNewSize;
}

- (void)updateAndDisplay:(CGSize)newSize{

    _absoluteSize = newSize;
    self.size = newSize;
    self.imageView.size = newSize;
}

- (CGSize)sizeToFitOrientaion:(CGSize)size{
    
    CGFloat minSizeValue = MIN(size.width, size.height);
    CGFloat maxSizeValue = MAX(size.width, size.height);
    
    UIInterfaceOrientation Orientation = [[UIApplication sharedApplication] statusBarOrientation];
    if ((Orientation == UIInterfaceOrientationLandscapeLeft || Orientation == UIInterfaceOrientationLandscapeRight))
    {
        size.width = maxSizeValue;
        size.height = minSizeValue;
    }else{
        size.width = minSizeValue;
        size.height = maxSizeValue;
    }
    
    return size;
}


#pragma mark - - 

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = touches.anyObject;
    CGPoint currentPoint = [touch locationInView:self.superview];
    
    _preivousCenter = currentPoint;
}

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = touches.anyObject;
    CGPoint currentPoint = [touch locationInView:self.superview];
    
    CGPoint center = self.center;
    center.x += (currentPoint.x - _preivousCenter.x);
    center.y += (currentPoint.y - _preivousCenter.y);
    
    // 修改当前view的中点(中点改变view的位置就会改变)
    self.center = center;
    _preivousCenter = currentPoint;
}

- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    CGPoint origin = self.frame.origin;
    
    if( origin.x < 0 ){
        origin.x = 0;
    }
    else if( origin.x > (kScreenWidth - self.width) ){
        origin.x = (kScreenWidth - self.width);
    }
    
    if(origin.y < 0){
        origin.y = 0;
    }
    else if(origin.y > (kScreenHeight - self.height) ){
        origin.y = (kScreenHeight - self.height);
    }
    
    WEAKSELF(weakSelf);
    
    [UIView animateWithDuration:0.2 animations:^{
        [weakSelf setFrame:CGRectMake(origin.x, origin.y, weakSelf.width, weakSelf.height)];
    }];
}


@end
