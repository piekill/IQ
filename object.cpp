#include "object.h"
#include <QPainterPath>
#include <QPainter>

//图形基类
Object::Object()
{
}
//绘制图形
void Object::drawShape(QPainter &painter)
{
    painter.drawPath(shape);
}

//默认标准三角形
Triangle::Triangle()
{
    shape.lineTo(40.0,0.0);
    shape.lineTo(0.0,40.0);
    shape.lineTo(0.0,0.0);
}
//重载构造函数，更改图形大小
Triangle::Triangle(int _doub)
{
    doub=_doub;
    shape.lineTo(40.0*doub,0.0);
    shape.lineTo(0.0,40.0*doub);
    shape.lineTo(0.0,0.0);
}


Rectangle::Rectangle()
{
    shape.addRect(0.0,0.0,40.0,40.0);
}

Rectangle::Rectangle(int _doub)
{
    doub=_doub;
    shape.addRect(0.0,0.0,40.0*doub,40.0*doub);
}

Line::Line()
{
    shape.lineTo(40.0,40.0);
}

Line::Line(int _doub)
{
    shape.lineTo(40.0*doub,40.0*doub);
}
