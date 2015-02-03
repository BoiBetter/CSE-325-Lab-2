
#include "common.h"

void led_all_init(){
    led_init(LED1);
    led_init(LED2);
    led_init(LED3);
    led_init(LED4);
}

void led_all_off(){
    led_off(LED1);
    led_off(LED2);
    led_off(LED3);
    led_off(LED4);
}

void led_all_on(){
    led_on(LED1);
    led_on(LED2);
    led_on(LED3);
    led_on(LED4);
}

void led_init(int led){
    gpio_init(MCF_GPIO_PORTTC,led,FUNC_GPIO, DATA_DIR_OUT, LOW);
}

void led_off(int led){
    gpio_set_pin_state(MCF_GPIO_PORTTC,led,LOW);
}

void led_on(int led){
    gpio_set_pin_state(MCF_GPIO_PORTTC,led,HIGH);
}






