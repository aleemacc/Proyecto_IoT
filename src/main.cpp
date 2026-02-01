#include <Arduino.h>

// Pines botones
const uint8_t BTN_RESET = D5;
const uint8_t BTN_TOGGLE = D6;

// Pines salidas
const uint8_t OUT1 = D1;
const uint8_t OUT2 = D2;

// Variables de estado
bool lastBtnResetState = HIGH;
bool lastBtnToggleState = HIGH;

bool nextOutputIs1 = true;  // true -> D1, false -> D2

void setup() {
    pinMode(BTN_RESET, INPUT_PULLUP);
    pinMode(BTN_TOGGLE, INPUT_PULLUP);

    pinMode(OUT1, OUTPUT);
    pinMode(OUT2, OUTPUT);

    digitalWrite(OUT1, LOW);
    digitalWrite(OUT2, LOW);
}

void loop() {
    bool btnResetState  = digitalRead(BTN_RESET);
    bool btnToggleState = digitalRead(BTN_TOGGLE);

    // --- Botón D5: reset ---
    if (lastBtnResetState == HIGH && btnResetState == LOW) {
        digitalWrite(OUT1, LOW);
        digitalWrite(OUT2, LOW);
    }

    // --- Botón D6: toggle ---
    if (lastBtnToggleState == HIGH && btnToggleState == LOW) {

        if (digitalRead(OUT1) == LOW && digitalRead(OUT2) == LOW) {
            if (nextOutputIs1) {
                digitalWrite(OUT1, HIGH);
                digitalWrite(OUT2, LOW);
            } else {
                digitalWrite(OUT1, LOW);
                digitalWrite(OUT2, HIGH);
            }

            // Alternar para la próxima vez
            nextOutputIs1 = !nextOutputIs1;
        }
    }

    lastBtnResetState  = btnResetState;
    lastBtnToggleState = btnToggleState;

    delay(20); // antirrebote simple
}
