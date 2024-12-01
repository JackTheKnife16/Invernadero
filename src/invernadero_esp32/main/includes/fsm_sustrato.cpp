#include "fsm_sustrato.h"

FSMSustrato::FSMSustrato(State _next_state) : FSM(_next_state) {
    next_state = _next_state;
}

void
FSMSustrato::setear_mediciones(std::vector<int16_t> mediciones) {
    humedad_sustrato = mediciones[0];
}

void
FSMSustrato::ejecutar_maquina() {
    setear_state();
    switch (state)
    {
    case ON:
        if (humedad_sustrato >= 82) {
            // apagar riego
            next_state = OFF;
        }
        break;
    case OFF:
        if (humedad_sustrato <= 55) {
            // encender riego
            next_state = ON;
        }
        break;
    default:
        next_state = OFF;
        break;
    }
}