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
#include "includes/fsm_ambiental.h"
#include "includes/coordinador.h"
#include "includes/sensor_interfaz.h"
#include "includes/sensor_dht22.h"
#include "sensor_capacitive_soil.h"
#include "dht.h"
#include <vector>

extern "C" void app_main(void)
{
    
    
    //std::vector<int16_t> vectorcito_humedad_sustrato;
    //std::vector<int16_t> vectorcito_humedad_ambiental;
    //int luz;
    // declarar un vector de Sensores
    
    // funcionando >>>
    // declarar un vector de Sensores
    std::vector<SensorInterfaz*> dht_array;
    // meter un sensor en el vector de sensores
    dht_array.push_back(new SensorDHT22(GPIO_NUM_32));
    // instanciar una maquina de estados
    FSM* fsm_ambiental = new FSMAmbiental(OFF);
    // instanciar una interfaz de actuador
    ActuadorInterfaz* ventana = new ActuadorInterfaz(GPIO_NUM_23);
    // crear el coordinador del vector de sensores
    Coordinador* coordinador_dht = new Coordinador(dht_array, fsm_ambiental, ventana);

    // declarar un vector de Sensores
    //std::vector<SensorInterfaz*> soil_derecha;
    // meter dos sensores en el vector de sensores
    //soil_derecha.push_back(new SensorCapacitiveSoil(GPIO_NUM_36, 1400, 3200));
    //soil_derecha.push_back(new SensorCapacitiveSoil(GPIO_NUM_39, 1400, 3200));
    // instanciar una maquina de estados
    //FSM* fsm_sustrato_derecha = new FSMSustrato(OFF);
    // instanciar una interfaz de actuador
    //ActuadorInterfaz* bomba_derecha = new ActuadorInterfaz(GPIO_NUM_23);
    // crear el coordinador del vector de sensores
    //Coordinador* coordinador_sustrato_derecha = new Coordinador(soil_derecha, fsm_sustrato_derecha, bomba_derecha);
    
    // declarar un vector de Sensores
    //std::vector<SensorInterfaz*> soil_izquierda;
    // meter dos sensores en el vector de sensores
    //soil_izquierda.push_back(new SensorCapacitiveSoil(GPIO_NUM_34, 1400, 3200));
    //soil_izquierda.push_back(new SensorCapacitiveSoil(GPIO_NUM_35, 1400, 3200));
    // instanciar una maquina de estados
    //FSM* fsm_sustrato_izquierda = new FSMSustrato(OFF);
    // instanciar una interfaz de actuador
    //ActuadorInterfaz* bomba_izquierda = new ActuadorInterfaz(GPIO_NUM_22);
    // crear el coordinador del vector de sensores
    //Coordinador* coordinador_sustrato_izquierda = new Coordinador(soil_izquierda, soil_izquierda, bomba_izquierda);

    while(1) {
        //dht->get_mediciones();
        //vectorcito_humedad_sustrato = soil_1->get_mediciones();
        //luz = adc1_get_raw(ADC1_CHANNEL_6);
        //std::cout << "luz = " << luz << std::endl;
        //std::cout << "humedad = " << dht->get_humedad_ambiental() << ", temperatura = " << dht->get_temperatura_ambiental() << std::endl;
        
        // funcionando >>>
        coordinador_dht->ejecutor();
        //coordinador_sustrato_derecha->ejecutor();
        //coordinador_sustrato_izquierda->ejecutor();
        //std::cout << "humedad_sustrato = " << soil_derecha[0]->get_humedad_sustrato() << "%" << std::endl;
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
