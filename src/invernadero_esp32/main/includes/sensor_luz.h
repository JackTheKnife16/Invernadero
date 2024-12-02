#ifndef SENSOR_LUZ_H
#define SENSOR_LUZ_H
#include "sensor_interfaz.h"
#include "driver/adc.h"

class SensorLuz : public SensorInterfaz {
 public:
    SensorLuz(gpio_num_t _gpio, adc1_channel_t _channel);
    std::vector<int16_t> get_mediciones();
    int16_t get_medicion();
 private:
    int16_t medicion_adc;
    adc1_channel_t channel;
    std::vector<int16_t> mediciones = {0};
};

#endif
