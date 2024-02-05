#include "NewPing.h"

#define TRIGGER_PIN_1 9
#define ECHO_PIN_1 10

#define TRIGGER_PIN_2 6
#define ECHO_PIN_2 7

#define TRIGGER_PIN_3 3
#define ECHO_PIN_3 4

#define MAX_DISTANCE 400

NewPing sonar1(TRIGGER_PIN_1, ECHO_PIN_1, MAX_DISTANCE);
NewPing sonar2(TRIGGER_PIN_2, ECHO_PIN_2, MAX_DISTANCE);
NewPing sonar3(TRIGGER_PIN_3, ECHO_PIN_3, MAX_DISTANCE);
char data[3];
float distance1, distance2, distance3;
char receivedData[20];  // receivedData karakter dizisi olarak değiştirildi
char metinReady[] = "hazir";
char metinReady2[] = "aldim";
int sonuc = 2;
int counter = 0;
int i = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Ping gönder, her sensör için cm cinsinden mesafeyi al
  while (1) {
    String tempData = Serial.readStringUntil('\n');
    tempData.trim();
    strncpy(receivedData, tempData.c_str(), sizeof(receivedData));  // receivedData'ya kopyala
    if (strcmp(receivedData, metinReady) == 0) {
      break;
    }
  }

  while (1) {
    distance3 = sonar1.ping_cm();
    delay(50);
    distance2 = sonar2.ping_cm();
    delay(50);
    distance1 = sonar3.ping_cm();
    delay(50);
    
    sonuc = printDistance(distance1);
    if (sonuc == 1) {
      data[0] = '1';
    } else {
      data[0] = '0';
    }
    
    sonuc = printDistance(distance2);
    if (sonuc == 1) {
      data[1] = '1';
    } else {
      data[1] = '0';
    }
    
    sonuc = printDistance(distance3);
    if (sonuc == 1) {
      data[2] = '1';
    } else {
      data[2] = '0';
    }
    
    Serial.println(data);
    delay(100);
    
    String tempData = Serial.readStringUntil('\n');
    tempData.trim();
    strncpy(receivedData, tempData.c_str(), sizeof(receivedData));  // receivedData'ya kopyala
    if (strcmp(receivedData, metinReady2) == 0) {
      break;
    }
  }
}

int printDistance(float dist) {
  if (dist > 0 && dist < 10) {
    return 1;
  } else {
    return 0;
  }
}
