/* 片元着色器 */
//获取纹理
uniform sampler2D drawShaderTexture;
//输出颜色的集合数组
varying lowp vec4 varyColor;
//[片元着色器]的核心函数
void main(){
    //将颜色和纹理组合 是相乘！！！！
    gl_FragColor = varyColor * texture2D(drawShaderTexture, gl_PointCoord);
}
