#include "fsm.h"
#include "actuador_interfaz.h"
#include "sensor_interfaz.h"
#include <vector>

#ifndef COORDINADOR_H
#define COORDINADOR_H

class Coordinador {
public:
    Coordinador(std::vector<SensorInterfaz*> _sensor, FSM* _fsm, ActuadorInterfaz* _actuador);
    void ejecutor();
private:
    FSM* fsm;
    ActuadorInterfaz* actuador;
    std::vector<SensorInterfaz*> sensor;
    std::vector<std::vector<int16_t>> mediciones;
    std::vector<int16_t> mediciones_promediadas;
    int16_t mediciones_diferentes_por_sensor;
    int16_t numero_total_sensores;
};


#endif
