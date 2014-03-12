#include "Overlay.h"

Overlay::Overlay()
{
    init();
    setAll();
    Matrices::setUi();
}

void Overlay::init()
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

}

//����ͼ�ε��������
void Overlay::setAll()
{
    //Ϊÿ����ͼ���ͼ�ζ���
    for(int i=0;i<9;i+=3)
    {
        //��һ��
        if(graphs[i]->objectNum()<2)//����ͼ�е�ͼ������2��ʱ�����һ��ͼ��
            graphs[i]->addObject(Triangle());
        else if(graphs[i]->objectNum()>2)//����ͼ��ͼ�ζ���2��ʱ��ɾȥһ��ͼ��
        {
            for(int j=graphs[i]->objectNum();j>2;j--)
                graphs[i]->popObject();
        }
        //�ڶ���
        if(graphs[i+1]->objectNum()<1)
            graphs[i+1]->addObject(Rectangle());
        else if(graphs[i+1]->objectNum()>1)
        {
            for(int j=graphs[i+1]->objectNum();j>1;j--)
                graphs[i+1]->popObject();
        }
        //QMessageBox msg;msg.setText("OK!");msg.exec();
        //������
        graphs[i+2]=new ChildGraph();
        graphs[i+2]->addObject(graphs[i]->getObject(0));
        graphs[i+2]->addObject(graphs[i]->getObject(1));
        graphs[i+2]->addObject(graphs[i+1]->getObject(0));
    }

    //ʩ�ӱ任����
    for(int i=0;i<9;i+=3)
    {
        //��һ��
        graphs[i]->addRule(new Rule());                 //ͼ�β���
        graphs[i]->addRule(new Translation(55,55));      //ͼ����ʼ��ƽ����(0,55)
        //�ڶ���
        graphs[i+1]->addRule(new Translation(0,55));
        //������
        graphs[i+2]->addRule(new Rule());
        graphs[i+2]->addRule(new Translation(55,55));
        graphs[i+2]->addRule(new Translation(0,55));
    }

    //���ɱ�ѡ��
    Matrices::chooseAnswer();   //���������ȷ��
    QTime t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);

    for(int i=0;i<4;i++)        //��������������ѡ��
    {
        int errans=qrand()%4;
        if(i!=answer-1){
            choices[i]=new ChildGraph;
            switch(errans){
            case 0:
                choices[i]->addObject(Triangle());
                choices[i]->addObject(Line());
                choices[i]->addObject(Rectangle());
                choices[i]->addRule(new Rule());choices[i]->addRule(new Rule());
                choices[i]->addRule(new Translation(55,55));
                break;
            case 1:
                choices[i]->addObject(Rectangle());
                choices[i]->addObject(Line());
                choices[i]->addObject(Triangle());
                choices[i]->addRule(new Rule());
                choices[i]->addRule(new Translation(0,55));
                choices[i]->addRule(new Translation(55,0));
                break;
            case 2:
                choices[i]->addObject(Rectangle());
                choices[i]->addObject(Triangle());
                choices[i]->addObject(Rectangle());
                choices[i]->addRule(new Translation(55,0));
                choices[i]->addRule(new Rule());
                choices[i]->addRule(new Translation(55,55));
                break;
            case 3:
                choices[i]->addObject(Triangle());
                choices[i]->addObject(Rectangle());
                choices[i]->addObject(Triangle());
                choices[i]->addRule(new Translation(55,0));
                choices[i]->addRule(new Rule());
                choices[i]->addRule(new Translation(55,55));
                break;

            }
        }
    }

}

