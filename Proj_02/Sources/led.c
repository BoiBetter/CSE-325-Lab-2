//**************************************************************************************************************
// FILE: led.h
//
// DECRIPTION
// This header file specifies the function protypes that will be defined to initialize, turn on, and turn
// off certai LED.

// AUTHORS
// Hoa Nguyen  htnguy14@asu.edu
// Eric Pollack ericapproves84@gmail.com
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
// Computer Science & Engineering
// Arizona State University
// Tempe, AZ 85287-8809
//**************************************************************************************************************

#include "common.h"

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: led_all_init()
//
// DESCRIPTION
// Initialize all LEDs and turn them off initially.
//--------------------------------------------------------------------------------------------------------------
void led_all_init(){
    led_init(LED1);
    led_init(LED2);
    led_init(LED3);
    led_init(LED4);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: led_all_off()
//
// DESCRIPTION
// Turn all LEDs off.
//--------------------------------------------------------------------------------------------------------------
void led_all_off(){
    led_off(LED1);
    led_off(LED2);
    led_off(LED3);
    led_off(LED4);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: led_all_on()
//
// DESCRIPTION
// Turn all LEDs on.
//--------------------------------------------------------------------------------------------------------------
void led_all_on(){
    led_on(LED1);
    led_on(LED2);
    led_on(LED3);
    led_on(LED4);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: led_init()
//
// DESCRIPTION
// Initialize certain LED.
//
// Input:
// LEDx in which x can be replaced with 1,2,3, or 4.
//--------------------------------------------------------------------------------------------------------------
void led_init(int led){
    gpio_init(PORT_TC,led,FUNCT_GPIO, LOW);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: led_off()
//
// DESCRIPTION
// Turn off certain LED.
//
// Input:
// LEDx in which x can be replaced with 1,2,3, or 4.
//--------------------------------------------------------------------------------------------------------------
void led_off(int led){
    gpio_set_pin_state(PORT_TC,led,LOW);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: led_init()
//
// DESCRIPTION
// Turn on certain LED.
//
// Input:
// LEDx in which x can be replaced with 1,2,3, or 4.
//--------------------------------------------------------------------------------------------------------------
void led_on(int led){
    gpio_set_pin_state(PORT_TC,led,HIGH);
}






