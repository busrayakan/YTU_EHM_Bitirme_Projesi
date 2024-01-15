#ifndef HOMEPAGE_H
#define HOMEPAGE_H

#include <QMainWindow>
#include "login.h"
#include "registerpage.h"

namespace Ui {
class HomePage;
}

class HomePage : public QMainWindow
{
    Q_OBJECT

public:
    explicit HomePage(QWidget *parent = nullptr);
    ~HomePage();

private slots:
    void on_pushButtonGiris_clicked();

    void on_pushButtonKayit_clicked();


private:
    Ui::HomePage *ui;
    Login* loginPage;
    RegisterPage* kayitPage;
};

#endif // HOMEPAGE_H
