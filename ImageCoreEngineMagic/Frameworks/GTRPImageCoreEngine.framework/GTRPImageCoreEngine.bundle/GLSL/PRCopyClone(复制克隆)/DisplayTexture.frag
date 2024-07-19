/* 片元着色器 */
//获取纹理
uniform sampler2D displayTexture;
//OpenGLES坐标系归一化的长宽比
uniform highp float aspectRatio;
//标志圆圈半径
uniform highp float markRadius;
//标志圆圈中心坐标
uniform highp vec2 markCenter;
//顶点的颜色
uniform lowp vec4 markColor;

//传递的纹理坐标
varying lowp vec2 varyTextureCoord;
//[片元着色器]的核心函数
void main(){
    highp float borderWidth = 0.05 * markRadius;
    highp float minWidth = 0.1 * 0.01;
    if (borderWidth < minWidth) {
        borderWidth = minWidth;
    }
    highp float maxWidth = 0.1 * 0.08;
    if (borderWidth > maxWidth) {
        borderWidth = maxWidth;
    }
    
    highp vec2 realVaryTextureCoord = vec2(varyTextureCoord.x,
                                          (varyTextureCoord.y - markCenter.y)*aspectRatio + markCenter.y);
    if (distance(markCenter, realVaryTextureCoord)<=markRadius &&
        distance(markCenter, realVaryTextureCoord)>=(markRadius-borderWidth)) {
        //边框区域
        gl_FragColor = markColor;
        return;
    }
    
    highp float lineLong = 0.3 * markRadius;
    if (abs(realVaryTextureCoord.x - markCenter.x) < markRadius &&
        abs(realVaryTextureCoord.x - markCenter.x) >= markRadius-lineLong &&
        abs(realVaryTextureCoord.y - markCenter.y) <= 0.5*borderWidth) {
        //边框区域
        gl_FragColor = markColor;
        return;
    }
    if (abs(realVaryTextureCoord.y - markCenter.y) < markRadius &&
        abs(realVaryTextureCoord.y - markCenter.y) >= markRadius-lineLong &&
        abs(realVaryTextureCoord.x - markCenter.x) <= 0.5*borderWidth) {
        //边框区域
        gl_FragColor = markColor;
        return;
    }
    
    //获取图像所有像素点,并对像素点进行赋值,从而实现渲染效果
    gl_FragColor = texture2D(displayTexture, varyTextureCoord);
}
