#include "childgraph.h"//子图类
#include "object.h"//图形类

#include <QtGui>
#include <QList>
#include <QPainterPath>

//构造函数
ChildGraph::ChildGraph(QWidget *parent): QWidget(parent)
{
    this->setMaximumSize(110,110); //子图尺寸：110*110
}

//加入图形
void ChildGraph::addObject(const Object &obj)
{
    shapes.push_back(obj);
}

//加入规则
void ChildGraph::addRule(Rule *rule)
{
    rules.push_back(rule);
}

//得到第i个图形
Object ChildGraph::getObject(int i)
{
    if(shapes.size()>i)
        return shapes[i];
    return Object();
}

//删除图形
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
        if(rules.size()>i){//若当前子图的规则数多于图形数
            rules[i]->transform(painter);//对第i个图形施加第i个添加的规则
        }else{
            rules[0]->transform(painter);//否则，使用第一个规则
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
