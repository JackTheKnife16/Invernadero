#include "actuador_interfaz.h"

ActuadorInterfaz::ActuadorInterfaz(gpio_num_t _gpio) {
    gpio = _gpio;
}

void
ActuadorInterfaz::seteo_gpio(){
    gpio_reset_pin(gpio);
    gpio_set_direction(gpio, GPIO_MODE_OUTPUT);
}

void
ActuadorInterfaz::setear_level(uint32_t level) {
    std::cout << "level = " << level << std::endl;
    gpio_set_level(gpio, level);
}
