#include <QtGui/QApplication>
#include "mainwindow.h"//主窗口
#include "logondlg.h"//登录对话框


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LogonDlg log;
    if(log.exec()==QDialog::Accepted)
    {
        MainWindow w;
        w.show();
        return a.exec();
    }
    else return 0;
}
