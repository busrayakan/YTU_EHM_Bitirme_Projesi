#include "navigation.h"
#include "ui_navigation.h"

Navigation::Navigation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Navigation)
{
    ui->setupUi(this);
}

Navigation::~Navigation()
{
    delete ui;
}

void Navigation::on_pushButton_cikis_clicked()
{


    db.handleMotor(false);

    QMessageBox *confirmationBox = new QMessageBox(QMessageBox::Question, "Onay", "Otoparktan çıkış yaptım.", QMessageBox::Yes | QMessageBox::No, this);

    confirmationBox->setButtonText(QMessageBox::Yes, "Evet");
    confirmationBox->setButtonText(QMessageBox::No, "Hayır");

    int result = confirmationBox->exec();

    if (result == QMessageBox::Yes) {
        count --;
        db.handleCarsInside(count);
        db.handleMotor(true);
    }
}


void Navigation::on_pushButton_giris_clicked()
{

    db.handleMotor(true);

    QMessageBox *confirmationBox = new QMessageBox(QMessageBox::Question, "Onay", "Otoparka giriş yaptım.", QMessageBox::Yes | QMessageBox::No, this);
    confirmationBox->setButtonText(QMessageBox::Yes, "Evet");
    confirmationBox->setButtonText(QMessageBox::No, "Hayır");

    int result = confirmationBox->exec();
    if (result == QMessageBox::Yes) {
        count ++;
        db.handleCarsInside(count);
        db.handleMotor(false);
    }
}

