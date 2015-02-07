//**************************************************************************************************************
// FILE: dtim.c
//
// DECRIPTION
// This file implements the functions that will initilize the DTIM timer0 and allow precise delay time
// using timer counter.
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

#include "dtim.h"
#include "support_common.h"

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: dtim0_delay_ms()
//
// DESCRIPTION
// Delay by millisecond by calling the dtim0_delay_us() function and pass in 1000*m where m is the input
// of the function.
//
// Input:
// m is a positive integer.
//--------------------------------------------------------------------------------------------------------------
void dtim0_delay_ms(unsigned long m){
        dtim0_delay_us(m * 1000);
}

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
void dtim0_delay_us(unsigned long u) {
    MCF_DTIM0_DTER = 0x03; // Clear Events
    MCF_DTIM0_DTCN = 0x00000000; // Clear Timer Counter
    MCF_DTIM0_DTRR = (u-1);
    MCF_DTIM0_DTMR |= 0x0001;
    while ( !(MCF_DTIM0_DTER & 0x02)) {}
}

//--------------------------------------------------------------------------------------------------------------
// FUNCTION: dtim0_init()
//
// DESCRIPTION
// Initialize timer 0 by writing to the DTMR and DTMXR registers. Clock divider and PS are set to 1 and 79 to
// achieve a 1MHz clock.
//--------------------------------------------------------------------------------------------------------------
void dtim0_init() {
    MCF_DTIM0_DTMR |= 0x0001; // Reset Timer
    MCF_DTIM0_DTMR &= 0xFFFE; // Must have high to low pulse in order to reset the register
    MCF_DTIM0_DTMR = 0x4F02; // Set PS = 79, Clk Div = 1
    MCF_DTIM0_DTXMR = 0x40; // Set HALTED.
}




