#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "Settings.h"



void setup() {
  pinMode(AnalogSEL,OUTPUT);

  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("SSID", "Password");
  while (WiFi.status() != WL_CONNECTED &&0) {
    delay(500);
  }


}


void loop() {
  nReq = 10;

checkSensors(currentAnalogSensor);
checkStat(currentAnalogSensor);

  WiFiClient client;
  HTTPClient http;
  while (http.begin(client, "req link") && nReq > 0) {
    nReq--;
  }

currentAnalogSensor=!currentAnalogSensor;

Serial.print("punti A: ");
Serial.print(Sensors[0].score);
Serial.print("  punti B: ");
Serial.print(Sensors[1].score);
Serial.println();
}