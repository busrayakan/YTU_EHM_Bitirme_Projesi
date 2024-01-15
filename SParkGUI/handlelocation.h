#ifndef HANDLELOCATION_H
#define HANDLELOCATION_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QMessageBox>
#include <QVBoxLayout>
#include "databasehandler.h"

namespace Ui {
class HandleLocation;
}

class HandleLocation : public QMainWindow
{
    Q_OBJECT

public:
    explicit HandleLocation(QWidget *parent = nullptr);
    ~HandleLocation();



private slots:
    void on_backButton_clicked();

private:
    Ui::HandleLocation *ui;
    QWebEngineView *m_view;
    DatabaseHandler db;
};

#endif // HANDLELOCATION_H
