//**************************************************************************************************************
// FILE: dp_switch.h
//
// DECRIPTION
// This header file specifies the function protypes that will be defined to initialize and read state
// from the dip switch.
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

#include "dp_switch.h"
#include "support_common.h"

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: dp_switch_init()
//
// DESCRIPTION
// Call gpio_init() to initialize certain dip switch input.
//
// Input:
// dp_switch can be 1, 2, 3, 4.
//--------------------------------------------------------------------------------------------------------------
void dp_switch_init(int dp_switch){
    MCF_GPIO_PDDPAR &= ~(1<<(dp_switch+3));
    MCF_GPIO_DDRDD &= ~(1<<dp_switch+3);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: get_dp_switch__state()
//
// DESCRIPTION
// Call gpio_get_pin_state() to return status of a pin from port DD.
//
// Input:
// dp_switch can be 1, 2, 3, 4
//--------------------------------------------------------------------------------------------------------------
int get_dp_switch_state(int dp_switch){
    return !((MCF_GPIO_SETDD & (1<<(dp_switch+3)))>>(dp_switch+3));
}
