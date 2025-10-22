int led1 = 8;     // LED 1 sur la broche 8
int led2 = 9;     // LED 2 sur la broche 9

unsigned long previousMillis1 = 0;
unsigned long previousMillis2 = 0;

unsigned long period1 = 0; // P1 en ms
unsigned long period2 = 0; // P2 en ms

bool etatLed1 = LOW;
bool etatLed2 = LOW;

String inputString = "";
bool inputComplete = false;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.println("=== Controle de deux LEDs avec P1 et P2 ===");
  Serial.println("Entrez deux periodes (en millisecondes), separees par un espace. Exemple: 500 800");
  Serial.println("Chaque LED s’allumera pendant sa periode, puis s’eteindra pendant la meme duree.");
}

void loop() {
  // Lecture des entrees utilisateur
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (c == '\n' || c == '\r') {
      inputComplete = true;
    } else {
      inputString += c;
    }
  }

  // Si une ligne complete est recue
  if (inputComplete) {
    unsigned long p1, p2;
    int n = sscanf(inputString.c_str(), "%lu %lu", &p1, &p2);

    if (n == 2 && p1 > 0 && p2 > 0 && p1 <= 10000 && p2 <= 10000) {
      period1 = p1;
      period2 = p2;
      Serial.print("Periode LED1 = "); Serial.print(period1); Serial.print(" ms, ");
      Serial.print("Periode LED2 = "); Serial.print(period2); Serial.println(" ms");
      Serial.println("Clignotement en cours...");
    } else {
      Serial.println("Entree invalide. Saisissez deux nombres entre 1 et 10000 separes par un espace.");
    }

    inputString = "";
    inputComplete = false;
  }

  // Gestion du clignotement sans delay()
  unsigned long currentMillis = millis();

  // LED1 : alterne entre allumee et eteinte toutes les period1 ms
  if (period1 > 0 && currentMillis - previousMillis1 >= period1) {
    previousMillis1 = currentMillis;
    etatLed1 = !etatLed1;
    digitalWrite(led1, etatLed1);
  }

  // LED2 : alterne entre allumee et eteinte toutes les period2 ms
  if (period2 > 0 && currentMillis - previousMillis2 >= period2) {
    previousMillis2 = currentMillis;
    etatLed2 = !etatLed2;
    digitalWrite(led2, etatLed2);
  }
}