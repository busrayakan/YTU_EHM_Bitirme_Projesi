#include "maplocation.h"
#include "ui_maplocation.h"
#include "homepage.h"
#include "navigation.h"
#include "handlelocation.h"

MapLocation::MapLocation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MapLocation),
    navigationPage(nullptr),
    location(nullptr)
//  homePage(nullptr)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/user/Desktop/GUI/test/assets/mapLocationPage_3.jpg");

    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(on_comboBoxLocation_currentIndexChanged(int)));
    connect(&db, &DatabaseHandler::reservationStatus, this, &MapLocation::handleReservationStatus);

    connect(ui->pushButton_Dav_SlotA, &QPushButton::clicked, this, [=]() {
        QString slotName = "SlotA";
        QString slotUrl = QString("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Locations/%1/%2/available.json")
                              .arg(selectedLocation,slotName);

        db.sendRequest(slotUrl, this);
        howClose = 1;
        //        result = db.isReserved;
        //        if(result){
        //            navigationPage = new Navigation(this);

        //            navigationPage->show(); // Show the login page
        //            this->hide(); // Hide the main window
        //        }


        //    db.CalculateDistance(howClose,slotName);
        //db.updateParkingSpaceStatus();
    });

    connect(ui->pushButton_Dav_SlotB, &QPushButton::clicked, this, [=]() {
        QString slotName = "SlotB";
        QString slotUrl = QString("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Locations/%1/%2/available.json")
                              .arg(selectedLocation,slotName);

        db.sendRequest(slotUrl, this);
        howClose = 2;
        //    db.CalculateDistance(howClose,slotName);
    });
    connect(ui->pushButton_Dav_SlotC, &QPushButton::clicked, this, [=]() {
        QString slotName = "SlotC";
        QString slotUrl = QString("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Locations/%1/%2/available.json")
                              .arg(selectedLocation,slotName);

        db.sendRequest(slotUrl, this);
        howClose = 3;
        //    db.CalculateDistance(howClose,slotName);
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
    }
}

