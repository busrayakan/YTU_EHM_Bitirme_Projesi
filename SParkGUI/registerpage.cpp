#include "registerpage.h"
#include "ui_registerpage.h"

RegisterPage::RegisterPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegisterPage),
    loginPage(nullptr)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Desktop/GUI/test/assets/loginPage.jpg");

    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

RegisterPage::~RegisterPage()
{
    delete ui;
}

void RegisterPage::on_pushButtonKayit_clicked()
{
    QString name = ui->lineEdit_isim->text();
    QString mail = ui->lineEdit_email->text();
    QString phone = ui->lineEdit_telno->text();
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_sifre->text();
    QString licensePlate = ui->lineEdit_plaka->text();


    QJsonObject userJson;
    userJson["name"] = name;
    userJson["email"] = mail;
    userJson["phone"] = phone;
    userJson["username"] = username;
    userJson["password"] = password;
    userJson["license_plate"] = licensePlate;

    // Convert the JSON object to a QByteArray
    QJsonDocument userDoc(userJson);
    QByteArray postData = userDoc.toJson();
   // QString header = "Users";
    // Create a DatabaseHandler instance and send the data to Firebase
    DatabaseHandler* dbHandler = new DatabaseHandler(this);
    dbHandler->sendDataToFirebase(postData,username);

    dbHandler->networkReplyRead();

    QMessageBox::information(this,"Info","Kayıt Başarılı");

}



void RegisterPage::on_pushButtonBack_clicked()
{

    if (!loginPage) {
        loginPage = new Login(this);
    }
    loginPage->show(); // Show the login page
    this->hide(); // Hide the main window
}

