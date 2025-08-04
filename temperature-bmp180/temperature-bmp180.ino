
///Need to install the library adafruit bmp085
// PINs
//  SDA -> GPIO 21 
//  SCL -> GPIO 22
//  VCC -> 3.3 V


#include <Wire.h>
#include <Adafruit_BMP085.h>




// Create BMP180 object
Adafruit_BMP085 bmp;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("BMP180 Sensor Test");
  
  // Initialize I2C communication
  Wire.begin();
  
  // Initialize BMP180 sensor
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP180 sensor, check wiring!");
    while (1) {
      delay(10000);
    }
  }
  
  Serial.println("BMP180 sensor initialized successfully!");
  Serial.println("Reading sensor data...");
  Serial.println("Temperature (°C) | Pressure (Pa) | Pressure (hPa) | Altitude (m)");
  Serial.println("----------------------------------------------------------------");
}

void loop() {
  // Read temperature in Celsius
  float temperature = bmp.readTemperature();
  
  // Read pressure in Pascals
  long pressure = bmp.readPressure();
  
  // Convert pressure to hPa (hectoPascals)
  float pressureHPa = pressure / 100.0;
  
  // Calculate altitude (assuming sea level pressure = 101325 Pa)
  float altitude = bmp.readAltitude();
  
  // Display readings on serial monitor
  Serial.print(temperature);
  Serial.print(" °C        | ");
  Serial.print(pressure);
  Serial.print(" Pa    | ");
  Serial.print(pressureHPa);
  Serial.print(" hPa     | ");
  Serial.print(altitude);
  Serial.println(" m");
  
  // Wait 2 seconds before next reading
  delay(2000);
}

// Optional: Function to read pressure at a specific altitude
float readPressureAtAltitude(float altitude) {
  return bmp.readPressure() / pow(1.0 - altitude/44330.0, 5.255);
}

// Optional: Function to calculate altitude with custom sea level pressure
float calculateAltitude(float seaLevelPressure) {
  float atmospheric = bmp.readPressure() / 100.0F;
  return 44330.0 * (1.0 - pow(atmospheric / seaLevelPressure, 0.1903));
}