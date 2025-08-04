
#include <WiFi.h>

// DON'T COMMIT CODE TO A REPO WITH ACTUAL PASSWORDS
// use a secrets.h file instead (see connect-https)

const char* ssid = "change-me";
const char* pwd = "change-me"; 

void setup() {
  Serial.begin(115200);
  delay(1000);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, pwd);
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }
  Serial.println("Wifi connected");
  Serial.print("IP:");
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:

}
