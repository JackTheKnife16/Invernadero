#include "fsm.h"

FSM::FSM(State _next_state) {
    next_state = _next_state;
}

void
FSM::setear_state() {
    state = next_state;
}

void
FSM::setear_mediciones(std::vector<int16_t> _mediciones) {
    mediciones = _mediciones;
}

void
FSM::ejecutar_maquina() {
    setear_state();
    switch (state)
    {
    case ON:
        next_state = OFF;
        break;
    case OFF:
        next_state = ON;
        break;
    
    default:
        next_state = OFF;
        break;
    }
}

int
FSM::get_state() {
    return state;
}
