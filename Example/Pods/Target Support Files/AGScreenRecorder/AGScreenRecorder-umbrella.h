#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "AGScreenRecorder.h"
#import "AG_ScreenRecorder_c_warpper.h"
#import "SRApi.h"
#import "SRBaseApi.h"
#import "AGScreenRecorder.h"
#import "SRNetworking.h"
#import "SRBaseMainPanel.h"
#import "SRBaseView.h"
#import "SRCamaraPanel.h"
#import "SRCommonMacros.h"
#import "SRPanel.h"
#import "SRPopPreviewView.h"

FOUNDATION_EXPORT double AGScreenRecorderVersionNumber;
FOUNDATION_EXPORT const unsigned char AGScreenRecorderVersionString[];

