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

#include "common.h"

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: dp_switch_init()
//
// DESCRIPTION
// Call gpio_init() to initialize certain dip switch input.
//
// Input:
// dp_switch can be DP_SWITCHx in which x can be replaced with 1, 2, 3, or 4.
//--------------------------------------------------------------------------------------------------------------
void dp_switch_init(int dp_switch){
    gpio_init(PORT_DD, dp_switch, FUNCT_GPIO, LOW);
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: get_dp_switch__state()
//
// DESCRIPTION
// Call gpio_get_pin_state() to return status of a pin from port DD.
//
// Input:
// dp_switch can be DP_SWITCHx in which x can be replaced with 1, 2, 3, or 4.
//--------------------------------------------------------------------------------------------------------------
int get_dp_switch_state(int dp_switch){
    return !gpio_get_pin_state(PORT_DD, dp_switch);
}
