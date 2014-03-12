#ifndef OBJECT_H
#define OBJECT_H
#include <QPainterPath>
#include <QPainter>

//图形类
class Object
{
public:
    Object();
    void drawShape(QPainter &painter);//绘制图形
protected:
    QPainterPath shape;
};

//子类1:三角形
class Triangle:public Object
{
public:
    Triangle();
    Triangle(int);
private:
    int doub;
};

//子类2：矩形
class Rectangle :public Object
{
public:
    Rectangle();
    Rectangle(int);
private:
    int doub;
};

//子类3：线段
class Line:public Object
{
public:
    Line();
    Line(int);
private:
    int doub;
};

//其他待扩展的图形子类

#endif // OBJECT_H
