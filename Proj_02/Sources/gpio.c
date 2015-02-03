
#include "gpio.h"
#include "common.h"

void gpio_init(int port, int pin, int func, int dir, int state){
    // Check for which peripherals that we are configuring
    switch(port){
        // We are using LED
        case MCF_GPIO_PORTTC:
            MCF_GPIO_PTCPAR &= ~ ((1<<(pin*2))|(1<<(pin*2+1)));
            break;

        // We are using push button
        case MCF_GPIO_PORTTA:
             MCF_GPIO_PTAPAR &= ~ ((1<<(pin*2))|(1<<(pin*2+1)));
             break;

        // We using dip switch
        case MCF_GPIO_PORTDD:
            if(!func){
                MCF_GPIO_PDDPAR &= ~(1<<pin);
            }
            else{
                MCF_GPIO_PDDPAR |= (1<<pin);
            }
            break;

    }

    // If configure the pin to be GPIO
    if(!func){
        // If port is LED, configure pin to be output
        if(port == MCF_GPIO_PORTTC){
            MCF_GPIO_DDRTC |= (1<<pin);
            gpio_set_pin_state(port, pin, state);
        }
        // If either push button or dip switch, configure input as direction
        if(port == MCF_GPIO_PORTDD || port == MCF_GPIO_PORTTA){
            if(port == MCF_GPIO_PORTTA){
                MCF_GPIO_DDRTA &= ~(1<<pin);
            }
            else if(port == MCF_GPIO_PORTDD){
                MCF_GPIO_DDRDD &= ~(1<<pin);
            }
        }

    }
}

//**************************************************************************************************************
// FUNCTION: gpio_get_pin_state ()
//
// DESCRIPTION
// Get the state of pin in certain port.
//
// Input
// Port should have format of MCF_xxx and pin should be an from 0 to 7
//**************************************************************************************************************
int gpio_get_pin_state(int port, int pin){

    return ((port & (1<<pin))>>pin);
}

//**************************************************************************************************************
// FUNCTION: gpio_set_pin_state ()
//
// DESCRIPTION
// set the state of pin in certain port.
//
// Input
// Port should have format of MCF_xxx and pin should be an from 0 to 7 and state should HIGH or LOW.
//**************************************************************************************************************
void gpio_set_pin_state(int port, int pin, int state){

    if(state){
        port |= (1 << pin);
    }
    else{
        port &= ~(1 << pin);
    }
}

