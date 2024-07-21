/* 顶点着色器 */
//顶点的集合数组
attribute vec4 drawShaderVertex;
//顶点的大小
uniform highp float pointSize;
//顶点的颜色
uniform lowp vec4 pointColor;
//输出颜色的集合数组
varying lowp vec4 varyColor;
//[顶点着色器]的核心函数
void main(){
    //顶点计算
    gl_Position = drawShaderVertex;
    //设置各个顶点的大小
    gl_PointSize = pointSize;
    //赋值颜色矩阵
    varyColor = pointColor;
}
