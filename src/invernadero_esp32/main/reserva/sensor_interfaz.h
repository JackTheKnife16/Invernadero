#ifndef SENSOR_INTERFAZ_H
#define SENSOR_INTERFAZ_H

#include <iostream>
#include "driver/ledc.h"
#include "driver/adc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"

class SensorInterfaz {
public:
    SensorInterfaz(gpio_num_t _gpio);
    virtual void get_mediciones();
    virtual int16_t get_medicion();
    virtual float get_humedad_ambiental();
    virtual float get_temperatura_ambiental();

protected:
    gpio_num_t gpio;
    int16_t medicion = 1;
    float humedad_ambiental = 0.0;
    float temperatura_ambiental = 0.0;
};
#endif

