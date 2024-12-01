#ifndef FSM_SUSTRATO_H
#define FSM_SUSTRATO_H
#include "fsm.h"
#include <iostream>

class FSMSustrato : public FSM {
public: 
    FSMSustrato(State _next_state);
    void ejecutar_maquina();
    void setear_mediciones(std::vector<int16_t> mediciones);;
private:
    int16_t humedad_sustrato;
};


#endif