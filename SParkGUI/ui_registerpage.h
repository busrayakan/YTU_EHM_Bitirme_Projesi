/********************************************************************************
** Form generated from reading UI file 'registerpage.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERPAGE_H
#define UI_REGISTERPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterPage
{
public:
    QWidget *centralwidget;
    QLineEdit *lineEdit_isim;
    QLabel *label_4;
    QLineEdit *lineEdit_username;
    QLineEdit *lineEdit_sifre;
    QLabel *label_5;
    QLineEdit *lineEdit_telno;
    QLineEdit *lineEdit_email;
    QPushButton *pushButtonBack;
    QLabel *label_3;
    QLabel *label;
    QLineEdit *lineEdit_plaka;
    QPushButton *pushButtonKayit;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_pic;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RegisterPage)
    {
        if (RegisterPage->objectName().isEmpty())
            RegisterPage->setObjectName("RegisterPage");
        RegisterPage->resize(420, 800);
        centralwidget = new QWidget(RegisterPage);
        centralwidget->setObjectName("centralwidget");
        lineEdit_isim = new QLineEdit(centralwidget);
        lineEdit_isim->setObjectName("lineEdit_isim");
        lineEdit_isim->setGeometry(QRect(225, 185, 145, 25));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 310, 101, 17));
        label_4->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-weight: bold;\n"
"color:rgb(43, 0, 108);\n"
"}"));
        lineEdit_username = new QLineEdit(centralwidget);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(225, 305, 145, 25));
        lineEdit_sifre = new QLineEdit(centralwidget);
        lineEdit_sifre->setObjectName("lineEdit_sifre");
        lineEdit_sifre->setGeometry(QRect(225, 345, 145, 25));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 350, 66, 17));
        label_5->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-weight: bold;\n"
"color:rgb(43, 0, 108);\n"
"}"));
        lineEdit_telno = new QLineEdit(centralwidget);
        lineEdit_telno->setObjectName("lineEdit_telno");
        lineEdit_telno->setGeometry(QRect(225, 265, 145, 25));
        lineEdit_email = new QLineEdit(centralwidget);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(225, 225, 145, 25));
        pushButtonBack = new QPushButton(centralwidget);
        pushButtonBack->setObjectName("pushButtonBack");
        pushButtonBack->setGeometry(QRect(60, 430, 145, 25));
        pushButtonBack->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(170, 170, 0);\n"
"	border-width: 2px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(170, 170, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"\n"
"}"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 270, 115, 17));
        label_3->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-weight: bold;\n"
"color:rgb(43, 0, 108);\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 190, 111, 20));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-weight: bold;\n"
"color:rgb(43, 0, 108);\n"
"}"));
        lineEdit_plaka = new QLineEdit(centralwidget);
        lineEdit_plaka->setObjectName("lineEdit_plaka");
        lineEdit_plaka->setGeometry(QRect(225, 385, 145, 25));
        pushButtonKayit = new QPushButton(centralwidget);
        pushButtonKayit->setObjectName("pushButtonKayit");
        pushButtonKayit->setGeometry(QRect(220, 430, 151, 25));
        pushButtonKayit->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(170, 170, 0);\n"
"	border-width: 2px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(170, 170, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"\n"
"}"));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(70, 390, 66, 17));
        label_6->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-weight: bold;\n"
"color:rgb(43, 0, 108);\n"
"}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 230, 111, 20));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-weight: bold;\n"
"color:rgb(43, 0, 108);\n"
"}"));
        label_pic = new QLabel(centralwidget);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(0, 0, 421, 781));
        RegisterPage->setCentralWidget(centralwidget);
        label_pic->raise();
        lineEdit_isim->raise();
        label_4->raise();
        lineEdit_username->raise();
        lineEdit_sifre->raise();
        label_5->raise();
        lineEdit_telno->raise();
        lineEdit_email->raise();
        pushButtonBack->raise();
        label_3->raise();
        label->raise();
        lineEdit_plaka->raise();
        pushButtonKayit->raise();
        label_6->raise();
        label_2->raise();
        menubar = new QMenuBar(RegisterPage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 420, 21));
        RegisterPage->setMenuBar(menubar);
        statusbar = new QStatusBar(RegisterPage);
        statusbar->setObjectName("statusbar");
        RegisterPage->setStatusBar(statusbar);

        retranslateUi(RegisterPage);

        QMetaObject::connectSlotsByName(RegisterPage);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterPage)
    {
        RegisterPage->setWindowTitle(QCoreApplication::translate("RegisterPage", "MainWindow", nullptr));
        lineEdit_isim->setText(QString());
        label_4->setText(QCoreApplication::translate("RegisterPage", "Kullan\304\261c\304\261 Ad\304\261", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterPage", "\305\236ifre", nullptr));
        lineEdit_email->setText(QString());
        pushButtonBack->setText(QCoreApplication::translate("RegisterPage", "Zaten \303\234ye misin?", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterPage", "TelefonNumaras\304\261", nullptr));
        label->setText(QCoreApplication::translate("RegisterPage", "\304\260sim Soyisim", nullptr));
        pushButtonKayit->setText(QCoreApplication::translate("RegisterPage", "Kayit", nullptr));
        label_6->setText(QCoreApplication::translate("RegisterPage", "Plaka", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterPage", "E-mail adresi", nullptr));
        label_pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegisterPage: public Ui_RegisterPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERPAGE_H
