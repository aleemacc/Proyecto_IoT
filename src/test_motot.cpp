#include <Arduino.h>

//GPIO pins que podemos usar: D1, D2, D5, D6, D7, A0(solo analog read)

uint8_t pinAbrir = D1;
uint8_t pinCerrar = D2;
uint8_t pinInterrupcion = D7;
uint8_t boton = D5;

void setup(){
    Serial.begin(115200);
    pinMode(pinAbrir, OUTPUT);
    pinMode(pinCerrar, OUTPUT);
}

void loop(){
    digitalWrite(pinAbrir, LOW);
    digitalWrite(pinCerrar, LOW);

    delay(1000);

    digitalWrite(pinAbrir, HIGH);

    delay(1000);

    digitalWrite(pinAbrir, LOW);

    delay(1000);

    digitalWrite(pinCerrar, HIGH);

    delay(1000);

}