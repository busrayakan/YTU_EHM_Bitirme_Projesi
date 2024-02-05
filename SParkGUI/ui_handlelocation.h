/********************************************************************************
** Form generated from reading UI file 'handlelocation.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HANDLELOCATION_H
#define UI_HANDLELOCATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HandleLocation
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_Back;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HandleLocation)
    {
        if (HandleLocation->objectName().isEmpty())
            HandleLocation->setObjectName("HandleLocation");
        HandleLocation->resize(420, 800);
        centralwidget = new QWidget(HandleLocation);
        centralwidget->setObjectName("centralwidget");
        pushButton_Back = new QPushButton(centralwidget);
        pushButton_Back->setObjectName("pushButton_Back");
        pushButton_Back->setGeometry(QRect(110, 720, 191, 25));
        HandleLocation->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HandleLocation);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 420, 22));
        HandleLocation->setMenuBar(menubar);
        statusbar = new QStatusBar(HandleLocation);
        statusbar->setObjectName("statusbar");
        HandleLocation->setStatusBar(statusbar);

        retranslateUi(HandleLocation);

        QMetaObject::connectSlotsByName(HandleLocation);
    } // setupUi

    void retranslateUi(QMainWindow *HandleLocation)
    {
        HandleLocation->setWindowTitle(QCoreApplication::translate("HandleLocation", "MainWindow", nullptr));
        pushButton_Back->setText(QCoreApplication::translate("HandleLocation", "Geri D\303\266n", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HandleLocation: public Ui_HandleLocation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HANDLELOCATION_H
