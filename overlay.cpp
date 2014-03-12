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
    //初始化第一列
    for(int i=0;i<3;i++){
        ChildGraph *temp=new ChildGraph;
        for(int j=0;j<qrand()%2+2;j++){
            int k=qrand()%3;
            switch(k){
            case 0:temp->addObject(Triangle());break;   //三角形
            case 1:temp->addObject(Rectangle());break;  //矩形
            case 2:temp->addObject(Line());break;       //线段
            //其他待扩展的图形
            }
        }
        graphs[3*i]=temp;
    }
    //初始化第二列
    for(int i=0;i<3;i++){
        ChildGraph *temp=new ChildGraph;
        for(int j=0;j<qrand()%2+2;j++){
            int k=qrand()%3;
            switch(k){
            case 0:temp->addObject(Triangle());break;   //三角形
            case 1:temp->addObject(Rectangle());break;  //矩形
            case 2:temp->addObject(Line());break;       //线段
            //其他待扩展的图形
            }
        }
        graphs[3*i+1]=temp;
    }

}

//生成图形叠加类的题
void Overlay::setAll()
{
    //为每个子图添加图形对象
    for(int i=0;i<9;i+=3)
    {
        //第一列
        if(graphs[i]->objectNum()<2)//当子图中的图形少于2个时，添加一个图形
            graphs[i]->addObject(Triangle());
        else if(graphs[i]->objectNum()>2)//当子图中图形多于2个时，删去一个图形
        {
            for(int j=graphs[i]->objectNum();j>2;j--)
                graphs[i]->popObject();
        }
        //第二列
        if(graphs[i+1]->objectNum()<1)
            graphs[i+1]->addObject(Rectangle());
        else if(graphs[i+1]->objectNum()>1)
        {
            for(int j=graphs[i+1]->objectNum();j>1;j--)
                graphs[i+1]->popObject();
        }
        //QMessageBox msg;msg.setText("OK!");msg.exec();
        //第三列
        graphs[i+2]=new ChildGraph();
        graphs[i+2]->addObject(graphs[i]->getObject(0));
        graphs[i+2]->addObject(graphs[i]->getObject(1));
        graphs[i+2]->addObject(graphs[i+1]->getObject(0));
    }

    //施加变换规则
    for(int i=0;i<9;i+=3)
    {
        //第一列
        graphs[i]->addRule(new Rule());                 //图形不动
        graphs[i]->addRule(new Translation(55,55));      //图形起始点平移至(0,55)
        //第二列
        graphs[i+1]->addRule(new Translation(0,55));
        //第三列
        graphs[i+2]->addRule(new Rule());
        graphs[i+2]->addRule(new Translation(55,55));
        graphs[i+2]->addRule(new Translation(0,55));
    }

    //生成备选答案
    Matrices::chooseAnswer();   //随机放置正确答案
    QTime t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);

    for(int i=0;i<4;i++)        //生成另外三个备选答案
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

