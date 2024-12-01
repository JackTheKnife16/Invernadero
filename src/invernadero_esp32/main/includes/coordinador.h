#include "fsm.h"
#include "actuador_interfaz.h"
#include "sensor_interfaz.h"
#include <vector>

#ifndef COORDINADOR_H
#define COORDINADOR_H

class Coordinador {
public:
    Coordinador(SensorInterfaz* _sensor, FSM* _fsm, ActuadorInterfaz* _actuador);
    void ejecutor();
private:
    FSM* fsm;
    ActuadorInterfaz* actuador;
    SensorInterfaz* sensor;
    std::vector<int16_t> mediciones;
};


#endif
