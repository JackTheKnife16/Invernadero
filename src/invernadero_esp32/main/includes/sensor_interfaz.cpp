#include "sensor_interfaz.h"

SensorInterfaz::SensorInterfaz(gpio_num_t _gpio) {
    gpio = _gpio;
}

std::vector<int16_t>
SensorInterfaz::get_mediciones(){
    return mediciones;
}

int16_t
SensorInterfaz::get_medicion() {
    return medicion;
}

float
SensorInterfaz::get_humedad_ambiental() {
    return humedad_ambiental;
}

float
SensorInterfaz::get_temperatura_ambiental() {
    return temperatura_ambiental;
}

int
SensorInterfaz::get_medicion_adc() {
    return medicion_adc;
}

int16_t
SensorInterfaz::get_humedad_sustrato() {
    return humedad_sustrato;
}