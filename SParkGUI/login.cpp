#include "login.h"
#include "ui_login.h"
#include "homepage.h"
#include "navigation.h"
#include <QMessageBox>


Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login),
    homePage(nullptr),
    mapper(nullptr),
    nav(nullptr)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Desktop/GUI/test/assets/loginPage.jpg");

    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    db = new DatabaseHandler(this);
    connect(db, &DatabaseHandler::authenticationResult, this, &Login::handleAuthenticationResult);
    connect(this,&Login::getUsername,this,&Login::handleUsername);
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
        if(db->checkReservationStatus(m_username)){
            if(!nav)   nav = new Navigation(this,m_username);
            nav->show();
            this->hide();
        }
        else {


            if (!mapper) {
                mapper = new MapLocation(this,m_username);
            }
            mapper->show();
            this->hide();
        }
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
    emit getUsername(username);

}

void Login::handleUsername(QString username)
{
    m_username = username;
}

