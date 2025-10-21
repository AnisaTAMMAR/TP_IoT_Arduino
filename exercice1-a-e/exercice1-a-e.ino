/* 
  Envoi et réception d’un message via le port série
  Commande de la LED :
  - Envoyer 'a' pour allumer
  - Envoyer 'e' pour éteindre
*/

int led = 9;          // Broche de la LED
char octet_rx = 0;    // Variable pour stocker le caractère reçu

void setup() {
  pinMode(led, OUTPUT);     // Définir la LED comme sortie
  Serial.begin(9600);       // Initialiser la communication série
  Serial.println("Tapez 'a' pour allumer la LED, 'e' pour l’éteindre.");
}

void loop() {
  // Vérifie si un caractère a été reçu depuis le port série
  if (Serial.available() > 0) {
    octet_rx = Serial.read();   // Lire le caractère reçu

    if (octet_rx == 'a') {      // 'a' = allumer
      digitalWrite(led, HIGH);
      Serial.println("LED allumée");
    } 
    else if (octet_rx == 'e') { // 'e' = éteindre
      digitalWrite(led, LOW);
      Serial.println("LED éteinte");
    }
  }
}