/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomePage
{
public:
    QWidget *centralwidget;
    QLabel *label_pic;
    QPushButton *pushButtonKayit;
    QPushButton *pushButtonGiris;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HomePage)
    {
        if (HomePage->objectName().isEmpty())
            HomePage->setObjectName("HomePage");
        HomePage->resize(420, 800);
        centralwidget = new QWidget(HomePage);
        centralwidget->setObjectName("centralwidget");
        label_pic = new QLabel(centralwidget);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(10, 10, 411, 771));
        pushButtonKayit = new QPushButton(centralwidget);
        pushButtonKayit->setObjectName("pushButtonKayit");
        pushButtonKayit->setGeometry(QRect(50, 330, 151, 31));
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
        pushButtonGiris = new QPushButton(centralwidget);
        pushButtonGiris->setObjectName("pushButtonGiris");
        pushButtonGiris->setGeometry(QRect(50, 390, 151, 31));
        pushButtonGiris->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"border-color: rgb(170, 170, 0);\n"
"border-width: 2px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"background-color:rgb(170, 170, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"\n"
"}"));
        HomePage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HomePage);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 420, 21));
        HomePage->setMenuBar(menubar);
        statusbar = new QStatusBar(HomePage);
        statusbar->setObjectName("statusbar");
        HomePage->setStatusBar(statusbar);

        retranslateUi(HomePage);

        QMetaObject::connectSlotsByName(HomePage);
    } // setupUi

    void retranslateUi(QMainWindow *HomePage)
    {
        HomePage->setWindowTitle(QCoreApplication::translate("HomePage", "MainWindow", nullptr));
        label_pic->setText(QString());
        pushButtonKayit->setText(QCoreApplication::translate("HomePage", "Kay\304\261t Ol", nullptr));
        pushButtonGiris->setText(QCoreApplication::translate("HomePage", "Giri\305\237 Yap", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HomePage: public Ui_HomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
