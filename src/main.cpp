#include <Arduino.h>

//GPIO pins que podemos usar: D1, D2, D5, D6, D7, A0(solo analog read)

const int pinAbrir = 1;
const int pinCerrar = 2;
const int pinInterrupcion = 7;
bool estado = false; //mi idea es usar un boolean para guardar si la puerta se estaba abriendo o cerrando. Por ejemplo podemos llamar false a cerrado y true a abierto
int estados = 0; 
/*
nueva idea: dependiendo del numero de "estados" se hara una accion
  estados = 0 -> la puerta no se mueve
  estados = 1 -> la puerta se abre
  estados = 2 -> la puerta se cierra
el booleano "estado" nos sigue sirviendo pero para indicar el ultimo estado de la puera, asi en la interrupcion decidimos cual sera la proxima accion de la puerta
*/

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pinInterrupcion, INPUT_PULLUP); //usamos la resistencia pullup integrada en la placa
  pinMode(pinAbrir, OUTPUT);
  pinMode(pinCerrar, OUTPUT);
  attachInterrupt(pinInterrupcion, isr, FALLING); //Esto define una interrupcion, el primer valor es el pin que se observa, el segundo es la funcion a la que se llama en caso de la interrupcion, y el tercer valor es en que evento del pin llama a la funcion.

}


/*
La idea para el funcionamiento: cuando se este abriendo, el pinAbrir se pone a HIGH y el pinCerrar se pone a LOW. Se quedan asi hasta que se pulse uno de los 
interruptores de limite, entonces se lleva a cabo la interrupccion que pondra ambos pines a low y se guarda un estado que nos indique que lo ultimo que ha hecho la 
puerta es abrirse. De este modo sabremos que la siguiente accion sera cerrar, y para cerrar se hace justo lo opuesto a lo anterior.
*/

void loop() {
  
  if (estados == 1)
  {
    /*
    aqui estamos en el caso en el que la ultima posicion extrema de la puerta era cerrada, entonces estado va a ser igual a false hasta que se habra del todo, pulse el 
    interruptor de limite y ejecute la interrupcion, que debera cambiar estado a true
    */
    digitalWrite(pinCerrar, LOW);
    digitalWrite(pinAbrir, HIGH);
  }
  else if (estados == 2)
  {
    digitalWrite(pinCerrar, HIGH);
    digitalWrite(pinAbrir, LOW);
  }
  else{
    digitalWrite(pinCerrar, LOW);
    digitalWrite(pinAbrir, LOW);
  }
  
  /*
  Ahora tenemos en teoria programado el comportamiento de la puerta cuando esta en movimiento, nos falta implementar como actuar la puerta cuando esta este parada, 
  para eso tenemos que asociar una variable que nos indique cuando se ha pulsado el boton de abrir (desde la aplicacion de arduino cloud se pulsa este boton)
  */
  

}

void ICACHE_RAM_ATTR isr(){
  //Esta sera la funcion llamada para la interrupcion cuando se pulse un interruptor limite

  if (estado)
  {
    /*
    En este caso el ultimo estado extremo de la puerta era abierto, lo que significa que ahora se ha pulsado el interruptor con la puerta cerrada, entonces debemos 
    poner los pines del motor a LOW para que el motor se pare, y ademas actualizar "estado" a false para idicar que la puerta esta cerrada.
    */

    estados = 0;
    estado = false;
  }
  else{
    estados = 0;
    estado = true;
  }
  

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}