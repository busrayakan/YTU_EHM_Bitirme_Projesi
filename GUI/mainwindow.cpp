#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databasehandler.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    homePage = new HomePage(this);
    homePage->show();
}


MainWindow::~MainWindow()
{
    delete ui;
}



