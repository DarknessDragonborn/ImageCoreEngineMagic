//
//  TBDrawBrushTool.h
//  ESImageCoreEngine
//
//  Created by Hlathguth Valkyrie on 14/8/2022.
//  Copyright © 2024 Hlathguth Valkyrie. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface TBDrawBrushTool : NSObject
/// 初始化实例对象
/// @param image 图像
/// @param maskMaxWidth [mask遮罩画布]宽度最大值(数值越大绘制越精细,内核负担也越大,一般设置1000px即可)
+ (instancetype)initWithImage:(UIImage*)image maskMaxWidth:(CGFloat)maskMaxWidth;
/// 整体画布大小
@property (nonatomic, assign, readonly) CGSize layerSize;
/// [mask遮罩画布]的尺寸
@property (nonatomic, assign, readonly) CGSize maskSize;

/// 设置 mask遮罩图
/// @param image mask遮罩图
- (void)setMaskImage:(UIImage*)image;

/// 画笔大小(1~550 备注:不能超过550)
@property (nonatomic, assign) CGFloat brushWidth;
/// 画笔硬度(范围 : 0.0 ~ 1.0)
@property (nonatomic, assign) CGFloat hardness;
/// 画笔透明度最小值(默认0.2)
@property (nonatomic, assign) CGFloat minAlpha;
/// 画笔透明度最大值(默认1.0)
@property (nonatomic, assign) CGFloat maxAlpha;
/// 画笔类型的枚举
typedef NS_ENUM(NSInteger, TBDWBrushType) {
    TBDWBrushType_Paint = 1001,///<[绘画笔]模式
    TBDWBrushType_Eraser = 1002,///<[橡皮擦]模式
};
/// 画笔类型
@property (nonatomic, assign) TBDWBrushType brushType;
/// 画笔颜色
@property (nonatomic, strong) UIColor *brushColor;

/// 初始化 [混合画布](背景+叠加效果)的纹理Texture对象
- (void)initCombineTexture;
/// 更新 [叠加效果]的纹理Texture对象
//- (void)overlayTextureRender;
/// 更新[混合画布](背景+绘画画板)的纹理Texture对象
- (void)combineTextureRender;
/// 更新 [临时缓存]combineTexture[混合画布]的纹理Texture对象
- (void)cacheTextureRender;
/// 清空mask遮罩纹理的所有内容
- (void)clearMaskTexture;
/// 画线方法
/// @param start 开始点
/// @param end 结束点
/// @param vertexCount 绘点平均数量
-(void)renderLineFromPoint:(CGPoint)start toPoint:(CGPoint)end vertexCount:(CGFloat)vertexCount;
/// 预备绘画
/// @param start 开始点
/// @param end 结束点
/// @param vertexCount 绘点数量
- (void)prepareFromPoint:(CGPoint)start toPoint:(CGPoint)end vertexCount:(CGFloat)vertexCount;
/// 通过缓存点集渲染图像
- (void)renderByCachePoints;

/// 获取渲染缓存区的纹理对象
- (GLuint)getTextureID;
/// 获取OpenGLES遮罩图
- (UIImage*)getMaskImageOfRender;
/// 获取最终mask遮罩图
/// @desc (该方法将释放OpenGLES所有内存用于最终mask遮罩图渲染,即OpenGLES需要重新初始化才能对图像进行再次渲染)
/// @param maskSize mask遮罩图尺寸(CGSizeZero即为图像原尺寸)
- (UIImage*)getLastMaskImage:(CGSize)maskSize;
/// 获取OpenGLES渲染图像
- (UIImage*)getImageOfRender;
/// 获取最终结果图
/// @desc (该方法将释放OpenGLES所有内存用于最终结果图渲染,即OpenGLES需要重新初始化才能对图像进行再次渲染)
/// @param imageSize 图像尺寸(CGSizeZero即为图像原尺寸)
- (UIImage*)getLastResultImage:(CGSize)imageSize;

@end

NS_ASSUME_NONNULL_END
