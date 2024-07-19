//
//  ERRubikCubeGLESView.h
//  ESImageCoreEngine
//
//  Created by Evan Santis on 2023/4/10.
//  Copyright © 2023 Evan Santis. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ESRCVertexModel.h"
NS_ASSUME_NONNULL_BEGIN

@interface ERRubikCubeGLESView : UIView
/// 初始化[魔方]功能的OpenGLES图层
+ (instancetype)glesView;
/// 初始化OpenGLES着色器以及缓存区(该方法务必放在self.frame赋值以后调用,否则将会加载失败)
- (void)loadOpenGLES;
/// 刷新并显示最新OpenGLES视图
- (void)display;

/// X方向旋转
@property (nonatomic, assign) CGFloat rotateX;
/// Y方向旋转
@property (nonatomic, assign) CGFloat rotateY;
/// Z方向旋转
@property (nonatomic, assign) CGFloat rotateZ;
/// 光栅化的顶点集合model
@property (nonatomic, strong) ESRCVertexModel* vertexModel;

@end

NS_ASSUME_NONNULL_END
