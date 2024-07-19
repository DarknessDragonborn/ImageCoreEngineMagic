/* 片元着色器 */
//获取纹理
uniform sampler2D displayTexture;
//OpenGLES坐标系归一化的长宽比
uniform highp float aspectRatio;
//标志圆圈半径
uniform highp float markRadius;
//标志圆圈中心坐标
uniform highp vec2 markCenter;

//传递的纹理坐标
varying highp vec2 varyTextureCoord;
//[片元着色器]的核心函数
void main(){
    lowp vec4 resultColor = texture2D(displayTexture, varyTextureCoord);
    
    highp float borderWidth = 0.025 * markRadius;
    highp vec2 realVaryTextureCoord = vec2(varyTextureCoord.x,
                                          (varyTextureCoord.y - markCenter.y)*aspectRatio + markCenter.y);
    highp float dist = distance(markCenter, realVaryTextureCoord);
    if (distance(markCenter, realVaryTextureCoord)<=markRadius) {
        if (distance(markCenter, realVaryTextureCoord)>=(markRadius-borderWidth)) {
            //边框区域
            resultColor = vec4(88.0/255.0, 162.0/255.0, 249.0/255.0, 1.0);
        } else {
            //中心区域
            resultColor = vec4(255.0/255.0, 255.0/255.0, 255.0/255.0, 1.0);
        }
    }
    
    //绘制圆圈
//    if (dist <= (markRadius + borderWidth) &&
//        dist >= (markRadius - borderWidth)) {
//        resultColor = vec4(255.0/255.0, 255.0/255.0, 255.0/255.0, 1.0);
//    }
//
//    //绘制圆圈周边阴影
//    highp float shadowWidth = 3.0*borderWidth;
//    highp float offsetDist = abs(dist - markRadius);
//    if (offsetDist > borderWidth &&
//        offsetDist < borderWidth + shadowWidth) {
//        highp float distRate = 1.0 - (offsetDist - borderWidth)/shadowWidth;
//        lowp vec4 shadowColor = vec4(0.0, 0.0, 0.0, 0.5*distRate);
//        lowp vec4 textureColor = resultColor;
//        lowp vec4 color =  vec4((1.0-shadowColor.a)*textureColor.r,
//                                (1.0-shadowColor.a)*textureColor.g,
//                                (1.0-shadowColor.a)*textureColor.b,
//                                (1.0-shadowColor.a));
//        resultColor = color;
//    }
    
    //获取图像所有像素点,并对像素点进行赋值,从而实现渲染效果
    gl_FragColor = resultColor;
}
