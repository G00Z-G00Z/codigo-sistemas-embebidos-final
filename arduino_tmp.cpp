#include <Wire.h>
int celsius = 0;

void setup()
{
  pinMode(A1, INPUT);
  Serial.begin(9600);
  Wire.begin(4);
}


void loop()
{
  
  //Serial.println(analogRead(A1));
  celsius = analogRead(A1);
  // 0 -> 62 analogo
  // 40 -> 123
  celsius *= 0.75;
  celsius -= 15.8;
  
  Serial.println(celsius);
 
    Wire.beginTransmission(4); 
  Wire.write(celsius);
  Wire.endTransmission(); 
  
  delay(1000); 
}

