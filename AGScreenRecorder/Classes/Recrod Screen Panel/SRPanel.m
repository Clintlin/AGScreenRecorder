//
//  RecordScreenPanel.m
//  AYMovePanel
//
//  Created by HeXingang on 2017/9/4.
//  Copyright © 2017年 zhangxinming. All rights reserved.
//

#import "SRPanel.h"
#import "SRCommonMacros.h"
#import "SRApi.h"
#import "SRCamaraPanel.h"

#import <itmSDK/itmSDK.h>
#import <AVFoundation/AVFoundation.h>
#import <ReplayKit/ReplayKit.h>
//#import <MediaLibrary/MediaLibrary.h>

@interface SRPanel()<AVCaptureVideoDataOutputSampleBufferDelegate, RPScreenRecorderDelegate,RPPreviewViewControllerDelegate>
{
    itmTimer*       _recordTimer;
    itmTimer*       _showTimer;
    itmTimer*       _respiratoryTimer;
    
    UIControl*      _background;
    CGSize          originalSize;
    BOOL            _hasSaved;
}

@property (nonatomic, strong) SRCamaraPanel* camaraPanel;

@property (nonatomic, strong) UIView*       colorBgView;
@property (nonatomic, strong) UIView*       redDot;

@property (nonatomic, strong) UILabel*  timeLabel;
//@property (nonatomic, strong) AYBrushView* brushView;

@end

CGFloat kScreenRecorderPanelWidth;
CGFloat kScreenRecorderPanelBorderWidth;
CGFloat kScreenRecorderPanelGap;
CGFloat kScreenRecorderPanelRedDotWidth;
CGFloat kScreenRecorderPanelRedDotGap;
CGFloat kScreenRecorderPanelItemWidth;

@interface SRPanel ()
- (void)didStopRecordingWithUserInfo:(NSDictionary *)userInfo error:(NSError *)error;
@end

//int videoCallback(const char *retMsg ,id object){
//
//    if (![object isKindOfClass:[SRPanel class]]) {
//        return 0;
//    }
//
//    __typeof(SRPanel *) weakSelf = (SRPanel *)object;
//
//    // 解析json数据
//    NSString *strretmssage = [NSString stringWithCString:retMsg encoding:NSUTF8StringEncoding];
//
//    // 解析json数据 to NSDictionary
//    NSDictionary * o = (NSDictionary *)[NSString converObjectFrom:strretmssage];
//
//    // 根据callBackFun分析
//    NSString * functionType = [o objectForKey:@"callBackFun"];
//
//    // 解析retMsg
//    NSDictionary * dict = [o objectForKey:@"retMsg"];
//
//
//    // 使用weakSelf做点什么
//    NSLog(@"functionType is aaa %@ -- %@",functionType,dict);
//
//    if ([functionType isEqualToString:@"StopRecScreenVideo"]) {
//
//        NSString * pathStr = [dict objectForKey:@"path"];
//        NSURL * path = [NSURL fileURLWithPath:pathStr];
//        [weakSelf didStopRecording:@"录制完成" videoURL:path];
//    }
//    return 0;
//}



@implementation SRPanel

+ (instancetype)showInView:(UIView *)view
{
    SRPanel* panel = [SRPanel new];
    [panel setHidden:YES];
    [view addSubview:panel];
    [panel setupSubviews];
    
    return panel;
}

