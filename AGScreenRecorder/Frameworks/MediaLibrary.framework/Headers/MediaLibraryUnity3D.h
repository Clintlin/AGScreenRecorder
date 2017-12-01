//
//  MediaLibraryUnity3D.h
//  VideoFileCapture
//
//  Created by zhangxinming on 16/5/17.
//  Copyright © 2016年 zhangxinming. All rights reserved.
//

#ifndef MediaLibraryUnity3D_h
#define MediaLibraryUnity3D_h

#include <stdio.h>
#import <Foundation/Foundation.h>

@interface UnityMsgObj: NSObject
@property(nonatomic,strong)NSString *functionName;
@property(nonatomic,strong)NSString *UnityObject;
@property(nonatomic,strong)NSString *UnityFunSucces;
@property(nonatomic,strong)NSString *UnityFunFail;

@end
#ifdef __cplusplus
extern "C" {
#endif
///////////////////unity回调
    
    typedef int (*UNITYSENDMSG)(const char *cunityObj,const char* unityFunSucces,const char* msg);

    void setUnitySendmsg(UNITYSENDMSG unitymsg);
    
    //初始化视频回调
void initUnityVideocallback(const char* unityObject,const char* UnityFunSucces,const char* UnityFunFail);

//初始化音频录制回调
void initUnityAudiocallback(const char* unityObject,const char* UnityFunSucces,const char* UnityFunFail);

//初始化照片获取回调
void initUnityPhotoCallBack(const char* unityObject,const char* UnityFunSucces,const char* UnityFunFail);

//初始化文件上传回调
void initUnityHttpFileCallback(const char* unityObject,const char* UnityFunSucces,const char* UnityFunFail);
//////////////////////////
    
typedef int (*MEDIACOMMONCALLBACK)(const char *retMsg ,id object);
    
/////////////////////////////////////////////普通app调用方式
    //初始化视频回调
void initVideoCallback(MEDIACOMMONCALLBACK callback,id object);
    
//初始化音频录制回调
void initAudioCallback(MEDIACOMMONCALLBACK callback,id object);
    
//初始化照片获取回调
void initPhotoCallBack(MEDIACOMMONCALLBACK callback,id object);
    
//初始化文件上传回调
void initHttpFileCallback(MEDIACOMMONCALLBACK callback,id object);
/////////////////////////////////////////
    
//开始录制视频文件
void MediaStartRecordCameraVideo(bool isFront);

//设置摄像头
void MediaSetRecordCamera(bool isFront);

void MediaStartRecordScreenVideo();
    
void MediaStopRecordScreenVideo();

void MediaCancelRecordScreenVideo();
    
//播放视频
void  MediaPlayVideoWithUrl(const char*videourl);
//停止播放
void MediaStopPlayVideo();

//录制音频
void  MediaStartRecordAudio();

//停止录制音频
void  MediaStopRecordAudio();

//取消录制音频
void  MediaCancelRecordVoice();

void  MediaPlayVoiceWithName(const char* voicepath,const char* msgid);

void  MediaStopPlayVoice();

////所录制视频的路径的回调
 void on_MediaReceiverCallbackVideo(const char*videopath,unsigned long  length );

//上传文件
void  MediaUploadFile(const char *filePath,const char* uuid,const char* uploadurl);

//下载文件
void  MediaDownloadFile(const char *fileid,const char* uuid,const char*downloadurl);
 
//删除文件
bool MediaDeleteFile(const char* path);

//调取摄像头拍照
void MediaTakePhoto(int orientation );
    
void MediaTakeScreenshot( );
    
 
//从照片库获取照片
void MediaGetPhotobyLbrary();

//获取视频或者音频的时长
float   MediaGetMediaDuration (const char *strURL);
 
    void MediaOpenCamera(int x,int y);
    
    void MediaCloseCamera();
    
    void MediaReOrientationCamera();
    
#ifdef __cplusplus
}
#endif


#endif /* MediaLibraryUnity3D_h */
