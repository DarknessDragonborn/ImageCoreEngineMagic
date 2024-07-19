/* 片元着色器 */
//获取纹理
uniform sampler2D displayTexture;
//OpenGLES坐标系归一化的长宽比
uniform highp float aspectRatio;
//标识圆圈的半径
uniform highp float markRadius;
//标识圆圈的中心坐标
uniform highp vec2 markCenter;

//传递的纹理坐标
varying lowp vec2 varyTextureCoord;
//[片元着色器]的核心函数
void main(){
    highp float borderWidth = 0.025 * markRadius;
    highp vec2 realVaryTextureCoord = vec2(varyTextureCoord.x,
                                          (varyTextureCoord.y - markCenter.y)*aspectRatio + markCenter.y);
    if (distance(markCenter, realVaryTextureCoord)<=markRadius &&
        distance(markCenter, realVaryTextureCoord)>=(markRadius-borderWidth)) {
            gl_FragColor = vec4(0.9, 0.9, 0.9, 1.0);
        return;
    }
    
    //获取图像所有像素点,并对像素点进行赋值,从而实现渲染效果
    gl_FragColor = texture2D(displayTexture, varyTextureCoord);
}