- (instancetype)init
{
    if(self = [super init]){
        
        kScreenRecorderPanelWidth = itmConverToPtFromPx(92.f);
        kScreenRecorderPanelBorderWidth = itmConverToPtFromPx(5.f);
        kScreenRecorderPanelGap = itmConverToPtFromPx(40.f);
        kScreenRecorderPanelRedDotWidth = itmConverToPtFromPx(28.f);
        kScreenRecorderPanelRedDotGap = itmConverToPtFromPx(13.f);
        
        kScreenRecorderPanelItemWidth = itmConverToPtFromPx(92.f);
        
        
        [self setFrame:CGRectMake(kScreenWidth - kScreenRecorderPanelWidth - kScreenRecorderPanelGap,
                                  kScreenHeight - kScreenRecorderPanelWidth - kScreenRecorderPanelGap,
                                  kScreenRecorderPanelWidth,
                                  kScreenRecorderPanelWidth)];
        
        self.backgroundColor = [[itmColor colorWithHexString:@"ff5001" alpha:0.5] UIColor];
        self.layer.cornerRadius = kScreenRecorderPanelWidth/2.f;
        self.position = SRPanelPositionRightBottom;
        
        
        UITapGestureRecognizer * tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tap)];
        [self setUserInteractionEnabled:YES];
        [self addGestureRecognizer:tap];
        
        UITapGestureRecognizer * doubleTap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(doubleTapAction)];
        [doubleTap setNumberOfTapsRequired:2];
        [self addGestureRecognizer:doubleTap];
        
        [tap requireGestureRecognizerToFail:doubleTap];
        
        originalSize = self.size;
        
//        itmButton* btn1 = [self menuButtonWithImage:[UIImage PDFNamed:@"screen_record_brush"
//                                                                  size:CGSizeMake(kScreenRecorderPanelItemWidth, kScreenRecorderPanelItemWidth)
//                                                                bundle:SR_BUNDLE_IDENTIFIER]
//                                               size:kScreenRecorderPanelItemWidth];
        
        itmButton* btn2 = [self menuButtonWithImage:[UIImage PDFNamed:@"screen_record_camara"
                                                                  size:CGSizeMake(kScreenRecorderPanelItemWidth, kScreenRecorderPanelItemWidth)
                                                                bundle:SR_BUNDLE_IDENTIFIER]
                                               size:kScreenRecorderPanelItemWidth];
        
        itmButton* btn3 = [self menuButtonWithImage:[UIImage PDFNamed:@"screen_record_stop"
                                                                  size:CGSizeMake(kScreenRecorderPanelItemWidth, kScreenRecorderPanelItemWidth)
                                                                bundle:SR_BUNDLE_IDENTIFIER]
                                               size:kScreenRecorderPanelItemWidth];
        
//        self.mainMenuItems = @[btn1, btn2, btn3,];
        self.mainMenuItems = @[btn2, btn3,];
//        self.subItems = @[
//                          @"画笔",
//                          @"摄像头",
//                          @"停止"
//                          ];
        
        self.subItems = @[
                          @"摄像头",
                          @"停止"
                          ];
        
        self->_background = [[UIControl alloc] init];
        [self->_background addTarget:self action:@selector(hideMenu) forControlEvents:UIControlEventTouchUpInside];
        self.itemGap = itmConverToPtFromPx(20.f);
        
//        initVideoCallback(videoCallback,self);
//        [[RPScreenRecorder sharedRecorder] prepareForInterfaceBuilder];;
    }

    return self;
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    
    if(_background){
        [_background removeFromSuperview];
        _background = nil;
    }
    
//    if(self.brushView){
//        [self.brushView removeFromSuperview];
//        self.brushView = nil;
//    }
    
    if(_camaraPanel){
        [_camaraPanel destroy];
        _camaraPanel = nil;
    }
}

- (void)setupSubviews
{
    [super setupSubviews];
    
    if(!_colorBgView){
        _colorBgView = [[UIView alloc] initWithFrame:CGRectMake(kScreenRecorderPanelBorderWidth,
                                                                kScreenRecorderPanelBorderWidth,
                                                                self.width - kScreenRecorderPanelBorderWidth*2,
                                                                self.height - kScreenRecorderPanelBorderWidth*2)];
        [_colorBgView setBackgroundColor:[[itmColor colorWithHexString:@"ff5001" alpha:0.5] UIColor]];
        [_colorBgView setUserInteractionEnabled:NO];
        _colorBgView.layer.cornerRadius = _colorBgView.frame.size.width/2.f;
        [self addSubview:_colorBgView];
        _colorBgView.hidden = YES;
    }
    
    if(!_timeLabel){
        _timeLabel = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, kScreenRecorderPanelWidth, kScreenRecorderPanelWidth)];
        [_timeLabel setBackgroundColor:[UIColor clearColor]];
        [_timeLabel setTextColor:[UIColor whiteColor]];
        [_timeLabel setFont:[UIFont systemFontOfSize:10]];
        [_timeLabel setTextAlignment:NSTextAlignmentCenter];
        [self addSubview:_timeLabel];
        _timeLabel.hidden = YES;
    }
    
    if(!_redDot){
        _redDot = [[UIView alloc] initWithFrame:CGRectMake(kScreenRecorderPanelRedDotGap,
                                                           (self.height - kScreenRecorderPanelRedDotWidth)/2.f,
                                                           kScreenRecorderPanelRedDotWidth,
                                                           kScreenRecorderPanelRedDotWidth)];
        [_redDot setBackgroundColor:[UIColor redColor]];
        _redDot.layer.cornerRadius = _redDot.frame.size.width/2.f;
        [self addSubview:_redDot];
        _redDot.hidden = YES;
    }
}

