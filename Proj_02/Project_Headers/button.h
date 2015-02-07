//**************************************************************************************************************
// FILE: button.h
//
// DECRIPTION
// This header file specifies the function protypes that will be defined to initialize and read state
// from the button switch.
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


#ifndef BUTTON_H_
#define BUTTON_H_

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: button_init()
//
// DESCRIPTION
// Call gpio_init() to initialize certain push button.
//
// Input:
// button can be 0 or 1 which are button 1 and button 3.
//--------------------------------------------------------------------------------------------------------------
void button_init(int button);

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: get_button_state()
//
// DESCRIPTION
// Call gpio_get_pin_state() to return status of a pin from port TA.
//
// Input:
// button can be 0 or 1 which are button 1 and button 3.
//--------------------------------------------------------------------------------------------------------------
int get_button_state(int button);


#endif /* BUTTON_H_ */
