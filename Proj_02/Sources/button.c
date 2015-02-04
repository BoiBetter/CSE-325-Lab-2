
#include "common.h"

void button_init(int pin){
    gpio_init(MCF_GPIO_PORTTA, pin, FUNC_GPIO, DATA_DIR_IN, LOW);
}

int get_button_state(int pin){
    return gpio_get_pin_state(MCF_GPIO_PORTTA, pin);
}



