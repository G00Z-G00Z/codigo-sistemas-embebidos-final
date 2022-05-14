// Pines de entrada
#define PIN_LED_LUZ_ARTIFICIAL 7
#define PIN_PERSIANA1 6
#define PIN_PERSIANA2 5
#define PIN_VENTANA1 4
#define PIN_VENTANA2 3
#define PIN_ABANICO 2
#define PIN_BOMBILLA_CALOR 0

// Pines de salida
#define PIN_BIT0 8
#define PIN_BIT1 9
#define PIN_BIT2 10
#define PIN_BIT3 11

int Estado_Ventana;
int Estado_Persiana;

int bit0, bit1, bit2, bit3; // Variables de lectura

class Motor {

  private : 
    bool isClosed = true;
    int pin_open;
    int pin_close;

    void move_motor(int pin){
      for(int x; x<500; x++){
        digitalWrite(pin,HIGH); 
      }
    }

  public : 

    Motor(int pin_open, int pin_close){
      this->pin_open = pin_open;
      this->pin_close = pin_close;
      pinMode(pin_open, OUTPUT);
      pinMode(pin_close, OUTPUT);
      close();
    }

    void open(){
      if(isClosed){
        move_motor(pin_open);
        isClosed = false;
      }
    } 

    void close(){
      if(!isClosed){
        move_motor(pin_close);
        isClosed = true;
      }
    } 
};

// Motores para los actuadores
Motor persiana(PIN_PERSIANA1, PIN_PERSIANA2), ventana(PIN_VENTANA1, PIN_VENTANA2);

void setup(){

  // Salidas
  pinMode(PIN_LED_LUZ_ARTIFICIAL, OUTPUT);
  pinMode(PIN_ABANICO, OUTPUT);
  pinMode(PIN_BOMBILLA_CALOR, OUTPUT);

  // Entradas
  pinMode(PIN_BIT0, INPUT);
  pinMode(PIN_BIT1, INPUT);
  pinMode(PIN_BIT2, INPUT);
  pinMode(PIN_BIT3, INPUT);

  // Serial
  Serial.begin(9600);
}

void read_inputs(){
  //Lectura de los bits del Arduino Central
  bit0 = digitalRead(PIN_BIT0);
  bit1 = digitalRead(PIN_BIT1);
  bit2 = digitalRead(PIN_BIT2);
  bit3 = digitalRead(PIN_BIT3);
}


void print_state(){
  //Ver cual de los 15 estado esta el sistema
  Serial.print(bit0);
  Serial.print(bit1);
  Serial.print(bit2);
  Serial.print(bit3);
  Serial.print("    ");
  Serial.print(Estado_Persiana);
  Serial.println(Estado_Ventana);
}






