#ifndef RULE_H
#define RULE_H
#include <QPainter>

//基本规则类
class Rule
{
public:
    Rule();
    virtual void transform(QPainter &painter){}
};

//基本规则子类：平移
class Translation:public Rule
{
public:
    //构造函数重载
    Translation();
    Translation(int,int);
    void transform(QPainter &painter);
private:
    int x,y;//平移向量坐标
};


//基本规则子类：旋转
class Rotation:public Rule
{
public:
    //构造函数重载
    Rotation();
    Rotation(int);
    void transform(QPainter &painter);
private:
    int angle;//旋转角度
};

//复合规则子类：旋转平移
class TransRotation:public Rule
{
public:
    TransRotation(int,int,int);
    void transform(QPainter &painter);
private:
    int angle,x,y;
};


#endif // RULE_H
