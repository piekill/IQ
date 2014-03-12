#include "rule.h"
#include <QPainter>

Rule::Rule()
{
}
//���캯�����޲�������Ĭ�ϲ�ƽ��
Translation::Translation():x(0),y(0){}
//���캯����������(int _x,int _y)����ƽ������Ϊ(_x,_y)
Translation::Translation(int _x,int _y):x(_x),y(_y){}

void Translation::transform(QPainter &painter)
{
    painter.translate(x, y);//ƽ�Ʋ���
}

//���캯�����޲�������Ĭ�ϲ���ת
Rotation::Rotation():angle(0){}
//���캯����������(int _angle)������ת�Ƕ�Ϊ_angle
Rotation::Rotation(int _angle):angle(_angle){}

void Rotation::transform(QPainter &painter)
{
    painter.rotate(angle);//��ת����
}

TransRotation::TransRotation(int _x,int _y,int _angle)
{
    x=_x;
    y=_y;
    angle=_angle;
}
void TransRotation::transform(QPainter &painter)
{
    painter.rotate(angle);//��ת
    painter.translate(x,y);//ƽ��
}



