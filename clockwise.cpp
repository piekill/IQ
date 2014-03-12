#include "Clockwise.h"

//图形旋转变换，构造函数
Clockwise::Clockwise()
{
    Matrices::init();
    setAll();
    Matrices::setUi();
}

//生成图形旋转类的题
void Clockwise::setAll()
{
    //为每个子图添加图形对象
    for(int i=0;i<9;i+=3)
    {
        //第一列
        if(graphs[i]->objectNum()<1)//当子图中的图形少于1个时，添加一个图形
            graphs[i]->addObject(Triangle());
        else if(graphs[i]->objectNum()>1)//当子图中图形多于1个时，删去一个图形
        {
            for(int j=graphs[i]->objectNum();j>1;j--)
                graphs[i]->popObject();
        }

        //第三列
        graphs[i+1]=new ChildGraph();
        graphs[i+1]->addObject(graphs[i]->getObject(0));
        //第三列
        graphs[i+2]=new ChildGraph();
        graphs[i+2]->addObject(graphs[i]->getObject(0));

    }

    //施加变换规则
    for(int i=0;i<9;i+=3)
    {
        //第一列
        graphs[i]->addRule(new Translation(30,30));
        //第二列
        graphs[i+1]->addRule(new TransRotation(50,5,30));   //平移向量(35,35),旋转角度30°
        //第三列
        graphs[i+2]->addRule(new TransRotation(60,-10,45));   //平移向量(35,35),旋转角度45°

    }

    //生成备选答案
    Matrices::chooseAnswer();   //随机放置正确答案
    QTime t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);

    for(int i=0;i<4;i++)        //生成另外三个备选答案
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


