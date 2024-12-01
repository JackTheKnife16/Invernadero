#include "sensor_dht22.h"

SensorDHT22::SensorDHT22(gpio_num_t _gpio) : SensorInterfaz(_gpio) {
    gpio = _gpio;
}

void
SensorDHT22::get_mediciones() {
    while( dht_read_data(DHT_TYPE_AM2301, gpio, &humedad, &temperatura) != ESP_OK ) {
        std::cout << "Error DHT22" << std::endl;
    }
}

float
SensorDHT22::get_humedad_ambiental() {
    return (float) humedad / 10;
}

float
SensorDHT22::get_temperatura_ambiental() {
    return (float) temperatura / 10;
}
