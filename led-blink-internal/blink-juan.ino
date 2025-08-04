// ESP32 Blink Example
// This code blinks the built-in LED on an ESP32

// Define the LED pin
// Most ESP32 boards have a built-in LED on pin 2
// Some boards may use different pins (like pin 5 or 22)
#define LED_PIN 2

void setup() {
  // Initialize the LED pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize serial communication for debugging (optional)
  Serial.begin(115200);
  Serial.println("ESP32 Blink Starting...");
}

void loop() {
  // Turn the LED on
  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
  
  // Wait for 1 second
  delay(1000);
  
  // Turn the LED off
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");
  
  // Wait for 1 second
  delay(1000);
}