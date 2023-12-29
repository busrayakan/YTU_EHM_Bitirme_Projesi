#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "databasehandler.h"
#include "maplocation.h"

class HomePage; // Forward declaration
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void handleAuthenticationResult(bool isAuthenticated);
    void on_pushButtonBack_clicked();
    void on_pushButtonGiris_clicked();

private:
    Ui::Login *ui;
    HomePage *homePage;
    MapLocation* mapper;
    DatabaseHandler *db;
};

#endif // LOGIN_H
