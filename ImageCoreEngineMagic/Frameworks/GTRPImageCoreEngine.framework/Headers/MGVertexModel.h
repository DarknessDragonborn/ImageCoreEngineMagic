//
//  MGVertexModel.h
//  MGTwistTool
//
//  Created by Magic Master on 2020/12/16.
//  Copyright © 2020 Magic Master. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface MGVertexModel : NSObject
/// 光栅化顶点集合的宽度
@property (nonatomic, assign) GLuint width;
/// 光栅化顶点集合的高度
@property (nonatomic, assign) GLuint height;
/// 光栅化顶点集合的宽高尺寸
@property (nonatomic, assign) CGSize size;
/// 光栅化顶点集合数组
@property (nonatomic, strong) NSMutableArray <NSMutableArray <NSValue*> *> *vertexMarr;
/// 自定义光栅化顶点集合的model
/// @param size 光栅化顶点集合的宽高大小
+ (instancetype)modelBySize:(CGSize)size;
/// 自定义光栅化顶点集合的model
/// @param vertexModel 光栅化顶点集合的model对象
+ (instancetype)modelByVertexModel:(MGVertexModel*)vertexModel;

/// 获取某个顶点坐标对象
/// @param x 横坐标
/// @param y 纵坐标
- (CGPoint)getPointByX:(GLuint)x y:(GLuint)y;
/// 赋值某个顶点
/// @param x 横坐标
/// @param y 纵坐标
/// @param point 赋值点
- (void)setPointByByX:(GLuint)x
                    y:(GLuint)y
                point:(CGPoint)point;
@end

NS_ASSUME_NONNULL_END
