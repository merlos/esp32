// ESP32 DHT11 Temperature and Humidity Reader
// This code reads temperature and humidity from a DHT11 sensor

#include "DHT.h"

// Define the DHT11 sensor pin and type
#define DHT_PIN 4        // GPIO pin where DHT11 data pin is connected
#define DHT_TYPE DHT22   // DHT sensor type
#define LED_PIN 2

// Initialize DHT sensor
DHT dht(DHT_PIN, DHT_TYPE);


void blink_delay() {

  digitalWrite(LED_PIN, HIGH);
  Serial.println("LED ON");
  
  // Wait for 1 second
  delay(1000);
  
  // Turn the LED off
  digitalWrite(LED_PIN, LOW);
  Serial.println("LED OFF");
  
  // Wait for 1 second
  delay(1000);
  

void setup() {

  //Initialize the led pin as an output
  pinMode(LED_PIN, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(115200);

  Serial.println("DHT22 Temperature & Humidity Sensor");
  Serial.println("====================================");
  
  // Initialize the DHT sensor
  dht.begin();
  
  // Wait a moment for sensor to stabilize
  delay(2000);
}

void loop() {
  // Read humidity and temperature
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();        // Celsius
  float temperatureF = dht.readTemperature(true);   // Fahrenheit
  
  // Check if readings are valid
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    blink_delay();
    return;
  }
  
  // Calculate heat index (feels like temperature)
  float heatIndexC = dht.computeHeatIndex(temperature, humidity, false);
  float heatIndexF = dht.computeHeatIndex(temperatureF, humidity);
  
  // Display readings on Serial Monitor
  Serial.println("─────────────────────────────────");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C / ");
  Serial.print(temperatureF);
  Serial.println(" °F");
  
  Serial.print("Heat Index: ");
  Serial.print(heatIndexC);
  Serial.print(" °C / ");
  Serial.print(heatIndexF);
  Serial.println(" °F");
  
  // Wait 2 seconds before next reading
  blink_delay();
}