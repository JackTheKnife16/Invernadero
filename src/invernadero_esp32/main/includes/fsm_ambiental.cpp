#include "fsm_ambiental.h"

FSMAmbiental::FSMAmbiental(State _next_state) : FSM(_next_state) {
    next_state = _next_state;
}

void
FSMAmbiental::setear_mediciones(std::vector<int16_t> mediciones) {
    humedad_ambiental = mediciones[0];
    temperatura_ambiental = mediciones[1];
}

void
FSMAmbiental::ejecutar_maquina() {
    setear_state();
    switch (state)
    {
    case ON:
        if (humedad_ambiental <= 700 && temperatura_ambiental <= 300) {
            // cerrar ventana
            next_state = OFF;
        }
        break;
    case OFF:
        if (humedad_ambiental >= 800 || temperatura_ambiental >= 390) {
            // abrir ventana
            next_state = ON;
        }
        break;
    default:
        next_state = OFF;
        break;
    }
}