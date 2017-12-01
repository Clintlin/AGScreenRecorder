//
//  AG_ScreenRecorder_c_warper.h
//  Pods
//
//  Created by Clintlin on 2017/9/25.
//

#import <Foundation/Foundation.h>

typedef enum : NSUInteger {
    SRVideoShapeTypeCircle = 1,
    SRVideoShapeTypeSquare,
    SRVideoShapeTypeDefault
} SRVideoShapeType;

typedef void (*SRGameCallback)(const char *className,const char* method,const char* msg);

#define API

#ifdef __cplusplus
extern "C" {
#endif
    
    API     void AGSR_SetCallback(SRGameCallback callback);
    API     void AGSR_Init(const char* gameKey, const char* objName, const char* onSucces, const char* onFailure);
    API     void AGSR_Start(void);
    API     void AGSR_Stop(void);
    API     void AGSR_Cancel(void);
    API     void AGSR_SetVideoPreviewHidden(bool hidden);
    API     void AGSR_SetVideoPreviewShape(SRVideoShapeType type);
    
#ifdef __cplusplus
}
#endif
