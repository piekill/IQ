#ifndef CHILDGRAPH_H
#define CHILDGRAPH_H

#include <QWidget>
#include <QVector>
#include <QPainterPath>
#include "object.h"//图形类的头文件
#include "rule.h"//规则类的头文件

QT_BEGIN_NAMESPACE
class QPaintEvent;
QT_END_NAMESPACE

//矩阵中的子图类，继承QWidget
class ChildGraph : public QWidget
{
    Q_OBJECT
public:
    ChildGraph(QWidget *parent = 0);//构造函数
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void addObject(const Object &);//添加图形
    void addRule(Rule *);//添加规则
    Object getObject(int i);//得到子图中的第i个图形
    void popObject();//删除图形
    int objectNum()const{return shapes.size();}//返回子图中的图形数目
protected:
    void paintEvent(QPaintEvent *event);
private:
    QVector<Object> shapes;//子图中的图形数组
    QVector<Rule *> rules; //子图中的规则数组
    void drawOutline(QPainter &painter);
};

#endif // CHILDGRAPH_H
