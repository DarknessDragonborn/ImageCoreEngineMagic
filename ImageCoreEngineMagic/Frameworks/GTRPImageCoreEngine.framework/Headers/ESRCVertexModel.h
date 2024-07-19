//
//  ESRCVertexModel.h
//  ESImageCoreEngine
//
//  Created by Evan Santis on 2023/4/28.
//  Copyright © 2023 Evan Santis. All rights reserved.
//

#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
/// [魔方3D建模]顶点数据模型
@interface ES3DPoint : NSObject
/// X轴坐标
@property (nonatomic, assign, readonly) CGFloat x;
/// Y轴坐标
@property (nonatomic, assign, readonly) CGFloat y;
/// Z轴坐标
@property (nonatomic, assign, readonly) CGFloat z;


/// 纹理X坐标
@property (nonatomic, assign) CGFloat textureX;
/// 纹理Y坐标
@property (nonatomic, assign) CGFloat textureY;

/// 顶点序号
@property (nonatomic, assign, readonly) GLuint index;

/// 初始化3D顶点对象
/// - Parameters:
///   - x: X轴坐标
///   - y: Y轴坐标
///   - z: Z轴坐标
///   - index: 顶点序号
+ (instancetype)pointByX:(CGFloat)x y:(CGFloat)y z:(CGFloat)z index:(GLuint)index;


/// 初始化3D顶点对象
/// - Parameter model: 顶点对象
+ (instancetype)pointByModel:(ES3DPoint*)model;

@end

/// [矩阵单元]model数据模型
@interface ESUnitModel : NSObject
/// 矩阵单元6顶点对象的数组集合
@property (nonatomic, strong) NSArray <ES3DPoint*> *pointsGroup;

/// 自定义初始化 [矩阵单元]model数据模型 的实例对象
/// - Parameters:
///   - pointsGroup: 矩阵单元6顶点对象的数组集合
+ (instancetype)modelByPointsGroup:(NSArray <ES3DPoint*> *)pointsGroup;
@end




/// [魔方3D建模]顶点数据模型
@interface ESRCVertexModel : NSObject
/// 魔方6个面的枚举
typedef NS_ENUM(NSInteger, ESRCFaceType) {
    ESRCFCType_TopFace = 101,///<顶面
    ESRCFCType_BottomFace = 102,///<底面

    ESRCFCType_LeftFace = 103,///<左面
    ESRCFCType_RightFace = 104,///<右面

    ESRCFCType_FrontFace = 105,///<前面
    ESRCFCType_BackFace = 106,///<后面
};

/// 自定义初始化 [魔方3D建模]顶点数据模型 实例对象
/// @param xOrder X轴阶数
/// @param yOrder Y轴阶数
/// @param zOrder Z轴阶数
+ (instancetype)initVertexModelByXOrder:(GLuint)xOrder yOrder:(GLuint)yOrder zOrder:(GLuint)zOrder;
/// X轴阶数
@property (nonatomic, assign, readonly) GLuint xOrder;
/// Y轴阶数
@property (nonatomic, assign, readonly) GLuint yOrder;
/// Z轴阶数
@property (nonatomic, assign, readonly) GLuint zOrder;

/// 魔方3D模型6个面的顶点集合字典
//@property (nonatomic, strong) NSMutableDictionary <NSString*, NSMutableArray <NSMutableArray <ES3DPoint*> *> *> *vertexMdict;
/// 魔方3D模型6个面的顶点集合字典
@property (nonatomic, strong) NSMutableDictionary  <NSString*, NSMutableArray <NSNumber*> *> *indicesMdict;

/// 魔方6面的顶点字典集合
@property (nonatomic, strong) NSDictionary <NSNumber*, NSMutableArray <ES3DPoint*> *> *vertexPointDict;


/// [单元矩阵]的集合数组
@property (nonatomic, strong) NSMutableArray <ESUnitModel*> *unitGroupMarr;

/// [单元矩阵]的集合字典
@property (nonatomic, strong) NSMutableDictionary <NSNumber*, NSMutableArray <ESUnitModel*> *> *unitGroupDict;
@end



NS_ASSUME_NONNULL_END
