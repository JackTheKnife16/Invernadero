idf_component_register(SRCS "main.cpp" 
                            "includes/sensor_dht22.cpp" 
                            "includes/sensor_capacitive_soil.cpp"
                            "includes/sensor_luz.cpp"
                            "includes/sensor_interfaz.cpp" 
                            "includes/coordinador.cpp" 
                            "includes/fsm.cpp" 
                            "includes/fsm_sustrato.cpp"
                            "includes/fsm_ambiental.cpp"
                            "includes/fsm_luz.cpp"
                            "includes/actuador_interfaz.cpp" 
                       INCLUDE_DIRS "." "includes")

