//
//  GTRPImageTool.h
//  GTRPImageCoreEngine
//
//  Created by Evan Santis on 2023/4/21.
//  Copyright © 2023 Evan Santis. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface GTRPImageTool : NSObject
/// 自定义尺寸缩放图像
/// @param image 图像对象
/// @param size 自定义尺寸
+ (UIImage*)scaleImage:(UIImage*)image size:(CGSize)size;
/// 创建一张纯色图像
/// @param color 颜色值
/// @param size 图像尺寸
+ (UIImage *)crearteColorImage:(UIColor *)color size:(CGSize)size;


/// 将UIView视图转换成UIImage图像
/// @param view UIView视图对象
+ (UIImage *)imageWithView:(UIView *)view;



/// 反码mask遮罩图(黑白像素反转)
/// @param maskImage 传入mask黑白遮罩图
+ (UIImage *)reverseMask:(UIImage *)maskImage;
/// 裁剪(根据mask黑白蒙版图)
/// @param inputImage 待处理图像
/// @param maskImage mask黑白蒙版图
+ (UIImage *)cutoutImage:(UIImage *)inputImage maskImage:(UIImage *)maskImage;
@end

NS_ASSUME_NONNULL_END
