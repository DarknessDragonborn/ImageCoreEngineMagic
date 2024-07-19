//
//  GTRPQueueManager.h
//  GTRPImageCoreEngine
//
//  Created by Evan Santis on 2019/10/18.
//  Copyright © 2019 Evan Santis. All rights reserved.
//

#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
/// OpenGLES线程管理类(OpenGLES渲染过程必须线程管理,否则子线程拿不到缓存区资源)
@interface GTRPQueueManager : NSObject
/// 在渲染线程异步执行
void runAsyncOnGLESRenderQueue(void (^block)(void));
/// 在渲染线程同步执行
void runSyncOnGLESRenderQueue(void (^block)(void));

/// 单例共享 OpenGL 上下文
+ (EAGLContext *)shareGLESContext;
/// 单例共享 OpenGL 渲染线程
+ (dispatch_queue_t)shareRenderQueue;
/// 销毁单例
+ (void)destroySingleton;
@end
NS_ASSUME_NONNULL_END
