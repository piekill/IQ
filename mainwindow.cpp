#include "mainwindow.h"     //主窗口头文件
#include "centerwidget.h"   //中央窗口部头文件
#include <fstream>

//构造函数
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();
    std::ifstream infile("info.dat");
    infile>>questions;
    center=new CenterWidget((questions<=0||questions>100)?10:questions);//中央窗口部件center
    infile.close();
    this->setCentralWidget(center);
    this->setMaximumSize(500,630);
    this->setMinimumSize(500,630);
}

//析构函数
MainWindow::~MainWindow()
{
    QFile::remove("info.dat");
}

//创建动作
void MainWindow::createActions()
{
    actionRetry=new QAction(tr("Retry"),this);
    connect(actionRetry,SIGNAL(triggered()),this,SLOT(reset()));
    actionExit=new QAction(tr("Exit"),this);
    connect(actionExit,SIGNAL(triggered()),this,SLOT(close()));
    actionAbout=new QAction(tr("About"),this);
    connect(actionAbout,SIGNAL(triggered()),this,SLOT(about()));
}


//创建菜单
void MainWindow::createMenus()
{
    menuFile=menuBar()->addMenu(tr("&File"));
    menuFile->addAction(actionRetry);
    menuFile->addAction(actionExit);
    menuHelp=menuBar()->addMenu(tr("&Help"));
    menuHelp->addAction(actionAbout);
}

//about对话框
void MainWindow::about()
{
    QMessageBox::about(this,tr("About IQ Test"),tr("Version 1.0"));
}

//中央窗口部件重置
void MainWindow::reset()
{
    center=new CenterWidget((questions<=0||questions>100)?10:questions);
    this->setCentralWidget(center);
 }
