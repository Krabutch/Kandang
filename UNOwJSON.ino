//using JSON library for converting sensor data to string
//https://engineeringprojectshub.com/serial-communication-between-nodemcu-and-arduino/
#include <SoftwareSerial.h>
#include <ArduinoJson.h>
SoftwareSerial s(3,4);
#include "DHT.h"
#define DHTPIN 2     
#define DHTTYPE DHT11   
DHT dht(DHTPIN, DHTTYPE);
 
void setup() {
  Serial.begin(9600);
  s.begin(115200);
  dht.begin();
}

StaticJsonBuffer<1000> jsonBuffer;
JsonObject& root = jsonBuffer.createObject();

void loop() {

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

if (isnan(h) || isnan(t)) {
    return;
  }
 
  // If the DHT-11 is not connected to correct pin or if it doesnot
  //work no data will be sent
  root["temp"] = t;
  root["hum"] = h;

if(s.available()>0)
{
 root.printTo(s);
}
}
