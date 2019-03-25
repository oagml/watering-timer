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


void config_green_led();

void config_red_led();

void config_relay_switch();

void config_device();

void config_clock();

#endif	/* XC_HEADER_TEMPLATE_H */
