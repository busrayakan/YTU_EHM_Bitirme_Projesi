/********************************************************************************
** Form generated from reading UI file 'navigation.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAVIGATION_H
#define UI_NAVIGATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Navigation
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_giris;
    QPushButton *pushButton_cikis;
    QComboBox *comboBox_2;
    QLabel *label_pic;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Navigation)
    {
        if (Navigation->objectName().isEmpty())
            Navigation->setObjectName("Navigation");
        Navigation->resize(420, 800);
        centralwidget = new QWidget(Navigation);
        centralwidget->setObjectName("centralwidget");
        pushButton_giris = new QPushButton(centralwidget);
        pushButton_giris->setObjectName("pushButton_giris");
        pushButton_giris->setGeometry(QRect(110, 250, 191, 31));
        pushButton_giris->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        pushButton_cikis = new QPushButton(centralwidget);
        pushButton_cikis->setObjectName("pushButton_cikis");
        pushButton_cikis->setGeometry(QRect(110, 310, 191, 31));
        pushButton_cikis->setStyleSheet(QString::fromUtf8("QPushButton\n"
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
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(320, 0, 101, 31));
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox\n"
"\n"
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
        label_pic->setGeometry(QRect(-2, 5, 441, 771));
        Navigation->setCentralWidget(centralwidget);
        label_pic->raise();
        pushButton_giris->raise();
        pushButton_cikis->raise();
        comboBox_2->raise();
        menubar = new QMenuBar(Navigation);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 420, 21));
        Navigation->setMenuBar(menubar);
        statusbar = new QStatusBar(Navigation);
        statusbar->setObjectName("statusbar");
        Navigation->setStatusBar(statusbar);

        retranslateUi(Navigation);

        QMetaObject::connectSlotsByName(Navigation);
    } // setupUi

    void retranslateUi(QMainWindow *Navigation)
    {
        Navigation->setWindowTitle(QCoreApplication::translate("Navigation", "MainWindow", nullptr));
        pushButton_giris->setText(QCoreApplication::translate("Navigation", "Otoparka giri\305\237 i\303\247in t\304\261klay\304\261n\304\261z", nullptr));
        pushButton_cikis->setText(QCoreApplication::translate("Navigation", "Otoparktan \303\247\304\261k\304\261\305\237 i\303\247in t\304\261klay\304\261n\304\261z", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("Navigation", "Ayarlar", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("Navigation", "\303\207\304\261k\304\261\305\237", nullptr));

        label_pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Navigation: public Ui_Navigation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAVIGATION_H
