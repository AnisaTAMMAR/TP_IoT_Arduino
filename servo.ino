#include <Servo.h>

Servo myServo;

const int SERVO_PIN = 9;   // Broche signal du servo sur le shield ou directement sur D9
const int POS1 = 45;       // Position 1
const int POS2 = 120;      // Position 2

void setup() {
  Serial.begin(9600);       // Communication série (USB)
  Serial.println("=== Controle Servo ===");
  Serial.println("Envoyez 1 pour 45°  |  2 pour 120°");

  myServo.attach(SERVO_PIN);
  myServo.write(POS1);      // Position initiale
}

void loop() {
  if (Serial.available()) {
    int cmd = Serial.parseInt();   // Lire commande

    switch (cmd) {
      case 1:
        myServo.write(POS1);
        Serial.println("Servo -> 45°");
        break;

      case 2:
        myServo.write(POS2);
        Serial.println("Servo -> 120°");
        break;

      default:
        Serial.println("Commande invalide (1 ou 2)");
        break;
    }

    Serial.println("Nouvelle commande : 1 ou 2");
  }
}