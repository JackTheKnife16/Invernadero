#include <iostream>
#include <string>
#include "driver/ledc.h"
#include "driver/adc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "actuador_interfaz.h"
#include "fsm.h"
#include "includes/coordinador.h"
#include "sensor_interfaz.h"
#include "sensor_dht22.h"
#include "dht.h"

extern "C" void app_main(void)
{
    
    ActuadorInterfaz* ledcito = new ActuadorInterfaz(GPIO_NUM_23);
    FSM* fsm_blink = new FSM(OFF);
    Coordinador* coordinador = new Coordinador(NULL, fsm_blink, ledcito);

    SensorInterfaz* dht = new SensorDHT22(GPIO_NUM_22);
    Coordinador* coordinador_dht = new Coordinador(dht, NULL, NULL);
    
    
    while(1) {
        coordinador->ejecutor();
        //dht->get_mediciones();
        coordinador_dht->ejecutor();
        std::cout << "humedad = " << dht->get_humedad_ambiental() << ", temperatura = " << dht->get_temperatura_ambiental() << std::endl;
        //dht_read_data(DHT_TYPE_AM2301, GPIO_NUM_22, &humedad, &temperatura);
        //std::cout << "humedad = " << humedad << ", temperatura = " << temperatura << std::endl;
        std::cout << "perro" << std::endl;
        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
