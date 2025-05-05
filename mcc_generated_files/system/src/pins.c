/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.1.1
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

#include "../pins.h"

void (*nRF24_IRQ_InterruptHandler)(void);

void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATB = 0x0;
    LATC = 0x0;
    LATD = 0x0;
    LATE = 0x0;
    LATF = 0x0;
    /**
    ODx registers
    */
    ODCONA = 0x0;
    ODCONB = 0x0;
    ODCONC = 0x0;
    ODCOND = 0x0;
    ODCONE = 0x0;
    ODCONF = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0xFB;
    TRISB = 0xF0;
    TRISC = 0x8E;
    TRISD = 0xFF;
    TRISE = 0xF;
    TRISF = 0xFF;

    /**
    ANSELx registers
    */
    ANSELA = 0xFF;
    ANSELB = 0xFF;
    ANSELC = 0x81;
    ANSELD = 0xFF;
    ANSELE = 0x7;
    ANSELF = 0xFF;

    /**
    WPUx registers
    */
    WPUA = 0x0;
    WPUB = 0x0;
    WPUC = 0x0;
    WPUD = 0x0;
    WPUE = 0x0;
    WPUF = 0x0;


    /**
    SLRCONx registers
    */
    SLRCONA = 0xFF;
    SLRCONB = 0xFF;
    SLRCONC = 0xFF;
    SLRCOND = 0xFF;
    SLRCONE = 0x7;
    SLRCONF = 0xFF;

    /**
    INLVLx registers
    */
    INLVLA = 0xFF;
    INLVLB = 0xFF;
    INLVLC = 0xFF;
    INLVLD = 0xFF;
    INLVLE = 0xF;
    INLVLF = 0xFF;

   /**
    RxyI2C | RxyFEAT registers   
    */
    RB1I2C = 0x0;
    RB2I2C = 0x0;
    RC3I2C = 0x0;
    RC4I2C = 0x0;
    /**
    PPS registers
    */
    SPI1SDIPPS = 0x12; //RC2->SPI1:SDI1;
    RC4PPS = 0x32;  //RC4->SPI1:SDO1;
    RB3PPS = 0x1C;  //RB3->PWM3_16BIT:PWM31;
    RB2PPS = 0x1D;  //RB2->PWM3_16BIT:PWM32;
    RB1PPS = 0x1A;  //RB1->PWM2_16BIT:PWM21;
    RB0PPS = 0x1B;  //RB0->PWM2_16BIT:PWM22;
    RC0PPS = 0x18;  //RC0->PWM1_16BIT:PWM11;
    SPI1SCKPPS = 0x13;  //RC3->SPI1:SCK1;
    RC3PPS = 0x31;  //RC3->SPI1:SCK1;

   /**
    IOCx registers 
    */
    IOCAP = 0x0;
    IOCAN = 0x0;
    IOCAF = 0x0;
    IOCBP = 0x0;
    IOCBN = 0x0;
    IOCBF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x2;
    IOCCF = 0x0;
    IOCEP = 0x0;
    IOCEN = 0x0;
    IOCEF = 0x0;

    nRF24_IRQ_SetInterruptHandler(nRF24_IRQ_DefaultInterruptHandler);

    // Enable PIE0bits.IOCIE interrupt 
    PIE0bits.IOCIE = 1; 
}
  
void PIN_MANAGER_IOC(void)
{
    // interrupt on change for pin nRF24_IRQ
    if(IOCCFbits.IOCCF1 == 1)
    {
        nRF24_IRQ_ISR();  
    }
}
   
/**
   nRF24_IRQ Interrupt Service Routine
*/
void nRF24_IRQ_ISR(void) {

    // Add custom nRF24_IRQ code

    // Call the interrupt handler for the callback registered at runtime
    if(nRF24_IRQ_InterruptHandler)
    {
        nRF24_IRQ_InterruptHandler();
    }
    IOCCFbits.IOCCF1 = 0;
}

/**
  Allows selecting an interrupt handler for nRF24_IRQ at application runtime
*/
void nRF24_IRQ_SetInterruptHandler(void (* InterruptHandler)(void)){
    nRF24_IRQ_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for nRF24_IRQ
*/
void nRF24_IRQ_DefaultInterruptHandler(void){
    // add your nRF24_IRQ interrupt custom code
    // or set custom function using nRF24_IRQ_SetInterruptHandler()
}
/**
 End of File
*/