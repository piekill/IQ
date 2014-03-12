#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QWidget>
#include <QVector>
#include "matrices.h"   //矩阵类的头文件

//中央窗口部件类CenterWidget，继承QWidget
class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    CenterWidget(int questions); //构造函数
    void setMaxNum(int max); //设置最大题数
    void getResult(); //得出测试结果
private slots:
    void nextMatrix(); //转入下一矩阵题
    void update(); //倒计时
private:
    Matrices *matrices; //矩阵题matrices
    QLabel *qnum; //题号标签
    QTimer *timer; //时间种子
    QTime time;
    QPushButton *buttonNext; //下一题按钮buttonNext
    QLCDNumber *showtime;
    QGridLayout *layout; //布局管理器
    int questionNum;  //题号
    int questionMax; //最大题数
    QVector<int> rightAnswers; //正确答案
    QVector<int> userAnswers; //测试者答案
    void newQuestion(); //随机生成新的矩阵题
};

#endif // CENTERWIDGET_H
