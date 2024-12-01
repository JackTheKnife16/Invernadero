#ifndef FSM_H
#define FSM_H

enum State {
    OFF,
    ON
};

class FSM {
public:
    FSM(State _next_state);
    virtual void setear_state();
    virtual void ejecutar_maquina();
    int get_state();
private:
    State state;
    State next_state;
};

#endif