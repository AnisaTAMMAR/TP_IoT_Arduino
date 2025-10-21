int pinPIR = 2;
int pinLED = 8;
int val = 0;

void setup() {
  pinMode(pinPIR, INPUT);
  pinMode(pinLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(pinPIR);

  if (val == HIGH) {
    digitalWrite(pinLED, HIGH);
    Serial.println("Mouvement détecté");
  } else {
    digitalWrite(pinLED, LOW);
    Serial.println("Aucun mouvement");
  }
}