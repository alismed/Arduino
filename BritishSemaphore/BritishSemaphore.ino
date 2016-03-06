int ledDelay = 7000;  // espera entre as alterações
int redPin = 10;
int yellowPin = 9;
int greenPin = 8;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  digitalWrite(redPin, HIGH);    // acende a luz vermelha
  delay(ledDelay);               // espera 5 segundos
  
  digitalWrite(yellowPin, HIGH); // acende a luz amarela
  delay(2000);                   // espera 2 segundos
  
  digitalWrite(greenPin, HIGH);  // acende a luz verde
  digitalWrite(redPin, LOW);     // apaga a luz vermelha
  digitalWrite(yellowPin, LOW);  // apaga a luz amarela
  delay(ledDelay);               // espera ledDelay milissegundos
  
  digitalWrite(yellowPin, HIGH); // acende a luz amarela
  digitalWrite(greenPin, LOW);   // apaga a luz verde
  delay(2000);                   // espera 2 segundos
  
  digitalWrite(yellowPin, LOW);  // apaga a luz amarela
                                 // agora nosso loop se repete
}

