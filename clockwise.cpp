#include "Clockwise.h"

//ͼ����ת�任�����캯��
Clockwise::Clockwise()
{
    Matrices::init();
    setAll();
    Matrices::setUi();
}

//����ͼ����ת�����
void Clockwise::setAll()
{
    //Ϊÿ����ͼ���ͼ�ζ���
    for(int i=0;i<9;i+=3)
    {
        //��һ��
        if(graphs[i]->objectNum()<1)//����ͼ�е�ͼ������1��ʱ�����һ��ͼ��
            graphs[i]->addObject(Triangle());
        else if(graphs[i]->objectNum()>1)//����ͼ��ͼ�ζ���1��ʱ��ɾȥһ��ͼ��
        {
            for(int j=graphs[i]->objectNum();j>1;j--)
                graphs[i]->popObject();
        }

        //������
        graphs[i+1]=new ChildGraph();
        graphs[i+1]->addObject(graphs[i]->getObject(0));
        //������
        graphs[i+2]=new ChildGraph();
        graphs[i+2]->addObject(graphs[i]->getObject(0));

    }

    //ʩ�ӱ任����
    for(int i=0;i<9;i+=3)
    {
        //��һ��
        graphs[i]->addRule(new Translation(30,30));
        //�ڶ���
        graphs[i+1]->addRule(new TransRotation(50,5,30));   //ƽ������(35,35),��ת�Ƕ�30��
        //������
        graphs[i+2]->addRule(new TransRotation(60,-10,45));   //ƽ������(35,35),��ת�Ƕ�45��

    }

    //���ɱ�ѡ��
    Matrices::chooseAnswer();   //���������ȷ��
    QTime t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);

    for(int i=0;i<4;i++)        //��������������ѡ��
    {
        int errans=qrand()%3;
        if(i!=answer-1){
            choices[i]=new ChildGraph;
            switch(errans){
            case 0:
                choices[i]->addObject(Triangle());
                choices[i]->addRule(new Translation(55,55));
                break;
            case 1:
                choices[i]->addObject(Line());
                choices[i]->addRule(new Translation(0,55));
                break;
            case 2:
                choices[i]->addObject(Rectangle());
                choices[i]->addRule(new Translation(55,0));
                break;

            }
        }
    }

}


