#ifndef MAPLOCATION_H
#define MAPLOCATION_H

#include <QMainWindow>
#include <QMap>
#include "databasehandler.h"

class HandleLocation;
class Navigation;
class HomePage;
class Login;
namespace Ui {
class MapLocation;
}

class MapLocation : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapLocation(QWidget *parent = nullptr, const QString& username = "");  // Add default value for username

    ~MapLocation();

private slots:
    void on_comboBoxLocation_currentIndexChanged(int index);
    void on_pushButton_ShowInMap_clicked();
    void handleReservationStatus(bool isReserved);


    void on_comboBox_2_currentIndexChanged(int index);
    void handleUserDeleted();

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
    Login *login;
    void removeButton(QPushButton *buttonToRemove);
    QString m_username;  // Static member variable for username

};

#endif // MAPLOCATION_H
