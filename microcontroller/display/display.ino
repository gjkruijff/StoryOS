#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


void setup() {
  Serial.begin(9600); 
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c); 
  display.display();
  delay(2000); 

  // clear the buffer
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(50,0);
  display.setTextColor(WHITE);
}

void loop() {
  float sensor = analogRead(A0); 
  Serial.println(sensor);
  display.setCursor(0,0);
  display.println("hello mars!");
  display.setCursor(0,15);
  display.print("Value: ");
  display.println(sensor);
  display.display(); // you have to tell the display to display
  delay(200);
  display.clearDisplay();
  
}
