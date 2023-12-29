#include "qrscanner.h"
#include "ui_qrscanner.h"

QRScanner::QRScanner(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QRScanner)
{
    ui->setupUi(this);
}

QRScanner::~QRScanner()
{
    delete ui;
}
