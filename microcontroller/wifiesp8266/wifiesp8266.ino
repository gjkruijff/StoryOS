#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <WiFiEspServer.h>

// ESP8266 Wifi using WiFiESP library 

char ssid[] = "FRITZ!Box 6360 Cable";
char pass[] = "7269254594953942";
int status = WL_IDLE_STATUS;  

const byte rxPin = 6; // wire this to Tx pin of ESP8266
const byte txPin = 7; // wire this to Rx pin of ESP8266 

#ifndef HAVE_HWSERIAL1
#include <SoftwareSerial.h>
SoftwareSerial ESP8266(rxPin, txPin); 
#endif

void setup() {
  // initialize serial for debugging
  Serial.begin(9600);

  Serial.println("Serial monitor initialized"); 
  
  // initialize serial for ESP module
  ESP8266.begin(115200); 
  // initialize ESP module 
  WiFi.init(&ESP8266); 

  // check for the presence of the shield 
  if (WiFi.status() == WL_NO_SHIELD) { 
     Serial.println("Wifi shield not present");
     // don't continue
     while (true); 
  }

     
}

void loop() {
  // put your main code here, to run repeatedly:

}
