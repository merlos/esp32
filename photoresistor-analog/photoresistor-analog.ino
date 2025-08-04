
#define LDR_PIN 34

void setup() {
  // put your setup code here, to run once:
  pinMode(LDR_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  int ldr_value = analogRead(LDR_PIN);
  Serial.println(ldr_value);
  delay(1000);

}
