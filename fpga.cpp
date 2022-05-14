// Pines de Salida
#define PIN_LED_LUZ_ARTIFICIAL 7
#define PIN_PERSIANA1 6
#define PIN_PERSIANA2 5
#define PIN_VENTANA1 4
#define PIN_VENTANA2 3
#define PIN_ABANICO 2
#define PIN_BOMBILLA_CALOR 12

// Pines de Entrada
#define PIN_BIT0 8
#define PIN_BIT1 9
#define PIN_BIT2 10
#define PIN_BIT3 11


// bits de entrada
int bit_0_luz, bit_1_tmp_alta, bit_2_tmp_baja, bit_3_gas; // Variables de lectura

/**
 * Motor
 *
 * Esta clase maneja como abrir y cerrar los botones. 
 */
class Motor {

  private : 
    bool isClosed = true;
    int pin_open;
    int pin_close;

    void move_motor(const int &pin){
      for(int x; x<500; x++){
        digitalWrite(pin,HIGH); 
      }
      digitalWrite(pin, LOW);
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

    bool get_State(){
      return isClosed;
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
  bit_0_luz = digitalRead(PIN_BIT0);
  bit_1_tmp_alta = digitalRead(PIN_BIT1);
  bit_2_tmp_baja = digitalRead(PIN_BIT2);
  bit_3_gas = digitalRead(PIN_BIT3);
}


void print_state(){
  //Ver cual de los 15 estado esta el sistema
  Serial.print(bit_0_luz);
  Serial.print(bit_1_tmp_alta);
  Serial.print(bit_2_tmp_baja);
  Serial.print(bit_3_gas);
  Serial.print("    ");
  Serial.print(persiana.get_State());
  Serial.println(ventana.get_State());
}

void loop(){

  read_inputs();
  print_state();

  // Manejo de persiana
  // Si hay luz natural, se habre, si no, se cierra

  if (bit_0_luz == HIGH){
    digitalWrite(PIN_LED_LUZ_ARTIFICIAL, LOW);
    persiana.open();
  } else {
    digitalWrite(PIN_LED_LUZ_ARTIFICIAL, HIGH);
    persiana.close();
  }
  
  // Manejo temperatura
  // No puede haber un caso con ambos, entonces se ignorara
  bit_1_tmp_alta == HIGH ? digitalWrite(PIN_ABANICO, HIGH) : digitalWrite(PIN_ABANICO, LOW);
  bit_2_tmp_baja == HIGH ? digitalWrite(PIN_BOMBILLA_CALOR, HIGH) : digitalWrite(PIN_BOMBILLA_CALOR, LOW);

  // Manejo de ventana
  // Si hay gas, se abre
  bit_3_gas == HIGH ? ventana.open() : ventana.close();
}

