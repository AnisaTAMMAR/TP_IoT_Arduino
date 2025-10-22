#include <AFMotor.h>

// Moteur DC branché sur le canal M1 du shield L293D
AF_DCMotor motor(4);

int speedValue = 0; // Valeur de vitesse entrée par l'utilisateur (0–255)

void setup() {
  Serial.begin(9600);  // Initialisation de la communication série
  Serial.println("=== Mini Ventilateur DC (PWM Control) ===");
  Serial.println("Entrez une valeur de vitesse entre 0 et 255 :");

  motor.run(RELEASE); // Moteur arrêté au démarrage
}

void loop() {
  // Vérifie si une donnée est disponible depuis le port série
  if (Serial.available()) {
    // Lecture de la valeur entrée
    speedValue = Serial.parseInt();

    // Vérification des bornes (sécurité)
    if (speedValue < 0) speedValue = 0;
    if (speedValue > 255) speedValue = 255;

    // Application de la vitesse
    motor.setSpeed(speedValue);

    if (speedValue == 0) {
      motor.run(RELEASE);  // arrêt du moteur
      Serial.println("Moteur arrêté.");
    } else {
      motor.run(FORWARD);  // rotation avant
      Serial.print("Vitesse du moteur : ");
      Serial.println(speedValue);
    }

    // Message de rappel
    Serial.println("Entrez une nouvelle valeur (0–255) :");
  }
}