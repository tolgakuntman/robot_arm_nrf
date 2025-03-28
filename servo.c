#include "servo.h"
#include "mcc_generated_files/system/system.h"

servoMotor servos[NUM_SERVOS];

void isrTim0() {
    for (int i = 0; i < NUM_SERVOS; i++) {
        if (servos[i].currAngle < servos[i].nextAngle) {
            servos[i].currAngle++;
        } else if (servos[i].currAngle > servos[i].nextAngle) {
            servos[i].currAngle--;
        }
        
        // Set the PWM duty cycle based on the servo ID
        if (i == 0) {
            PWM2_16BIT_SetSlice1Output1DutyCycleRegister(servos[i].currAngle);
        } else if (i == 1) {
            PWM2_16BIT_SetSlice1Output2DutyCycleRegister(servos[i].currAngle);
        } else if (i == 2) {
            PWM3_16BIT_SetSlice1Output1DutyCycleRegister(servos[i].currAngle);
        } else if (i == 3) {
            PWM3_16BIT_SetSlice1Output2DutyCycleRegister(servos[i].currAngle);
        }
    }
    PWM2_16BIT_LoadBufferRegisters();
    PWM3_16BIT_LoadBufferRegisters();
}

void enableMagnet() {
    PWM1_16BIT_Enable();
    //PWM1_16BIT_SetSlice1Output1DutyCycleRegister(32767);
}

void disableMagnet() {
    PWM1_16BIT_Disable();
    //PWM1_16BIT_SetSlice1Output1DutyCycleRegister(0);
}

uint16_t calculateAngle(int angleDeg) {
    return (1760+(angleDeg*33));
}

void initServo() {
    //servos[0].id = 0; P6
    servos[0].currAngle = calculateAngle(45); 
    servos[0].nextAngle = calculateAngle(45); // Ensure target angle is different for movement
    
    //servos[1].id = 1; P5
    servos[1].currAngle = calculateAngle(90);
    servos[1].nextAngle = calculateAngle(90); // Ensure target angle is different for movement

    //servos[2].id = 2; P8
    servos[2].currAngle = calculateAngle(140);
    servos[2].nextAngle = calculateAngle(140); // Ensure target angle is different for movement

    //servos[3].id = 3; P7
    servos[3].currAngle = calculateAngle(10);
    servos[3].nextAngle = calculateAngle(10); // Ensure target angle is different for movement
    TMR2_Start();
}

void enablePWM() {
    PWM1_16BIT_Enable();
    PWM2_16BIT_Enable();
    //PWM3_16BIT_Enable();
    TMR2_OverflowCallbackRegister(isrTim0);
}