#include "sensor_luz.h"

SensorLuz::SensorLuz(gpio_num_t _gpio, adc1_channel_t _channel) : SensorInterfaz(_gpio) {
    channel = _channel;
}

std::vector<int16_t>
SensorLuz::get_mediciones() {
    get_medicion();
    mediciones[0] = medicion_adc;
    return mediciones;
}

int16_t
SensorLuz::get_medicion() {
    medicion_adc = adc1_get_raw(channel);
    return medicion_adc;
}
