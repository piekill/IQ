#include <QtGui>
#include <QVector>
#include "matrices.h"       //矩阵类
#include "childgraph.h"     //子图类
#include "object.h"         //图形类
#include "rule.h"           //基本规则类

Matrices::Matrices()
{
}

//矩阵初始化
void Matrices::init()
{
     //利用系统时间设置随机数种子
    QTime t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);

    //初始化第一列
    for(int i=0;i<3;i++){
        ChildGraph *temp=new ChildGraph;
        for(int j=0;j<qrand()%2+2;j++){
            int k=qrand()%3;
            switch(k){
                case 0:temp->addObject(Triangle());break;
                case 1:temp->addObject(Rectangle());break;
                case 2:temp->addObject(Line());break;
                    //其他待扩展的图形
                }
        }
       graphs[3*i]=temp;
    }
}

//矩阵界面设置
void Matrices::setUi()
{
    layout = new QGridLayout;

    //加入9个矩阵子图
    for(int i=0;i<8;i++)
        layout->addWidget(graphs[i],i/3,i%3);
    layout->addWidget(new ChildGraph(),2,2);
    layout->addWidget(new QLabel("Choose your Answer:"),3,0,1,3,Qt::AlignLeft);

    //加入4个备选答案子图
    for(int i=0;i<=AreaNum;i++)
    {
        layout->addWidget(choices[i],4,i);
    }

    //加入4个单选按钮
    choice[0]=new QRadioButton("A");
    choice[1]=new QRadioButton("B");
    choice[2]=new QRadioButton("C");
    choice[3]=new QRadioButton("D");
    for(int i=0;i<=AreaNum;i++)
    layout->addWidget(choice[i],5,i);

    setLayout(layout);
}

//生成各类规则的矩阵题
void Matrices::setAll()
{
}


//随机放置正确答案
void Matrices::chooseAnswer()
{
    QTime t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    answer=qrand()%4+1;
    choices[answer-1]=graphs[8];//正确答案graphs[8]随机放置在choices中
}

//获取测试者答案
int Matrices::getUserAnswer()const
{
    for(int i=0;i<4;i++)
        if(choice[i]->isChecked())
            return i+1;
    return 0;
}
