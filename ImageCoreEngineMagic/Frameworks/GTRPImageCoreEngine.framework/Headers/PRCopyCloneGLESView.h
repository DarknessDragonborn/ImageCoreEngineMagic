//
//  PRCopyCloneGLESView.h
//  PRCopyClone
//
//  Created by Evan Santis on 2021/10/28.
//  Copyright © 2021 Evan Santis. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PRCopyCloneRender.h"
NS_ASSUME_NONNULL_BEGIN
@interface PRCopyCloneGLESView : UIView
/// OpenGLES核心渲染对象
@property (nonatomic, strong) PRCopyCloneRender *cloneCopyTool;
/// 初始化的OpenGLES图层
/// @param image 纹理图像
/// @param maskMaxWidth  [mask遮罩画布]宽度最大值(数值越大绘制越精细,内核负担也越大,一般设置1000px即可)
+ (instancetype)glesViewByImage:(UIImage*)image maskMaxWidth:(CGFloat)maskMaxWidth;
/// 初始化OpenGLES着色器以及缓存区(该方法务必放在self.frame赋值以后调用,否则将会加载失败)
- (void)loadOpenGLES;

/// 画线方法
/// @param start 开始点
/// @param end 结束点
/// @param scale 缩放比率
-(void)drawLineFromPoint:(CGPoint)start toPoint:(CGPoint)end scale:(CGFloat)scale;
/// 预备绘画
/// @param start 开始点
/// @param end 结束点
/// @param scale 缩放比率
- (void)prepareFromPoint:(CGPoint)start toPoint:(CGPoint)end scale:(CGFloat)scale;
/// 刷新并显示最新OpenGLES视图
- (void)display;

/// 绘点密度(默认100,单位距离的绘点数量)
@property (nonatomic, assign) CGFloat density;
/// 标志圆圈半径
@property (nonatomic, assign) CGFloat markRadius;
/// 标志圆圈中心点
@property (nonatomic, assign) CGPoint markCenter;
/// 设置[目标圆圈]颜色
/// @param color 颜色对象
- (void)setTargetRoundColor:(UIColor*)color;
/// 是否显示标志圆圈
@property (nonatomic, assign) BOOL isShowMarkRound;

/// 获取最终结果图
/// @desc (该方法将释放OpenGLES所有内存用于最终结果图渲染,即OpenGLES需要重新初始化才能对图像进行再次渲染)
/// @param imageSize 图像尺寸(CGSizeZero即为图像原尺寸)
- (UIImage*)getLastResultImage:(CGSize)imageSize;
@end

NS_ASSUME_NONNULL_END
