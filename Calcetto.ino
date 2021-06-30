#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

//PIN
#define MUXSelect 1
struct Sensor{
  int threshold;
  bool stat;
  bool isAvailable;
};
struct Sensor Sensors;
int nReq;
bool currentSensor;


void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin("SSID", "Password");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}


void loop() {
  nReq = 10;

checkSensors();

  WiFiClient client;

  HTTPClient http;

  while (http.begin(client, "req link") && nReq > 0) {
    nReq--;
  }

}

void checkSensors(){
  pinMode(MUXSelect,currentSensor?1:0);
  delay(0);
  Sensors[currentSensor].stat=analogRead(A0)>Sensors[currentSensor].treshold;
  
}
