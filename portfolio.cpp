#include "Portfolio.h"

Portfolio::Portfolio()
{
    init();
    setAll();
    Matrices::setUi();
}

void Portfolio::init()
{
    QTime t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    //��ʼ����һ��
    for(int i=0;i<3;i++){
        ChildGraph *temp=new ChildGraph;
        for(int j=0;j<qrand()%2+2;j++){
            int k=qrand()%3;
            switch(k){
            case 0:temp->addObject(Triangle());break;   //������
            case 1:temp->addObject(Rectangle());break;  //����
            case 2:temp->addObject(Line());break;       //�߶�
            //��������չ��ͼ��
            }
        }
        graphs[3*i]=temp;
    }
    //��ʼ���ڶ���
    for(int i=0;i<3;i++){
        ChildGraph *temp=new ChildGraph;
        for(int j=0;j<qrand()%2+2;j++){
            int k=qrand()%3;
            switch(k){
            case 0:temp->addObject(Triangle());break;   //������
            case 1:temp->addObject(Rectangle());break;  //����
            case 2:temp->addObject(Line());break;       //�߶�
            //��������չ��ͼ��
            }
        }
        graphs[3*i+1]=temp;
    }
    //��ʼ��������
    for(int i=0;i<3;i++){
        ChildGraph *temp=new ChildGraph;
        for(int j=0;j<qrand()%2+2;j++){
            int k=qrand()%3;
            switch(k){
            case 0:temp->addObject(Triangle());break;   //������
            case 1:temp->addObject(Rectangle());break;  //����
            case 2:temp->addObject(Line());break;       //�߶�
            //��������չ��ͼ��
            }
        }
        graphs[3*i+2]=temp;
    }

}


//����ͼ����������
void Portfolio::setAll()
{
    //Ϊÿ����ͼ���ͼ�ζ���
    for(int i=0;i<9;i+=3)
    {
        //�ڶ���
        if(graphs[i+1]->objectNum()<1)
            graphs[i+1]->addObject(Rectangle());
        else if(graphs[i+1]->objectNum()>1)
        {
            for(int j=graphs[i+1]->objectNum();j>1;j--)
                graphs[i+1]->popObject();
        }
        //��һ��
        if(graphs[i]->objectNum()<1)//����ͼ�е�ͼ������1��ʱ��������һ��ͼ��
            graphs[i]->addObject(Triangle());
        else if(graphs[i]->objectNum()>1)//����ͼ��ͼ�ζ���1��ʱ��ɾȥһ��ͼ��
        {
            for(int j=graphs[i]->objectNum();j>1;j--)
                graphs[i]->popObject();
        }
        graphs[i]->addObject(graphs[i+1]->getObject(0));

        //QMessageBox msg;msg.setText("OK!");msg.exec();
        //������
        if(graphs[i+2]->objectNum()<1)//����ͼ�е�ͼ������1��ʱ��������һ��ͼ��
            graphs[i+2]->addObject(Line());
        else if(graphs[i+2]->objectNum()>1)//����ͼ��ͼ�ζ���1��ʱ��ɾȥһ��ͼ��
        {
            for(int j=graphs[i+2]->objectNum();j>1;j--)
                graphs[i+2]->popObject();
        }
        graphs[i+2]->addObject(graphs[i+1]->getObject(0));
    }

    //ʩ�ӱ任����
    for(int i=0;i<9;i+=3)
    {
        //�ڶ���
        graphs[i+1]->addRule(new Rule());                 //ͼ�β���
        //��һ��
        graphs[i]->addRule(new Translation(55,55));   //ͼ����ʼ��ƽ����(55,55)
        graphs[i]->addRule(new Rule());                 //ͼ�β���
        //������
        graphs[i+2]->addRule(new Translation(55,55));   //ͼ����ʼ��ƽ����(55,55)
        graphs[i+2]->addRule(new Rule());                 //ͼ�β���
    }

    //���ɱ�ѡ��
    Matrices::chooseAnswer();   //���������ȷ��
    for(int i=0;i<4;i++)        //��������������ѡ��
    {
        QTime t=QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        if(i!=answer-1){
            choices[i]=new ChildGraph;
            switch(i){
            case 0:
                choices[i]->addObject(Triangle());
                choices[i]->addRule(new Translation(10,10));break;
            case 1:
                choices[i]->addObject(Rectangle());
                choices[i]->addRule(new Translation(20,20));break;
            case 2:;
                choices[i]->addObject(Line());
                choices[i]->addRule(new Translation(30,30));break;
            case 3:;
                choices[i]->addObject(Triangle());choices[i]->addObject(Line());
                choices[i]->addRule(new Rule());break;
            }
        }
    }

}

