//
//  GTRPDrawDebug.h
//  GTRPImageCoreEngine
//
//  Created by Evan Santis on 2020/9/4.
//  Copyright © 2020 Evan Santis. All rights reserved.
//

#ifndef GTRPDrawDebug_h
#define GTRPDrawDebug_h

#define glError() { \
    GLenum err = glGetError(); \
    if (err != GL_NO_ERROR) { \
        printf("glError: %04x caught at %s:%u\n", err, __FILE__, __LINE__); \
    } \
}

/**打印快捷键**/
#ifdef DEBUG  //调试状态,打开Log功能
#define GTRPDislog(fmt, ...) NSLog(fmt, ##__VA_ARGS__)
#else  //发布状态,关闭Log功能
#define GTRPDislog(fmt, ...)
#endif
//#define
#endif /* ESDrawDebug_h */
