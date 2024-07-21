/* 顶点着色器 */
//顶点的集合数组
attribute vec4 displayVertex;
//纹理坐标集合
attribute vec2 displayTextureCoord;

//投影矩阵
uniform mat4 projectionMatrix;
//模型视图矩阵
uniform mat4 modelViewMatrix;

//传递的纹理坐标
varying highp vec2 varyTextureCoord;
//[顶点着色器]的核心函数
void main() {
    //传递纹理坐标
    varyTextureCoord = displayTextureCoord;
    //赋值顶点坐标集合
    gl_Position = projectionMatrix * modelViewMatrix * displayVertex;
}
