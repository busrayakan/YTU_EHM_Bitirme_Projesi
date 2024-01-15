#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include "databasehandler.h"
#include "maplocation.h"

class HomePage;
class Navigation;
namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
    QString m_username;
signals:
    void getUsername(QString Username);
private slots:
    void handleAuthenticationResult(bool isAuthenticated);
    void on_pushButtonBack_clicked();
    void on_pushButtonGiris_clicked();
    void handleUsername(QString username);

private:
    Ui::Login *ui;
    HomePage *homePage;
    MapLocation* mapper;
    DatabaseHandler *db;
    Navigation *nav;

};

#endif // LOGIN_H
