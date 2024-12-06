#ifndef FSM_LUZ_H
#define FSM_LUZ_H
#include "fsm.h"
#include <iostream>

class FSMLuz : public FSM {
public: 
    FSMLuz(State _next_state, int16_t _max_count_off, int16_t _max_count_on);
    void ejecutar_maquina();
    void setear_mediciones(std::vector<int16_t> mediciones);;
private:
    int16_t cantidad_luz;
    int16_t acumulador_luz = 0;
    int16_t desacumulador_luz = 0;
    int16_t max_count_off;
    int16_t max_count_on;
};


#endif