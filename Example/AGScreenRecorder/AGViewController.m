//
//  AGViewController.m
//  AGScreenRecorder
//
//  Created by linguanjie@gmail.com on 09/25/2017.
//  Copyright (c) 2017 linguanjie@gmail.com. All rights reserved.
//

#import "AGViewController.h"
#import <AGScreenRecorder/AGScreenRecorder.h>

@interface AGViewController ()

@end

void SRCallback(const char * className, const char * method, const char * msg){
    NSLog(@"className : %s \n method : %s \n msg : %s",className, method, msg);
}


@implementation AGViewController{
    BOOL isRecording;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    isRecording = NO;
    
    AGSR_Init("11", "1", "2", "3");
    AGSR_SetCallback(SRCallback);

    
    //create particle emitter layer
    CAEmitterLayer *emitter = [CAEmitterLayer layer];
    emitter.frame = CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height * 0.6);
    [self.view.layer addSublayer:emitter];
    
    //configure emitter
    emitter.renderMode = kCAEmitterLayerAdditive;
    emitter.emitterPosition = CGPointMake(emitter.frame.size.width * 0.5, 2.0);
    
    //create a particle template
    CAEmitterCell *cell = [[CAEmitterCell alloc] init];
    cell.contents = (__bridge id)[UIImage imageNamed:@"t"].CGImage; // 粒子中的图片
    
    cell.scale = 0.12;
    cell.yAcceleration = 120;     // 粒子的初始加速度
    cell.xAcceleration = rand() % 20;
    cell.birthRate = 10.f;           // 每秒生成粒子的个数
    cell.lifetime = 10.f;            // 粒子存活时间
    cell.alphaSpeed = -0.25f;        // 粒子消逝的速度
    cell.velocity = 2.f;           // 粒子运动的速度均值
    cell.velocityRange = 120.f;      // 粒子运动的速度扰动范围
    cell.emissionRange = M_PI * 10.f; // 粒子发射角度, 这里是一个扇形.
    
    //add particle template to emitter
    emitter.emitterCells = @[cell];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)actionButtonOnClicked:(UIButton *)sender {
    
    if (isRecording) {
        AGSR_Stop();
        [sender setTitle:@"开始录制" forState:UIControlStateNormal];
    }else{

        AGSR_Start();
        [sender setTitle:@"停止" forState:UIControlStateNormal];
    }
    isRecording = !isRecording;
}
- (IBAction)setControlPanelHidden:(UISwitch *)sender {
    AGSR_SetVideoPreviewHidden(!sender.on);
}
- (IBAction)cancelButtonOnClicked:(UIButton *)sender {
    AGSR_Cancel();
}

@end
