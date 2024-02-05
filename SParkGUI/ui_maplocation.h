/********************************************************************************
** Form generated from reading UI file 'maplocation.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPLOCATION_H
#define UI_MAPLOCATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapLocation
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QPlainTextEdit *plainTextEdit;
    QStackedWidget *stackedWidget;
    QWidget *page_Cev;
    QTextEdit *textEdit_Cev;
    QLabel *lblSlotCev_B;
    QLabel *lblSlotCev_C;
    QLabel *lblSlotCev_A;
    QProgressBar *progressBarCev;
    QPushButton *pushButton_Cev_SlotC;
    QPushButton *pushButton_Cev_SlotB;
    QPushButton *pushButton_Cev_SlotA;
    QWidget *page_Yildiz;
    QLabel *lblSlotYil_C;
    QLabel *lblSlotYil_B;
    QProgressBar *progressBarYil;
    QTextEdit *textEdit_Yil;
    QLabel *lblSlotYil_A;
    QPushButton *pushButton_Yil_SlotA;
    QPushButton *pushButton_Yil_SlotB;
    QPushButton *pushButton_Yil_SlotC;
    QWidget *page_Dav;
    QLabel *lblSlotDav_A;
    QTextEdit *textEdit_Dav;
    QLabel *lblSlotDav_C;
    QLabel *lblSlotDav_B;
    QProgressBar *progressBarDav;
    QPushButton *pushButton_Dav_SlotA;
    QPushButton *pushButton_Dav_SlotB;
    QPushButton *pushButton_Dav_SlotC;
    QPushButton *pushButton_ShowInMap;
    QComboBox *comboBox_2;
    QLabel *label_pic;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MapLocation)
    {
        if (MapLocation->objectName().isEmpty())
            MapLocation->setObjectName("MapLocation");
        MapLocation->resize(420, 800);
        centralwidget = new QWidget(MapLocation);
        centralwidget->setObjectName("centralwidget");
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(50, 200, 141, 31));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox{\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(114, 132, 135);\n"
"	border-width: 2px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(224, 255, 251);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"}"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(50, 120, 311, 41));
        plainTextEdit->setStyleSheet(QString::fromUtf8("QPlainTextEdit{\n"
"\n"
"	border: 2px;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(0, 0, 0);\n"
"	border-width: 2px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(255, 255, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"}"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(50, 270, 321, 381));
        page_Cev = new QWidget();
        page_Cev->setObjectName("page_Cev");
        textEdit_Cev = new QTextEdit(page_Cev);
        textEdit_Cev->setObjectName("textEdit_Cev");
        textEdit_Cev->setGeometry(QRect(0, 20, 141, 41));
        textEdit_Cev->setStyleSheet(QString::fromUtf8("QTextEdit\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(114, 132, 135);\n"
"	border-width: 2px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(255, 255, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"}"));
        lblSlotCev_B = new QLabel(page_Cev);
        lblSlotCev_B->setObjectName("lblSlotCev_B");
        lblSlotCev_B->setGeometry(QRect(109, 110, 91, 80));
        QFont font;
        font.setPointSize(9);
        lblSlotCev_B->setFont(font);
        lblSlotCev_B->setFrameShape(QFrame::Panel);
        lblSlotCev_B->setFrameShadow(QFrame::Sunken);
        lblSlotCev_B->setAlignment(Qt::AlignCenter);
        lblSlotCev_C = new QLabel(page_Cev);
        lblSlotCev_C->setObjectName("lblSlotCev_C");
        lblSlotCev_C->setGeometry(QRect(220, 110, 91, 80));
        lblSlotCev_C->setFont(font);
        lblSlotCev_C->setFrameShape(QFrame::Panel);
        lblSlotCev_C->setFrameShadow(QFrame::Sunken);
        lblSlotCev_C->setAlignment(Qt::AlignCenter);
        lblSlotCev_A = new QLabel(page_Cev);
        lblSlotCev_A->setObjectName("lblSlotCev_A");
        lblSlotCev_A->setGeometry(QRect(0, 110, 91, 80));
        lblSlotCev_A->setFont(font);
        lblSlotCev_A->setFrameShape(QFrame::Panel);
        lblSlotCev_A->setFrameShadow(QFrame::Sunken);
        lblSlotCev_A->setAlignment(Qt::AlignCenter);
        progressBarCev = new QProgressBar(page_Cev);
        progressBarCev->setObjectName("progressBarCev");
        progressBarCev->setGeometry(QRect(150, 20, 161, 41));
        progressBarCev->setValue(25);
        pushButton_Cev_SlotC = new QPushButton(page_Cev);
        pushButton_Cev_SlotC->setObjectName("pushButton_Cev_SlotC");
        pushButton_Cev_SlotC->setGeometry(QRect(240, 200, 41, 31));
        pushButton_Cev_SlotC->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(0, 0, 0);\n"
"	border-width: 1px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(178, 213, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"\n"
"}"));
        pushButton_Cev_SlotB = new QPushButton(page_Cev);
        pushButton_Cev_SlotB->setObjectName("pushButton_Cev_SlotB");
        pushButton_Cev_SlotB->setGeometry(QRect(130, 200, 41, 31));
        pushButton_Cev_SlotB->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(0, 0, 0);\n"
"	border-width: 1px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(178, 213, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"\n"
"}"));
        pushButton_Cev_SlotA = new QPushButton(page_Cev);
        pushButton_Cev_SlotA->setObjectName("pushButton_Cev_SlotA");
        pushButton_Cev_SlotA->setGeometry(QRect(20, 200, 41, 31));
        pushButton_Cev_SlotA->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(0, 0, 0);\n"
"	border-width: 1px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(178, 213, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"\n"
"}"));
        stackedWidget->addWidget(page_Cev);
        page_Yildiz = new QWidget();
        page_Yildiz->setObjectName("page_Yildiz");
        lblSlotYil_C = new QLabel(page_Yildiz);
        lblSlotYil_C->setObjectName("lblSlotYil_C");
        lblSlotYil_C->setGeometry(QRect(220, 110, 91, 80));
        lblSlotYil_C->setFont(font);
        lblSlotYil_C->setFrameShape(QFrame::Panel);
        lblSlotYil_C->setFrameShadow(QFrame::Sunken);
        lblSlotYil_C->setAlignment(Qt::AlignCenter);
        lblSlotYil_B = new QLabel(page_Yildiz);
        lblSlotYil_B->setObjectName("lblSlotYil_B");
        lblSlotYil_B->setGeometry(QRect(109, 110, 91, 80));
        lblSlotYil_B->setFont(font);
        lblSlotYil_B->setFrameShape(QFrame::Panel);
        lblSlotYil_B->setFrameShadow(QFrame::Sunken);
        lblSlotYil_B->setAlignment(Qt::AlignCenter);
        progressBarYil = new QProgressBar(page_Yildiz);
        progressBarYil->setObjectName("progressBarYil");
        progressBarYil->setGeometry(QRect(150, 20, 161, 41));
        progressBarYil->setValue(10);
        textEdit_Yil = new QTextEdit(page_Yildiz);
        textEdit_Yil->setObjectName("textEdit_Yil");
        textEdit_Yil->setGeometry(QRect(0, 20, 141, 41));
        textEdit_Yil->setStyleSheet(QString::fromUtf8("QTextEdit\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(114, 132, 135);\n"
"	border-width: 2px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(255, 255, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"}"));
        lblSlotYil_A = new QLabel(page_Yildiz);
        lblSlotYil_A->setObjectName("lblSlotYil_A");
        lblSlotYil_A->setGeometry(QRect(0, 110, 91, 80));
        lblSlotYil_A->setFont(font);
        lblSlotYil_A->setFrameShape(QFrame::Panel);
        lblSlotYil_A->setFrameShadow(QFrame::Sunken);
        lblSlotYil_A->setAlignment(Qt::AlignCenter);
        pushButton_Yil_SlotA = new QPushButton(page_Yildiz);
        pushButton_Yil_SlotA->setObjectName("pushButton_Yil_SlotA");
        pushButton_Yil_SlotA->setGeometry(QRect(20, 200, 41, 31));
        pushButton_Yil_SlotA->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(0, 0, 0);\n"
"	border-width: 1px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(178, 213, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"\n"
"}"));
        pushButton_Yil_SlotB = new QPushButton(page_Yildiz);
        pushButton_Yil_SlotB->setObjectName("pushButton_Yil_SlotB");
        pushButton_Yil_SlotB->setGeometry(QRect(130, 200, 41, 31));
        pushButton_Yil_SlotB->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(0, 0, 0);\n"
"	border-width: 1px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(178, 213, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"\n"
"}"));
        pushButton_Yil_SlotC = new QPushButton(page_Yildiz);
        pushButton_Yil_SlotC->setObjectName("pushButton_Yil_SlotC");
        pushButton_Yil_SlotC->setGeometry(QRect(240, 200, 41, 31));
        pushButton_Yil_SlotC->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(0, 0, 0);\n"
"	border-width: 1px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(178, 213, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"\n"
"}"));
        stackedWidget->addWidget(page_Yildiz);
        page_Dav = new QWidget();
        page_Dav->setObjectName("page_Dav");
        lblSlotDav_A = new QLabel(page_Dav);
        lblSlotDav_A->setObjectName("lblSlotDav_A");
        lblSlotDav_A->setGeometry(QRect(0, 110, 91, 80));
        lblSlotDav_A->setFont(font);
        lblSlotDav_A->setFrameShape(QFrame::Panel);
        lblSlotDav_A->setFrameShadow(QFrame::Sunken);
        lblSlotDav_A->setAlignment(Qt::AlignCenter);
        textEdit_Dav = new QTextEdit(page_Dav);
        textEdit_Dav->setObjectName("textEdit_Dav");
        textEdit_Dav->setGeometry(QRect(0, 20, 141, 41));
        textEdit_Dav->setStyleSheet(QString::fromUtf8("QTextEdit\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(114, 132, 135);\n"
"	border-width: 2px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(255, 255, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"}"));
        lblSlotDav_C = new QLabel(page_Dav);
        lblSlotDav_C->setObjectName("lblSlotDav_C");
        lblSlotDav_C->setGeometry(QRect(220, 110, 91, 80));
        lblSlotDav_C->setFont(font);
        lblSlotDav_C->setFrameShape(QFrame::Panel);
        lblSlotDav_C->setFrameShadow(QFrame::Sunken);
        lblSlotDav_C->setAlignment(Qt::AlignCenter);
        lblSlotDav_B = new QLabel(page_Dav);
        lblSlotDav_B->setObjectName("lblSlotDav_B");
        lblSlotDav_B->setGeometry(QRect(109, 110, 91, 80));
        lblSlotDav_B->setFont(font);
        lblSlotDav_B->setFrameShape(QFrame::Panel);
        lblSlotDav_B->setFrameShadow(QFrame::Sunken);
        lblSlotDav_B->setAlignment(Qt::AlignCenter);
        progressBarDav = new QProgressBar(page_Dav);
        progressBarDav->setObjectName("progressBarDav");
        progressBarDav->setGeometry(QRect(150, 20, 161, 41));
        progressBarDav->setValue(0);
        pushButton_Dav_SlotA = new QPushButton(page_Dav);
        pushButton_Dav_SlotA->setObjectName("pushButton_Dav_SlotA");
        pushButton_Dav_SlotA->setGeometry(QRect(20, 200, 41, 31));
        pushButton_Dav_SlotA->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(0, 0, 0);\n"
"	border-width: 1px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(178, 213, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"\n"
"}"));
        pushButton_Dav_SlotB = new QPushButton(page_Dav);
        pushButton_Dav_SlotB->setObjectName("pushButton_Dav_SlotB");
        pushButton_Dav_SlotB->setGeometry(QRect(130, 200, 41, 31));
        pushButton_Dav_SlotB->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(0, 0, 0);\n"
"	border-width: 1px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(178, 213, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"\n"
"}"));
        pushButton_Dav_SlotC = new QPushButton(page_Dav);
        pushButton_Dav_SlotC->setObjectName("pushButton_Dav_SlotC");
        pushButton_Dav_SlotC->setGeometry(QRect(240, 200, 41, 31));
        pushButton_Dav_SlotC->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(0, 0, 0);\n"
"	border-width: 1px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(178, 213, 255);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"\n"
"}"));
        stackedWidget->addWidget(page_Dav);
        pushButton_ShowInMap = new QPushButton(centralwidget);
        pushButton_ShowInMap->setObjectName("pushButton_ShowInMap");
        pushButton_ShowInMap->setGeometry(QRect(200, 200, 161, 31));
        pushButton_ShowInMap->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"\n"
"	border: 1px solid #111111;\n"
"	border-radius: 5px;\n"
"	border-color: rgb(114, 132, 135);\n"
"	border-width: 2px;\n"
"	margin-left: 4px;\n"
"	padding: 5px;\n"
"	color:  rgb(0, 0, 0);\n"
"	background-color:rgb(224, 255, 251);\n"
"	font: 700 9pt \"Segoe UI\";\n"
"\n"
"\n"
"}"));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(281, 0, 141, 24));
        label_pic = new QLabel(centralwidget);
        label_pic->setObjectName("label_pic");
        label_pic->setGeometry(QRect(0, 0, 441, 791));
        MapLocation->setCentralWidget(centralwidget);
        label_pic->raise();
        comboBox->raise();
        plainTextEdit->raise();
        stackedWidget->raise();
        pushButton_ShowInMap->raise();
        comboBox_2->raise();
        statusbar = new QStatusBar(MapLocation);
        statusbar->setObjectName("statusbar");
        MapLocation->setStatusBar(statusbar);

        retranslateUi(MapLocation);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MapLocation);
    } // setupUi

    void retranslateUi(QMainWindow *MapLocation)
    {
        MapLocation->setWindowTitle(QCoreApplication::translate("MapLocation", "MainWindow", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MapLocation", "Cevizliba\304\237", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MapLocation", "Davutpa\305\237a", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MapLocation", "Y\304\261ld\304\261z", nullptr));

        plainTextEdit->setPlainText(QCoreApplication::translate("MapLocation", "                               Lokasyonlar  ", nullptr));
        textEdit_Cev->setHtml(QCoreApplication::translate("MapLocation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:700; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400;\">Doluluk oran\304\261</span></p></body></html>", nullptr));
        lblSlotCev_B->setText(QCoreApplication::translate("MapLocation", "Slot B", nullptr));
        lblSlotCev_C->setText(QCoreApplication::translate("MapLocation", "Slot C", nullptr));
        lblSlotCev_A->setText(QCoreApplication::translate("MapLocation", "Slot A", nullptr));
        pushButton_Cev_SlotC->setText(QCoreApplication::translate("MapLocation", "Se\303\247", nullptr));
        pushButton_Cev_SlotB->setText(QCoreApplication::translate("MapLocation", "Se\303\247", nullptr));
        pushButton_Cev_SlotA->setText(QCoreApplication::translate("MapLocation", "Se\303\247", nullptr));
        lblSlotYil_C->setText(QCoreApplication::translate("MapLocation", "Slot C", nullptr));
        lblSlotYil_B->setText(QCoreApplication::translate("MapLocation", "Slot B", nullptr));
        textEdit_Yil->setHtml(QCoreApplication::translate("MapLocation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:700; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400;\">Doluluk oran\304\261</span></p></body></html>", nullptr));
        lblSlotYil_A->setText(QCoreApplication::translate("MapLocation", "Slot A", nullptr));
        pushButton_Yil_SlotA->setText(QCoreApplication::translate("MapLocation", "Se\303\247", nullptr));
        pushButton_Yil_SlotB->setText(QCoreApplication::translate("MapLocation", "Se\303\247", nullptr));
        pushButton_Yil_SlotC->setText(QCoreApplication::translate("MapLocation", "Se\303\247", nullptr));
        lblSlotDav_A->setText(QCoreApplication::translate("MapLocation", "Slot A", nullptr));
        textEdit_Dav->setHtml(QCoreApplication::translate("MapLocation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:700; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400;\">Doluluk oran\304\261</span></p></body></html>", nullptr));
        lblSlotDav_C->setText(QCoreApplication::translate("MapLocation", "Slot C", nullptr));
        lblSlotDav_B->setText(QCoreApplication::translate("MapLocation", "Slot B", nullptr));
        pushButton_Dav_SlotA->setText(QCoreApplication::translate("MapLocation", "Se\303\247", nullptr));
        pushButton_Dav_SlotB->setText(QCoreApplication::translate("MapLocation", "Se\303\247", nullptr));
        pushButton_Dav_SlotC->setText(QCoreApplication::translate("MapLocation", "Se\303\247", nullptr));
        pushButton_ShowInMap->setText(QCoreApplication::translate("MapLocation", "Haritada G\303\266ster", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MapLocation", "Ayarlar", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MapLocation", "Kullan\304\261c\304\261y\304\261 Sil", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MapLocation", "\303\207\304\261k\304\261\305\237", nullptr));

        label_pic->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MapLocation: public Ui_MapLocation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPLOCATION_H
