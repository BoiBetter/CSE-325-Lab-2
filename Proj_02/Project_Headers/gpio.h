//*******************************************************
// gpio.h
//
// Description
//
// Author
// Hoa Nguyen (htnguy14@asu.edu)
// Computer Science and Engineering
// Arizona State University
// Tempe AZ, 85287-8809

#ifndef GPIO_H_
#define GPIO_H_

int gpio_get_pin_state(int port, int pin);
void gpio_init(int port, int pin, int func, int dir, int state);
void gpio_set_pin_state(int port, int pin, int state);

#endif /* GPIO_H_ */
