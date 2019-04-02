/* 
 * File:   rtc.c
 * Author: Oscar
 *
 * Created on 15 de marzo de 2019, 12:32 PM
 * 
 */

#include "rtc.h"

/**
 * Set the communication pins for CLK, DATA and CE
 */
void rtc_set_port()
{
    /* Clock pin */
    TRISCbits.TRISC0 = 0;   // 0 = PORTC0 pin is configured as an output
    ANSELCbits.ANSC0 = 0;   // 0 = Digital I/O
    WPUCbits.WPUC0 = 1;     // 0 = Pull-up disabled
    ODCONCbits.ODCC0 = 1;   // 0 = Port pin operates as standard push-pull drive (source and sink current)
    RTC_SCLK_PIN = 0;
    
    /* Data pin */
    TRISCbits.TRISC1 = 0;   // 0 = PORTC1 pin is configured as an output
    ANSELCbits.ANSC1 = 0;   // 0 = Digital I/O
    WPUCbits.WPUC1 = 1;     // 0 = Pull-up disabled
    ODCONCbits.ODCC1 = 1;   // 0 = Port pin operates as standard push-pull drive (source and sink current)
    RTC_DATA_PIN = LOW;
    
    /* CE pin */
    TRISCbits.TRISC2 = 0;   // 0 = PORTC2 pin is configured as an output
    ANSELCbits.ANSC2 = 0;   // 0 = Digital I/O
    WPUCbits.WPUC2 = 1;     // 0 = Pull-up disabled
    ODCONCbits.ODCC2 = 1;   // 0 = Port pin operates as standard push-pull drive (source and sink current)
    RTC_CE_PIN = LOW;
    
}

/**
 * Write a single byte to a given register
 * @param command - The command includes the register address that we want to write to
 * @param data
 */
void rtc_single_byte_write(uint8_t command, uint8_t data)
{  
    /* Enable chip */
    RTC_CE_PIN = HIGH;
    
    TRISCbits.TRISC1 = 0; // 0 = PORTC1 pin is configured as an OUTput
    WPUCbits.WPUC1 = 1; // Enable pull-up. Drive the line
    
    RTC_SCLK_PIN = LOW;
            
    for(int i = 0; i <= 7; i++){

        RTC_DATA_PIN = (uint8_t)(0x01 & (command >> i));
        delay(10);
        RTC_SCLK_PIN = HIGH;
        delay(10);
        RTC_SCLK_PIN = LOW;
    }
    
    for(int i = 0; i <= 7; i++){
        RTC_DATA_PIN = (uint8_t)(0x01 & (data >> i));
        delay(10);
        RTC_SCLK_PIN = HIGH;
        delay(10);
        RTC_SCLK_PIN = LOW;
    }
    
    RTC_CE_PIN = LOW;
}

/**
 * Read a byte of a register from the RTC
 * @param command - The command includes the register address we want to read
 * @return 
 */
uint8_t rtc_single_byte_read(uint8_t command)
{
    uint8_t data = 0;
    
    /* Enable chip */
    RTC_CE_PIN = HIGH;
    
    TRISCbits.TRISC1 = 0; // 0 = PORTC1 pin is configured as an OUTput
    WPUCbits.WPUC1 = 1; // Enable pull-up. Drive the line
    
    RTC_SCLK_PIN = LOW;
    
    for(int i = 0; i <= 7; i++){
        
        RTC_DATA_PIN = (uint8_t)(0x01 & (command >> i));
        delay(10);
        RTC_SCLK_PIN = HIGH;
        delay(10);
        RTC_SCLK_PIN = LOW;
    }
    
    RTC_DATA_PIN = 0; //Release the line
    
    TRISCbits.TRISC1 = 1; // 1 = PORTC1 pin is configured as an input
    WPUCbits.WPUC1 = 0;     // 0 = Pull-up disabled: let the rtc drive the line
    
    delay(5); //Delay to save the first bit
    
    for(int i = 0; i <= 7; i++){
        data |= (uint8_t)(PORTCbits.RC1 << i);
        delay(5);
        RTC_SCLK_PIN = HIGH;
        delay(10);
        RTC_SCLK_PIN = LOW;
        delay(5);
        //data |= (PORTCbits.RC1 << i);
    }
    
    RTC_CE_PIN = LOW;
    
    return data;
}

/**
 * Basic loop delay
 * @param time
 */
void delay(int counter)
{
    for(int i = 0; i < counter; i++){
    }
}