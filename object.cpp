#include "object.h"
#include <QPainterPath>
#include <QPainter>

//ͼ�λ���
Object::Object()
{
}
//����ͼ��
void Object::drawShape(QPainter &painter)
{
    painter.drawPath(shape);
}

//Ĭ�ϱ�׼������
Triangle::Triangle()
{
    shape.lineTo(40.0,0.0);
    shape.lineTo(0.0,40.0);
    shape.lineTo(0.0,0.0);
}
//���ع��캯��������ͼ�δ�С
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
