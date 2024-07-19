/* 片元着色器 */
//获取纹理
uniform sampler2D displayTexture;
//传递的纹理坐标
varying lowp vec2 varyTextureCoord;
//[片元着色器]的核心函数
void main(){
    //获取图像所有像素点,并对像素点进行赋值,从而实现渲染效果
    gl_FragColor = texture2D(displayTexture, varyTextureCoord);
}
