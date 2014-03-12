#ifndef MATRICES_H
#define MATRICES_H
#include <QVector>
#include <QtGui>
#include "childgraph.h"//子图类头文件

//矩阵类，是各类规则矩阵题的父类
class Matrices : public QWidget
{
    Q_OBJECT
public:
    Matrices();
    int getRightAnswer()const{return answer;}//获取正确答案
    int getUserAnswer()const;//获取测试者答案
protected:
    void init();//矩阵题初始化
    void setAll();//生成完整的矩阵题
    void setUi(); //界面设置
    void chooseAnswer();//随机放置正确答案

    enum{AreaNum = 3};//矩阵行列
    ChildGraph *graphs[AreaNum*AreaNum];//矩阵题的主体子图（9个）
    ChildGraph *choices[AreaNum+1]; //备选答案的子图（4个）
    QRadioButton *choice[AreaNum+1];//备选答案的4个单选按钮
    QGridLayout *layout;
    int answer;//正确答案
};

#endif // MATRICES_H
