/* 
 * File:   device.c
 * Author: Oscar
 *
 * Created on 28 de febrero de 2019, 12:50 PM
 */
#include <xc.h>
#include "device.h"

/**
 * Set the green led pin
 */
void config_green_led()
{
    TRISBbits.TRISB7 = 0;   // 0 = PORTB7 pin is configured as an output
    ANSELBbits.ANSB7 = 0;   // 0 = Digital I/O
    WPUBbits.WPUB7 = 0;     // 0 = Pull-up disabled
    ODCONBbits.ODCB7 = 0;   // 0 = Port pin operates as standard push-pull drive (source and sink current)
}

/**
 * Set the red led pin
 */
void config_red_led()
{
    TRISBbits.TRISB6 = 0;   // 0 = PORTB7 pin is configured as an output
    ANSELBbits.ANSB6 = 0;   // 0 = Digital I/O
    WPUBbits.WPUB6 = 0;     // 0 = Pull-up disabled
    ODCONBbits.ODCB6 = 0;   // 0 = Port pin operates as standard push-pull drive (source and sink current
}

/**
 *  Set the pin to drive the transistor to drive the relay
 */
void config_relay_switch()
{
    TRISBbits.TRISB5 = 0;   // 0 = PORTB7 pin is configured as an output
    ANSELBbits.ANSB5 = 0;   // 0 = Digital I/O
    WPUBbits.WPUB5 = 0;     // 0 = Pull-up disabled
    ODCONBbits.ODCB5 = 0;   // 0 = Port pin operates as standard push-pull drive (source and sink current
}

/**
 * Set the oscillator registers
 */
void config_clock()
{
    OSCCON1bits.NOSC = 0x5; //0x5 = LFINTOSC
    OSCCON1bits.NDIV = 0x0; //0x0 = Clock divider equals 1
    OSCCON2bits.CDIV = 0x0;
    OSCCON2bits.COSC = 0x5;
}

/**
 * Configure the device
 */
void config_device()
{
    //config_timer0();
    config_clock();
    config_green_led();
    config_red_led();
    config_relay_switch();
}