void loop(){

  read_inputs();
  print_state();


  //Estado 0
  if (bit0 == 0 && bit1 == 0 && bit2 == 0 && bit3 == 0){
    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,HIGH);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,LOW);

    if(Estado_Ventana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA1,HIGH); //Checar PWM
      }
      Estado_Ventana = 0;
    }
    digitalWrite(PIN_VENTANA1,LOW);

    if(Estado_Persiana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA2,HIGH);
      }
      Estado_Persiana = 1;
    }
    digitalWrite(PIN_PERSIANA2,LOW);


  }
  //Estado 1
  else if (bit0 == 0 && bit1 == 0 && bit2 == 0 && bit3 == 1){ digitalWrite(PIN_LED_LUZ_ARTIFICIAL,HIGH);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,LOW);

    if(Estado_Ventana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA2,HIGH);
      }
      Estado_Ventana = 1;
    }
    digitalWrite(PIN_VENTANA2,LOW);
    if(Estado_Persiana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA2,HIGH);
      }
      Estado_Persiana = 1;
    }
    digitalWrite(PIN_PERSIANA2,LOW);


  }
  //Estado 2
  else if (bit0 == 0 && bit1 == 0 && bit2 == 1 && bit3 == 0){
    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,HIGH);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,LOW);

    if(Estado_Ventana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA1,HIGH);
      }
      Estado_Ventana = 0;
    }
    digitalWrite(PIN_VENTANA1,LOW);

    if(Estado_Persiana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA2,HIGH);
      }
      Estado_Persiana = 1;
    }
    digitalWrite(PIN_PERSIANA2,LOW);



  }
  //Estado 3
  else if (bit0 == 0 && bit1 == 0 && bit2 == 1 && bit3 == 1){
    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,HIGH);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,LOW);

    if(Estado_Ventana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA2,HIGH);
      }
      Estado_Ventana = 1;
    }
    digitalWrite(PIN_VENTANA2,LOW);

    if(Estado_Persiana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA2,HIGH);
      }
      Estado_Persiana = 1;
    }
    digitalWrite(PIN_PERSIANA2,LOW);



  }
  //Estado 4
  else if (bit0 == 0 && bit1 == 1 && bit2 == 0 && bit3 == 0){
    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,HIGH);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,HIGH);

    if(Estado_Ventana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA1,HIGH);
      }
      Estado_Ventana = 0;
    }

    digitalWrite(PIN_VENTANA1,LOW);

    if(Estado_Persiana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA2,HIGH);
      }
      Estado_Persiana = 1;
    }
    digitalWrite(PIN_PERSIANA2,LOW);


  }
  //Estado 5
  else if (bit0 == 0 && bit1 == 1 && bit2 == 0 && bit3 == 1){

    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,HIGH);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,HIGH);

    if(Estado_Ventana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA2,HIGH);
      }

      Estado_Ventana = 1;
    }

    digitalWrite(PIN_VENTANA2,LOW);

    if(Estado_Persiana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA2,HIGH);
      }
      Estado_Persiana = 1;
    }
    digitalWrite(PIN_PERSIANA2,LOW);


  }
  //Estado 6
  else if (bit0 == 0 && bit1 == 1 && bit2 == 1 && bit3 == 0){

    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,HIGH);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,LOW);

    if(Estado_Ventana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA1,HIGH);
      }

      Estado_Ventana = 0;
    }

    digitalWrite(PIN_VENTANA1,LOW);

    if(Estado_Persiana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA2,HIGH);
      }
      Estado_Persiana = 1;
    }
    digitalWrite(PIN_PERSIANA2,LOW);


  }
  //Estado 7
  else if (bit0 == 0 && bit1 == 1 && bit2 == 1 && bit3 == 1){

    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,HIGH);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,LOW);

    if(Estado_Ventana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA2,HIGH);
      }

      Estado_Ventana = 1;
    }

    digitalWrite(PIN_VENTANA2,LOW);

    if(Estado_Persiana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA2,HIGH);
      }
      Estado_Persiana = 1;
    }
    digitalWrite(PIN_PERSIANA2,LOW);


  }
  //Estado 8
  else if (bit0 == 1 && bit1 == 0 && bit2 == 0 && bit3 == 0){

    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,LOW);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,LOW);

    if(Estado_Ventana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA1,HIGH);
      }

      Estado_Ventana = 0;
    }

    digitalWrite(PIN_VENTANA1,LOW);

    if(Estado_Persiana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA1,HIGH);
      }
      Estado_Persiana = 0;
    }
    digitalWrite(PIN_PERSIANA1,LOW);


  }
  //Estado 9
  else if (bit0 == 1 && bit1 == 0 && bit2 == 0 && bit3 == 1){

    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,LOW);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,LOW);

    if(Estado_Ventana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA2,HIGH);
      }

      Estado_Ventana = 1;
    }

    digitalWrite(PIN_VENTANA2,LOW);

    if(Estado_Persiana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA1,HIGH);
      }
      Estado_Persiana = 0;
    }
    digitalWrite(PIN_PERSIANA1,LOW);


  }
  //Estado 10
  else if (bit0 == 1 && bit1 == 0 && bit2 == 1 && bit3 == 0){

    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,LOW);
    digitalWrite(PIN_BOMBILLA_CALOR,HIGH);
    digitalWrite(PIN_ABANICO,LOW);

    if(Estado_Ventana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA1,HIGH);
      }

      Estado_Ventana = 0;
    }

    digitalWrite(PIN_VENTANA1,LOW);

    if(Estado_Persiana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA1,HIGH);
      }
      Estado_Persiana = 0;
    }
    digitalWrite(PIN_PERSIANA1,LOW);


  }
  //Estado 11
  else if (bit0 == 1 && bit1 == 0 && bit2 == 1 && bit3 == 1){

    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,LOW);
    digitalWrite(PIN_BOMBILLA_CALOR,HIGH);
    digitalWrite(PIN_ABANICO,LOW);

    if(Estado_Ventana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA2,HIGH);
      }

      Estado_Ventana = 1;
    }

    digitalWrite(PIN_VENTANA2,LOW);

    if(Estado_Persiana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA1,HIGH);
      }
      Estado_Persiana = 0;
    }
    digitalWrite(PIN_PERSIANA1,LOW);


  }
  //Estado 12
  else if (bit0 == 1 && bit1 == 1 && bit2 == 0 && bit3 == 0){

    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,LOW);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,HIGH);

    if(Estado_Ventana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA1,HIGH);
      }
      Estado_Ventana = 0;
    }

    digitalWrite(PIN_VENTANA1,LOW);

    if(Estado_Persiana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA1,HIGH);
      }
      Estado_Persiana = 0;
    }
    digitalWrite(PIN_PERSIANA1,LOW);


  }
  //Estado 13
  else if (bit0 == 1 && bit1 == 1 && bit2 == 0 && bit3 == 1){

    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,LOW);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,HIGH);

    if(Estado_Ventana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA2,HIGH);
      }
      Estado_Ventana = 1;
    }

    digitalWrite(PIN_VENTANA2,LOW);

    if(Estado_Persiana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA1,HIGH);
      }
      Estado_Persiana = 0;
    }
    digitalWrite(PIN_PERSIANA1,LOW);


  }
  //Estado 14
  else if (bit0 == 1 && bit1 == 1 && bit2 == 1 && bit3 == 0){

    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,LOW);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,LOW);

    if(Estado_Ventana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA1,HIGH);
      }
      Estado_Ventana = 0;
    }

    digitalWrite(PIN_VENTANA1,LOW);

    if(Estado_Persiana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA1,HIGH);
      }
      Estado_Persiana = 0;
    }
    digitalWrite(PIN_PERSIANA1,LOW);


  }
  //Estado 15
  else if (bit0 == 1 && bit1 == 1 && bit2 == 1 && bit3 == 1){

    digitalWrite(PIN_LED_LUZ_ARTIFICIAL,LOW);
    digitalWrite(PIN_BOMBILLA_CALOR,LOW);
    digitalWrite(PIN_ABANICO,LOW);

    if(Estado_Ventana == 0){
      for(int x; x<500; x++){
        digitalWrite(PIN_VENTANA2,HIGH);
      }
      Estado_Ventana = 1;
    }

    digitalWrite(PIN_VENTANA2,LOW);

    if(Estado_Persiana == 1){
      for(int x; x<500; x++){
        digitalWrite(PIN_PERSIANA1,HIGH);
      }
      Estado_Persiana = 0;
    }
    digitalWrite(PIN_PERSIANA1,LOW);


  }  

}
