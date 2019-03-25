/*
 * File:   timers.c
 * Author: Oscar
 *
 * Created on 27 de febrero de 2019, 03:37 PM
 */


#include <xc.h>
#include "timers.h"

/**
 * Configure the Timer0
 * @param clk_freq
 */

//void config_timer0()
//{
//    TMR0H = TMR_VALUE_HIGH;
//    TMR0L = TMR_VALUE_LOW;
//    
//    /* T0CON0: Timer0 Control Register 0 */
//    T0CON0bits.T0EN = 0;        // 1 = Enabled *******Changed to 0
//    T0CON0bits.T016BIT = 1;     // 1 = Timer0 is a 16 bit timer
//    T0CON0bits.T0OUTPS = TMR_POSTSCALER;   // 1111 = 1:16 postscaler 0000 = 1:1 postscaler
//    
//    /* T0CON1: Timer0 Control Register 1 */
//    T0CON1bits.T0CS = 0x4;      // 100 = LFINTOSC as clock source
//    T0CON1bits.T0ASYNC = 1;     // The input to the TMR0 is not synchronized to FOSC/4
//    T0CON1bits.T0CKPS = TMR_PRESCALER;    // 1111 = 1:32768 prescaler 0000 = 1:1 prescaler
//    
//    /* INTCON: Interrupt Control Register */
//    INTCONbits.GIE = 0;          // Enable global interrupts. *****Changed to 0
//    INTCONbits.PEIE = 0;         // 1 = Enable peripheral interrupts
//    PIE0bits.TMR0IE = 0;         //1 = Enables the Timer0 interrupt *******Changed to 0
//    PIR0bits.TMR0IF = 0;         //Clear the overflow interrupt flag of Timer0
//    
//    /* The RETFIE instruction exits the ISR by popping the
//    previous address from the stack, restoring the saved
//    context from the shadow registers and setting the GIE
//    bit. */
//    
//    /* The firmware within the Interrupt Service Routine (ISR)
//    should determine the source of the interrupt by polling
//    the interrupt flag bits.*/
//    
//}
//
//void interrupt tmr0_isr()
//{
//    if(PIE0bits.TMR0IE && PIR0bits.TMR0IF){
//        TMR0H = TMR_VALUE_HIGH;
//        TMR0L = TMR_VALUE_LOW;
//        PIR0bits.TMR0IF = 0;
//        TOGGLE_GREEN_LED();
//        
//        time_passed += 1;
//    }
//    
//    INTCONbits.GIE = 1;
//}