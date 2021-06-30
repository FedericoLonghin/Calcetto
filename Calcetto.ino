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
  Sensors[0].ReqURL="";
  Sensors[1].ReqURL="";
  Sensors[0].threshold=500;
  Sensors[1].threshold=500;
}


void loop() {
  nReq = 10;

checkSensors(0);

  WiFiClient client;
  HTTPClient http;
  while (http.begin(client, "req link") && nReq > 0) {
    nReq--;
  }
  
currentAnalogSensor=!currentAnalogSensor;

}