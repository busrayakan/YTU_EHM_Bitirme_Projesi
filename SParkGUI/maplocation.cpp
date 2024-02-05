#include "maplocation.h"
#include "ui_maplocation.h"
#include "homepage.h"
#include "navigation.h"
#include "handlelocation.h"

MapLocation::MapLocation(QWidget *parent, const QString& username) :
    QMainWindow(parent),
    ui(new Ui::MapLocation),
    navigationPage(nullptr),
    location(nullptr),
    login(nullptr),
    m_username(username)
//  homePage(nullptr)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Desktop/GUI/test/assets/mapLocationPage_3.jpg");

    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));


    connect(&db, &DatabaseHandler::userDeleted, this, &MapLocation::handleUserDeleted);

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBoxLocation_currentIndexChanged(int)));
    int c = (db.getResCountFromFirebase() *100 ) / 3;
    int in = db.getInsideCountFromFirebase();
    int rez = db.getResCountFromFirebase();

    ui->progressBarCev->setValue(20); //default
    ui->progressBarDav->setValue(c);


    for (int i = 1; i < 4; i++) {
        QString slotKey = "Slot" + QString::number(i);
        QPixmap carPic("C:/Users/user/Desktop/GUI/test/assets/car-on-top.png");

        if (slotKey == "Slot1" && db.checkSlotStatus(slotKey)) {
            ui->lblSlotDav_A->setPixmap(carPic.scaled(ui->lblSlotDav_A->size(), Qt::KeepAspectRatio));
            removeButton(ui->pushButton_Dav_SlotA);
        }
        if (slotKey == "Slot2" && db.checkSlotStatus(slotKey)) {
            ui->lblSlotDav_B->setPixmap(carPic.scaled(ui->lblSlotDav_B->size(), Qt::KeepAspectRatio));
            removeButton(ui->pushButton_Dav_SlotB);
        }
        if (slotKey == "Slot3" && db.checkSlotStatus(slotKey)) {
            ui->lblSlotDav_C->setPixmap(carPic.scaled(ui->lblSlotDav_C->size(), Qt::KeepAspectRatio));
            removeButton(ui->pushButton_Dav_SlotC);
        }
    }

    if(in!=rez){

        QPixmap RezcarPic("C:/Users/user/Desktop/GUI/test/assets/yellow-car.png");

        while(in<rez){
            if((!db.checkSlotStatus("Slot1"))){
                ui->lblSlotDav_A->setPixmap(RezcarPic.scaled(ui->lblSlotDav_A->size(), Qt::KeepAspectRatio));
                removeButton(ui->pushButton_Dav_SlotA);
                in++;
                if(in==rez)
                    break;
            }
            if((!db.checkSlotStatus("Slot2"))){
                ui->lblSlotDav_B->setPixmap(RezcarPic.scaled(ui->lblSlotDav_B->size(), Qt::KeepAspectRatio));
                removeButton(ui->pushButton_Dav_SlotB);
                in++;
                if(in==rez)
                    break;
            }
            if((!db.checkSlotStatus("Slot3"))){
                ui->lblSlotDav_C->setPixmap(RezcarPic.scaled(ui->lblSlotDav_C->size(), Qt::KeepAspectRatio));
                removeButton(ui->pushButton_Dav_SlotC);
                in++;
                if(in==rez)
                    break;
            }
        }
    }



    connect(&db, &DatabaseHandler::reservationStatus, this, &MapLocation::handleReservationStatus);

    connect(ui->pushButton_Dav_SlotA, &QPushButton::clicked, this, [=]() {
        QString slotName = "SlotA";
        QString slotUrl = QString("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Locations/%1/%2/available.json")
                              .arg(selectedLocation,slotName);

        db.sendRequest(slotUrl, this,m_username);

    });

    connect(ui->pushButton_Dav_SlotB, &QPushButton::clicked, this, [=]() {
        QString slotName = "SlotB";
        QString slotUrl = QString("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Locations/%1/%2/available.json")
                              .arg(selectedLocation,slotName);

        db.sendRequest(slotUrl, this,m_username);

    });
    connect(ui->pushButton_Dav_SlotC, &QPushButton::clicked, this, [=]() {
        QString slotName = "SlotC";
        QString slotUrl = QString("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Locations/%1/%2/available.json")
                              .arg(selectedLocation,slotName);

        db.sendRequest(slotUrl, this,m_username);

    });




}

MapLocation::~MapLocation()
{
    delete ui;
}


void MapLocation::on_comboBoxLocation_currentIndexChanged(int index)
{

    selectedLocation = ui->comboBox->itemText(index);

    int pageIndex = -1;
    if (selectedLocation == "Cevizlibağ") {
        pageIndex = 0;
} else if (selectedLocation == "Davutpaşa") {
    pageIndex = 2;
} else if (selectedLocation == "Yıldız") {

    pageIndex = 1;
}

ui->stackedWidget->setCurrentIndex(pageIndex);
}

void MapLocation::on_pushButton_ShowInMap_clicked()
{

    if (!location) {
        location = new HandleLocation(this);
    }
    location->show();
    this->hide();
}


void MapLocation::handleReservationStatus(bool isReserved)
{
    if (isReserved) {
        QPixmap pix("C:/Users/user/Desktop/GUI/test/assets/car-on-top.jpg");

        int w = ui->lblSlotYil_A->width();
        int h = ui->lblSlotYil_A->height();
        ui->lblSlotYil_A->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
        if (!navigationPage) {
            navigationPage = new Navigation(this);
        }
        navigationPage->show();
        this->hide();
    }
}




void MapLocation::on_comboBox_2_currentIndexChanged(int index)
{
    selectedSetting = ui->comboBox_2->itemText(index);

    int pageIndex = -1;
    if (selectedSetting == "Ayarlar") {
        pageIndex = 0;
    } else if (selectedSetting == "Çıkış") {
        pageIndex = 2;

        homePage = new HomePage(this);

        homePage->show();
        this->hide();
    } else if(selectedSetting =="Kullanıcıyı Sil"){
          pageIndex = 1;
        db.deleteUserFromFirebase(m_username);

    }
}

void MapLocation::removeButton(QPushButton* buttonToRemove)
{
    if (buttonToRemove) {
        buttonToRemove->hide();  // or buttonToRemove->setVisible(false);
    }
}

void MapLocation::handleUserDeleted()
{
   // if (!homePage) {
        homePage = new HomePage(this);
   // }
    homePage->show();
    this->hide();
}
