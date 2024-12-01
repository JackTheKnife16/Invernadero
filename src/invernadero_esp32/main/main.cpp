#include <iostream>
#include <string>
#include "driver/ledc.h"
#include "driver/adc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_err.h"
#include "includes/actuador_interfaz.h"
#include "includes/fsm.h"
#include "includes/fsm_sustrato.h"
#include "includes/coordinador.h"
#include "includes/sensor_interfaz.h"
#include "includes/sensor_dht22.h"
#include "sensor_capacitive_soil.h"
#include "dht.h"
#include <vector>

extern "C" void app_main(void)
{
    

    //SensorInterfaz* dht = new SensorDHT22(GPIO_NUM_22);
    //Coordinador* coordinador_dht = new Coordinador(dht, NULL, NULL);
    
    SensorInterfaz* soil_1 = new SensorCapacitiveSoil(GPIO_NUM_36, 1400, 3200);
    FSM* fsm_sustrato = new FSMSustrato(OFF);
    ActuadorInterfaz* electro_valvula = new ActuadorInterfaz(GPIO_NUM_23);
    Coordinador* coordinador_sustrato = new Coordinador(soil_1, fsm_sustrato, electro_valvula);

    //std::vector<int16_t> vectorcito_humedad_sustrato;
    //std::vector<int16_t> vectorcito_humedad_ambiental;
    //int luz;
    while(1) {
        //dht->get_mediciones();
        //vectorcito_humedad_sustrato = soil_1->get_mediciones();
        //coordinador_dht->ejecutor();
        //luz = adc1_get_raw(ADC1_CHANNEL_6);
        //std::cout << "luz = " << luz << std::endl;
        coordinador_sustrato->ejecutor();
        //std::cout << "humedad = " << dht->get_humedad_ambiental() << ", temperatura = " << dht->get_temperatura_ambiental() << std::endl;
        std::cout << "humedad_sustrato = " << soil_1->get_humedad_sustrato() << "%" << std::endl;
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}