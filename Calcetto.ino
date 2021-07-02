#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;
#include "Settings.h"

void setup() {
  pinMode(AnalogSEL,OUTPUT);

  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("SSID", "Password");
  while ((WiFiMulti.run() != WL_CONNECTED) ) {
    delay(500);
    Serial.print(".");
  }
Sensors[0].ReqURL="http://www.samuelelonghin.it/calcetto/web/index.php?r=api%2Fset-gol&team=0";
Sensors[1].ReqURL="http://www.samuelelonghin.it/calcetto/web/index.php?r=api%2Fset-gol&team=1";


}


void loop() {
if ((WiFiMulti.run() == WL_CONNECTED)) { mod=1;}




checkSensors(currentAnalogSensor);
checkStat(currentAnalogSensor);


 

currentAnalogSensor=!currentAnalogSensor;

Serial.print("punti A: ");
Serial.print(Sensors[0].score);
Serial.print("  punti B: ");
Serial.print(Sensors[1].score);
Serial.println();
}

