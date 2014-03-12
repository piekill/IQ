#ifndef MATRICES_H
#define MATRICES_H
#include <QVector>
#include <QtGui>
#include "childgraph.h"//��ͼ��ͷ�ļ�

//�����࣬�Ǹ�����������ĸ���
class Matrices : public QWidget
{
    Q_OBJECT
public:
    Matrices();
    int getRightAnswer()const{return answer;}//��ȡ��ȷ��
    int getUserAnswer()const;//��ȡ�����ߴ�
protected:
    void init();//�������ʼ��
    void setAll();//���������ľ�����
    void setUi(); //��������
    void chooseAnswer();//���������ȷ��

    enum{AreaNum = 3};//��������
    ChildGraph *graphs[AreaNum*AreaNum];//�������������ͼ��9����
    ChildGraph *choices[AreaNum+1]; //��ѡ�𰸵���ͼ��4����
    QRadioButton *choice[AreaNum+1];//��ѡ�𰸵�4����ѡ��ť
    QGridLayout *layout;
    int answer;//��ȷ��
};

#endif // MATRICES_H
