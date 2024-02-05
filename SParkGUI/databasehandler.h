#ifndef DATABASEHANDLER_H
#define DATABASEHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QMessageBox>
#include <QPushButton>
#include <QEventLoop>

class DatabaseHandler : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseHandler(QObject *parent = nullptr);
    ~DatabaseHandler();
    //void sendDataToFirebase(const QByteArray& data, QString header);

    void networkReplyRead();
    void authenticate(QString &username, QString &password);
    void sendRequest(QString &slotUrl, QWidget *parentWidget, QString &username);

    void sendDataToFirebase(const QByteArray& data, const QString& username);
    void sendCountToFirebase(int count);
    bool isReserved = false;
    void handleCarsInside(int count);
    void handleMotor(bool isOpen);
    void findClosestSlot();

    QString findFirstAvailableSlot();
    bool checkSlots(QString& slotName );


    bool checkSlotStatus(const QString &slotName);
    int getResCountFromFirebase();
    int getInsideCountFromFirebase();
    void handleResCount(int count);
    bool checkReservationStatus(const QString &username);
    void updateReservationStatus(const QString &username, bool newStatus);
    void deleteUserFromFirebase(const QString &username);
signals:
    void authenticationResult(bool isAuthenticated);

    void reservationStatus(bool isReserved);
    void userDeleted();


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
