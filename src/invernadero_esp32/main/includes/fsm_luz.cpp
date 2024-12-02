#include "fsm_luz.h"

FSMLuz::FSMLuz(State _next_state) : FSM(_next_state) {
    next_state = _next_state;
}

void
FSMLuz::setear_mediciones(std::vector<int16_t> mediciones) {
    cantidad_luz = mediciones[0];
    if ( cantidad_luz < 700 ) {
        desacumulador_luz += 1;
    }
    else {
        acumulador_luz += 1;
    }
}

void
FSMLuz::ejecutar_maquina() {
    setear_state();
    switch (state)
    {
    case ON:
        if (acumulador_luz >= 8640) {
            // apagar luz
            next_state = OFF;
            acumulador_luz = 0;
        }
        std::cout << "acumulador luz = " << acumulador_luz << std::endl;
        std::cout << "desacumulador luz = " << desacumulador_luz << std::endl;
        break;
    case OFF:
        if (desacumulador_luz >= 8640) {
            // encender luz
            next_state = ON;
            desacumulador_luz = 0;
        }
        std::cout << "desacumulador luz = " << desacumulador_luz << std::endl;
        std::cout << "acumulador luz = " << acumulador_luz << std::endl;
        break;
    default:
        next_state = OFF;
        break;
    }
}