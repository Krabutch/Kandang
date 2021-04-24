//using JSON library for converting sensor data to string
//https://engineeringprojectshub.com/serial-communication-between-nodemcu-and-arduino/

#include <SoftwareSerial.h>
SoftwareSerial s(D4,D3);
#include <ArduinoJson.h>
 
void setup() {
  // Initialize Serial port
  Serial.begin(115200);
  s.begin(115200);
  while (!Serial) continue;
}
 
void loop() {
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);
 
  if (root == JsonObject::invalid())
  {
    return;
  }
  //Print the data in the serial monitor
  Serial.println("JSON received and parsed");
  root.prettyPrintTo(Serial);
  Serial.println("");
  Serial.print("Temperature ");
  int data1=root["temp"];
  Serial.println(data1);
  Serial.print("Humidity    ");
  int data2=root["hum"];
  Serial.println(data2);
  Serial.println("");
  Serial.println("---------------------xxxxx--------------------");
 Serial.println("");
 delay(1000);
}
