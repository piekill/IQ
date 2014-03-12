#include "mainwindow.h"     //������ͷ�ļ�
#include "centerwidget.h"   //���봰�ڲ�ͷ�ļ�
#include <fstream>

//���캯��
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    createActions();
    createMenus();
    std::ifstream infile("info.dat");
    infile>>questions;
    center=new CenterWidget((questions<=0||questions>100)?10:questions);//���봰�ڲ���center
    infile.close();
    this->setCentralWidget(center);
    this->setMaximumSize(500,630);
    this->setMinimumSize(500,630);
}

//��������
MainWindow::~MainWindow()
{
    QFile::remove("info.dat");
}

//��������
void MainWindow::createActions()
{
    actionRetry=new QAction(tr("Retry"),this);
    connect(actionRetry,SIGNAL(triggered()),this,SLOT(reset()));
    actionExit=new QAction(tr("Exit"),this);
    connect(actionExit,SIGNAL(triggered()),this,SLOT(close()));
    actionAbout=new QAction(tr("About"),this);
    connect(actionAbout,SIGNAL(triggered()),this,SLOT(about()));
}


//�����˵�
void MainWindow::createMenus()
{
    menuFile=menuBar()->addMenu(tr("&File"));
    menuFile->addAction(actionRetry);
    menuFile->addAction(actionExit);
    menuHelp=menuBar()->addMenu(tr("&Help"));
    menuHelp->addAction(actionAbout);
}

//about�Ի���
void MainWindow::about()
{
    QMessageBox::about(this,tr("About IQ Test"),tr("Version 1.0"));
}

//���봰�ڲ�������
void MainWindow::reset()
{
    center=new CenterWidget((questions<=0||questions>100)?10:questions);
    this->setCentralWidget(center);
 }
