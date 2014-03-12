#ifndef RULE_H
#define RULE_H
#include <QPainter>

//����������
class Rule
{
public:
    Rule();
    virtual void transform(QPainter &painter){}
};

//�����������ࣺƽ��
class Translation:public Rule
{
public:
    //���캯������
    Translation();
    Translation(int,int);
    void transform(QPainter &painter);
private:
    int x,y;//ƽ����������
};


//�����������ࣺ��ת
class Rotation:public Rule
{
public:
    //���캯������
    Rotation();
    Rotation(int);
    void transform(QPainter &painter);
private:
    int angle;//��ת�Ƕ�
};

//���Ϲ������ࣺ��תƽ��
class TransRotation:public Rule
{
public:
    TransRotation(int,int,int);
    void transform(QPainter &painter);
private:
    int angle,x,y;
};


#endif // RULE_H
