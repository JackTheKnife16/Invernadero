#ifndef SENSOR_CAPACITIVE_SOIL_H
#define SENSOR_CAPACITIVE_SOIL_H
#include "sensor_interfaz.h"

class SensorCapacitiveSoil : public SensorInterfaz {
 public:
    SensorCapacitiveSoil(gpio_num_t _gpio, adc1_channel_t _channel, int16_t min, int16_t max);
    std::vector<int16_t> get_mediciones();
    int16_t get_medicion();
    int16_t get_humedad_sustrato();
 private:
    int medicion_adc;
    adc1_channel_t channel;
    std::vector<int16_t> humedad_sustrato_v = {0};
    int humedad_sustrato;
    float m;
    float b;
    int16_t min_adc = 1400;
    int16_t max_adc = 3200;
};

#endif
