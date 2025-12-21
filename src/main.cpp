#include <Arduino.h>

//GPIO pins que podemos usar: D1, D2, D5, D6, D7, A0(solo analog read)

const int pinAbrir = 1;
const int pinCerrar = 2;
const int pinInterrupcion = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pinInterrupcion, INPUT_PULLUP); //usamos la resistencia pullup integrada en la placa
  attachInterrupt(pinInterrupcion, isr, FALLING); //Esto define una interrupcion, el primer valor es el pin que se observa, el segundo es la funcion a la que se llama en caso de la interrupcion, y el tercer valor es en que evento del pin llama a la funcion.
}

void loop() {
  // put your main code here, to run repeatedly:
}

void ICACHE_RAM_ATTR isr(){
  //Esta sera la funcion llamada para la interrupcion cuando se pulse un interruptor limite
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}