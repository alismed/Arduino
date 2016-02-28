int value = 0;                            // variável que guarda o valor atual 
int ledpin = 9;                           // luz conectada ao pino digital 9

void setup() 
{ 
  // nada a configurar-se
} 

void loop() 
{ 
  for(value = 0 ; value <= 255; value+=5) // aumentar brilho
  { 
    analogWrite(ledpin, value);           // fornece valor entre 0 e 255 
    delay(15);                            // aguarda 30 milissegundos para
                                          // permitir visualização 
  } 
  for(value = 255; value >=0; value-=5)   // diminuir brilho 
  { 
    analogWrite(ledpin, value); 
    delay(5); 
  }  
}

