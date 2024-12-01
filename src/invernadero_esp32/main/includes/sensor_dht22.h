#ifndef SENSOR_DHT22_H
#define SENSOR_DHT22_H
#include "dht.h"
#include "sensor_interfaz.h"

class SensorDHT22 : public SensorInterfaz {
public:
    SensorDHT22(gpio_num_t _gpio);
    std::vector<int16_t> get_mediciones();
    float get_humedad_ambiental();
    float get_temperatura_ambiental();
private:
    float humedad_ambiental;
    float temperatura_ambiental;
    int16_t humedad;
    int16_t temperatura;
    std::vector<int16_t> humedad_temperatura = {0, 0};
};

#endif
