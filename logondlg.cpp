#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "logondlg.h"
#include "ui_logondlg.h"

//µÇÂ¼¶Ô»°¿ò
LogonDlg::LogonDlg(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::LogonDlg)
{
    m_ui->setupUi(this);
    connect(m_ui->commandLinkButton,SIGNAL(clicked()),this,SLOT(saveInfo()));
}

LogonDlg::~LogonDlg()
{
    delete m_ui;
}

void LogonDlg::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void LogonDlg::saveInfo()
{
    if(!isIntegrate())
    {
        QMessageBox::warning(this,"IQ Test","Please complete you infomation.");
        return;
    }
    if (m_ui->radioButton_1->isChecked()) {
            Gen=0;
        } else if (m_ui->radioButton_2->isChecked()) {
            Gen=1;
        }
   if (m_ui->radioButton_3->isChecked()) {
            kind=0;
        } else if(m_ui->radioButton_4->isChecked()){
            kind=1;
        }else if(m_ui->radioButton_5->isChecked()){
            kind=2;
        }
   QFile file("info.dat");
   if(!file.open(QIODevice::WriteOnly)){
       return;
   }
   QTextStream outfile(&file);
   outfile<<m_ui->comboBox_2->currentText().toInt()<<"\r\n"
              <<kind<<"\r\n"
              <<m_ui->lineEdit->text()<<"\r\n"
              <<m_ui->ageBox->value()<<"\r\n"
              <<Gen<<"\r\n"
              <<m_ui->comboBox_1->currentText();
   outfile.flush();
   file.close();
   QDialog::accept();
}

bool LogonDlg::isIntegrate()
{
    if(m_ui->lineEdit->text()=="")
        return false;
    if(!m_ui->radioButton_1->isChecked()&&!m_ui->radioButton_2->isChecked())
        return false;
    //if(!m_ui->radioButton_3->isChecked()&&!m_ui->radioButton_4->isChecked()
     //                                                                   &&!m_ui->radioButton_5>isChecked())
        //return false;
    return true;
}