- (SRCamaraPanel *)camaraPanel {
    if(!_camaraPanel){
        _camaraPanel = [SRCamaraPanel showInView:self.superview];
    }
    
    return _camaraPanel;
}

//- (AYBrushView*)brushView
//{
//    //画笔
//    if(_brushView == nil && self.superview != nil){
//
//        _brushView = [AYBrushView showInView:self.superview];
//        [self.superview bringSubviewToFront:self];
//        [_brushView hide:NO];
//    }
//
//    return _brushView;
//}


- (void)showMenu{
    [super showMenu];
    [self stopShowTimer];
    
    if (_background.superview == nil) {
        [self.superview addSubview:_background];
        
        [self generateMainMenu:^(NSArray *items) {
            // 添加 items - 第一个永远在最下面
            for (int i = 0; i < items.count; i++) {
                
                itmButton * menuItem = (itmButton *)self.mainMenuItems[i];
                [_background addSubview:menuItem];
                
                [menuItem setTitle:self.subItems[i] forState:UIControlStateNormal];
                menuItem.alpha = 0.f;
                menuItem.tag = i;
                [menuItem addTarget:self action:@selector(buttonOnClicked:) forControlEvents:UIControlEventTouchUpInside];
                
                [self repostionMainMenuItem:menuItem atIndex:i];
            }
        }];
    }
    
    [_background setFrame:self.superview.bounds];
    [_background setHidden:NO];
    [self.superview bringSubviewToFront:_background];
    [self.superview bringSubviewToFront:self];
    
    for (int i = 0; i<self. mainMenuItems.count; i++) {
        [self animateMenuItem:self. mainMenuItems[i] atIndex:i show:YES];
    }
}

- (void)hideMenu{
    
    [super hideMenu];
    
    [self startShowTimer];
    
    BOOL isOnBottom = self.position == SRPanelPositionLeftBottom
    || self.position == SRPanelPositionRightBottom;
    
    if (isOnBottom)
    {
        self.y = CGRectGetMaxY(self.frame) - originalSize.height;
    }
    
    self.size = originalSize;
    
    [self callFunctions:^{
         [_background setHidden:YES];
    } afterDelay:self.menuAnimationDuration];
}

- (void)repostionMainMenuItem:(itmButton *)item atIndex:(NSInteger)index{
    BOOL isOnLeft = self.position == SRPanelPositionLeftTop || self.position == SRPanelPositionLeftBottom;
    //{top, left, bottom, right};
    // 第一个图标有4个字
    if (!isOnLeft) {
        item.titleMode = itmButtonTitleModeLeft;
    }else{
        item.titleMode = itmButtonTitleModeRight;
    }
    
    [super repostionMainMenuItem:item atIndex:index];
    
}

- (void)tap{
    
    [self startShowTimer];
    
    if (self.isShowing) {
        return [self hideMenu];
    }
    
    [self showMenu];
    
    self.timeLabel.hidden = NO;
    self.redDot.hidden = YES;
    self.alpha = 1.f;
    [self stopRespiratoryTimer];
}


- (void)doubleTapAction
{
    [self stopRecord];
}



- (void)setHidden:(BOOL)hidden{
    dispatch_async(dispatch_get_main_queue(), ^{
        
        [super setHidden:hidden];
        [self.camaraPanel setHidden:hidden];
        [_colorBgView setHidden:hidden];
        [_redDot setHidden:hidden];
        [_timeLabel setHidden:hidden];
    });
    
    
    [self setLocalVideoMuted:hidden];
}


