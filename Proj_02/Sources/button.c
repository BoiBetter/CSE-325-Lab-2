//**************************************************************************************************************
// FILE: button.c
//
// DECRIPTION
// Thsi files implement the initilization function as well as the get state function in order to read inputfrom
// dip switch.
//
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
// FUNCTION: button_init()
//
// DESCRIPTION
// Call gpio_init() to initialize certain push button.
//
// Input:
// button can be BUTTONx in which x can be replaced with 1 or 3.
//--------------------------------------------------------------------------------------------------------------
void button_init(int button){
    gpio_init(PORT_TA, button, FUNCT_GPIO, LOW);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: get_button_state()
//
// DESCRIPTION
// Call gpio_get_pin_state() to return status of a pin from port TA.
//
// Input:
// button can be BUTTONx in which x can be replaced with 1 or 3.
//--------------------------------------------------------------------------------------------------------------
int get_button_state(int button){
    return !gpio_get_pin_state(PORT_TA, button);
}



