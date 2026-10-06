
#include <Wire.h>             // Librerias requeridas
#include <SparkFun_ENS160.h> // SparkFun Indoor Air Quality Sensor EN160 
#include <Adafruit_AHTX0.h> // Adafruit AHTX0 AHT21 Bibliothek

//Connections
/// ESP -> Sensor
/// ------------
//  VIN -> VIN (5v)
//  GND -> GND
//  D22 -> SLC
//  D21 -> SLA

// Sensoren initialisieren
SparkFun_ENS160 ens160;
Adafruit_AHTX0 aht;

void setup() {

  delay(2000);
  Wire.begin(21,22);
  delay(2000);
  Serial.begin(9600); // Serielle Kommunikation initialisieren - 9600 bits pro Sekunde
  while (!Serial); // Warte auf Seriellen Monitor

  int not_found = 0;  

  // ENS160 initialisieren
  if (ens160.begin() == false) {
    Serial.println("ENS160 nicht gefunden. Bitte Verkabelung prüfen!");
    not_found = 1;
  }
  ens160.setOperatingMode(SFE_ENS160_RESET);
  delay(100);
  ens160.setOperatingMode(SFE_ENS160_STANDARD);

  // AHT21 initialisieren
  if (!aht.begin()) {
    Serial.println("AHT21 nicht gefunden. Bitte Verkabelung prüfen!");
    not_found = 1;
  }
  if (not_found==1) {
   //while(1);
  }


  Serial.println("Sensoren bereit!");
}


void find_devices() {
  byte error, address;
  int nDevices = 0;

  Serial.println("Scanning I2C bus...");

  for (address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
      nDevices++;
    }
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.println("Done\n");
  }

  delay(2000); // Wait 5 seconds before next scan
}


void ens_test() {

  Serial.println("Begin ens test 0x53-----");
  Wire.beginTransmission(0x53);
  Wire.write(0x00);
  Wire.endTransmission(false);
  Wire.requestFrom(0x53, 2);
  while(Wire.available()){
    Serial.println(Wire.read(), HEX);
  }
  Serial.println("--end ens test 0x53---------");
}

void loop() {
  //find_devices();
  // ENS160-Daten auslesen
  if (ens160.checkDataStatus()) {
    int aqi = ens160.getAQI();
    int co2 = ens160.getECO2();
    int voc = ens160.getTVOC();

    Serial.print("AQI: "); Serial.println(aqi);
    Serial.print("CO₂: "); Serial.print(co2); Serial.println(" ppm");
    Serial.print("VOC: "); Serial.print(voc); Serial.println(" ppb");

  } else {
    Serial.print("en160 getoperating mode was: ");
    Serial.println(ens160.getOperatingMode());
  }

  // AHT21-Daten auslesen
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  Serial.print("Temperatur: "); Serial.print(temp.temperature); Serial.println(" °C");
  Serial.print("Luftfeuchtigkeit: "); Serial.print(humidity.relative_humidity); Serial.println(" %");
  Serial.println("");
    
  //ens160.setOperatingMode(SFE_ENS160_IDLE);
  ens160.setOperatingMode(SFE_ENS160_DEEP_SLEEP);
  // Test
  //ens_test();
  delay(30000);
}