#ifndef CENTERWIDGET_H
#define CENTERWIDGET_H

#include <QWidget>
#include <QVector>
#include "matrices.h"   //�������ͷ�ļ�

//���봰�ڲ�����CenterWidget���̳�QWidget
class CenterWidget : public QWidget
{
    Q_OBJECT
public:
    CenterWidget(int questions); //���캯��
    void setMaxNum(int max); //�����������
    void getResult(); //�ó����Խ��
private slots:
    void nextMatrix(); //ת����һ������
    void update(); //����ʱ
private:
    Matrices *matrices; //������matrices
    QLabel *qnum; //��ű�ǩ
    QTimer *timer; //ʱ������
    QTime time;
    QPushButton *buttonNext; //��һ�ⰴťbuttonNext
    QLCDNumber *showtime;
    QGridLayout *layout; //���ֹ�����
    int questionNum;  //���
    int questionMax; //�������
    QVector<int> rightAnswers; //��ȷ��
    QVector<int> userAnswers; //�����ߴ�
    void newQuestion(); //��������µľ�����
};

#endif // CENTERWIDGET_H
