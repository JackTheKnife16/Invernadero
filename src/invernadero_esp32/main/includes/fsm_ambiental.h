#ifndef FSM_AMBIENTAL_H
#define FSM_AMBIENTAL_H
#include "fsm.h"
#include <iostream>

class FSMAmbiental : public FSM {
public: 
    FSMAmbiental(State _next_state);
    void ejecutar_maquina();
    void setear_mediciones(std::vector<int16_t> mediciones);;
private:
    int16_t humedad_ambiental;
    int16_t temperatura_ambiental;
};


#endif