#include <Arduino.h>

/* 
Para la placa podemos usar los pines D1, D2, D5, D6, D7, A0(solo para analogRead)
*/
const uint8_t pinAbrir = D1;
const uint8_t pinCerrar = D2;
const uint8_t pinInterrupcion = D7;
const uint8_t boton = D5; //Este boton es temporal para hacer pruebas, el funcionamiento del boton lo tenemos que implementar con Arduino Cloud

/* 
Estados de la puerta 
*/
enum EstadoPuerta {
  PARADA,
  ABRIENDO,
  CERRANDO
};

volatile bool limite = false; //Esta variable se pone a true cuando la puerta llega a alguno de los extremos


EstadoPuerta estadoPuerta = PARADA;
bool puertaAbierta = false;   // Esta variable nos indica si la puerta esta abierta (true) o cerrada (false)



void setup() {
  Serial.begin(115200);

  pinMode(boton, INPUT_PULLUP);
  pinMode(pinInterrupcion, INPUT_PULLUP);

  pinMode(pinAbrir, OUTPUT);
  pinMode(pinCerrar, OUTPUT);
}

void loop(){

}
