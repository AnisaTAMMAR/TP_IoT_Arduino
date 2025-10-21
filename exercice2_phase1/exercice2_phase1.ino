int led1 = 8;   // première LED connectée à la broche 8
int led2 = 9;   // deuxième LED connectée à la broche 9

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Test des deux LEDs...");
}

void loop() {
  // Allumer LED1 et éteindre LED2
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  Serial.println("LED1 allumée, LED2 éteinte");
  delay(1000); // attendre 1 seconde

  // Éteindre LED1 et allumer LED2
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  Serial.println("LED1 éteinte, LED2 allumée");
  delay(1000); // attendre 1 seconde

  // Allumer les deux
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  Serial.println("Les deux LEDs sont allumées");int pinEntree = 2;     // Broche pour capteur PIR
int etatPir = LOW;     // Aucun mouvement détecté au départ
int val = 0;           // Variable pour lecture du PIR

void setup() {
  pinMode(pinEntree, INPUT);  // Déclarer le capteur en entrée
  Serial.begin(9600);         // Démarrer la communication série
}

void loop() {
  val = digitalRead(pinEntree);  // Lire la valeur du capteur

  if (val == HIGH) {             // Si mouvement détecté
    if (etatPir == LOW) {        // Si c’est un nouveau mouvement
      Serial.println("Mouvement détecté !");
      etatPir = HIGH;
    }
  } else {
    if (etatPir == HIGH) {       // Si le mouvement s'arrête
      Serial.println("Mouvement terminé !");
      etatPir = LOW;
    }
  }
}
  delay(1000);

  // Éteindre les deux
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  Serial.println("Les deux LEDs sont éteintes");
  delay(1000);
}