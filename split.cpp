#include "Split.h"

Split::Split()
{
    Matrices::init();     //ʹ�ø����еĳ�ʼ������
    setAll();
    Matrices::setUi();
}

//��������������

void Split::setAll()
{
    //��ʼ��������ͼ
    QTime t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    int k;
    int m,n;
    m=qrand()%3;                     //mָ���ֺ�ڶ���ͼ�м����ͼ��
    for(int i=0;i<9;i+=3){
        if(graphs[i]->objectNum()<3)                //��һ����ͼ�������������������һ��ͼ��
        {   k=qrand()%3;
            switch(k){                                //���ѡ����ϵ�ͼ��
                  case 0:graphs[i]->addObject(Triangle());break;
                  case 1:graphs[i]->addObject(Rectangle());break;
                  case 2:graphs[i]->addObject(Line());break;
                }
            }
       else if(graphs[i]->objectNum()>3)            //����3������ɾȥ�����ӵ�ͼ��
            graphs[i]->popObject();
        graphs[i+1]=new ChildGraph;
        graphs[i+1]->addObject(graphs[i]->getObject(m));    //���ѡ��һ����һ���е�ͼ�μ��뵽��Ӧ�ĵڶ�����
        graphs[i+2]=new ChildGraph;
       for(n=0;n<3;n++)
        {if(n!=m)
             graphs[i+2]->addObject(graphs[i]->getObject(n)); //��ʣ�µ�ͼ����ӵ���������
       }

    }
    for(int i=0;i<9;i+=3)                               //��ÿ��ͼ���Ϲ���
    {
        graphs[i]->addRule(new Translation());
        graphs[i]->addRule(new Translation(50,50));
        graphs[i]->addRule(new Translation(0,50));
        switch(m){                                          //���ѡ����ϵĹ���
        case 0:graphs[i+1]->addRule(new Translation());graphs[i+2]->addRule(new Translation(50,50));graphs[i+2]->addRule(new Translation(0,50));break;
        case 1:graphs[i+1]->addRule(new Translation(50,50));graphs[i+2]->addRule(new Translation());graphs[i+2]->addRule(new Translation(0,50));break;
        case 2:graphs[i+1]->addRule(new Translation(0,50));graphs[i+2]->addRule(new Translation());graphs[i+2]->addRule(new Translation(50,50));break;
        }
    }
    Matrices::chooseAnswer();   //���������ȷ��
    for(int i=0;i<4;i++)        //��������������ѡ��
    {
        QTime t=QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        if(i!=answer-1){         //����iֵ��Ӧ�Ĵ𰸲�����ȷ�𰸴��λ��ʱ�Ĳ���
            choices[i]=new ChildGraph;
            switch(qrand()%3){
            case 0:choices[i]->addObject(graphs[i]->getObject(0));
                   choices[i]->addRule(new Translation());
                   choices[i]->addObject(graphs[i]->getObject(1));
                  choices[i]->addRule(new Translation(50,0));
                  choices[i]->addObject(graphs[i]->getObject(2));
                 choices[i]->addRule(new Translation(0,50));

                   break;
            case 1:choices[i]->addObject(graphs[i]->getObject(0));
                  choices[i]->addRule(new Translation());
                   choices[i]->addObject(graphs[i]->getObject(1));
                   choices[i]->addRule(new Translation(50,0));
                   choices[i]->addObject(graphs[i]->getObject(2));
                   choices[i]->addRule(new Translation(50,50));
                   break;
            case 2:choices[i]->addObject(graphs[i]->getObject(0));
                   choices[i]->addRule(new Translation());
                   choices[i]->addObject(graphs[i]->getObject(1));
                   choices[i]->addRule(new Translation(0,50));
                   choices[i]->addObject(graphs[i]->getObject(2));
                  choices[i]->addRule(new Translation(50,50));
                   break;
            }
        }
    }
}

