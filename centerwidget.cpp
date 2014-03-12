#include <QtGui>
#include <QVector>
#include <fstream>
#include <string>

#include "centerwidget.h"
//����ͼ�ξ�����
#include "overlay.h"        //ͼ�ε�����
#include "portfolio.h"      //ͼ�������
#include "split.h"          //ͼ�β����
#include "clockwise.h"      //ͼ����ת��
//��������չ���͵ľ�����


//���캯��
CenterWidget::CenterWidget(int questions):questionMax(questions)
{
    layout=new QGridLayout(this);

    questionNum=1;//��ų�ʼ��Ϊ1
    qnum=new QLabel(QString("Question %1").arg(questionNum),this);
    layout->addWidget(qnum,0,0,1,1,Qt::AlignLeft);

    //��������µľ�����
    newQuestion();
    layout->addWidget(matrices,1,0);

    //�����ʱ��ʾ
    QHBoxLayout *buttom=new QHBoxLayout();
    showtime=new QLCDNumber(this);
    showtime->setSegmentStyle(QLCDNumber::Filled);
    buttom->addWidget(showtime);

    //������һ�ⰴťNext
    buttom->addSpacing(150);
    buttonNext=new QPushButton(QIcon("../images/next.png"),"Next",this);
    buttonNext->setMinimumSize(80,40);
    buttom->addWidget(buttonNext);
    connect(buttonNext,SIGNAL(clicked()),this,SLOT(nextMatrix()));

    layout->addLayout(buttom,2,0);

    //��ʱ����
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    time.start();
    timer->start(1000);
    update();
}

//������һ��������
void CenterWidget::nextMatrix()
{
    userAnswers.push_back(matrices->getUserAnswer());
    questionNum++;//��ż�1
    if(questionNum>questionMax){//�Ѵﵽ��������
        getResult();
        return;
    }
    //��ȥ�����еĵ�ǰ������
    layout->removeWidget(matrices);
    layout->removeWidget(qnum);
    delete matrices;
    delete qnum;
    //�ڴ����м�����һ��������
    newQuestion();

    qnum=new QLabel(QString("Question %1").arg(questionNum),this);
    layout->addWidget(qnum,0,0);
    layout->addWidget(matrices,1,0);
}

//��ʱˢ��
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

//�����������
void CenterWidget::setMaxNum(int max)
{
    questionMax=max;
}

//��ʾ���Խ��
void CenterWidget::getResult()
{
    delete timer;

    int count=0;
    std::string info;
    QMessageBox msg;//���Խ���Ի���
    QString str;
    std::ifstream infile("info.dat");
    //��������Ϣ
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

//��������µľ�����
void CenterWidget::newQuestion()
{

    //�������������
    QTime t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);

    int k=qrand()%4;
    switch(k){
    case 0:matrices=new Overlay();break;//ͼ�ε���
    case 1:matrices=new Portfolio();break;//ͼ�����
    case 2:matrices=new Split();break;//ͼ�β��
    case 3:matrices=new Clockwise();break;//ͼ����ת
    }
    //������ȷ��
    rightAnswers.push_back(matrices->getRightAnswer());
}
