#include <QtGui>
#include <QVector>
#include <fstream>
#include <string>

#include "centerwidget.h"
//各类图形矩阵题
#include "overlay.h"        //图形叠加类
#include "portfolio.h"      //图形组合类
#include "split.h"          //图形拆分类
#include "clockwise.h"      //图形旋转类
//其他待扩展类型的矩阵题


//构造函数
CenterWidget::CenterWidget(int questions):questionMax(questions)
{
    layout=new QGridLayout(this);

    questionNum=1;//题号初始化为1
    qnum=new QLabel(QString("Question %1").arg(questionNum),this);
    layout->addWidget(qnum,0,0,1,1,Qt::AlignLeft);

    //随机生成新的矩阵题
    newQuestion();
    layout->addWidget(matrices,1,0);

    //加入计时显示
    QHBoxLayout *buttom=new QHBoxLayout();
    showtime=new QLCDNumber(this);
    showtime->setSegmentStyle(QLCDNumber::Filled);
    buttom->addWidget(showtime);

    //加入下一题按钮Next
    buttom->addSpacing(150);
    buttonNext=new QPushButton(QIcon("../images/next.png"),"Next",this);
    buttonNext->setMinimumSize(80,40);
    buttom->addWidget(buttonNext);
    connect(buttonNext,SIGNAL(clicked()),this,SLOT(nextMatrix()));

    layout->addLayout(buttom,2,0);

    //计时设置
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    time.start();
    timer->start(1000);
    update();
}

//生成下一个矩阵题
void CenterWidget::nextMatrix()
{
    userAnswers.push_back(matrices->getUserAnswer());
    questionNum++;//题号加1
    if(questionNum>questionMax){//已达到测试题数
        getResult();
        return;
    }
    //消去窗口中的当前矩阵题
    layout->removeWidget(matrices);
    layout->removeWidget(qnum);
    delete matrices;
    delete qnum;
    //在窗口中加入下一个矩阵题
    newQuestion();

    qnum=new QLabel(QString("Question %1").arg(questionNum),this);
    layout->addWidget(qnum,0,0);
    layout->addWidget(matrices,1,0);
}

//计时刷新
void CenterWidget::update()
{
    int countdown=questionMax*30000-time.elapsed();
    if(countdown<=0)
    {
        getResult();
        return;
    }
    QString text = QString("%1:%2").arg(countdown/60000).arg(countdown%60000/1000);
    if(text.section(':',1,1).size()<2)
        text.insert(text.size()-1,"0");
    showtime->display(text);
 }

//设置最大题数
void CenterWidget::setMaxNum(int max)
{
    questionMax=max;
}

//显示测试结果
void CenterWidget::getResult()
{
    delete timer;

    int count=0;
    std::string info;
    QMessageBox msg;//测试结果对话框
    QString str;
    std::ifstream infile("info.dat");
    //测试者信息
    std::getline(infile,info);
    std::getline(infile,info);

    std::getline(infile,info);
    str.append("Name:\t");
    str.append(info.c_str());
    str.append("\r\n");

    std::getline(infile,info);
    str.append("Age:\t");
    str.append(info.c_str());
    str.append("\r\n");

    std::getline(infile,info);
    str.append("Gender:\t");
    str.append(info=="0"?"Male":"Female");
    str.append("\r\n\r\n");
    infile.close();

    for(int i=0;i<rightAnswers.size()&&i<userAnswers.size();i++)
        if(rightAnswers[i]==userAnswers[i])
            count++;
    str.append(QString("You've got    %1    correct answers out of     %2     questions").arg(count).arg(questionMax));

    str.append("\r\n\r\n");

    float score=(float)count/(float)questionMax;
    switch((int)(score*5)){
            case 0:str.append("I'm sorry about you");break;
            case 1:str.append("You need improvement");break;
            case 2:str.append("You're Normal");break;
            case 3:str.append("You're Good");break;
            case 4:str.append("You're Brilliant");break;
            case 5:str.append("You're a Geniu");break;
            }

    msg.setText(str);
    msg.exec();
}

//随机生成新的矩阵题
void CenterWidget::newQuestion()
{

    //设置随机数种子
    QTime t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);

    int k=qrand()%4;
    switch(k){
    case 0:matrices=new Overlay();break;//图形叠加
    case 1:matrices=new Portfolio();break;//图形组合
    case 2:matrices=new Split();break;//图形拆分
    case 3:matrices=new Clockwise();break;//图形旋转
    }
    //放置正确答案
    rightAnswers.push_back(matrices->getRightAnswer());
}
