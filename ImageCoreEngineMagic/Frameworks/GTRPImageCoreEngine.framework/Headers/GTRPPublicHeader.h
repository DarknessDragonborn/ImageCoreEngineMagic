//
//  GTRPPublicHeader.h
//  GTRPImageCoreEngine
//
//  Created by Evan Santis on 2021/10/16.
//  Copyright © 2021 Evan Santis. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for TSImageCoreEngine.
FOUNDATION_EXPORT double ESImageCoreEngineVersionNumber;

//! Project version string for TSImageCoreEngine.
FOUNDATION_EXPORT const unsigned char ESImageCoreEngineVersionString[];

//公共算法工具
#import <GTRPImageCoreEngine/ESMathTool.h>
#import <GTRPImageCoreEngine/GTRPImageHandle.h>
//[液化]算法
#import <GTRPImageCoreEngine/MGRenderTool.h>
#import <GTRPImageCoreEngine/MGRenderGLESView.h>
//[复制克隆]算法
#import <GTRPImageCoreEngine/PRCopyCloneRender.h>
#import <GTRPImageCoreEngine/PRCopyCloneGLESView.h>
//[美白]算法
#import <GTRPImageCoreEngine/DFMaskOverlayTool.h>
#import <GTRPImageCoreEngine/DFMaskOverlayGLESView.h>
//[绘画笔]算法
#import <GTRPImageCoreEngine/TBDrawBrushTool.h>
#import <GTRPImageCoreEngine/TBDrawBrushGLESView.h>
//[魔方3D建模]算法
#import <GTRPImageCoreEngine/ERRubikCubeGLESView.h>