#pragma mark - - Timer

- (void)timerEvent:(itmTimer*)timer
{
    @autoreleasepool {
        NSTimeInterval now = [[NSDate date] timeIntervalSince1970];
        NSTimeInterval interval = now - _recordTimer.startTime;
        
        NSDate* date = [NSDate dateWithTimeIntervalSince1970:interval];
        
        NSDateFormatter* format = [[NSDateFormatter alloc] init];
        [format setDateFormat:@"mm:ss"];
        NSString *dateString = [format stringFromDate:date];
        
        [_timeLabel setText:dateString];
    }
}

- (void)startShowTimer
{
    if(_showTimer){
        [self stopShowTimer];
    }
    
    _showTimer = [[itmTimer alloc] initWithInterval:2.f target:self selector:@selector(showTimerEvent:) repeat:NO];
    _showTimer.startTime = [[NSDate date] timeIntervalSince1970];
}

- (void)stopShowTimer
{
    if(_showTimer){
        [_showTimer invalidate];
        _showTimer = nil;
    }
}

- (void)showTimerEvent:(itmTimer*)timer
{
    if(_showTimer == nil)
        return;
    
    if(timer.startTime != _showTimer.startTime)
        return;
    
    CGFloat offSetX = self.x;
    
    switch (self.position) {
        case SRPanelPositionLeftTop:
        case SRPanelPositionLeftBottom:
            offSetX = - self.width/2.f;
            break;
            
        case SRPanelPositionRightTop:
        case SRPanelPositionRightBottom:
            offSetX = kScreenWidth - self.width/2.f;
            break;
            
        default:
            NSLog(@"########  unknown  ########");
            break;
    }
    
    WEAKSELF(weakSelf);
    
    [UIView animateWithDuration:0.3f animations:^{
        weakSelf.x = offSetX;
        weakSelf.timeLabel.hidden = YES;
        weakSelf.redDot.hidden = NO;
        weakSelf.alpha = 0.5f;
    }];
    self.redDot.alpha = 1.f;
    [self startRespiratoryTimer];
}

- (void)startRespiratoryTimer
{
    if(_respiratoryTimer){
        [self stopRespiratoryTimer];
    }
    
    _respiratoryTimer = [[itmTimer alloc] initWithInterval:2.f target:self selector:@selector(respiratoryEvent:) repeat:YES];
    _respiratoryTimer.startTime = [[NSDate date] timeIntervalSince1970];
}

- (void)stopRespiratoryTimer
{
    if(_respiratoryTimer){
        [_respiratoryTimer invalidate];
        _respiratoryTimer = nil;
    }
}

- (void)respiratoryEvent:(itmTimer*)timer
{
    if(!_respiratoryTimer)
        return;
    
    if(timer.startTime != _respiratoryTimer.startTime)
        return;
    
    WEAKSELF(weakSelf);
    
    [UIView animateWithDuration:2.f animations:^{
        if(weakSelf.redDot.alpha == 1.f){
            weakSelf.redDot.alpha = 0.1f;
        }
        else{
            weakSelf.redDot.alpha = 1.f;
        }
    }];
}

#pragma mark - 主悬浮球 事件
- (void)buttonOnClicked:(itmButton *)sender {
    
    [self hideMenu];
    
    switch (sender.tag) {
//        case 0:
////            [self showBrushView];
//            break;
        case 0:
            [_camaraPanel showCamara:_camaraPanel.hidden];
            break;
        case 1:
            [self stopRecord];
            break;
    }
    
//    if(sender){
//        if(_delegate != nil && [_delegate respondsToSelector:@selector(liveTouchPanelMenuSelected:)]){
//            [_delegate liveTouchPanelMenuSelected:sender.tag];
//        }
//    }
}


