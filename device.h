/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */


#ifndef XC_DEVICE_H
#define	XC_DEVICE_H

#include <xc.h> // include processor files - each processor file is guarded.  

#define CLK_FRQ                 (U31000)

#define TOGGLE_GREEN_LED()          LATBbits.LATB7 ^= 1
#define TOGGLE_RED_LED()            LATBbits.LATB6 ^= 1
#define TOGGLE_RELAY()              LATBbits.LATB5 ^= 1

#define TURN_ON_RELAY()             LATBbits.LATB5 = 1
#define TURN_OFF_RELAY()            LATBbits.LATB5 = 0
#define TURN_ON_RED_LED()           LATBbits.LATB6 = 1
#define TURN_OFF_RED_LED()          LATBbits.LATB6 = 0
#define TURN_ON_GREEN_LED()           LATBbits.LATB7 = 1
#define TURN_OFF_GREEN_LED()          LATBbits.LATB7 = 0

/**
 * Set the green led pin
 */
void config_green_led();

/**
 * Set the red led pin
 */
void config_red_led();

/**
 *  Set the pin to drive the transistor to drive the relay
 */
void config_relay_switch();

/**
 * Set the oscillator registers
 */
void config_clock();

/**
 * Configure the device
 */
void config_device();


#endif	/* XC_HEADER_TEMPLATE_H */
