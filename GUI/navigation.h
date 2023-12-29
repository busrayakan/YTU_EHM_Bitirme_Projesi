#ifndef NAVIGATION_H
#define NAVIGATION_H

#include <QMainWindow>
#include "databasehandler.h"
#include <QMessageBox>

namespace Ui {
class Navigation;
}

class Navigation : public QMainWindow
{
    Q_OBJECT

public:
    explicit Navigation(QWidget *parent = nullptr);
    ~Navigation();

private slots:
    void on_pushButton_cikis_clicked();

    void on_pushButton_giris_clicked();

private:
    Ui::Navigation *ui;
    DatabaseHandler db;
    int count = 0;
};

#endif // NAVIGATION_H
