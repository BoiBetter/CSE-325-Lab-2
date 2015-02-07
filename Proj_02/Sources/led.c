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

#include "support_common.h"
#include "led.h"

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: led_all_init()
//
// DESCRIPTION
// Initialize all LEDs and turn them off initially.
//--------------------------------------------------------------------------------------------------------------
void led_all_init(){
    led_init(0);
    led_init(1);
    led_init(2);
    led_init(3);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: led_all_off()
//
// DESCRIPTION
// Turn all LEDs off.
//--------------------------------------------------------------------------------------------------------------
void led_all_off(){
    led_off(0);
    led_off(1);
    led_off(2);
    led_off(3);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: led_all_on()
//
// DESCRIPTION
// Turn all LEDs on.
//--------------------------------------------------------------------------------------------------------------
void led_all_on(){
    led_on(0);
    led_on(1);
    led_on(2);
    led_on(3);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: led_init()
//
// DESCRIPTION
// Initialize certain LED.
//
// Input:
// led should be 0, 1, 2, 3
//--------------------------------------------------------------------------------------------------------------
void led_init(int led){
    MCF_GPIO_PTCPAR &= ~(0x03<<(led*2));
    MCF_GPIO_DDRTC |= (0x01<<led);
    led_off(led);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: led_off()
//
// DESCRIPTION
// Turn off certain LED.
//
// Input:
// led should be 0, 1, 2, 3
//--------------------------------------------------------------------------------------------------------------
void led_off(int led){
    MCF_GPIO_CLRTC &= ~(1<<led);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: led_init()
//
// DESCRIPTION
// Turn on certain LED.
//
// Input:
// led should be 0, 1, 2, 3
//--------------------------------------------------------------------------------------------------------------
void led_on(int led){
    MCF_GPIO_SETTC |= (1<<led);
}