#pragma mark - 录屏回调
// iOS 9-10
- (void)screenRecorder:(RPScreenRecorder *)screenRecorder didStopRecordingWithError:(NSError *)error previewViewController:( RPPreviewViewController *)previewViewController{
//    if (error) {
//        return [self recorderOnError:error];
//    }
}
// iOS 11
- (void)screenRecorder:(RPScreenRecorder *)screenRecorder didStopRecordingWithPreviewViewController:( RPPreviewViewController *)previewViewController error:( NSError *)error{
//    if (error) {
//        return [self recorderOnError:error];
//    }
}



#pragma mark - 录屏事件
- (void)recorderOnError:(NSError *)error{
    NSLog(@"RPScreenRecorder stop%@", error);
    //处理发生的错误，如磁盘空间不足而停止等 previewViewController.movie
    dispatch_async(dispatch_get_main_queue(), ^{
        [ _camaraPanel stopCAP];
        [ self removeFromSuperview];
        
    });
    
    [self didStopRecordingWithUserInfo:nil error:error];
}

- (void)startRecord
{
    
    [_timeLabel setText:@"00:00"];
    _timeLabel.hidden = NO;
    _redDot.hidden = YES;
    
    
    void (^startRecordingHandler)(NSError *) = ^(NSError * _Nullable error) {
        NSLog(@"startRecording error :%@",error);
        if (error) {
            [self recorderOnError:error];
        }else{
            [self startRecording:@"开始录屏"];
        }
    };
    
    
    if(itm_iOS10Later){
        if (![RPScreenRecorder sharedRecorder].available) {
            return NSLog(@"[RPScreenRecorder sharedRecorder].available == false");
        }
        
        if ([RPScreenRecorder sharedRecorder].recording) {
            [self cancelRecording];
        }
        
        [[RPScreenRecorder sharedRecorder] startRecordingWithHandler:startRecordingHandler];
    }else if(itm_iOS9Later){
        [[RPScreenRecorder sharedRecorder] startRecordingWithMicrophoneEnabled:YES handler:startRecordingHandler];
    } else{
//        MediaStartRecordScreenVideo();
    }
    
    _recordTimer = [[itmTimer alloc] initWithInterval:0.5f target:self selector:@selector(timerEvent:) repeat:YES];
    _recordTimer.startTime = [[NSDate date] timeIntervalSince1970];
    
    [self startShowTimer];
}

- (void)stopRecord
{
    if(itm_iOS9Later){
        
        [[RPScreenRecorder sharedRecorder] stopRecordingWithHandler:^(RPPreviewViewController * previewViewController, NSError * error){
            if (error) {
                return [self recorderOnError:error];
            }
            
            ////////////////////////////////////////////////////////////////////
            AVAudioSession* session = [AVAudioSession sharedInstance];
            [session setCategory:AVAudioSessionCategoryPlayback withOptions:AVAudioSessionCategoryOptionInterruptSpokenAudioAndMixWithOthers error:&error];
            [self showVideoPreviewController:previewViewController withAnimation:YES];
        }];
    }
    else
    {
//        MediaStopRecordScreenVideo();
//        [ self removeFromSuperview];
    }
    
    [self stopShowTimer];
    [self stopRespiratoryTimer];
    [_camaraPanel stopCAP];
    
    if(_recordTimer){
        [_recordTimer invalidate];
        _recordTimer = nil;
    }
}


- (void) cancelRecording {
    
    if(itm_iOS9Later){
        if ([RPScreenRecorder sharedRecorder].recording) {
            void (^stopHandler)(RPPreviewViewController *,NSError *) = ^(RPPreviewViewController * previewViewController, NSError * error){
                [[RPScreenRecorder sharedRecorder] discardRecordingWithHandler:^{
                    if (self.cancelRecordingBlock) {
                        self.cancelRecordingBlock(@"录制已取消");
                    }
                }];
            };
            
            [[RPScreenRecorder sharedRecorder] stopRecordingWithHandler:stopHandler];
        }
    }else{
//        MediaCancelRecordScreenVideo();
    }
    
    
    
}


- (void)startRecording:(NSString *)message {
    if (self.startRecordingBlock) {
        self.startRecordingBlock(message);
    }
}


- (void)didStopRecordingWithUserInfo:(NSDictionary *)userInfo error:(NSError *)error{
    _hasSaved = NO;
    if (self.didStopRecordingBlock) {
        dispatch_async(dispatch_get_main_queue(), ^{
            self.didStopRecordingBlock(userInfo, error);
        });
    }
}

