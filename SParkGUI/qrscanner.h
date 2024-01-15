#ifndef QRSCANNER_H
#define QRSCANNER_H

#include <QMainWindow>

namespace Ui {
class QRScanner;
}

class QRScanner : public QMainWindow
{
    Q_OBJECT

public:
    explicit QRScanner(QWidget *parent = nullptr);
    ~QRScanner();

private:
    Ui::QRScanner *ui;
};

#endif // QRSCANNER_H
