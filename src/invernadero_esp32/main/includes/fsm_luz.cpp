#include "fsm_luz.h"

FSMLuz::FSMLuz(State _next_state, int16_t _max_count_off, int16_t _max_count_on) : FSM(_next_state) {
    next_state = _next_state;
    max_count_off = _max_count_off;
    max_count_on = _max_count_on;
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
        if (acumulador_luz >= max_count_on) {
            // apagar luz
            next_state = OFF;
            acumulador_luz = 0;
        }
        std::cout << "ON acumulador luz = " << acumulador_luz << std::endl;
        std::cout << "ON desacumulador luz = " << desacumulador_luz << std::endl;
        break;
    case OFF:
        if (desacumulador_luz >= max_count_off) {
            // encender luz
            next_state = ON;
            desacumulador_luz = 0;
        }
        std::cout << "OFF desacumulador luz = " << desacumulador_luz << std::endl;
        std::cout << "OFF acumulador luz = " << acumulador_luz << std::endl;
        break;
    default:
        next_state = OFF;
        break;
    }
}