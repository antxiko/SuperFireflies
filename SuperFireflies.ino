
int leds [] = { 5, 9, 10, 11 };
int ledsMax = 4;
int fadeC = 5;
int fadeI = 0;
int fadeO = 255;
int intervalo = 50;
unsigned long preMillis=0;
unsigned long sonMillis=0;

void setup() {

Serial.begin(9600);

for (int i = 0; i < ledsMax; i++) {
    pinMode(leds[i], OUTPUT);
  }
for (int i = 0; i <= ledsMax; i++) {
    digitalWrite(leds[i], HIGH);
  }
}

void loop() {

gestLed(1,1);
gestLed(2,0);


}

int gestLed(int accion, int led) {

  switch (accion) {
    case 0:
    fadeIN(led);
    break;
    case 1:
    fadeOUTIN(led);
    break;
    case 2:
    fadeOUT(led);
    break;
    }
}

int fadeOUTIN (int led) {

  while (fadeOUT == 0) {
  fadeOUT(leds[led]);
  }
}
  
int fadeIN(int led) {

  Serial.println("llamado fadeIN");
  sonMillis = millis();

  if ((unsigned long)(sonMillis - preMillis) >= intervalo) {
    analogWrite(leds[led], fadeI);
    fadeI = fadeI + fadeC;
    preMillis = sonMillis; 
    if (fadeI >= 255) {
      fadeI = 255;
      return 1; 
      }
    }
}

int fadeOUT(int led) {

  Serial.println("llamado fadeOUT");
  sonMillis = millis();

  if ((unsigned long)(sonMillis - preMillis) >= intervalo) {
    analogWrite(leds[led], fadeO);
    fadeO = fadeO - fadeC;  
    if (fadeO <= 0) {
      fadeO = 0;
      return 1;
      }
    preMillis = sonMillis;  
    }
}
