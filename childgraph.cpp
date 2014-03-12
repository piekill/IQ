#include "childgraph.h"//��ͼ��
#include "object.h"//ͼ����

#include <QtGui>
#include <QList>
#include <QPainterPath>

//���캯��
ChildGraph::ChildGraph(QWidget *parent): QWidget(parent)
{
    this->setMaximumSize(110,110); //��ͼ�ߴ磺110*110
}

//����ͼ��
void ChildGraph::addObject(const Object &obj)
{
    shapes.push_back(obj);
}

//�������
void ChildGraph::addRule(Rule *rule)
{
    rules.push_back(rule);
}

//�õ���i��ͼ��
Object ChildGraph::getObject(int i)
{
    if(shapes.size()>i)
        return shapes[i];
    return Object();
}

//ɾ��ͼ��
void ChildGraph::popObject()
{
    if(shapes.size()>0)
        shapes.pop_back();
}

QSize ChildGraph::minimumSizeHint() const
{
    return QSize(110, 110);
}

QSize ChildGraph::sizeHint() const
{
    return QSize(110,110);
}
void ChildGraph::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.fillRect(event->rect(), QBrush(Qt::white));
    drawOutline(painter);

    for(int i=0;i<shapes.size();i++)
    {
        painter.save();
        if(rules.size()>i){//����ǰ��ͼ�Ĺ���������ͼ����
            rules[i]->transform(painter);//�Ե�i��ͼ��ʩ�ӵ�i����ӵĹ���
        }else{
            rules[0]->transform(painter);//����ʹ�õ�һ������
        }
        painter.translate(5.0,5.0);
        shapes[i].drawShape(painter);
        painter.restore();
    }

}
void ChildGraph::drawOutline(QPainter &painter)
{
    painter.setPen(Qt::black);
    painter.setPen(Qt::SolidLine);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(0, 0, 110, 110);
}
