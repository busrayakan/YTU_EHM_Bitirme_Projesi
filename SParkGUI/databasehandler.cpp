#include "databasehandler.h"
#include <QJsonDocument>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>


DatabaseHandler::DatabaseHandler(QObject *parent)
    : QObject{parent}
{
    m_networkManager = new QNetworkAccessManager ( this );
    m_networkReply = m_networkManager->get(QNetworkRequest(QUrl("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Users.json")));
    connect(m_networkReply,&QNetworkReply::readyRead,this,&DatabaseHandler::networkReplyRead);
}

DatabaseHandler::~DatabaseHandler()
{
    m_networkManager->deleteLater();

}

void DatabaseHandler::networkReplyRead()
{
  //  qDebug() << m_networkReply->readAll();
}

void DatabaseHandler::authenticate(QString& username, QString& password)
{
    QNetworkRequest request(QUrl("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Users.json"));
    QNetworkReply *networkReply = m_networkManager->get(request);

    connect(networkReply, &QNetworkReply::finished, [=]() {
        bool isAuthenticated = false;

        if (networkReply->error() == QNetworkReply::NoError) {
            QByteArray response = networkReply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
            QJsonObject usersData = jsonResponse.object();

            for (const QString& userKey : usersData.keys()) {
                QJsonObject userData = usersData[userKey].toObject();
                QString storedUsername = userData["username"].toString();
                QString storedPassword = userData["password"].toString();

                if (username == storedUsername && password == storedPassword) {
                    isAuthenticated = true;
                    break;
                }
            }
        }

        networkReply->deleteLater();
        emit authenticationResult(isAuthenticated);
    });

}

void DatabaseHandler::sendRequest(QString& slotUrl, QWidget* parentWidget, QString& username)
{
    QNetworkRequest request = QNetworkRequest(QUrl(slotUrl));
    QNetworkReply *networkReply = m_networkManager->get(request);

    connect(networkReply, &QNetworkReply::finished, [=]() {
        if (networkReply->error() == QNetworkReply::NoError) {
            QByteArray response = networkReply->readAll();
            bool isAvailable = (QString(response).trimmed().toLower() == "true");

            if (!isAvailable) {
                QMessageBox *confirmationBox = new QMessageBox(QMessageBox::Question, "Onay", "Bu park alanını Rezerve etmek istiyor musunuz?", QMessageBox::Yes | QMessageBox::No, parentWidget);

                confirmationBox->setButtonText(QMessageBox::Yes, "Evet");
                confirmationBox->setButtonText(QMessageBox::No, "Hayır");

                int result = confirmationBox->exec();

                if (result == QMessageBox::Yes) {
                    // Retrieve the current count from the database

                    QNetworkRequest countRequest(QUrl("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/ReservationCount.json"));
                    QNetworkReply *countReply = m_networkManager->get(countRequest);

                    connect(countReply, &QNetworkReply::finished, [=]() {
                        if (countReply->error() == QNetworkReply::NoError) {
                            QByteArray countResponse = countReply->readAll();
                            int currentCount = QJsonDocument::fromJson(countResponse).object()["count"].toInt();
                            if(currentCount>2){
                                QMessageBox::warning(parentWidget, "Park Alanı Dolu", "Tüm park alanları dolu!");
                                isReserved = false;
                                emit reservationStatus(isReserved);
                            } else{
                            // Increment the count
                            currentCount++;
                            isReserved = true;
                            // Update the count in the database
                            sendCountToFirebase(currentCount);
                            QMessageBox::information(parentWidget, "Rezervasyon", "Park alanı seçildi.");
                            emit reservationStatus(isReserved);
                            CarsInsideCount++;
                            updateReservationStatus(username,true);
                         }

                        } else {
                            QMessageBox::critical(parentWidget, "Error", "Failed to fetch current count.");
                         isReserved = false;
                         emit reservationStatus(isReserved);
                        }

                        countReply->deleteLater();
                    });
                }

                confirmationBox->deleteLater();
            } else {
                QMessageBox::warning(parentWidget, "Park Alanı Dolu", "Seçili park alanı dolu!");
                isReserved = false;
            }
        } else {
            QMessageBox::critical(parentWidget, "Error", "Failed to fetch parking space availability.");
            isReserved = false;
        }

        networkReply->deleteLater();
    });
}



