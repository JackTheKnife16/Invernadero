#include "coordinador.h"

Coordinador::Coordinador(std::vector<SensorInterfaz*> _sensor, FSM* _fsm, ActuadorInterfaz* _actuador) {
    sensor = _sensor;
    actuador = _actuador;
    fsm = _fsm;
    // inicializacion de vectores de medicion
    if( sensor.size() > 0 ) {
        numero_total_sensores = sensor.size();
        mediciones_diferentes_por_sensor = sensor[0]->get_mediciones().size();
        for ( int k = 0; k < numero_total_sensores; k++ ) {
            mediciones.push_back(std::vector<int16_t>());
            for ( int j = 0; j < mediciones_diferentes_por_sensor; j++ ) {
                mediciones[k].push_back(0);
            }  
        } 
        for ( int j = 0; j < mediciones_diferentes_por_sensor; j++ ) {
            mediciones_promediadas.push_back(0);
        }
    }
    if (actuador) {
        actuador->seteo_gpio();
    }
}

void
Coordinador::ejecutor() {
    if( sensor.size() > 0 ) {
        for ( int k = 0; k < numero_total_sensores; k++ ) {
            mediciones[k] = sensor[k]->get_mediciones();
        }

        for ( int j = 0; j < mediciones_diferentes_por_sensor; j++ ) {
            float suma_medicion = 0.0;
            for ( int k = 0; k < numero_total_sensores; k++ ) {
                suma_medicion += mediciones[k][j];
            }
            suma_medicion = suma_medicion / numero_total_sensores;
            mediciones_promediadas[j] = (int) suma_medicion;
        }
        std::cout << "mediciones promediadas = " << mediciones_promediadas[0] << std::endl;
    }
    if ( fsm ) {
        fsm->setear_mediciones(mediciones_promediadas);
        fsm->ejecutar_maquina();
    }
    if ( actuador ) {
        actuador->setear_level(fsm->get_state());
    }
}
