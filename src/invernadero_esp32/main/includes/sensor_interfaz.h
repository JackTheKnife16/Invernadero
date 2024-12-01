#ifndef SENSOR_INTERFAZ_H
#define SENSOR_INTERFAZ_H

#include <iostream>
#include "driver/ledc.h"
#include "driver/adc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include <vector>

class SensorInterfaz {
public:
    SensorInterfaz(gpio_num_t _gpio);
    virtual std::vector<int16_t> get_mediciones();
    virtual int16_t get_medicion();
    virtual float get_humedad_ambiental();
    virtual float get_temperatura_ambiental();
    virtual int get_medicion_adc();
    virtual int16_t get_humedad_sustrato();

protected:
    gpio_num_t gpio;
    std::vector<int16_t> mediciones;
    int16_t medicion = 1;
    float humedad_ambiental = 0.0;
    float temperatura_ambiental = 0.0;
    int medicion_adc = 0;
    int humedad_sustrato = 0;
};
#endif

