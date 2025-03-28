#include "servo.h"
#include "mcc_generated_files/system/system.h"
#include "boat_control.h"

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

uint16_t calculateAngle(uint8_t angleDeg) {
    return (1760+(angleDeg*33));
}

void initServo() {
    //servos[0].id = 0; P6
    servos[0].currAngle = calculateAngle(50); 
    servos[0].nextAngle = calculateAngle(50); // Ensure target angle is different for movement
    
    //servos[1].id = 1; P5
    servos[1].currAngle = calculateAngle(90);
    servos[1].nextAngle = calculateAngle(90); // Ensure target angle is different for movement

    //servos[2].id = 2; P8
    servos[2].currAngle = calculateAngle(25);
    servos[2].nextAngle = calculateAngle(25); // Ensure target angle is different for movement

    //servos[3].id = 3; P7
    servos[3].currAngle = calculateAngle(40);
    servos[3].nextAngle = calculateAngle(40); // Ensure target angle is different for movement
}

void enablePWM() {
    PWM1_16BIT_Enable();
    PWM2_16BIT_Enable();
    //PWM3_16BIT_Enable();
    TMR0_OverflowCallbackRegister(isrTim0);
}

void move_servo_to_angles(const uint8_t* angles) {
    if (angles) {
        for (uint8_t i = 0; i < NUM_SERVOS; i++) {
            servos[i].nextAngle = calculateAngle(angles[i]);
        }
    }
}

bool servoMovement() {
    for (int i = 0; i < NUM_SERVOS; i++) {
        if (servos[i].currAngle != servos[i].nextAngle) {
            return true;
        }
    }
    return false;
}
