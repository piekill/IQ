#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "centerwidget.h"//���봰�ڲ�����ͷ�ļ�
#include <QtGui/QMainWindow>

//�������࣬�̳�QMainWindow
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);//����
    ~MainWindow(); //����
private slots:
    void about();
    void reset();
private:
    QMenu *menuFile;//�˵�File
    QMenu *menuHelp;//�˵�Help
    QAction *actionRetry; //Retry��ť�¼�
    QAction *actionExit; //Exit��ť�¼�
    QAction *actionAbout; //About��ť�¼�
    CenterWidget *center; //���봰�ڲ���center
    int questions;

    void createActions();//��������
     void createMenus();//�����˵�
};

#endif // MAINWINDOW_H
