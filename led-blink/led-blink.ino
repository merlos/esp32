
#define LED_D2 2
#define LED_D4 4
#define LED_D5 5


void setup() {
  // put your setup code here, to run once:
  pinMode(LED_D2, OUTPUT);
  pinMode(LED_D4, OUTPUT);
  pinMode(LED_D5, OUTPUT);

  Serial.begin(115200);
  Serial.println("ESP led blink start");
}



void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(LED_D2, HIGH);
  digitalWrite(LED_D4, HIGH);
  digitalWrite(LED_D5, HIGH);
  delay(500);
  Serial.println("Hola");
  digitalWrite(LED_D2, LOW);
  digitalWrite(LED_D4, LOW);
  digitalWrite(LED_D5, LOW);
  delay(500);

}
