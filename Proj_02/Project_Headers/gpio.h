//**************************************************************************************************************
// FILE: gpio.h
//
// DECRIPTION
// This header file specifies the function protypes that will be defined to initialize, read, and set
// general GPIO port and pin.

// AUTHORS
// Hoa Nguyen  htnguy14@asu.edu
// Eric Pollack ericapproves84@gmail.com
//
// COURSE: CSE325 Embedded Microprocessor Systems, Spring 2015
// Computer Science & Engineering
// Arizona State University
// Tempe, AZ 85287-8809
//**************************************************************************************************************


#ifndef GPIO_H_
#define GPIO_H_

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: gpio_get_pin_state()
//
// DESCRIPTION
// Return 0 or 1 of certain pin from certain port by accessing the SETn register of that port.
//
// Input:
// The port and pin are defined in the common.h file for different peripherals. Refer to common.h file.
//
// Output:
// Status of the pin. Could be 1 or 0.
//--------------------------------------------------------------------------------------------------------------
int gpio_get_pin_state(int port, int pin);

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: gpio_init()
//
// DESCRIPTION
// Initialize pin of certain port to the function indicated by the input func. This is done by accessing
// the PAR register of the port. The state is to initialize the pin in an initial state when it is first initialized.
// The function right now only deal with initializing pin to GPIO function.
//
// Input:
// The port and pin are defined in the common.h file for different peripherals. Refer to common.h file.
// func input can be 0x00, 0x01, 0x02, or 0x03. These values are defined in common.h file.
// state input can be LOW or HIGH which are defined as 0 or 1.
//--------------------------------------------------------------------------------------------------------------
void gpio_init(int port, int pin, int func, int state);

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: gpio_set_pin_state()
//
// DESCRIPTION
// Setting the pin of certain port to 0 or 1 by accessing the SET or CLR register of the port.
//
// Input:
// The port and pin are defined in the common.h file for different peripherals. Refer to common.h file.
// state input can be LOW or HIGH which are defined as 0 or 1.
//--------------------------------------------------------------------------------------------------------------
void gpio_set_pin_state(int port , int pin, int state);

#endif /* GPIO_H_ */
