//**************************************************************************************************************
// FILE: common.h
//
// DECRIPTION
// Header file that defines common LED, dip switch, and button names to make it easier to code other
// files.
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


#ifndef COMMON_H_
#define COMMON_H_

// Header files
#include "button.h"
#include "dp_switch.h"
#include "gpio.h"
#include "led.h"
#include "support_common.h"

// Common buttons
#define BUTTON1 (0)
#define BUTTON3 (1)

// Common dip switches
#define DP_SWITCH1 (4)
#define DP_SWITCH2 (5)
#define DP_SWITCH3 (6)
#define DP_SWITCH4 (7)

// Common LEDs
#define LED1 (0)
#define LED2 (1)
#define LED3 (2)
#define LED4 (3)

// Define different functions of a pin
#define FUNCT_GPIO (0x00)

// Define common HIGH and LOW
#define HIGH (1)
#define LOW (0)

// Different port address extensions
#define PORT_DD (0x14)
#define PORT_TA (0x0E)
#define PORT_TC (0x0F)






#endif /* COMMON_H_ */
