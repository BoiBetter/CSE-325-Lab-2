//**************************************************************************************************************
// FILE: gpio.c
//
// DECRIPTION
// This file defines the implementation of general GPIO pins from different ports by accessing the PAR,
// DDR, SET, and CLR registers to initiallize, set direction, set high, and set low of the pins.
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

const uint32 IPSBAR = 0x40000000;
const uint32 GPIO_BASE = IPSBAR + 0x00100000;
const uint32 GPIO_DDR_BASE = GPIO_BASE + 0x18;
const uint32 GPIO_SET_BASE = GPIO_BASE + 0x30;
const uint32 GPIO_CLR_BASE = GPIO_BASE + 0x48;
const uint32 GPIO_PAR_BASE = GPIO_BASE + 0x60;
const uint32 GPIO_PORT_TA = 0x0E;
const uint32 GPIO_PORT_TC = 0x0F;
const uint32 GPIO_PORT_DD = 0x14;
const uint32 FUNCT_PRIM = 0x01;
const uint32 FUNCT_SEC = 0x02;
const uint32 FUNCT_TERT = 0x03;
const uint32 DATA_DIR_IN = 0x00;
const uint32 DATA_DIR_OUT = 0x01;

#define GPIO_PORT(n) (*(vuint8 *)(GPIO_BASE + (n)))
#define GPIO_SET(n) (*(vuint8 *)(GPIO_SET_BASE + (n)))
#define GPIO_DDR(n) (*(vuint8 *)(GPIO_DDR_BASE + (n)))
#define GPIO_CLR(n) (*(vuint8 *)(GPIO_CLR_BASE + (n)))
#define GPIO_PAR(n) (*(vuint8 *)(GPIO_PAR_BASE + (n)))

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
void gpio_init(int port, int pin, int func, int state){
    // Check for which peripherals that we are configuring
    switch(port){
        // We are using LED
        case GPIO_PORT_TC:
            GPIO_PAR(port) &= ~(3<<(2*pin));
            break;

        // We are using push button
        case GPIO_PORT_TA:
            GPIO_PAR(port) &= ~(3<<(2*pin));
             break;

        // We using dip switch
        case GPIO_PORT_DD:
            GPIO_PAR(port) &= ~(1<<(pin));
            break;

    }

    // If configure the pin to be GPIO
    if(!func){
        // If port is LED, configure pin to be output
        if(port == GPIO_PORT_TC){
            GPIO_DDR(port) |= (1<<pin);
            gpio_set_pin_state(port, pin, state);
        }
        // If either push button or dip switch, configure pin as input
        if(port == GPIO_PORT_DD || port == GPIO_PORT_TA){
            GPIO_DDR(port) &= ~(1<<pin);
        }

    }
}

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
int gpio_get_pin_state(int port, int pin){

    return ((GPIO_SET(port) & (1<<pin))>>pin);
}

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
void gpio_set_pin_state(int port, int pin, int state){

    if(state){
        GPIO_SET(port) |= (1 << pin);
    }
    else{
        GPIO_CLR(port) &= ~(1 << pin);
    }
}

