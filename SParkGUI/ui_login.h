/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

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

class Ui_Login
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButtonBack;
    QLineEdit *lineEdit_password;
    QLineEdit *lineEdit_username;
    QLabel *label_2;
    QPushButton *pushButtonGiris;
    QLabel *label_pic;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName("Login");
        Login->resize(420, 800);
        centralwidget = new QWidget(Login);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(65, 230, 111, 20));
        label->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-weight: bold;\n"
"color:rgb(43, 0, 108);\n"
"}"));
        pushButtonBack = new QPushButton(centralwidget);
        pushButtonBack->setObjectName("pushButtonBack");
        pushButtonBack->setGeometry(QRect(220, 360, 145, 25));
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
        lineEdit_password = new QLineEdit(centralwidget);
        lineEdit_password->setObjectName("lineEdit_password");
        lineEdit_password->setGeometry(QRect(220, 265, 145, 25));
        lineEdit_username = new QLineEdit(centralwidget);
        lineEdit_username->setObjectName("lineEdit_username");
        lineEdit_username->setGeometry(QRect(220, 225, 145, 25));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(65, 270, 111, 20));
        label_2->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-weight: bold;\n"
"color:rgb(43, 0, 108);\n"
"}"));
        pushButtonGiris = new QPushButton(centralwidget);
        pushButtonGiris->setObjectName("pushButtonGiris");
        pushButtonGiris->setGeometry(QRect(220, 320, 145, 25));
        pushButtonGiris->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        label_pic = new QLabel(centralwidget);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(0, 0, 421, 781));
        Login->setCentralWidget(centralwidget);
        label_pic->raise();
        label->raise();
        pushButtonBack->raise();
        lineEdit_password->raise();
        lineEdit_username->raise();
        label_2->raise();
        pushButtonGiris->raise();
        menubar = new QMenuBar(Login);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 420, 21));
        Login->setMenuBar(menubar);
        statusbar = new QStatusBar(Login);
        statusbar->setObjectName("statusbar");
        Login->setStatusBar(statusbar);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QMainWindow *Login)
    {
        Login->setWindowTitle(QCoreApplication::translate("Login", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("Login", "Kullan\304\261c\304\261 Ad\304\261", nullptr));
        pushButtonBack->setText(QCoreApplication::translate("Login", "Ana Sayfaya D\303\266n", nullptr));
        lineEdit_password->setText(QString());
        lineEdit_username->setText(QString());
        label_2->setText(QCoreApplication::translate("Login", "\305\236ifre", nullptr));
        pushButtonGiris->setText(QCoreApplication::translate("Login", "Giri\305\237", nullptr));
        label_pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
