#include "mainwindow.h"
#include "databasehandler.h"
#include <QApplication>
#include "registerpage.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    DatabaseHandler db;

    w.show();
    w.hide();
    return a.exec();
}


