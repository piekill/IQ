/********************************************************************************
** Form generated from reading UI file 'logondlg.ui'
**
** Created: Mon Jan 25 13:14:06 2010
**      by: Qt User Interface Compiler version 4.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGONDLG_H
#define UI_LOGONDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_LogonDlg
{
public:
    QLabel *label_1;
    QGroupBox *groupBox_1;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_2;
    QLabel *label_3;
    QRadioButton *radioButton_1;
    QRadioButton *radioButton_2;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QComboBox *comboBox_1;
    QGroupBox *groupBox_4;
    QLabel *label_5;
    QSpinBox *ageBox;
    QGroupBox *groupBox_5;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QGroupBox *groupBox_6;
    QLabel *label_7;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QCommandLinkButton *commandLinkButton;

    void setupUi(QDialog *LogonDlg)
    {
        if (LogonDlg->objectName().isEmpty())
            LogonDlg->setObjectName(QString::fromUtf8("LogonDlg"));
        LogonDlg->resize(580, 420);
        label_1 = new QLabel(LogonDlg);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(10, 20, 594, 21));
        QFont font;
        font.setFamily(QString::fromUtf8("Cambria"));
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        label_1->setFont(font);
        groupBox_1 = new QGroupBox(LogonDlg);
        groupBox_1->setObjectName(QString::fromUtf8("groupBox_1"));
        groupBox_1->setGeometry(QRect(30, 80, 231, 41));
        label_2 = new QLabel(groupBox_1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 51, 24));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Cambria"));
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        lineEdit = new QLineEdit(groupBox_1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 10, 121, 20));
        groupBox_2 = new QGroupBox(LogonDlg);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 130, 231, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Cambria"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        groupBox_2->setFont(font2);
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 61, 24));
        label_3->setFont(font1);
        radioButton_1 = new QRadioButton(groupBox_2);
        radioButton_1->setObjectName(QString::fromUtf8("radioButton_1"));
        radioButton_1->setGeometry(QRect(80, 10, 54, 28));
        radioButton_1->setFont(font1);
        radioButton_2 = new QRadioButton(groupBox_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(140, 10, 81, 28));
        radioButton_2->setFont(font1);
        groupBox_3 = new QGroupBox(LogonDlg);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(30, 180, 231, 80));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 10, 141, 24));
        label_4->setFont(font1);
        comboBox_1 = new QComboBox(groupBox_3);
        comboBox_1->setObjectName(QString::fromUtf8("comboBox_1"));
        comboBox_1->setGeometry(QRect(10, 40, 211, 30));
        comboBox_1->setFont(font1);
        groupBox_4 = new QGroupBox(LogonDlg);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(30, 280, 231, 41));
        label_5 = new QLabel(groupBox_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 26, 24));
        label_5->setFont(font1);
        ageBox = new QSpinBox(groupBox_4);
        ageBox->setObjectName(QString::fromUtf8("ageBox"));
        ageBox->setGeometry(QRect(90, 10, 51, 22));
        ageBox->setMinimumSize(QSize(42, 0));
        ageBox->setValue(20);
        groupBox_5 = new QGroupBox(LogonDlg);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(300, 80, 251, 71));
        label_6 = new QLabel(groupBox_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(20, 10, 151, 24));
        label_6->setFont(font1);
        comboBox_2 = new QComboBox(groupBox_5);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(20, 40, 111, 22));
        groupBox_6 = new QGroupBox(LogonDlg);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(300, 170, 251, 151));
        label_7 = new QLabel(groupBox_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 10, 123, 24));
        label_7->setFont(font1);
        radioButton_3 = new QRadioButton(groupBox_6);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(20, 40, 134, 28));
        radioButton_3->setFont(font1);
        radioButton_3->setCheckable(true);
        radioButton_3->setChecked(true);
        radioButton_4 = new QRadioButton(groupBox_6);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(20, 70, 150, 28));
        radioButton_4->setFont(font1);
        radioButton_4->setCheckable(false);
        radioButton_5 = new QRadioButton(groupBox_6);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(20, 100, 119, 28));
        radioButton_5->setFont(font1);
        radioButton_5->setCheckable(false);
        commandLinkButton = new QCommandLinkButton(LogonDlg);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(300, 350, 141, 41));
        commandLinkButton->setFont(font);

        retranslateUi(LogonDlg);

        QMetaObject::connectSlotsByName(LogonDlg);
    } // setupUi

    void retranslateUi(QDialog *LogonDlg)
    {
        LogonDlg->setWindowTitle(QApplication::translate("LogonDlg", "IQ Test", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_1->setToolTip(QApplication::translate("LogonDlg", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">Please input your basic information before the test</span></p></body></html>", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_1->setText(QApplication::translate("LogonDlg", "Please input your basic information before the test! ", 0, QApplication::UnicodeUTF8));
        groupBox_1->setTitle(QString());
        label_2->setText(QApplication::translate("LogonDlg", "Name", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QString());
        label_3->setText(QApplication::translate("LogonDlg", "Gender", 0, QApplication::UnicodeUTF8));
        radioButton_1->setText(QApplication::translate("LogonDlg", "Male", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("LogonDlg", "Female", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QString());
        label_4->setText(QApplication::translate("LogonDlg", "Degree of Education", 0, QApplication::UnicodeUTF8));
        comboBox_1->clear();
        comboBox_1->insertItems(0, QStringList()
         << QApplication::translate("LogonDlg", "Primary School and Below", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LogonDlg", "Junier School", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LogonDlg", "Senier School", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LogonDlg", "Bachelor", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LogonDlg", "Master", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LogonDlg", "PhD and Above", 0, QApplication::UnicodeUTF8)
        );
        groupBox_4->setTitle(QString());
        label_5->setText(QApplication::translate("LogonDlg", "Age", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QString());
        label_6->setText(QApplication::translate("LogonDlg", "Number of Questions", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("LogonDlg", "10", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LogonDlg", "20", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LogonDlg", "30", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LogonDlg", "40", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("LogonDlg", "50", 0, QApplication::UnicodeUTF8)
        );
        groupBox_6->setTitle(QString());
        label_7->setText(QApplication::translate("LogonDlg", "Kind of Questions", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("LogonDlg", "Matrix Question", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("LogonDlg", "Sequence Question", 0, QApplication::UnicodeUTF8));
        radioButton_5->setText(QApplication::translate("LogonDlg", "Both of Above", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setText(QApplication::translate("LogonDlg", "Go to Test", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LogonDlg: public Ui_LogonDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGONDLG_H
