byte ledPin[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13};  // cria um array para os pinos dos LEDs
int ledDelay(50);                                    // intervalo entre as alterações
int direction = 1;                                   // relacao com o indice do array
int currentLED = 0;
unsigned long changeTime;

void setup() {
  // define todos os pinos como saída
  for (int x = 0; x < 10; x++) {
    pinMode(ledPin[x], OUTPUT);
  }
  changeTime = millis();
}

void loop() {
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
  digitalWrite(ledPin[currentLED], HIGH);
  // incrementa de acordo com o valor da direcao
  currentLED += direction;
  
  // altera a direcao se atingir o fim
  if (currentLED == 9) {
    direction = -1;
  }
  if (currentLED == 0) {
    direction = 1;
  }
}

