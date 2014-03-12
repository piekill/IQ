#ifndef CHILDGRAPH_H
#define CHILDGRAPH_H

#include <QWidget>
#include <QVector>
#include <QPainterPath>
#include "object.h"//ͼ�����ͷ�ļ�
#include "rule.h"//�������ͷ�ļ�

QT_BEGIN_NAMESPACE
class QPaintEvent;
QT_END_NAMESPACE

//�����е���ͼ�࣬�̳�QWidget
class ChildGraph : public QWidget
{
    Q_OBJECT
public:
    ChildGraph(QWidget *parent = 0);//���캯��
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void addObject(const Object &);//���ͼ��
    void addRule(Rule *);//��ӹ���
    Object getObject(int i);//�õ���ͼ�еĵ�i��ͼ��
    void popObject();//ɾ��ͼ��
    int objectNum()const{return shapes.size();}//������ͼ�е�ͼ����Ŀ
protected:
    void paintEvent(QPaintEvent *event);
private:
    QVector<Object> shapes;//��ͼ�е�ͼ������
    QVector<Rule *> rules; //��ͼ�еĹ�������
    void drawOutline(QPainter &painter);
};

#endif // CHILDGRAPH_H
