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
    //初始化第三列
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
        graphs[3*i+2]=temp;
    }

}


//生成图形组合类的题
void Portfolio::setAll()
{
    //为每个子图添加图形对象
    for(int i=0;i<9;i+=3)
    {
        //第二列
        if(graphs[i+1]->objectNum()<1)
            graphs[i+1]->addObject(Rectangle());
        else if(graphs[i+1]->objectNum()>1)
        {
            for(int j=graphs[i+1]->objectNum();j>1;j--)
                graphs[i+1]->popObject();
        }
        //第一列
        if(graphs[i]->objectNum()<1)//当子图中的图形少于1个时，随机添加一个图形
            graphs[i]->addObject(Triangle());
        else if(graphs[i]->objectNum()>1)//当子图中图形多于1个时，删去一个图形
        {
            for(int j=graphs[i]->objectNum();j>1;j--)
                graphs[i]->popObject();
        }
        graphs[i]->addObject(graphs[i+1]->getObject(0));

        //QMessageBox msg;msg.setText("OK!");msg.exec();
        //第三列
        if(graphs[i+2]->objectNum()<1)//当子图中的图形少于1个时，随机添加一个图形
            graphs[i+2]->addObject(Line());
        else if(graphs[i+2]->objectNum()>1)//当子图中图形多于1个时，删去一个图形
        {
            for(int j=graphs[i+2]->objectNum();j>1;j--)
                graphs[i+2]->popObject();
        }
        graphs[i+2]->addObject(graphs[i+1]->getObject(0));
    }

    //施加变换规则
    for(int i=0;i<9;i+=3)
    {
        //第二列
        graphs[i+1]->addRule(new Rule());                 //图形不动
        //第一列
        graphs[i]->addRule(new Translation(55,55));   //图形起始点平移至(55,55)
        graphs[i]->addRule(new Rule());                 //图形不动
        //第三列
        graphs[i+2]->addRule(new Translation(55,55));   //图形起始点平移至(55,55)
        graphs[i+2]->addRule(new Rule());                 //图形不动
    }

    //生成备选答案
    Matrices::chooseAnswer();   //随机放置正确答案
    for(int i=0;i<4;i++)        //生成另外三个备选答案
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

