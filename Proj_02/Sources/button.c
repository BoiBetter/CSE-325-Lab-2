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
#include "button.h"
#include "support_common.h"

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: button_init()
//
// DESCRIPTION
// Call gpio_init() to initialize certain push button.
//
// Input:
// button can be 0 or 1 which are button 1 and button 3.
//--------------------------------------------------------------------------------------------------------------
void button_init(int button){
    MCF_GPIO_PTAPAR &= ~(3<<(button*2)); // set up GPIO function
    MCF_GPIO_DDRTA &= ~(1<<button); // Set direction to be input
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: get_button_state()
//
// DESCRIPTION
// Call gpio_get_pin_state() to return status of a pin from port TA.
//
// Input:
// button can be 0 or 1 which are button 1 and button 3.
//--------------------------------------------------------------------------------------------------------------
int get_button_state(int button){
    return !((MCF_GPIO_SETTA & (1<<button))>>button); // Pull the state from SET register
}



