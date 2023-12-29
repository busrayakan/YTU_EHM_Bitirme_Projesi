#ifndef MAPLOCATION_H
#define MAPLOCATION_H

#include <QMainWindow>
#include <QMap>
#include "databasehandler.h"

class HandleLocation;
class Navigation;
class HomePage;
namespace Ui {
class MapLocation;
}

class MapLocation : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapLocation(QWidget *parent = nullptr);
    ~MapLocation();
private slots:
    void on_comboBoxLocation_currentIndexChanged(int index);
    void on_pushButton_ShowInMap_clicked();
    void handleReservationStatus(bool isReserved);


    void on_comboBox_2_currentIndexChanged(int index);

private:
    Ui::MapLocation *ui;
    HandleLocation* location;
    QString selectedLocation;
    QString selectedSetting;
    DatabaseHandler db;
    quint8 howClose;
    bool result = false;
    Navigation *navigationPage;
    HomePage *homePage;
};

#endif // MAPLOCATION_H
