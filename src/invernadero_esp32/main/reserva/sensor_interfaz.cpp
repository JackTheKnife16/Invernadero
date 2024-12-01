#include "sensor_interfaz.h"

SensorInterfaz::SensorInterfaz(gpio_num_t _gpio) {
    gpio = _gpio;
}

void
SensorInterfaz::get_mediciones(){}

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
