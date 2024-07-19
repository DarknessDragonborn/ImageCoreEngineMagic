//
//  GTRPShaderManager.h
//  GTRPImageCoreEngine
//
//  Created by Evan Santis on 2020/9/4.
//  Copyright © 2020 Evan Santis. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GTRPRootModel.h>
NS_ASSUME_NONNULL_BEGIN
/* =================== Shader着色器程序的常量集合 start =================== */
/// [顶点着色器]程序的主键
static NSString * _Nullable ESDV_ProgramOfVert = @"vert";
/// [片元着色器]程序的主键
static NSString * _Nullable ESDV_ProgramOfFrag = @"frag";
/// attribut属性集合的主键
static NSString * _Nullable ESDV_Attributs = @"attributs";
/// uniforms常量集合的主键
static NSString * _Nullable ESDV_Uniforms = @"uniforms";
/* =================== Shader着色器程序的常量集合 end =================== */
@interface GTRPGLProgramModel : GTRPRootModel
/// [顶点着色器]程序名称
@property (nonatomic, copy) NSString *programOfVert;
/// [片元着色器]程序名称
@property (nonatomic, copy) NSString *programOfFrag;
/// attitude属性名称的集合数组
@property (nonatomic, strong) NSArray <NSString*> *attributeNamesArray;
/// uniform常量名称的集合数组
@property (nonatomic, strong) NSArray <NSString*> *uniformNamesArray;

/// 自定义初始化model对象
/// @param vertProgram [顶点着色器]程序名称
/// @param fragProgram [片元着色器]程序名称
/// @param attributesArray attitude属性名称的集合数组
/// @param uniformsArray uniform常量名称的集合数组
+ (instancetype)customByVertProgram:(NSString*)vertProgram
                        fragProgram:(NSString*)fragProgram
                    attributesArray:(NSArray<NSString*>*)attributesArray
                      uniformsArray:(NSArray<NSString*>*)uniformsArray;
/// 自定义初始化model对象
/**@param dict 初始化NSDictionary:@{
        ESDV_ProgramOfVert : @"DrawShader.vert",
        ESDV_ProgramOfFrag : @"DrawShader.frag",
        ESDV_Attributs : @[
            @"attribut01"
        ],
        ESDV_Uniforms : @[
            @"uniform01"
        ],
    }
 */
+ (instancetype)customByDict:(NSDictionary*)dict;
@end

@interface GTRPGLShaderModel : GTRPRootModel
/// 程序ID
@property (nonatomic, assign) GLuint programID;
/// OpenGLES缓存区(存储临时数据)
@property (nonatomic, assign) GLuint bufferID;
/// OpenGLES缓存区(vertex顶点坐标集合)
@property (nonatomic, assign) GLuint vertexVBO;
/// OpenGLES缓存区(texture纹理坐标集合)
@property (nonatomic, assign) GLuint textureVBO;
/// OpenGLES缓存区(indices绘制顶点顺序集合)
@property (nonatomic, assign) GLuint indicesVBO;
/// attitude属性对象的集合字典
@property (nonatomic, strong) NSDictionary *attributesDict;
/// uniform常量对象的集合字典
@property (nonatomic, strong) NSDictionary *uniformNamesDict;
/// 获取Attribute属性ID
/// @param key 索引建
- (GLuint)getAttributeByKey:(NSString*)key;
/// 获取Uniform属性ID
/// @param key 索引建
- (GLuint)getUniformByKey:(NSString*)key;
/// 销毁着色器 program程序存储空间 和 buffer数据缓存池
- (void)deallocShaderModel;
@end

/// OpenGLES纹理Texture的实体类
@interface GTRPGLTexture : GTRPRootModel
/// 纹理ID
@property (nonatomic, assign) GLuint ID;
/// 纹理[宽度]
@property (nonatomic, assign) GLsizei width;
/// 纹理[高度]
@property (nonatomic, assign) GLsizei height;
/// 销毁Texture纹理对象
- (void)deallocTexture;
@end

/// 光栅化的顶点集合model
@interface GTRPVertexModel : GTRPRootModel
/// 光栅化顶点集合的宽度
@property (nonatomic, assign) GLuint width;
/// 光栅化顶点集合的高度
@property (nonatomic, assign) GLuint height;
/// 光栅化顶点集合数组
@property (nonatomic, strong) NSMutableArray <NSMutableArray <NSValue*> *> *vertexMarr;
@end

@interface GTRPShaderManager : NSObject
/// 加载OpenGLES着色器程序(重点注意:该程序必须要在UIView完成layoutSubviews后调用才能生效)
/// @param model 着色器程序信息model对象
/// @return OpenGLES着色器对象
+ (GTRPGLShaderModel*)loadShaderProgramByModel:(GTRPGLProgramModel*)model;
/// 加载纹理对象
/// @param image 纹理图像
+ (GTRPGLTexture*)loadTextureByImage:(UIImage*)image;
/// 获取bundle资源库中文件路径
/// @param fileName 文件名
/// @param folder 文件夹
+ (NSString*)getPathFromBundleByFileName:(NSString*)fileName folder:(NSString*)folder;
@end
NS_ASSUME_NONNULL_END
