//
//  ESRCImageHelper.h
//  ESImageCoreEngine
//
//  Created by Evan Santis on 2023/4/21.
//  Copyright © 2023 Evan Santis. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ESRCImageHelper : NSObject
/// 生成正方体图像素材
/// - Parameters:
///   - bodyColor: 主体颜色
///   - size: 整体正方形的边长
///   - borderColor: 边界颜色
///   - borderWidth: 边界宽度
+ (UIImage*)squareByBodyColor:(UIColor*)bodyColor
                         size:(CGFloat)size
                  borderColor:(UIColor*)borderColor
                  borderWidth:(CGFloat)borderWidth;

/// 随机颜色
+ (UIColor*)randomColor;
@end

NS_ASSUME_NONNULL_END
