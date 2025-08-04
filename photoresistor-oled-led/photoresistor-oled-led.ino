
// Photo resistor 
#define LDR_PIN 34

// Led 
#define LED_PIN 4
// Oled display

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int ldr_value = analogRead(LDR_PIN);
  Serial.println(ldr_value);
  if (ldr_value > 500) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(1000);

}
