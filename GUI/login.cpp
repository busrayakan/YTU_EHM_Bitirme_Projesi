#include "login.h"
#include "ui_login.h"
#include "homepage.h"

#include <QMessageBox>


Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login),
    homePage(nullptr),
    mapper(nullptr)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Desktop/GUI/test/assets/loginPage.jpg");

    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    db = new DatabaseHandler(this);
    connect(db, &DatabaseHandler::authenticationResult, this, &Login::handleAuthenticationResult);
}

Login::~Login()
{
    delete ui;
    delete db;
}

void Login::handleAuthenticationResult(bool isAuthenticated)
{
    if (isAuthenticated) {
        QMessageBox::information(nullptr, "Login Successful", "Giriş Başarılı.");

        if (!mapper) {
            mapper = new MapLocation(this);
        }
        mapper->show();
        this->hide();
    }
    else{
        QMessageBox::information(nullptr, "Login Failed!", "Giriş Başarısız.");

        Login* newLogin = new Login();
        newLogin->show();

        this->close();
    }
}


void Login::on_pushButtonBack_clicked()
{

    if (!homePage) {
        homePage = new HomePage(this);
    }
    homePage->show();
    this->hide();
}


void Login::on_pushButtonGiris_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    db->authenticate(username,password);

}
