// Hello World of the OLED display
//
// PINS OLED Display
// SCL -> D22
// SDA -> D21
// Requires library Adafruit SSD1306
// To install it go to Tools -> Manage libraries
// It will install also Adafruit BusIO and
// Adafruit GFX library
// 
// Based on this tutorial:
// https://lastminuteengineers.com/oled-display-esp32-tutorial/


#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 //PX
#define SCREEN_HEIGHT 64 //PX

// Declaration of SSD1306 connected using I2C
#define OLED_RESET -1 //Reset pin
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
    setCpuFrequencyMhz(80);

    Serial.begin(115200);
    Wire.begin();

    Serial.println("Inicio programa");
    //initialize the oled object
    if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
      Serial.println(F("Failed to allocate screen"));
      for(;;)
      ; //Dont proceed loop forever and ever
    }

    //Clear the display
    display.clearDisplay();
    
    // setup the text
    display.setTextSize(2); //1 -> small, 2 medium, 3 big
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0,0); //x,y
    display.println("INDIRA");
    display.setTextSize(3);
    display.println("PAPA");
    display.println("MAMA");

    display.display();
    
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("loop");
  delay(1000);
}
