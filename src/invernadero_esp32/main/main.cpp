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
#include "includes/fsm_luz.h"
#include "includes/coordinador.h"
#include "includes/sensor_interfaz.h"
#include "includes/sensor_dht22.h"
#include "includes/sensor_capacitive_soil.h"
#include "includes/sensor_luz.h"
#include "dht.h"
#include <vector>

extern "C" void app_main(void)
{

     // declarar un vector de Sensores
    std::vector<SensorInterfaz*> luz_array;
    // meter un sensor en el vector de sensores
    luz_array.push_back(new SensorLuz(GPIO_NUM_32, ADC1_CHANNEL_4));
    // instanciar una maquina de estados
    FSM* fsm_luz = new FSMLuz(OFF);
    // instanciar una interfaz de actuador
    ActuadorInterfaz* bombillos = new ActuadorInterfaz(GPIO_NUM_3);
    // crear el coordinador del vector de sensores
    Coordinador* coordinador_luz = new Coordinador(luz_array, fsm_luz, bombillos);
    
    /*
    // funcionando >>>
        // configurar el pin 26 del sensor de lluvia como entrada   
    gpio_config_t io_conf = {
        .pin_bit_mask = (1ULL << GPIO_NUM_26),  // Seleccionar GPIO26
        .mode = GPIO_MODE_INPUT,               // Configurar como entrada
        .pull_up_en = GPIO_PULLUP_DISABLE,     // Deshabilitar resistencia pull-up
        .pull_down_en = GPIO_PULLDOWN_ENABLE,  // Habilitar resistencia pull-down
        .intr_type = GPIO_INTR_DISABLE         // Sin interrupciones
    };
    gpio_config(&io_conf);
    int no_lluvia;

    // declarar un vector de Sensores
    std::vector<SensorInterfaz*> dht_array;
    // meter un sensor en el vector de sensores
    dht_array.push_back(new SensorDHT22(GPIO_NUM_32));
    // instanciar una maquina de estados
    FSM* fsm_ambiental = new FSMAmbiental(OFF);
    // instanciar una interfaz de actuador
    ActuadorInterfaz* ventana = new ActuadorInterfaz(GPIO_NUM_1);
    // crear el coordinador del vector de sensores
    Coordinador* coordinador_dht = new Coordinador(dht_array, fsm_ambiental, ventana);

    // declarar un vector de Sensores
    std::vector<SensorInterfaz*> soil_derecha;
    // meter dos sensores en el vector de sensores
    soil_derecha.push_back(new SensorCapacitiveSoil(GPIO_NUM_36, 1400, 3200));
    soil_derecha.push_back(new SensorCapacitiveSoil(GPIO_NUM_39, 1400, 3200));
    // instanciar una maquina de estados
    FSM* fsm_sustrato_derecha = new FSMSustrato(OFF);
    // instanciar una interfaz de actuador
    ActuadorInterfaz* bomba_derecha = new ActuadorInterfaz(GPIO_NUM_23);
    // crear el coordinador del vector de sensores
    Coordinador* coordinador_sustrato_derecha = new Coordinador(soil_derecha, fsm_sustrato_derecha, bomba_derecha);
    
    // declarar un vector de Sensores
    std::vector<SensorInterfaz*> soil_izquierda;
    // meter dos sensores en el vector de sensores
    soil_izquierda.push_back(new SensorCapacitiveSoil(GPIO_NUM_34, 1400, 3200));
    soil_izquierda.push_back(new SensorCapacitiveSoil(GPIO_NUM_35, 1400, 3200));
    // instanciar una maquina de estados
    FSM* fsm_sustrato_izquierda = new FSMSustrato(OFF);
    // instanciar una interfaz de actuador
    ActuadorInterfaz* bomba_izquierda = new ActuadorInterfaz(GPIO_NUM_22);
    // crear el coordinador del vector de sensores
    Coordinador* coordinador_sustrato_izquierda = new Coordinador(soil_izquierda, fsm_sustrato_izquierda, bomba_izquierda);
    
    
    */
   
    while(1) {
        std::cout << "luz = " << luz_array[0]->get_medicion() << std::endl;
        coordinador_luz->ejecutor();

        /*
        // funcionando >>>
        coordinador_sustrato_derecha->ejecutor();
        coordinador_sustrato_izquierda->ejecutor();
        no_lluvia = gpio_get_level(GPIO_NUM_26);
        std::cout << "lluvia = " << no_lluvia << std::endl; //borrar al final
        if (no_lluvia) {
            coordinador_dht->ejecutor();
        }
        */
       
       
       vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
