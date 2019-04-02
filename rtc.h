/* 
 * File:   rtc.h
 * Author: Oscar
 * Comments:
 * Revision history: 1
 */


#ifndef XC_RTC_H
#define	XC_RTC_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

#define RTC_SCLK_PIN            LATCbits.LATC0
#define RTC_DATA_PIN            LATCbits.LATC1
#define RTC_CE_PIN              LATCbits.LATC2

#define HIGH                    1
#define LOW                     0

/* These are the register/commands of the RTC chip, the byte include both the 
    register and operation we want to do */
#define RTC_WRITE_SECONDS       0x80
#define RTC_READ_SECONDS        0x81
#define RTC_WRITE_MINUTES       0x82
#define RTC_READ_MINUTES        0x83
#define RTC_WRITE_HOURS         0x84
#define RTC_READ_HOURS          0x85
#define RTC_WRITE_DATE          0x86
#define RTC_READ_DATE           0x87
#define RTC_WRITE_MONTH         0x88
#define RTC_READ_MONTH          0x89
#define RTC_WRITE_DAY           0x8A
#define RTC_READ_DAY            0x8B
#define RTC_WRITE_YEAR          0x8C
#define RTC_READ_YEAR           0x8D
#define RTC_WRITE_WP            0x8E
#define RTC_READ_WP             0x8F
#define RTC_WRITE_TCS           0x90
#define RTC_READ_TCS            0x91

#define RTC_WRITE_CLOCK_BURST   0xBE
#define RTC_READ_CLOCK_BURST    0xBF

#define RTC_RAM_BURST_WRITE     0xFE
#define RTC_RAT_BURST_READ      0xFF

/**
 * Set the communication pins for CLK, DATA and CE
 */
void rtc_set_port();

/**
 * Write a single byte to a given register
 * @param command - The command includes the register address that we want to write to
 * @param data
 */
void rtc_single_byte_write(uint8_t command, uint8_t data);

/**
 * Read a byte of a register from the RTC
 * @param command - The command includes the register address we want to read
 * @return 
 */
uint8_t rtc_single_byte_read(uint8_t command);

/**
 * Basic loop delay
 * @param time
 */
void delay(int counter);

#endif	/* XC_HEADER_TEMPLATE_H */
