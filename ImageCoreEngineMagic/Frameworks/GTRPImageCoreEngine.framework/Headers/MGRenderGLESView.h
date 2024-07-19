//
//  MGRenderGLESView.h
//  MGTwistTool
//
//  Created by Magic Master on 2020/12/16.
//  Copyright © 2020 Magic Master. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MGRenderTool.h"
NS_ASSUME_NONNULL_BEGIN

@interface MGRenderGLESView : UIView
/// 扭曲算法核心工具Tool对象
@property (nonatomic, strong) MGRenderTool *twistTool;
/// 初始化[扭曲]功能的OpenGLES图层
/// @param image 纹理图像
/// @param maxCount 最大光栅化网格数量
+ (instancetype)glesViewByImage:(UIImage*)image maxCount:(GLuint)maxCount;
/// 初始化OpenGLES着色器以及缓存区(该方法务必放在self.frame赋值以后调用,否则将会加载失败)
- (void)loadOpenGLES;
/// 刷新并显示最新OpenGLES视图
- (void)display;

/// 标志圆圈半径
@property (nonatomic, assign) CGFloat markRadius;
/// 标志圆圈中心点
@property (nonatomic, assign) CGPoint markCenter;
/// 是否显示标志圆圈
@property (nonatomic, assign) BOOL isShowMarkRound;

@end

NS_ASSUME_NONNULL_END
