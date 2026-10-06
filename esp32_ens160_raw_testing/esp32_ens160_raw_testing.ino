#include <Wire.h>




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

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1000);
  Wire.begin(21,22);

  find_devices();

  Serial.println("****************");
  Wire.beginTransmission(0x38);
  int e = Wire.endTransmission();
  Serial.print("ACK 0x38 = ");
  Serial.println(e);
  int n = Wire.requestFrom(0x38, 1);
  Serial.print("Bytes 0x38 = ");
  Serial.println(n);

  Wire.beginTransmission(0x53);
  int e2 = Wire.endTransmission();
  Serial.print("ACK 0x53 = ");
  Serial.println(e2);
  int n2 = Wire.requestFrom(0x53, 1);
  Serial.print("Bytes 0x53 = ");
  Serial.println(n2);
  Serial.println("****************");
  
  

  Serial.println("Begin enstest-----");
  Wire.beginTransmission(0x53);
  Wire.write(0x00);
  byte err = Wire.endTransmission(false);
  Serial.print("End transmission= ");
  Serial.println(err);

  int count = Wire.requestFrom(0x53, 2);
  
  Serial.print("Byts returned = ");
  Serial.println(count);



  while(Wire.available()){
    Serial.println(Wire.read(), HEX);
  }
  Serial.println("-----------");
  
  
  
  int count2 = Wire.requestFrom(0x38, 1);
  
  Serial.print("AHT Byts returned = ");
  Serial.println(count2);

  
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:

}
