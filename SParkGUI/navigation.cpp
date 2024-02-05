#include "navigation.h"
#include "ui_navigation.h"
#include "homepage.h"
#include "login.h"

Navigation::Navigation(QWidget *parent,const QString& username) :
    QMainWindow(parent),
    ui(new Ui::Navigation),
    home(nullptr),
m_username(username)
{
    ui->setupUi(this);
    ResCount = db.getResCountFromFirebase();
    count = db.getInsideCountFromFirebase();

    QPixmap pix("C:/Users/user/Desktop/SParkGUI/test/assets/last-page-2.jpg");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

Navigation::~Navigation()
{
    delete ui;
}

void Navigation::on_pushButton_cikis_clicked()
{


    db.handleMotor(true);

    QMessageBox *confirmationBox = new QMessageBox(QMessageBox::Question, "Onay", "Otoparktan çıkış yaptım.", QMessageBox::Yes | QMessageBox::No, this);

    confirmationBox->setButtonText(QMessageBox::Yes, "Evet");
    confirmationBox->setButtonText(QMessageBox::No, "Hayır");

    int result = confirmationBox->exec();

    if (result == QMessageBox::Yes) {
        count --;
        db.handleCarsInside(count);
        db.handleMotor(false);
        ResCount --;
        db.handleResCount(ResCount);
        db.updateReservationStatus(m_username,false);
        if(!home){
            home = new HomePage(this);
        }
        home->show();
        this->hide();
    }
}


void Navigation::on_pushButton_giris_clicked()
{

    db.handleMotor(true);
    QString slotName =  db.findFirstAvailableSlot();
    if(slotName.endsWith("1")){
        slotName = "SlotA";
    }
    if(slotName.endsWith("2")){
        slotName = "SlotB";
    }
    if(slotName.endsWith("3")){
        slotName = "SlotC";
    }
    QMessageBox::information(this, "En yakın boş slot", slotName);

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



void Navigation::on_comboBox_2_currentIndexChanged(int index)
{
    QString selectedSetting;
    selectedSetting = ui->comboBox_2->itemText(index);

    int pageIndex = -1;
    if (selectedSetting == "Ayarlar") {
        pageIndex = 0;
    } else if (selectedSetting == "Çıkış") {
        pageIndex = 2;
        if(!home){
            home = new HomePage(this);
        }

        home->show();
        this->hide();
    }
}

