int carRed = 10;           // estabelece o semáforo para carros
int carYellow = 9;
int carGreen = 8;
int pedRed = 7;            // estabelece o semáforo para pedestres
int pedGreen = 6;
int button = 2;            // pino do botão
int crossTime = 7000;      // tempo para que os pedestres atravessem
unsigned long changeTime;  // tempo desde que o botão foi pressionado

void setup() {
  //Serial.begin(9600);
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT);        // botão no pino 2
  digitalWrite(carGreen, HIGH);  // acende a luz verde
  digitalWrite(pedRed, HIGH);
}

void loop() {
  int state = digitalRead(button);
  /*
  Serial.print(state);
  Serial.print("\t");
  Serial.println((millis() - changeTime)); */
  
  /* verifica se o botão foi pressionado e se transcorreram
     5 segundos desde a última vez que isso ocorreu */
  
  if (state == HIGH && (millis() - changeTime) > 5000) {
    changeLights();  // Chama a função para alterar as luzes
  }
}

void changeLights() {
  digitalWrite(carGreen, LOW);   // apaga o verde
  digitalWrite(carYellow, HIGH); // acende o amarelo
  delay(4000);                   // espera 4 segundos

  digitalWrite(carYellow, LOW);  // apaga o amarelo
  digitalWrite(carRed, HIGH);    // acende o vermelho
  delay(1000);                   // espera 1 segundo, por segurança

  digitalWrite(pedRed, LOW);     // apaga o vermelho dos pedestres
  digitalWrite(pedGreen, HIGH);  // acende o verde dos pedestres
  delay(crossTime);              // espera por um intervalo de tempo predefinido

  // pisca o verde dos pedestres
  for (int x = 0; x < 10; x++) {
    digitalWrite(pedGreen, HIGH);
    delay(125);
    digitalWrite(pedGreen, LOW);
    delay(125);
  }


  digitalWrite(pedRed, HIGH);    // acende o vermelho dos pedestres
  delay(1000);
  digitalWrite(carRed, LOW);     // apaga o vermelho
  digitalWrite(carGreen, HIGH);  // acende o verde
  digitalWrite(carYellow, LOW);  // apaga o amarelo


  changeTime = millis();         // registra o tempo desde a última alteração no semáforo
                                 // depois retorna para o loop principal do programa
}


