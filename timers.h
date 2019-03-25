/* 
 * File: timers.h
 * Author: Oscar
 * Comments: 
 * Revision history: 1 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_TIMERS_H
#define	XC_TIMERS_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include "device.h"
#include <stdint.h>

/* Timer value defined to get a 1 second */
#define TMR_VALUE       0x86E7

#define TMR_VALUE_HIGH  0x86
#define TMR_VALUE_LOW   0xE7    

/* 4 bit prescaler and postscaler */
#define TMR_PRESCALER   0x0
#define TMR_POSTSCALER  0x0


/**************************** Global Variables* *******************************/


/*************************** Function protoypes *******************************/
/**
 * Configure the Timer0
 */
//void config_timer0();

/**
 * ISR for Timer 0
 */
//void __interrupt tmr0_isr(void);


#endif	/* XC_HEADER_TEMPLATE_H */

