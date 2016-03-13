byte ledPin[10] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13}; // cria um array para os pinos dos LEDs
int ledDelay;                                         // intervalo entre as alterações
boolean direction = true;                             // relacao com o indice do array
int currentLED = 0;
int maxHeight = 9;
unsigned long changeTime;
int potPin = A2;                                      // potenciometro
int count = 0;

void setup() {
  // define todos os pinos como saída
  for (int x = 0; x < 10; x++) {
    pinMode(ledPin[x], OUTPUT);
  }
  changeTime = millis();
}

void loop() {
  // leitura do potenciometro
  ledDelay = analogRead(potPin);

  // verifica se já transcorreram ledDelay ms desde
  if ((millis() - changeTime) > ledDelay) {
    changeLED();
    changeTime = millis();
  }
}

void changeLED() {
  // apaga todos os LEDs
  for (int x = 0; x < 10; x++) {
    digitalWrite(ledPin[x], LOW);
  }

  // acende o LED atual
  if (currentLED <= maxHeight) {
    digitalWrite(ledPin[currentLED], HIGH);
  }

  // reinicia
  if ( currentLED == 0 ) {
    direction = true;
  }

  // verifica o fim de linha
  if (currentLED == maxHeight) {
    direction = false;
  }

  // incrementa de acordo com o valor da direcao
  currentLED += (direction == true) ? 1 : -1;

  // ao voltar ao inicio, reduz o fim de linha
  if ( currentLED == 0 ) {
    maxHeight -= 1;
  }

  // reinicia
  if (maxHeight == 0)
    maxHeight = 9;
}

