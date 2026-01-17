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

/* Tiempos */
const unsigned long debounceBoton = 300;   // ms
unsigned long ultimoBoton = 0;

/*
Para parar la puerta cuando llegue a alguno de los limites usamos una interrupcion que se ejecuta cuando alguno de los interruptores limite es pulsado
*/
void IRAM_ATTR ISR() {
  limite = true;
}

void setup() {
  Serial.begin(115200);

  pinMode(boton, INPUT_PULLUP);
  pinMode(pinInterrupcion, INPUT_PULLUP);

  pinMode(pinAbrir, OUTPUT);
  pinMode(pinCerrar, OUTPUT);

  digitalWrite(pinAbrir, LOW);
  digitalWrite(pinCerrar, LOW);
  //Inicializamos los pines que activan los bjt a low para evitar cortos

  attachInterrupt(pinInterrupcion, ISR, FALLING); //Esta es la interrupcion que se ejecuta cuando detecta un flanco de bajada en el pinInterrupcion, esto es asi porque lo tenemos en input pullup por lo que cuando es pulsado pasa de HIGH a LOW
}

void loop() {

  
  if (digitalRead(boton) == LOW && estadoPuerta == PARADA) {
    unsigned long ahora = millis(); //Esto de los millis me lo ha dicho chatgpt para evitar rebotes del boton
    if (ahora - ultimoBoton > debounceBoton) {
      ultimoBoton = ahora;

      if (puertaAbierta) {
        estadoPuerta = CERRANDO;
        Serial.println("Cerrando puerta");
      } else {
        estadoPuerta = ABRIENDO;
        Serial.println("Abriendo puerta");
      }
    }
  }

  
  if (limite) {
    limite = false;

    if (estadoPuerta == ABRIENDO) {
      puertaAbierta = true;
      Serial.println("Puerta totalmente abierta");
    }
    else if (estadoPuerta == CERRANDO) {
      puertaAbierta = false;
      Serial.println("Puerta totalmente cerrada");
    }

    estadoPuerta = PARADA;
  }

  //Funcionamiento de la puerta segun el estado en el que se encuentre
  switch (estadoPuerta) {

    case ABRIENDO:
      digitalWrite(pinCerrar, LOW);
      digitalWrite(pinAbrir, LOW);
      delay(10);                 // para que les de tiempo a los bjt a "asentarse" y evitar cortos
      digitalWrite(pinAbrir, HIGH);
      break;

    case CERRANDO:
      digitalWrite(pinAbrir, LOW);
      digitalWrite(pinCerrar, LOW);
      delay(10);
      digitalWrite(pinCerrar, HIGH);
      break;

    case PARADA:
    default:
      digitalWrite(pinAbrir, LOW);
      digitalWrite(pinCerrar, LOW);
      break;
  }
}
