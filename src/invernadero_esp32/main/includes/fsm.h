#ifndef FSM_H
#define FSM_H
#include <stdint.h>
#include <vector>

enum State {
    OFF = 0,
    ON
};

class FSM {
public:
    FSM(State _next_state);
    virtual void setear_state();
    virtual void ejecutar_maquina();
    virtual void setear_mediciones(std::vector<int16_t> mediciones);
    int get_state();
protected:
    State state;
    State next_state;
    std::vector<int16_t> mediciones;
};

#endif
