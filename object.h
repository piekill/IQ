#ifndef OBJECT_H
#define OBJECT_H
#include <QPainterPath>
#include <QPainter>

//ͼ����
class Object
{
public:
    Object();
    void drawShape(QPainter &painter);//����ͼ��
protected:
    QPainterPath shape;
};

//����1:������
class Triangle:public Object
{
public:
    Triangle();
    Triangle(int);
private:
    int doub;
};

//����2������
class Rectangle :public Object
{
public:
    Rectangle();
    Rectangle(int);
private:
    int doub;
};

//����3���߶�
class Line:public Object
{
public:
    Line();
    Line(int);
private:
    int doub;
};

//��������չ��ͼ������

#endif // OBJECT_H