void DatabaseHandler::sendDataToFirebase(const QByteArray& data, const QString& username)
{

    QNetworkRequest request(QUrl("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Users/" + username + ".json"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    m_networkReply = m_networkManager->put(request, data);
    connect(m_networkReply, &QNetworkReply::readyRead, this, &DatabaseHandler::networkReplyRead);
}


void DatabaseHandler::sendCountToFirebase(int count)
{
    // Convert the count to a JSON object
    QJsonObject countJson;
    countJson["count"] = count;

    QJsonDocument countDoc(countJson);
    QByteArray countByteArray = countDoc.toJson();

    // Send the count to Firebase
    QNetworkRequest request(QUrl("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/ReservationCount.json"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *countReply = m_networkManager->put(request, countByteArray);
    connect(countReply, &QNetworkReply::readyRead, this, &DatabaseHandler::networkReplyRead);
}

void DatabaseHandler::handleCarsInside(int count)
{
    // Convert the count to a JSON object
    QJsonObject countJson;
    countJson["count"] = count;

    QJsonDocument countDoc(countJson);
    QByteArray countByteArray = countDoc.toJson();

    // Send the count to Firebase
    QNetworkRequest request(QUrl("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Iceridekiler.json"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *countReply = m_networkManager->put(request, countByteArray);
    connect(countReply, &QNetworkReply::readyRead, this, &DatabaseHandler::networkReplyRead);
}

void DatabaseHandler::handleMotor(bool isOpen)
{
    QJsonObject countJson;
    countJson["Bariyer"] = isOpen;

    QJsonDocument countDoc(countJson);
    QByteArray countByteArray = countDoc.toJson();

    // Send the count to Firebase
    QNetworkRequest request(QUrl("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/motor.json"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *countReply = m_networkManager->put(request, countByteArray);
    connect(countReply, &QNetworkReply::readyRead, this, &DatabaseHandler::networkReplyRead);
}

int DatabaseHandler::getResCountFromFirebase()
{
    QNetworkRequest request(QUrl("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/ReservationCount.json"));
    QNetworkReply *countReply = m_networkManager->get(request);

    int count = -1;  // Default value indicating an error

    QEventLoop loop;
    connect(countReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    // Wait for the network request to finish
    loop.exec();

    if (countReply->error() == QNetworkReply::NoError) {
        QByteArray countResponse = countReply->readAll();
        count = QJsonDocument::fromJson(countResponse).object()["count"].toInt();
    }

    countReply->deleteLater();
    return count;
}

void DatabaseHandler::handleResCount(int count)
{
    // Convert the count to a JSON object
    QJsonObject countJson;
    countJson["count"] = count;

    QJsonDocument countDoc(countJson);
    QByteArray countByteArray = countDoc.toJson();

    // Send the count to Firebase
    QNetworkRequest request(QUrl("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app//ReservationCount.json"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QNetworkReply *countReply = m_networkManager->put(request, countByteArray);
    connect(countReply, &QNetworkReply::readyRead, this, &DatabaseHandler::networkReplyRead);
}

int DatabaseHandler::getInsideCountFromFirebase()
{
    QNetworkRequest request(QUrl("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Iceridekiler.json"));
    QNetworkReply *countReply = m_networkManager->get(request);

    int count = -1;  // Default value indicating an error

    QEventLoop loop;
    connect(countReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    // Wait for the network request to finish
    loop.exec();

    if (countReply->error() == QNetworkReply::NoError) {
        QByteArray countResponse = countReply->readAll();
        count = QJsonDocument::fromJson(countResponse).object()["count"].toInt();
    }

    countReply->deleteLater();
    return count;
}
QString DatabaseHandler::findFirstAvailableSlot()
{
    QString slotName = "";  // Default value indicating no available slot

    QNetworkRequest request(QUrl("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Locations/Davutpasa.json"));
    QNetworkReply *reply = m_networkManager->get(request);

    connect(reply, &QNetworkReply::finished, [&]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray response = reply->readAll();
            QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
            QJsonObject slotsData = jsonResponse.object();

            for (int i = 1; i <= 3; ++i) {
                QString slotKey = "Slot" + QString::number(i);
                bool isSlotAvailable = slotsData[slotKey].toBool();

                if (!isSlotAvailable) {
                    slotName = slotKey;
                    break;
                }
            }
        } else {
            qDebug() << "Error fetching slot information:" << reply->errorString();
        }

        reply->deleteLater();
    });

    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    // Wait for the network request to finish
    loop.exec();

    return slotName;
}

bool DatabaseHandler::checkSlotStatus(const QString& slotName)
{
    QString apiUrl = "https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Locations/Davutpasa.json";
    QNetworkRequest request;
    request.setUrl(QUrl(apiUrl));
    QNetworkReply* slotReply = m_networkManager->get(request);

    bool slotStatus = false;  // Default value indicating an error

    QEventLoop loop;
    connect(slotReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    // Wait for the network request to finish
    loop.exec();

    if (slotReply->error() == QNetworkReply::NoError) {
        QByteArray slotResponse = slotReply->readAll();
        QJsonObject slotsData = QJsonDocument::fromJson(slotResponse).object();

        if (slotsData.contains(slotName)) {
            slotStatus = slotsData[slotName].toBool();
        } else {
            qDebug() << "Slot not found in the response.";
        }
    } else {
        qDebug() << "Failed to fetch slot status.";
    }

    slotReply->deleteLater();
    return slotStatus;
}


void DatabaseHandler::updateReservationStatus(const QString& username, bool hasReservation)
{
    // Create a JSON object with the updated has_Reservation value
    QJsonObject userData;
    userData["status"] = hasReservation;

    // Convert the JSON object to a byte array
    QJsonDocument doc(userData);
    QByteArray data = doc.toJson();

    // Send the data to Firebase
    QNetworkRequest request(QUrl("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Users/" + username + "/has_Reservation.json"));
   // request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    m_networkReply = m_networkManager->put(request, data);
    connect(m_networkReply, &QNetworkReply::readyRead, this, &DatabaseHandler::networkReplyRead);
}

bool DatabaseHandler::checkReservationStatus(const QString& username)
{
    QNetworkRequest request(QUrl("https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/Users/" + username + "/has_Reservation/status.json"));
    QNetworkReply *statusReply = m_networkManager->get(request);

    bool hasReservation = false;  // Default value indicating an error or false status

    QEventLoop loop;
    connect(statusReply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    // Wait for the network request to finish
    loop.exec();

    if (statusReply->error() == QNetworkReply::NoError) {
        QByteArray statusResponse = statusReply->readAll();
        //hasReservation = QJsonDocument::fromJson(statusResponse).object()["status"].toBool();
        hasReservation = (statusResponse == "true");
    } else {
        qDebug() << "Failed to fetch reservation status.";
    }

    statusReply->deleteLater();
    return hasReservation;
}



