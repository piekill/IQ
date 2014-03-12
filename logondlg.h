#ifndef LOGONDLG_H
#define LOGONDLG_H

#include <QtGui/QDialog>

//登录界面对话框
namespace Ui {
    class LogonDlg;
}

class LogonDlg : public QDialog {
    Q_OBJECT
public:
    LogonDlg(QWidget *parent = 0);
    ~LogonDlg();

protected:
    void changeEvent(QEvent *e);

private slots:
    void saveInfo();

private:
    Ui::LogonDlg *m_ui;
    int Gen;
    int kind;
    bool isIntegrate();
};

#endif // LOGONDLG_H
