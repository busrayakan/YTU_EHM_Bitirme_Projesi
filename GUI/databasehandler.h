#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QMessageBox>
#include <QPushButton>

class DatabaseHandler : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseHandler(QObject *parent = nullptr);
    ~DatabaseHandler();
    //void sendDataToFirebase(const QByteArray& data, QString header);

    void networkReplyRead();
    void authenticate(QString &username, QString &password);
    void sendRequest(QString &slotUrl, QWidget *parentWidget);

    void sendDataToFirebase(const QByteArray &data);
    void sendCountToFirebase(int count);
    bool isReserved = false;
    void handleCarsInside(int count);
    void handleMotor(bool isOpen);
    void findClosestSlot();
signals:
    void authenticationResult(bool isAuthenticated);

    void reservationStatus(bool isReserved);



private  slots:


private:
    QNetworkAccessManager* m_networkManager;
    QNetworkReply* m_networkReply;
    QNetworkReply* getNetworkReply;
    bool isAuthenticated;
    quint8 count = 0;
    quint8 CarsInsideCount = 0;
    bool getReservationStatus() const { return isReserved; }
};

#endif // DATABASEHANDLER_H
