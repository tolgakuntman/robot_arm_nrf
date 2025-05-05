/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.1
*/

/*
? [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA2 aliases
#define IO_RA2_TRIS                 TRISAbits.TRISA2
#define IO_RA2_LAT                  LATAbits.LATA2
#define IO_RA2_PORT                 PORTAbits.RA2
#define IO_RA2_WPU                  WPUAbits.WPUA2
#define IO_RA2_OD                   ODCONAbits.ODCA2
#define IO_RA2_ANS                  ANSELAbits.ANSELA2
#define IO_RA2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_RA2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_RA2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_RA2_GetValue()           PORTAbits.RA2
#define IO_RA2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_RA2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_RA2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_RA2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_RA2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_RA2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_RA2_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define IO_RA2_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set RB0 aliases
#define IO_RB0_TRIS                 TRISBbits.TRISB0
#define IO_RB0_LAT                  LATBbits.LATB0
#define IO_RB0_PORT                 PORTBbits.RB0
#define IO_RB0_WPU                  WPUBbits.WPUB0
#define IO_RB0_OD                   ODCONBbits.ODCB0
#define IO_RB0_ANS                  ANSELBbits.ANSELB0
#define IO_RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_RB0_GetValue()           PORTBbits.RB0
#define IO_RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IO_RB0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define IO_RB0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define IO_RB0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define IO_RB0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define IO_RB0_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define IO_RB0_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 aliases
#define IO_RB1_TRIS                 TRISBbits.TRISB1
#define IO_RB1_LAT                  LATBbits.LATB1
#define IO_RB1_PORT                 PORTBbits.RB1
#define IO_RB1_WPU                  WPUBbits.WPUB1
#define IO_RB1_OD                   ODCONBbits.ODCB1
#define IO_RB1_ANS                  ANSELBbits.ANSELB1
#define IO_RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_RB1_GetValue()           PORTBbits.RB1
#define IO_RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define IO_RB1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define IO_RB1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define IO_RB1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define IO_RB1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define IO_RB1_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define IO_RB1_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 aliases
#define IO_RB2_TRIS                 TRISBbits.TRISB2
#define IO_RB2_LAT                  LATBbits.LATB2
#define IO_RB2_PORT                 PORTBbits.RB2
#define IO_RB2_WPU                  WPUBbits.WPUB2
#define IO_RB2_OD                   ODCONBbits.ODCB2
#define IO_RB2_ANS                  ANSELBbits.ANSELB2
#define IO_RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_RB2_GetValue()           PORTBbits.RB2
#define IO_RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IO_RB2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IO_RB2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IO_RB2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define IO_RB2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define IO_RB2_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define IO_RB2_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 aliases
#define IO_RB3_TRIS                 TRISBbits.TRISB3
#define IO_RB3_LAT                  LATBbits.LATB3
#define IO_RB3_PORT                 PORTBbits.RB3
#define IO_RB3_WPU                  WPUBbits.WPUB3
#define IO_RB3_OD                   ODCONBbits.ODCB3
#define IO_RB3_ANS                  ANSELBbits.ANSELB3
#define IO_RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IO_RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IO_RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IO_RB3_GetValue()           PORTBbits.RB3
#define IO_RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IO_RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define IO_RB3_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define IO_RB3_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define IO_RB3_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define IO_RB3_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define IO_RB3_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define IO_RB3_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RC0 aliases
#define IO_RC0_TRIS                 TRISCbits.TRISC0
#define IO_RC0_LAT                  LATCbits.LATC0
#define IO_RC0_PORT                 PORTCbits.RC0
#define IO_RC0_WPU                  WPUCbits.WPUC0
#define IO_RC0_OD                   ODCONCbits.ODCC0
#define IO_RC0_ANS                  ANSELCbits.ANSELC0
#define IO_RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_RC0_GetValue()           PORTCbits.RC0
#define IO_RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_RC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_RC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define IO_RC0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define IO_RC0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 aliases
#define nRF24_IRQ_TRIS                 TRISCbits.TRISC1
#define nRF24_IRQ_LAT                  LATCbits.LATC1
#define nRF24_IRQ_PORT                 PORTCbits.RC1
#define nRF24_IRQ_WPU                  WPUCbits.WPUC1
#define nRF24_IRQ_OD                   ODCONCbits.ODCC1
#define nRF24_IRQ_ANS                  ANSELCbits.ANSELC1
#define nRF24_IRQ_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define nRF24_IRQ_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define nRF24_IRQ_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define nRF24_IRQ_GetValue()           PORTCbits.RC1
#define nRF24_IRQ_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define nRF24_IRQ_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define nRF24_IRQ_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define nRF24_IRQ_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define nRF24_IRQ_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define nRF24_IRQ_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define nRF24_IRQ_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define nRF24_IRQ_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)
#define RC1_SetInterruptHandler  nRF24_IRQ_SetInterruptHandler

// get/set RC2 aliases
#define MISO_TRIS                 TRISCbits.TRISC2
#define MISO_LAT                  LATCbits.LATC2
#define MISO_PORT                 PORTCbits.RC2
#define MISO_WPU                  WPUCbits.WPUC2
#define MISO_OD                   ODCONCbits.ODCC2
#define MISO_ANS                  ANSELCbits.ANSELC2
#define MISO_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define MISO_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define MISO_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define MISO_GetValue()           PORTCbits.RC2
#define MISO_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define MISO_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define MISO_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define MISO_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define MISO_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define MISO_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define MISO_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define MISO_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 aliases
#define SCK_TRIS                 TRISCbits.TRISC3
#define SCK_LAT                  LATCbits.LATC3
#define SCK_PORT                 PORTCbits.RC3
#define SCK_WPU                  WPUCbits.WPUC3
#define SCK_OD                   ODCONCbits.ODCC3
#define SCK_ANS                  ANSELCbits.ANSELC3
#define SCK_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCK_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCK_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCK_GetValue()           PORTCbits.RC3
#define SCK_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCK_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCK_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SCK_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SCK_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SCK_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define SCK_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define SCK_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 aliases
#define MOSI_TRIS                 TRISCbits.TRISC4
#define MOSI_LAT                  LATCbits.LATC4
#define MOSI_PORT                 PORTCbits.RC4
#define MOSI_WPU                  WPUCbits.WPUC4
#define MOSI_OD                   ODCONCbits.ODCC4
#define MOSI_ANS                  ANSELCbits.ANSELC4
#define MOSI_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define MOSI_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define MOSI_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define MOSI_GetValue()           PORTCbits.RC4
#define MOSI_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define MOSI_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define MOSI_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define MOSI_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define MOSI_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define MOSI_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define MOSI_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define MOSI_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 aliases
#define nRF24_CE_TRIS                 TRISCbits.TRISC5
#define nRF24_CE_LAT                  LATCbits.LATC5
#define nRF24_CE_PORT                 PORTCbits.RC5
#define nRF24_CE_WPU                  WPUCbits.WPUC5
#define nRF24_CE_OD                   ODCONCbits.ODCC5
#define nRF24_CE_ANS                  ANSELCbits.ANSELC5
#define nRF24_CE_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define nRF24_CE_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define nRF24_CE_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define nRF24_CE_GetValue()           PORTCbits.RC5
#define nRF24_CE_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define nRF24_CE_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define nRF24_CE_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define nRF24_CE_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define nRF24_CE_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define nRF24_CE_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define nRF24_CE_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define nRF24_CE_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 aliases
#define nRF24_CSN_TRIS                 TRISCbits.TRISC6
#define nRF24_CSN_LAT                  LATCbits.LATC6
#define nRF24_CSN_PORT                 PORTCbits.RC6
#define nRF24_CSN_WPU                  WPUCbits.WPUC6
#define nRF24_CSN_OD                   ODCONCbits.ODCC6
#define nRF24_CSN_ANS                  ANSELCbits.ANSELC6
#define nRF24_CSN_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define nRF24_CSN_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define nRF24_CSN_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define nRF24_CSN_GetValue()           PORTCbits.RC6
#define nRF24_CSN_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define nRF24_CSN_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define nRF24_CSN_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define nRF24_CSN_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define nRF24_CSN_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define nRF24_CSN_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define nRF24_CSN_SetAnalogMode()      do { ANSELCbits.ANSELC6 = 1; } while(0)
#define nRF24_CSN_SetDigitalMode()     do { ANSELCbits.ANSELC6 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the nRF24_IRQ pin functionality
 * @param none
 * @return none
 */
void nRF24_IRQ_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for nRF24_IRQ pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for nRF24_IRQ at application runtime
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void nRF24_IRQ_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for nRF24_IRQ pin.
 *        This is a dynamic interrupt handler to be used together with the nRF24_IRQ_SetInterruptHandler() method.
 *        This handler is called every time the nRF24_IRQ ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*nRF24_IRQ_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for nRF24_IRQ pin. 
 *        This is a predefined interrupt handler to be used together with the nRF24_IRQ_SetInterruptHandler() method.
 *        This handler is called every time the nRF24_IRQ ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void nRF24_IRQ_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/