#include <stdio.h>
#include "driver/ledc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "esp_err.h"

#include "dht.h"

#define DTH_MAX_NUM_ERRORES 25

/*
* al agregar gpios a las listas se debe tambien aumentar el valor de los define NUM_DHT...
*/
#define NUM_DTH_INTERNOS 1
#define NUM_DTH_EXTERNOS 1
int8_t GPIOS_AMBIENTAL_INTERNA[] = {25};
int8_t GPIOS_AMBIENTAL_EXTERNA[] = {33};


int16_t aire_temperatura_interna[NUM_DTH_INTERNOS];
int16_t aire_humedad_interna[NUM_DTH_INTERNOS];
int16_t aire_temperatura_externa[NUM_DTH_EXTERNOS];
int16_t aire_humedad_externa[NUM_DTH_EXTERNOS];

esp_err_t error_aire_interna[NUM_DTH_INTERNOS];
esp_err_t error_aire_externa[NUM_DTH_EXTERNOS];

float temperatura_centigrados_interna = 0.0;
float humedad_relativa_interna = 0.0;
float temperatura_centigrados_externa = 0.0;
float humedad_relativa_externa = 0.0;

/*
* se usa para promediar las mediciones de los sensores de temperatura y humedad ambiental, esto tiene utilidad
* en el caso de que el invernadero tenga un tamanio que obligue a agregar varios sensores de medicion, de la 
* misma manera se usa para sensores fuera del invernadero. En el caso de que solo tengamos un sensor el promedio
* daria el resultado de un solo sensor.
*/
void promediar_mediciones_aire(uint8_t num_sensores_dth, int16_t *aire_temperatura, 
    int16_t *aire_humedad, esp_err_t *error_aire, float *temperatura_centigrados, float *humedad_relativa) {
        float temperatura_temp = 0.0;
        float humedad_temp = 0.0;
        int mediciones_validas = 0;
        for( int k = 0; k < num_sensores_dth; k++ ) {
            if( error_aire[k] == ESP_OK) {
                temperatura_temp += aire_temperatura[k];
                humedad_temp += aire_humedad[k];
                mediciones_validas++;
            }
        }
        temperatura_temp = temperatura_temp / mediciones_validas;
        humedad_temp = humedad_temp / mediciones_validas;

        *temperatura_centigrados = (temperatura_temp / 10 - 32) * 5/9; 
        *humedad_relativa = humedad_temp / 10;
}

/*
* Este metodo sirve para guardar los valores de los sensores en sus respectivas variables, tambien guarda los
* errores de existir estos al tratar de hacer mediciones, esto es necesario para luego poder hacer los 
* promedios de mediciones de forma correcta.
*/
void set_mediciones_aire(uint8_t num_sensores_dth, int8_t *array_gpios, int16_t *array_humedad, 
    int16_t *array_temperatura, esp_err_t *array_error_aire) {

    int8_t num_errores = 0;
    for(int k = 0; k < num_sensores_dth; k++) {
        while( (array_error_aire[k] = dht_read_data(DHT_TYPE_AM2301, array_gpios[k], &array_humedad[k], &array_temperatura[k])) != ESP_OK ){
            if ( num_errores >= DTH_MAX_NUM_ERRORES ) {        
                printf("Error de lectura sensor dth22 conectado al gpio %d\n", array_gpios[k]);
                num_errores = 0;
                break;
            }
            else {
                num_errores++;
            }
        }
    }
}

/*
* se usa para obtener las mediciones promedidas de todos los sensores dhtXX internos
*/
void get_mediciones_internas_promediadas_dht(void) {
    set_mediciones_aire(NUM_DTH_INTERNOS, GPIOS_AMBIENTAL_INTERNA, 
        aire_temperatura_interna, aire_humedad_interna, error_aire_interna);
    promediar_mediciones_aire(NUM_DTH_INTERNOS, aire_temperatura_interna, aire_humedad_interna, 
        error_aire_interna, &temperatura_centigrados_interna, &humedad_relativa_interna);
}

/*
* se usa para obtener las mediciones promedidas de todos los sensores dhtXX externos
*/
void get_mediciones_externas_promediadas_dht(void) {
    set_mediciones_aire(NUM_DTH_EXTERNOS, GPIOS_AMBIENTAL_EXTERNA, 
        aire_temperatura_externa, aire_humedad_externa, error_aire_externa);
    promediar_mediciones_aire(NUM_DTH_EXTERNOS, aire_temperatura_externa, aire_humedad_externa, 
        error_aire_externa, &temperatura_centigrados_externa, &humedad_relativa_externa);
}

void app_main(void)
{
    while(1) {
        get_mediciones_internas_promediadas_dht();
        printf("humedad_relativa_interna = %.2f, temperatura_centigrados_interna = %.2f\n", 
            humedad_relativa_interna, temperatura_centigrados_interna);

        vTaskDelay(2000 / portTICK_PERIOD_MS);

    }

}
