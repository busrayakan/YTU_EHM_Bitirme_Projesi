#include "homepage.h"
#include "ui_homepage.h"
#include <QPixmap>

HomePage::HomePage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HomePage),
    loginPage(nullptr),
    kayitPage(nullptr)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Desktop/GUI/test/assets/homePage_2.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

HomePage::~HomePage()
{
    delete ui;
}


void HomePage::on_pushButtonGiris_clicked()
{
    if (!loginPage) {
        loginPage = new Login(this);
    }
    loginPage->show();
    this->hide();

}


void HomePage::on_pushButtonKayit_clicked()
{
    if (!kayitPage) {
        kayitPage = new RegisterPage(this);
    }
    kayitPage->show();
    this->hide();
}

