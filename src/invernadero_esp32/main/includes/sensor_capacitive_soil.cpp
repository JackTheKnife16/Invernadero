#include "sensor_capacitive_soil.h"

SensorCapacitiveSoil::SensorCapacitiveSoil(gpio_num_t _gpio, int16_t _min, int16_t _max) : SensorInterfaz(_gpio) {
    gpio = _gpio;
    min_adc = _min;
    max_adc = _max;
    m = (float) 100 / (max_adc - min_adc);
    b = (float) m * min_adc * -1;
}

std::vector<int16_t>
SensorCapacitiveSoil::get_mediciones() {
    humedad_sustrato_v[0] = get_humedad_sustrato();
    std::cout << "Debug SensorCapacitiveSoil::get_mediciones >>> humedad_sustrato = " << humedad_sustrato_v[0] << std::endl;
    std::cout << "Debug SensorCapacitiveSoil::get_mediciones >>> numero de mediciones = " << humedad_sustrato_v.size() << std::endl;
    return humedad_sustrato_v; 
}

int16_t
SensorCapacitiveSoil::get_medicion() {
    medicion_adc = adc1_get_raw(ADC1_CHANNEL_0);
    return medicion_adc;
}

int16_t
SensorCapacitiveSoil::get_humedad_sustrato() {

    humedad_sustrato = m * get_medicion() + b;
    if ( humedad_sustrato < 0 ) {
        humedad_sustrato = 0;
    }
    else if ( humedad_sustrato > 100 ) {
        humedad_sustrato = 100;
    }
    
    return humedad_sustrato;
}

