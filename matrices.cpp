#include <QtGui>
#include <QVector>
#include "matrices.h"       //������
#include "childgraph.h"     //��ͼ��
#include "object.h"         //ͼ����
#include "rule.h"           //����������

Matrices::Matrices()
{
}

//�����ʼ��
void Matrices::init()
{
     //����ϵͳʱ���������������
    QTime t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);

    //��ʼ����һ��
    for(int i=0;i<3;i++){
        ChildGraph *temp=new ChildGraph;
        for(int j=0;j<qrand()%2+2;j++){
            int k=qrand()%3;
            switch(k){
                case 0:temp->addObject(Triangle());break;
                case 1:temp->addObject(Rectangle());break;
                case 2:temp->addObject(Line());break;
                    //��������չ��ͼ��
                }
        }
       graphs[3*i]=temp;
    }
}

//�����������
void Matrices::setUi()
{
    layout = new QGridLayout;

    //����9��������ͼ
    for(int i=0;i<8;i++)
        layout->addWidget(graphs[i],i/3,i%3);
    layout->addWidget(new ChildGraph(),2,2);
    layout->addWidget(new QLabel("Choose your Answer:"),3,0,1,3,Qt::AlignLeft);

    //����4����ѡ����ͼ
    for(int i=0;i<=AreaNum;i++)
    {
        layout->addWidget(choices[i],4,i);
    }

    //����4����ѡ��ť
    choice[0]=new QRadioButton("A");
    choice[1]=new QRadioButton("B");
    choice[2]=new QRadioButton("C");
    choice[3]=new QRadioButton("D");
    for(int i=0;i<=AreaNum;i++)
    layout->addWidget(choice[i],5,i);

    setLayout(layout);
}

//���ɸ������ľ�����
void Matrices::setAll()
{
}


//���������ȷ��
void Matrices::chooseAnswer()
{
    QTime t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    answer=qrand()%4+1;
    choices[answer-1]=graphs[8];//��ȷ��graphs[8]���������choices��
}

//��ȡ�����ߴ�
int Matrices::getUserAnswer()const
{
    for(int i=0;i<4;i++)
        if(choice[i]->isChecked())
            return i+1;
    return 0;
}
