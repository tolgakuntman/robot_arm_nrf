/* 
 * File:   servo.h
 * Author: Reaven Jansen
 *
 * Created on November 17, 2024, 4:25 PM
 */

#ifndef SERVO_H
#define	SERVO_H

#define NUM_SERVOS 4

#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/timer/tmr0.h"

typedef struct {
    //uint8_t id;
    uint16_t currAngle;
    uint16_t nextAngle;
} servoMotor;

//max servo 7700 = 180°
//min servo 1760 = 0°
//servoMotor servo0; //4000-9000 first arm
//servoMotor servo1; //1500-8500 rotate arm
//servoMotor servo2;
//servoMotor servo3; //5000-6500 second arm

extern servoMotor servos[NUM_SERVOS];

void isrTim0();
void enableMagnet();
void disableMagnet();
uint16_t calculateAngle(uint8_t angleDeg);
void initServo();
void enablePWM();
void move_servo_to_angles(const uint8_t* angles);
void move_servo_to_int(const uint16_t* intAngles);
bool servoMovement();
uint16_t getAngle(uint8_t i);

#endif	/* SERVO_H */

