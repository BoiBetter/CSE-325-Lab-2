//**************************************************************************************************************
// FILE: dtim.h
//
// DECRIPTION
// This header file specifies the function protypes that will be defined to initialize and set timer
// dtim0.
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

#ifndef DTIM_H_
#define DTIM_H_

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: dtim0_delay_ms()
//
// DESCRIPTION
// Delay by millisecond by calling the dtim0_delay_us() function and pass in 1000*m where m is the input
// of the function.
//
// Input:
// m is a positive integer less than 4294967.
//--------------------------------------------------------------------------------------------------------------
void dtim0_delay_ms(int m);

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: dtim0_delay_us()
//
// DESCRIPTION
// Delay by microsecond by setting the DTRR register and checking the DTER register to see if the counter value
// is set to 0X02, which indicates that counter value has matched reference value.
//
// Input:
// u is a positive integer.
//--------------------------------------------------------------------------------------------------------------
void dtim0_delay_us(int u);

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: dtim0_init()
//
// DESCRIPTION
// Initialize timer 0 by writing to the DTMR and DTMXR registers. Clock divider and PS are set to 1 and 79 to
// achieve a 1MHz clock.
//--------------------------------------------------------------------------------------------------------------
void dtim0_init();


#endif /* DTIM_H_ */
