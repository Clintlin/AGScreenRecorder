//
//  ShareLibrary.hpp
//  Coordinate
//
//  Created by zhangxinming on 16/5/13.
//  Copyright © 2016年 Corrine Chan. All rights reserved.
//

#ifndef ShareLibrary_hpp
#define ShareLibrary_hpp
#import <UIKit/UIKit.h>

extern NSString* const kAGSocialOpenURLNotification;

#include <stdio.h>
#ifdef __cplusplus
extern "C" {
    
#endif
  
    typedef int (*AYSHARECALLBACK)(const char *retMsg ,id caller);
  @protocol WXApiDelegate;
    
 
    
void initAYShareCallback(AYSHARECALLBACK callback,id callerid);
    
void AGSocial_WXShareRegister(const char* appid, const char*appSecret);
void AGSocial_QQShareRegister(const char* appid);
void AGSocial_OpenURL(NSURL* url);
    
    void AGSocial_ShareVideoToWXSessionWithTitle(NSString * title,UIImage *image ,NSString * videoURL);
    void AGSocial_ShareVideoToWXTimelineWithTitle(NSString * title,UIImage *image ,NSString * videoURL);
    
    void WXShareVideoWithTitle(const char* title, const char* description, const char* thumbImage);
    
    
void WXShareTextMessage(const char* msg  , int sceneType);
void WXShareImgDataMessage(NSData* imageData, int sceneType,const char*title,const char*description);
void WXShareImgMessage(const char* path  , int sceneType,const char*title,const char*description,const char*thumbImage);

void WXShareWebPageMessage(const char* url  , int sceneType,const char*title,const char*description,const char*thumbImage);
    
void WXShareOAuthLogin(void);
    
void QQApiSentText(const char *message);
    
void  QQApiSentImage(const char *iamgepath,const char *title,const char *  description);
    
void  QQApiToQZoneWithText(const char *message);
    
void QQApiToQZoneWithImage (const char *imagepath,const char* title);
    
void QQApiToQZoneWithUrl (const char *Url,const char *previewImgeURL,const char *title,const char *description);
    
void   QQApiSharedNewsWithNetworkImage (const char *Url,const char *previewImageURL,const char *title,const char *description);
    
void   QQApiSharedNewsWithLocalImage (const char *Url,const char *imagepath,const char *title,const char *description);

    
void QQApilogin(void);
    
void showShareList(void);
    
    
    
#ifdef __cplusplus
}
#endif


#endif /* ShareLibrary_hpp */
