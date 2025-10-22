

#define STEPPER_PIN_1 9
#define STEPPER_PIN_2 10
#define STEPPER_PIN_3 11
#define STEPPER_PIN_4 12

int step_number = 0;       /

// -------------------- CAPTEUR PIR --------------------
const int pirPin = 8;       // Pin du capteur PIR
bool pirState = false;      // État du PIR: true = mouvement détecté

// -------------------- BUZZER --------------------
const int buzzerPin = 7;    // Pin pour le buzzer

// -------------------- PARAMÈTRES MOTEUR --------------------
int stepDelay = 5;          // Délai entre chaque étape (ms), contrôle la vitesse
bool motorDirection = true; // Direction du moteur: true = avance, false = recule

void setup() {
  // Définir les pins du moteur comme sorties
  pinMode(STEPPER_PIN_1, OUTPUT);
  pinMode(STEPPER_PIN_2, OUTPUT);
  pinMode(STEPPER_PIN_3, OUTPUT);
  pinMode(STEPPER_PIN_4, OUTPUT);

  // Définir le pin PIR comme entrée
  pinMode(pirPin, INPUT);

  // Définir le pin buzzer comme sortie
  pinMode(buzzerPin, OUTPUT);

  // Initialisation série pour debug
  Serial.begin(9600);
}

void loop() {
  // Lire l'état du PIR
  pirState = digitalRead(pirPin);

  // Si mouvement détecté → augmenter la vitesse, inverser la direction, activer buzzer
  if (pirState) {
    stepDelay = 2;                       // moteur plus rapide
    motorDirection = !motorDirection;    // inversion de la direction
    Serial.println("Mouvement détecté! Vitesse augmentée et direction inversée");

    // Activer le buzzer
    digitalWrite(buzzerPin, HIGH);  
  } 
  else {
    // Pas de mouvement → vitesse normale, direction avance, buzzer éteint
    stepDelay = 5;
    motorDirection = true;
    Serial.println("Pas de mouvement, vitesse normale");

    // Désactiver le buzzer
    digitalWrite(buzzerPin, LOW);
  }

  // Effectuer une étape dans la direction choisie
  OneStep(motorDirection);

  // Délai pour contrôler la vitesse
  delay(stepDelay);
}

// Fonction pour effectuer une seule étape du moteur
// dir = true → avance, dir = false → recule
void OneStep(bool dir){
  if(dir){
    // Séquence pour avancer
    switch(step_number){
      case 0:
        digitalWrite(STEPPER_PIN_1, HIGH);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 1:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, HIGH);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 2:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, HIGH);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 3:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, HIGH);
        break;
    } 
  } 
  else {
    // Séquence pour reculer
    switch(step_number){
      case 0:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, HIGH);
        break;
      case 1:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, HIGH);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 2:
        digitalWrite(STEPPER_PIN_1, LOW);
        digitalWrite(STEPPER_PIN_2, HIGH);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
      case 3:
        digitalWrite(STEPPER_PIN_1, HIGH);
        digitalWrite(STEPPER_PIN_2, LOW);
        digitalWrite(STEPPER_PIN_3, LOW);
        digitalWrite(STEPPER_PIN_4, LOW);
        break;
    } 
  }

  // Passer à l'étape suivante
  step_number++;
  if(step_number > 3){
    step_number = 0;
  }
}
