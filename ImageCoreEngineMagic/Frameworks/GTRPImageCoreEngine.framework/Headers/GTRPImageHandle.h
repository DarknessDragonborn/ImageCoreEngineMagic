//
//  GTRPImageHandle.h
//  GTRPImageCoreEngine
//
//  Created by Hlathguth Valkyrie on 27/6/2018.
//  Copyright © 2024 Hlathguth Valkyrie. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@interface GTRPLossPixelModel : NSObject
/// x坐标
@property(nonatomic, assign) size_t x;
/// y坐标
@property(nonatomic, assign) size_t y;
/// 距离值
@property(nonatomic, assign) double distance;
/// 角度
@property(nonatomic, assign) double angle;

+ (instancetype)modelWithX:(size_t)x y:(size_t)y distance:(double)distance angle:(double)angle;

@end


@interface GTRPPixelModel : NSObject
/// 像素点下标
@property(nonatomic, assign) int32_t index;
/// 红
@property(nonatomic, assign) unsigned char red;
/// 绿
@property(nonatomic, assign) unsigned char green;
/// 蓝
@property(nonatomic, assign) unsigned char blue;
/// 透明度
@property(nonatomic, assign) unsigned char alpha;

/// 初始化个空像素
+ (instancetype)modelWithZero;

+ (instancetype)modelWithIndex:(int32_t)index red:(unsigned char)red green:(unsigned char)green blue:(unsigned char)blue alpha:(unsigned char)alpha;

@end


@interface GTRPImageHandle : NSObject
/// 修复图像(根据:距离算法)
/// - Parameter image: 图像
+ (nullable UIImage*)repairImageByDistanceWithImage:(UIImage *)image;
/// 修复图像(根据:遍历算法)
/// - Parameter image: 图像
+ (nullable UIImage*)repairImageByTraversalWithImage:(UIImage *)image;

/// 移除图像局部
/// @param image 图像
/// @param maskImage mask图像
+ (UIImage *)removePart:(UIImage *)image maskImage:(UIImage *)maskImage;

/// 生成羽化图像
/// @param alpha 透明度
/// @param loc 羽化起点
- (UIImage *)featheredImageWithAlpha:(CGFloat)alpha startLoc:(CGFloat)loc;

@end



NS_ASSUME_NONNULL_END
