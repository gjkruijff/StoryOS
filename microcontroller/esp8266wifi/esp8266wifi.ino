
#include <SoftwareSerial.h>

// Basic code for ESP8266 WIFI 

const byte rxPin = 2; // wire this to Tx pin of ESP8266
const byte txPin = 3; // wire this to Rx pin of ESP8266 

// Use a software serial interface to connect to ESP8266
SoftwareSerial ESP8266 (rxPin, txPin); 

void setup() {
  Serial.begin(9600); 

  Serial.println("Setting default BAUDRATE"); 
  ESP8266.begin(115200); 
  delay(1000); 


  Serial.println("Setting BAUDRATE to 9600");   
  ESP8266.println("AT+IPR=9600"); 

  
}

bool okReceived = false; 

void loop() {
  if (Serial.available() > 0) 
  { 
     String command = Serial.readStringUntil('\n'); 
     Serial.println("Command sent: "+command); 
     Serial.println();
     ESP8266.println(command+"\r"); 
  }

  String responseBuffer;
  char charIn;

  int responseCounter = 0;
  if (ESP8266.available() > 0) 
  {
    Serial.println("ESP8266 available"); 
    while (ESP8266.available() > 0) 
    {
      if (responseCounter == 0) 
      {
        Serial.println("Response received: "); 
      }
      String response = ESP8266.readStringUntil('\r'); 
      Serial.println(response); 
      responseCounter++; 
    } // end while 
    Serial.println(); 
    Serial.println("=================");
    Serial.println(); 
  } // end if available 
} // end loop 
