#include "Split.h"

Split::Split()
{
    Matrices::init();     //使用父类中的初始化函数
    setAll();
    Matrices::setUi();
}

//生成整个矩阵题

void Split::setAll()
{
    //初始化三列子图
    QTime t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    int k;
    int m,n;
    m=qrand()%3;                     //m指向拆分后第二列图中加入的图形
    for(int i=0;i<9;i+=3){
        if(graphs[i]->objectNum()<3)                //第一列中图形数少于三则随机加上一个图形
        {   k=qrand()%3;
            switch(k){                                //随机选择加上的图形
                  case 0:graphs[i]->addObject(Triangle());break;
                  case 1:graphs[i]->addObject(Rectangle());break;
                  case 2:graphs[i]->addObject(Line());break;
                }
            }
       else if(graphs[i]->objectNum()>3)            //多于3个，则删去最后添加的图形
            graphs[i]->popObject();
        graphs[i+1]=new ChildGraph;
        graphs[i+1]->addObject(graphs[i]->getObject(m));    //随机选择一个第一列中的图形加入到相应的第二列中
        graphs[i+2]=new ChildGraph;
       for(n=0;n<3;n++)
        {if(n!=m)
             graphs[i+2]->addObject(graphs[i]->getObject(n)); //将剩下的图形添加到第三列中
       }

    }
    for(int i=0;i<9;i+=3)                               //给每个图加上规则
    {
        graphs[i]->addRule(new Translation());
        graphs[i]->addRule(new Translation(50,50));
        graphs[i]->addRule(new Translation(0,50));
        switch(m){                                          //随机选择加上的规则
        case 0:graphs[i+1]->addRule(new Translation());graphs[i+2]->addRule(new Translation(50,50));graphs[i+2]->addRule(new Translation(0,50));break;
        case 1:graphs[i+1]->addRule(new Translation(50,50));graphs[i+2]->addRule(new Translation());graphs[i+2]->addRule(new Translation(0,50));break;
        case 2:graphs[i+1]->addRule(new Translation(0,50));graphs[i+2]->addRule(new Translation());graphs[i+2]->addRule(new Translation(50,50));break;
        }
    }
    Matrices::chooseAnswer();   //随机放置正确答案
    for(int i=0;i<4;i++)        //生成另外三个备选答案
    {
        QTime t=QTime::currentTime();
        qsrand(t.msec()+t.second()*1000);
        if(i!=answer-1){         //当该i值对应的答案不是正确答案存放位置时的操作
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

