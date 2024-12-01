#include "driver/ledc.h"
#include "driver/adc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"

#ifndef ACTUADOR_INTERFAZ_H
#define ACTUADOR_INTERFAZ_H

class ActuadorInterfaz {
public:
    ActuadorInterfaz(gpio_num_t _gpio);
    virtual void seteo_gpio();
    virtual void setear_level(uint32_t level);
private:
    gpio_num_t gpio;
};


#endif