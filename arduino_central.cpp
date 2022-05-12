
#include <SoftwareSerial.h>
#include <Wire.h>

/**************************************************/

// Entradas
#define PIN_RX 2
#define PIN_TX 3
#define PIN_B0 6
#define PIN_B1 5
#define PIN_SCK 4

// Salidas
#define PIN_TMP_BAJA 7
#define PIN_TMP_ALTA 8
#define PIN_GAS 9
#define PIN_LUZ 10

// Variables de estado
int nivel_de_luz = LOW; // 0 -> oscuro y 1 -> luminoso
int porcentaje_gas;     // 0 - 100
int temp_value = 0;     // -40 - 125
int temperatura_alta = LOW;
int temperatura_baja = LOW;
int nivel_de_gas = LOW;

/**************************************************/

/**
 * @brief Pone los pines para comucacion paralela con el microbit
 */
void Paralelo_setup()
{
  pinMode(PIN_B0, INPUT);
  pinMode(PIN_B1, INPUT);
  pinMode(PIN_SCK, INPUT);
}

/*Fucniones de lectura*****************************/
/**
 * @brief Lee los bits del microbit de forma paralela
 * el bit de luz, se pone en HIGH si esta iluminado y LOW si esta oscuro
 * @param bit_luz
 */
void Read_light_bit(int &bit_luz)
{

  if (digitalRead(PIN_SCK) != 0)
    return;

  // Serial.println("Leyendo luz");
  bit_luz = digitalRead(PIN_B1) == 0 ? 0 : 1;
}

// /**
//  * @brief  Lee el porcentaje de gas por UART
//  *
//  * @param softSerial
//  * @param portcentaje_gas
//  */
// void Read_porcentaje_gas(SoftwareSerial &softSerial, int &portcentaje_gas)
// {
//   softSerial.begin(9600);

//   if (softSerial.available())
//   {
//     porcentaje_gas = (int)softSerial.read();
//     Serial.print("El porcentaje de gas es de: ");
//     Serial.println(porcentaje_gas);
//   }
// }

/**
 * @brief Lee el valor de la temperatura con i2c
 *
 * @param howMany
 */
void Read_temp_value(int howMany)
{
  temp_value = Wire.read();
  Serial.println(temp_value);
}

/**************************************************/

/*******Set up*************************************/

SoftwareSerial mySerial(PIN_RX, PIN_TX); // Comunicaicon con attiny

void setup()
{

  Serial.begin(9600);
  Paralelo_setup();
  Wire.begin(4);
  Wire.onReceive(Read_temp_value);
  pinMode(PIN_TMP_BAJA, OUTPUT);
  pinMode(PIN_TMP_ALTA, OUTPUT);
  pinMode(PIN_GAS, OUTPUT);
  pinMode(PIN_LUZ, OUTPUT);
}

/**************************************************/

void loop()
{

  delay(100);

  // Lectura microbit
  Read_light_bit(nivel_de_luz);

  // Lecutra attiny

  mySerial.begin(9600);

  if (mySerial.available())
  {
    porcentaje_gas = (int)mySerial.read();
    // Serial.print("El porcentaje de gas es de: ");
    // Serial.println(porcentaje_gas);
  }

  // Lectura arduion
  // Se lee con interrupciones en la funcion Read_temp_value

  // Mandar informacion al fpga

  // logica de mandar informacion

  // nivel de gas


  
    // Evaluaciones de condiciones
  nivel_de_gas = porcentaje_gas > 50 ? HIGH : LOW;
  temperatura_alta = temp_value > 123 ? HIGH : LOW;
  temperatura_baja = temp_value < 62 ? HIGH : LOW;

  digitalWrite(PIN_TMP_BAJA, temperatura_baja);
  digitalWrite(PIN_TMP_ALTA, temperatura_alta);
  digitalWrite(PIN_GAS, nivel_de_gas);
  digitalWrite(PIN_LUZ, nivel_de_luz);
}

