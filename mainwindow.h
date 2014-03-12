#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "centerwidget.h"//中央窗口部件的头文件
#include <QtGui/QMainWindow>

//主窗口类，继承QMainWindow
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);//构造
    ~MainWindow(); //析构
private slots:
    void about();
    void reset();
private:
    QMenu *menuFile;//菜单File
    QMenu *menuHelp;//菜单Help
    QAction *actionRetry; //Retry按钮事件
    QAction *actionExit; //Exit按钮事件
    QAction *actionAbout; //About按钮事件
    CenterWidget *center; //中央窗口部件center
    int questions;

    void createActions();//创建动作
     void createMenus();//创建菜单
};

#endif // MAINWINDOW_H
