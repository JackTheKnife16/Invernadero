#include "coordinador.h"

Coordinador::Coordinador(SensorInterfaz* _sensor, FSM* _fsm, ActuadorInterfaz* _actuador) {
    sensor = _sensor;
    actuador = _actuador;
    fsm = _fsm;
    if (actuador) {
        actuador->seteo_gpio();
    }
}

void
Coordinador::ejecutor() {
    if( sensor ) {
        sensor->get_mediciones();
    }
    if ( fsm ) {
        fsm->ejecutar_maquina();
    }
    if ( actuador ) {
        actuador->setear_level(fsm->get_state());
    }
}