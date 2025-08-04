// Requires Adafruit DAM neopixel library

#include <Adafruit_NeoPixel.h>

// Define the pin connected to the RGB LED
// Common pins for ESP32-S3 dev boards: 38, 48, or 2
// Check your specific board's documentation
#define RGB_LED_PIN 48
#define NUM_PIXELS 1

// Create NeoPixel object
Adafruit_NeoPixel pixels(NUM_PIXELS, RGB_LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  pixels.begin(); // Initialize the NeoPixel library
  pixels.clear(); // Turn off the LED initially
  pixels.show();
  
  Serial.println("ESP32-S3 RGB LED Demo Starting...");
}

void loop() {
  // Cycle through different colors
  
  // Red
  setColor(255, 0, 0);
  Serial.println("Red");
  delay(1000);
  
  // Green
  setColor(0, 255, 0);
  Serial.println("Green");
  delay(1000);
  
  // Blue
  setColor(0, 0, 255);
  Serial.println("Blue");
  delay(1000);
  
  // Yellow (Red + Green)
  setColor(255, 255, 0);
  Serial.println("Yellow");
  delay(1000);
  
  // Magenta (Red + Blue)
  setColor(255, 0, 255);
  Serial.println("Magenta");
  delay(1000);
  
  // Cyan (Green + Blue)
  setColor(0, 255, 255);
  Serial.println("Cyan");
  delay(1000);
  
  // Purple
  setColor(128, 0, 128);
  Serial.println("Purple");
  delay(1000);
  
  // Orange
  setColor(255, 165, 0);
  Serial.println("Orange");
  delay(1000);
  
  // White
  setColor(255, 255, 255);
  Serial.println("White");
  delay(1000);
  
  // Turn off
  setColor(0, 0, 0);
  Serial.println("Off");
  delay(1000);
  
  // Rainbow effect
  rainbow(10);
  
  // Breathing effect
  breathingEffect(255, 0, 100, 50); // Red breathing
}

// Function to set RGB color
void setColor(uint8_t red, uint8_t green, uint8_t blue) {
  pixels.setPixelColor(0, pixels.Color(red, green, blue));
  pixels.show();
}

// Rainbow cycling effect
void rainbow(int wait) {
  Serial.println("Rainbow effect");
  for(long firstPixelHue = 0; firstPixelHue < 5*65536; firstPixelHue += 256) {
    int pixelHue = firstPixelHue;
    pixels.setPixelColor(0, pixels.gamma32(pixels.ColorHSV(pixelHue)));
    pixels.show();
    delay(wait);
  }
}

// Breathing effect
void breathingEffect(uint8_t red, uint8_t green, uint8_t blue, int steps) {
  Serial.println("Breathing effect");
  
  // Fade in
  for(int brightness = 0; brightness <= 255; brightness += (255/steps)) {
    uint8_t r = (red * brightness) / 255;
    uint8_t g = (green * brightness) / 255;
    uint8_t b = (blue * brightness) / 255;
    setColor(r, g, b);
    delay(20);
  }
  
  // Fade out
  for(int brightness = 255; brightness >= 0; brightness -= (255/steps)) {
    uint8_t r = (red * brightness) / 255;
    uint8_t g = (green * brightness) / 255;
    uint8_t b = (blue * brightness) / 255;
    setColor(r, g, b);
    delay(20);
  }
}