- (void)showVideoPreviewController:(RPPreviewViewController *)previewController withAnimation:(BOOL)animation {

    [self didStopRecordingWithUserInfo:@{@"message":@"录制完成"} error:nil];
    
    // 没有movieURL，所以我们得自己想办法
    previewController.previewControllerDelegate = self;
    UIViewController * rootVC = AGSR_getCurrentRootController();
    [rootVC presentViewController:previewController animated:animation completion:nil];
    
    //
//    previewController.hos
}


#pragma mark - RPPreviewViewControllerDelegate

//选择了某些功能的回调（如分享和保存）
- (void)previewController:(RPPreviewViewController *)previewController didFinishWithActivityTypes:(NSSet <NSString *> *)activityTypes {
    
    
    if ([activityTypes containsObject:@"com.apple.UIKit.activity.SaveToCameraRoll"]) {
        _hasSaved = YES;
        dispatch_async(dispatch_get_main_queue(), ^{
//            [self showAlert:@"保存成功" andMessage:@"已经保存到系统相册"];
        });
    }
//    if ([activityTypes containsObject:@"com.apple.UIKit.activity.CopyToPasteboard"]) {
//        dispatch_async(dispatch_get_main_queue(), ^{
////            [weakSelf showAlert:@"复制成功" andMessage:@"已经复制到粘贴板"];
//        });
//    }
}

- (void)previewControllerDidFinish:(RPPreviewViewController *)previewController {
    
    AVAudioSession* session = [AVAudioSession sharedInstance];
    
    [session setCategory:AVAudioSessionCategoryPlayAndRecord withOptions:AVAudioSessionCategoryOptionDefaultToSpeaker error:nil];
    
    [self hideVideoPreviewController:previewController withAnimation:YES];
}

- (void)hideVideoPreviewController:(RPPreviewViewController *)previewController withAnimation:(BOOL)animation {
    
    if (!_hasSaved) {
//        用户取消
//        if (self.videoShareBlock) {
//            self.videoShareBlock(SRVideoPreviewActionCancel);
//        }
    }
    
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [previewController dismissViewControllerAnimated:YES completion:nil];
        [ _camaraPanel stopCAP];
        [ self removeFromSuperview];
    });
    
    
    
}



#pragma mark -
- (void)setLocalVideoMuted:(BOOL)muted {
    if (_camaraPanel) {
        dispatch_async(dispatch_get_main_queue(), ^{
            
            if (muted) {
                [_camaraPanel stopCAP];
            } else{
                [_camaraPanel startCAP];
            }
            [_camaraPanel showCamara:!muted];
            
        });
        
    }
}


- (itmButton *)menuButtonWithImage:(UIImage *)image size:(CGFloat)size {
    
    itmButton * btn = [itmButton new];
    if (image != nil) {
        [btn setImage:image forState:UIControlStateNormal];
    }
    
    btn.titleLabel.font = [UIFont systemFontOfSize:13.f];
    btn.titleLabel.textColor = [UIColor whiteColor];
    btn.titleLabel.layer.shadowColor = [UIColor blackColor].CGColor;
    btn.titleLabel.layer.shadowRadius = 5.f;
    btn.titleLabel.layer.shadowOpacity = 0.8;
    
    btn.frame = CGRectMake(0, 0, size, size);
    
    return btn;
}

- (void)panHandle:(UIPanGestureRecognizer *)pan{
    [super panHandle:pan];
    
    if (pan.state == UIGestureRecognizerStateBegan) {
        
        [self hideMenu];
        [self stopShowTimer];
        
        self.timeLabel.hidden = NO;
        self.redDot.hidden = YES;
        self.alpha = 1.f;
        [self stopRespiratoryTimer];
        
    }else if (pan.state == UIGestureRecognizerStateEnded){
        for (int i = 0; i<self.mainMenuItems.count; i++) {
            [self repostionMainMenuItem:self.mainMenuItems[i] atIndex:i];
        }
        [self startShowTimer];
    }
    
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





