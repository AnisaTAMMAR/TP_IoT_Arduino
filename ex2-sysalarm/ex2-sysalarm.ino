int pinPIR = 2;
int pinLED = 8;
int pinBuzzer = 9;
bool armed = true;

void setup() {
  pinMode(pinPIR, INPUT);
  pinMode(pinLED, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  Serial.begin(9600);
  Serial.println("Tapez A pour armer, D pour désarmer");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == 'A') { armed = true; Serial.println("Système armé"); }
    if (c == 'D') { armed = false; Serial.println("Système désarmé"); }
  }

  if (armed) {
    int val = digitalRead(pinPIR);
    if (val == HIGH) {
      digitalWrite(pinLED, HIGH);
      digitalWrite(pinBuzzer, HIGH);
      delay(3000); // buzzer sonne 3 secondes (anti-spam)
      digitalWrite(pinBuzzer, LOW);
    } else {
      digitalWrite(pinLED, LOW);
    }
  }
}