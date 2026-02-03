#include <Arduino.h>

// Pines botones
const uint8_t detener = D5;
const uint8_t abrir_cerrar = D6;

// Pines salidas
const uint8_t motor1 = D1;
const uint8_t motor2 = D2;

// Variables de estado
bool lastEstadoLimite = HIGH;
bool lastEstadoBoton = HIGH;

bool dirSiguiente = true;  // true -> D1, false -> D2

void setup() {
    pinMode(detener, INPUT_PULLUP);
    pinMode(abrir_cerrar, INPUT_PULLUP);

    pinMode(motor1, OUTPUT);
    pinMode(motor2, OUTPUT);

    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
}

void loop() {
    bool estadoLimite  = digitalRead(detener);
    bool estadoBoton = digitalRead(abrir_cerrar);

    // Si se pulsa alguno de los interruptores de limite, el motor se para
    if (lastEstadoLimite == HIGH && estadoLimite == LOW) {
        digitalWrite(motor1, LOW);
        digitalWrite(motor2, LOW);
    }

    // Si se pulsa el boton y el motor esta parado, se empieza a girar en la direccion contraria a la que estaba girando antes
    if (lastEstadoBoton == HIGH && estadoBoton == LOW) {

        if (digitalRead(motor1) == LOW && digitalRead(motor2) == LOW) {
            if (dirSiguiente) {
                digitalWrite(motor1, HIGH);
                digitalWrite(motor2, LOW);
            } else {
                digitalWrite(motor1, LOW);
                digitalWrite(motor2, HIGH);
            }

            // Alternar para la próxima vez
            dirSiguiente = !dirSiguiente;
        }
    }

    lastEstadoLimite  = estadoLimite;
    lastEstadoBoton = estadoBoton;

    delay(20); // antirrebote simple
}
