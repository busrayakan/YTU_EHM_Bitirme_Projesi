#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QMainWindow>
#include "databasehandler.h"
#include <QMessageBox>
class HomePage;
class Login;

namespace Ui {
class Navigation;
}

class Navigation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Navigation(QWidget *parent = nullptr, const QString& username = "");
    ~Navigation();

private slots:
    void on_pushButton_cikis_clicked();

    void on_pushButton_giris_clicked();

    void on_comboBox_2_currentIndexChanged(int index);

private:
    Ui::Navigation *ui;
    DatabaseHandler db;
    HomePage *home;
    Login *login;
    int count;
    int ResCount ;
    QString m_username;
};

#endif // NAVIGATION_H
