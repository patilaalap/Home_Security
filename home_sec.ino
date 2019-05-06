  
#include "ESP8266WiFi.h"
#include <SoftwareSerial.h>
#include <BlynkSimpleEsp8266.h>

//************************** PIR Motion Sensor Setup *************************
int ledPin = D5;
int pirPin = D6;
int val = 0;
char auth[] = "3c4a440f147245f58b977b1f0b3c2305";
int pirValue;

//************************** WiFi Access Point *******************************

#define WLAN_SSID "Aalap"
#define WLAN_PWD "aalap123"
#define BLYNK_PRINT Serial

//****************************************************************************


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Blynk.begin(auth, WLAN_SSID, WLAN_PWD);
  pinMode(ledPin, OUTPUT);
  pinMode(pirPin, INPUT);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  getPirValue();
  Blynk.run();
}

void getPirValue() {
  pirValue = digitalRead(pirPin);
  if(pirValue) {
    Serial.println("==> Intruder ALERT!!!!");
    Blynk.notify("T==> Intruder ALERT!!!!");
  }
  digitalWrite(ledPin, pirValue);
}
