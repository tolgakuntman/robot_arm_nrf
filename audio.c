/*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

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
#include "audio.h"
#include "mcc_generated_files/system/system.h"
#include "arm_fsm.h"

/*
    Main application
*/
#define FREQUENCY 100000              // Target frequency of the sine wave in Hz
//#define HIT_SOUND_LENGTH 5603  // Number of samples             // Increased points per sine wave cycle for smoothness
//#define MISS_SOUND_LENGTH 2044
#define AMPLITUDE 127                 // Amplitude for 8-bit DAC (0-255 range)
#define OFFSET 128                    // Offset to center the wave at mid-scale (for DAC)

// Pre-calculated sine values (64 points per cycle for 100 Hz wave)


volatile uint16_t index = 0;  // Index to step through array
void tim_1_irs() {
    
        DAC1DAT = sound->sound_array[index];  // Output the current sine wave value to DAC
        if(index++>=sound->length){
            TMR1_Stop();
            index=0;
        }
}

audio_init() {
    DAC1_Initialize();
    TMR1_Initialize();
    TMR1_OverflowCallbackRegister(tim_1_irs);
    sound = malloc(sizeof(Sound));
    sound->length=MISS_SOUND_LENGTH;
    sound->sound_array=MissSound;
    TMR1_Stop();

}
