#include <Arduino.h>
#include <Servo.h>
#if defined(ESP32)
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>
#include <LiquidCrystal_I2C.h>
//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"
// Insert your network credentials
#define WIFI_SSID "iPhone"
#define WIFI_PASSWORD "241412onurr"
// Firebase proje API Key'i girin
#define API_KEY "AIzaSyBgPy0y93E6XyrkAZXkma41gKmh8Pt-n0E"
// Veritabanı URL'sini girin */
#define DATABASE_URL "https://smartparkgui-fc48e-default-rtdb.europe-west1.firebasedatabase.app/"
//Define Firebase Data object
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
unsigned long sendDataPrevMillis = 0;
bool signupOK = false;
#define RXp2 16
#define TXp2 17
#define SERVO_PIN 26 // ESP32 pin GPIO26 connected to servo motor
Servo servoMotor;
char metinRead[20];  // Dizinin boyutunu belirtin
char sendData[] = "hazir";
char sendData2[] = "aldim";
int counter = 0;
int i = 0;
bool servo;
int pos = 90;
int pos1 = 180;
bool boolArray [3];
bool ctrlArray [3]= {1,1,1};
bool ctrl=1;
bool ctrl2=1;
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
int toplamRez;
int toplamSlot=3; // Örnek bir integer değeri
int bosSlot;

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200, SERIAL_8N1, RXp2, TXp2);
  lcd.init(); // LCD'yi başlat
  lcd.backlight();
  servoMotor.attach(SERVO_PIN); 
  delay(100);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")){
    Serial.println("ok");
    signupOK = true;
  }
  else{
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }
  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
}

void loop() {

  while (1) {
    // Seri2 üzerinden "hazir" mesajını tekrar gönder
    Serial2.println(sendData);
    Serial.println("Hazirim Data bilgisi gönderildi");
    delay(100);

    // Seri2 üzerinden bir satır okuyun
    String receivedData = Serial2.readStringUntil('\n');
    receivedData.trim();  // Baştaki ve sondaki boşlukları kaldır

    // Okunan satırı metinRead dizisine kopyala
    strncpy(metinRead, receivedData.c_str(), sizeof(metinRead));

    // MetinRead dizisindeki karakter sayısını say
    for (i = 0; i <5; i++) {
      if (metinRead[i]) {
        counter++;
        }
    }

    // Eğer counter 3'e ulaşırsa döngüyü sonlandır
    if (counter == 3) {
      break;
    }

    // Counter'ı sıfırla ve bir sonraki iterasyona geç
    counter = 0;
  }

  counter = 0;
  Serial2.println(sendData2);
  delay(100);
  Serial.println("Veriyi aldim data bilgisi gonderildi");
  for (int i = 0; i < 3; i++) {
        boolArray[i] = (metinRead[i] == '1');
    }


  // part 2
 // if(ctrlArray[1]!=boolArray[1] || ctrlArray[2]!=boolArray[2] || ctrlArray[3]!=boolArray[3]){  } 
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();
    
    FirebaseJson json;

    for (int i = 0; i <3; ++i) {
      String slotKey = "Slot" + String(i + 1);
      json.add(slotKey.c_str(), boolArray[i]);
    }
    FirebaseJson *jsonPtr = &json;

    // updateNode fonksiyonuna FirebaseJson işaretçisini geçir
    if (Firebase.RTDB.updateNode(&fbdo, "/Locations/Davutpasa", jsonPtr)) { //test
      Serial.println("Güncelleme başarılı!");
    } else {
      Serial.println("Güncelleme başarısız. Hata: " + fbdo.errorReason());
    }
  }
 
  /*
for(int i = 0 ; i<3;i++){
    Serial.println(ctrlArray[i]);
  Serial.println(boolArray[i]);
}
  for(int i = 0; i<3; i++){
    ctrlArray[i]=boolArray[i];
  }
  */
  delay (5000);

  if (Firebase.RTDB.getBool(&fbdo, "/motor/Bariyer")){
  servo = fbdo.boolData();
  Serial.println(servo);
  delay(100);
    if (servo){
      servoMotor.write(pos);
      while (1){
      
      delay(5000);

      if (Firebase.RTDB.getBool(&fbdo, "/motor/Bariyer")){  //test/servo
      servo = fbdo.boolData();
      Serial.println(servo);
      
      if(servo==0){
        servoMotor.write(pos1);
        
        break;
      }
      }
      }
    }
    else {
      servoMotor.write(pos1);
    }
  }

  servo=0;
  delay(5000);

  if (Firebase.RTDB.getInt(&fbdo, "/ReservationCount/count")) { //test2/total
      toplamRez = fbdo.intData();
      Serial.println(toplamRez);
      bosSlot=toplamSlot-toplamRez;
      }
    else {
      Serial.println(fbdo.errorReason());
    }
  
  lcd.clear();              // Ekranı temizle
  lcd.setCursor(0, 0);      // Cursor'u (0, 0) konumuna getir
  lcd.print("Dolu: "); // İlk mesajı ekrana yazdır
  lcd.print(toplamRez);         // Integer değeri aynı satıra yazdır
  lcd.setCursor(0, 1);
  lcd.print("Bos : "); // İlk mesajı ekrana yazdır
  lcd.print(bosSlot); 
  delay(2000);
 
}
