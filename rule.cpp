#include "rule.h"
#include <QPainter>

Rule::Rule()
{
}
//构造函数：无参数，则默认不平移
Translation::Translation():x(0),y(0){}
//构造函数：带参数(int _x,int _y)，则平移坐标为(_x,_y)
Translation::Translation(int _x,int _y):x(_x),y(_y){}

void Translation::transform(QPainter &painter)
{
    painter.translate(x, y);//平移操作
}

//构造函数：无参数，则默认不旋转
Rotation::Rotation():angle(0){}
//构造函数：带参数(int _angle)，则旋转角度为_angle
Rotation::Rotation(int _angle):angle(_angle){}

void Rotation::transform(QPainter &painter)
{
    painter.rotate(angle);//旋转操作
}

TransRotation::TransRotation(int _x,int _y,int _angle)
{
    x=_x;
    y=_y;
    angle=_angle;
}
void TransRotation::transform(QPainter &painter)
{
    painter.rotate(angle);//旋转
    painter.translate(x,y);//平移
}



