#include <QtGui/QApplication>
#include "mainwindow.h"//������
#include "logondlg.h"//��¼�Ի���


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
