//
//  MGRenderTool.h
//  MGTwistTool
//
//  Created by Magic Master on 2020/12/16.
//  Copyright © 2020 Magic Master. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MGVertexModel.h"
NS_ASSUME_NONNULL_BEGIN
@interface MGRenderTool : NSObject
/// 初始化实例对象
/// @param image 图像
/// @param maxCount 最大光栅化网格数量
+ (instancetype)initWithImage:(UIImage*)image maxCount:(GLuint)maxCount;
/// 设置渲染图像
/// @param image 图像对象
- (void)setImageOfRender:(UIImage*)image;
/// 最大光栅化网格数量
@property (nonatomic, assign, readonly) GLuint maxCount;
/// 获取渲染缓存区的纹理对象
- (GLuint)getTextureID;
/// 画布大小
@property (nonatomic, assign, readonly) CGSize layerSize;
/// 光栅化的顶点集合model
@property (nonatomic, strong) MGVertexModel* vertexModel;
/// 更新顶点数据集合到BufferData缓存区
- (void)updateVertexBuffer;

/// 渲染核心方法
- (void)renderAction;
/// 重置渲染管线
- (void)resetRender;
/// 获取OpenGLES渲染图像
- (UIImage*)getImageOfRender;
@end

NS_ASSUME_NONNULL_END
