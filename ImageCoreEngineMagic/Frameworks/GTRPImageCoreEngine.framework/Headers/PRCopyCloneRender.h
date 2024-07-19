//
//  PRCopyCloneRender.h
//  PRCopyClone
//
//  Created by Evan Santis on 2021/10/16.
//  Copyright © 2021 Evan Santis. All rights reserved.
//

#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@interface PRCopyCloneRender : NSObject
/// 初始化实例对象
/// @param image 图像
/// @param maskMaxWidth [mask遮罩画布]宽度最大值(数值越大绘制越精细,内核负担也越大,一般设置1000px即可)
+ (instancetype)initWithImage:(UIImage*)image maskMaxWidth:(CGFloat)maskMaxWidth;
/// 画布大小
@property (nonatomic, assign, readonly) CGSize layerSize;
/// [mask遮罩画布]宽度最大值(数值越大绘制越精细,内核负担也越大,一般设置1500px即可)
@property (nonatomic, assign, readonly) CGFloat maskMaxWidth;
/// [mask遮罩]的尺寸
@property (nonatomic, assign, readonly) CGSize maskSize;
/// 更新[混合画布](背景+绘画画板)的纹理Texture对象
- (void)combineTextureRender;
/// 更新 [复制克隆]的纹理Texture对象
- (void)cloneCopyTextureRender;

/// 画线方法
/// @param start 开始点
/// @param end 结束点
/// @param vertexCount 绘点数量
-(void)renderLineFromPoint:(CGPoint)start toPoint:(CGPoint)end vertexCount:(GLint)vertexCount;
/// 预备绘画
/// @param start 开始点
/// @param end 结束点
/// @param vertexCount 绘点数量
- (void)prepareFromPoint:(CGPoint)start toPoint:(CGPoint)end vertexCount:(GLint)vertexCount;
/// 通过缓存点集渲染图像
- (void)renderByCachePoints;
/// [画笔类型]的枚举
typedef NS_ENUM(NSInteger, PRCPBrushType) {
    PRCPBT_Empty = 1000,///<[空]的画笔(不做任何操作)
    PRCPBT_CopyClone = 1001,///<[复制克隆]的画笔
    PRCPBT_Restore = 1002,///<[恢复原图]的画笔
};
/// 画笔类型
@property (nonatomic, assign) PRCPBrushType brushType;
/// 画笔大小
@property (nonatomic, assign) CGFloat brushWidth;
/// 画笔硬度(范围 : 0.0 ~ 1.0)
@property (nonatomic, assign) CGFloat hardness;
/// 画笔透明度最小值(默认0.2)
@property (nonatomic, assign) CGFloat minAlpha;
/// 画笔透明度最大值(默认1.0)
@property (nonatomic, assign) CGFloat maxAlpha;
/// 画笔透明度的比率
@property (nonatomic, assign) CGFloat alphaRatio;

/// 目标克隆所在点(0-1坐标系)
@property (nonatomic, assign) CGPoint targetPoint;
/// 开始克隆所在点(0-1坐标系)
@property (nonatomic, assign) CGPoint begainPoint;

/// [镜像类型]的枚举
typedef NS_ENUM(NSInteger, PRCPMirrorType) {
    PRCPMR_NoMirror = 1000,///<无镜像(默认状态)
    PRCPMR_HorizontalMirror = 1001,///<水平镜像(左右颠倒)
    PRCPMR_VerticalMirror = 1002,///<垂直镜像(上下颠倒)
    PRCPMR_HorizontalVertical = 1003,///<水平镜像 + 垂直镜像(左右颠倒 + 上下颠倒)
};
/// 镜像类型(默认PRCPMR_Nothing:无镜像)
@property (nonatomic, assign) PRCPMirrorType mirrorType;

/// 初始化 [混合画布](背景+复制克隆)的纹理Texture对象
- (void)initCombineTexture;
/// 清空绘画画板的所有内容
- (void)clearDrawBoard;
/// 更新 [临时缓存]combineTexture[混合画布]的纹理Texture对象
- (void)cacheTextureRender;

/// 获取渲染缓存区的纹理对象
- (GLuint)getTextureID;
/// 获取OpenGLES渲染图像
- (UIImage*)getImageOfRender;
/// 获取最终结果图
/// @desc (该方法将释放OpenGLES所有内存用于最终结果图渲染,即OpenGLES需要重新初始化才能对图像进行再次渲染)
/// @param imageSize 图像尺寸(CGSizeZero即为图像原尺寸)
- (UIImage*)getLastResultImage:(CGSize)imageSize;
@end

NS_ASSUME_NONNULL_END
