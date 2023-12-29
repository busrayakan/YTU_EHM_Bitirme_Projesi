#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include <QMainWindow>
#include <QMessageBox>
#include "databasehandler.h"
#include <QJsonDocument>
#include <QJsonObject>
#include "login.h"

namespace Ui {
class RegisterPage;
}

class RegisterPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegisterPage(QWidget *parent = nullptr);
    ~RegisterPage();

private slots:
    void on_pushButtonKayit_clicked();

    void on_pushButtonBack_clicked();

private:
    Ui::RegisterPage *ui;
    Login* loginPage;
};

#endif // REGISTERPAGE_H
