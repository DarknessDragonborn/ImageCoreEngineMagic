//
//  ESMathTool.h
//  ESImageCoreEngine
//
//  Created by Evan Santis on 2020/12/16.
//  Copyright © 2021 Evan Santis. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESMathTool : NSObject
#pragma mark - ================== 常用数学公式 start ================
/// 计算两点之间的距离
/// @param pointA  A点
/// @param pointB  B点
+ (CGFloat)distanceByPointA:(CGPoint)pointA pointB:(CGPoint)pointB;
/// 方向单位向量
/// @param pointA  A点
/// @param pointB  B点
+ (CGVector)motionByPointA:(CGPoint)pointA pointB:(CGPoint)pointB;

/// 两点之间的中心点
/// @param pointA  A点
/// @param pointB  B点
+ (CGPoint)centerByPointA:(CGPoint)pointA pointB:(CGPoint)pointB;
#pragma mark ================== 常用数学公式方法 end ==================

#pragma mark - ================== 基本图像处理 start ================

#pragma mark ================== 基本图像处理 end ==================
@end

NS_ASSUME_NONNULL_END
