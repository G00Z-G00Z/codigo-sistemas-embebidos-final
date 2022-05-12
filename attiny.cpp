#include <SoftwareSerial.h>

int valor;

SoftwareSerial mySerial(0, 1); // RX, TX
void setup()
{
  mySerial.begin(9600);
  pinMode(A1, INPUT);
}

void loop()
{
  valor = map(analogRead(A1),300,750,0,100);
  mySerial.write(valor);
  
  delay(100);
}
