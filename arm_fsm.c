/* 
 * File:   arm_fsm.C
 * Author: aevern
 * 
 * Created on March 25, 2025, 10:38 AM
 */

#include "arm_fsm.h"
#include "servo.h"
#include "boat_control.h"
#include "grid_lookup.h"
#include "mcc_generated_files/timer/tmr2.h"
#include "mcc_generated_files/pwm/pwm1_16bit.h"


static ArmState current_state, next_state, previous_state = IDLE;
static ArmMode arm_mode = PLACE;
static uint8_t target_boat;
static uint8_t target_x, target_y;
static uint8_t target_orientation;
static volatile bool process_fsm = false;
static volatile bool state_done = true;
static volatile bool delay_done = true;

void arm_fsm_init() {
    initServo();
    current_state = next_state = previous_state = IDLE;
    process_fsm = false;
    state_done = true;
    TMR0_OverflowCallbackRegister(delay);
    //init_boats();
}

void set_magnet_strength() {
    switch(target_boat) {
        case(0): {
            PWM1_16BIT_SetSlice1Output1DutyCycleRegister(23000);
            break;
        }
        case(1): {
            PWM1_16BIT_SetSlice1Output1DutyCycleRegister(100);
            break;
        }
        case(2): {
            PWM1_16BIT_SetSlice1Output1DutyCycleRegister(50);
            break;
        }
        case(3): {
            PWM1_16BIT_SetSlice1Output1DutyCycleRegister(50);
            break;
        }
    }
    PWM1_16BIT_LoadBufferRegisters();
}

void arm_set_target(uint8_t boat_id, uint8_t x, uint8_t y, uint8_t is_vertical, ArmMode mode) {
    if (current_state == IDLE) {
        target_boat = boat_id;
        target_x = x;
        target_y = y;
        target_orientation = is_vertical;
        arm_mode = mode;
        current_state = (mode == PLACE) ? ROTATE_DOCK/* MAGNET_ON*/ : ROTATE_BOARD;
        process_fsm = true;
        set_magnet_strength();
    }
}

bool arm_is_busy() {
    return process_fsm;  // Returns true if FSM is running
}

void delay() {
    delay_done = true;
    TMR0_Stop();  // Optional: Stop the timer if you only want one-shot delay
}

void start_fsm_delay(){//ArmState next) {
    delay_done = false;
    //delay_next_state = next;

    TMR0_Start();
}


void arm_fsm_update() {
    if (!process_fsm || servoMovement()) return;  // Only process when needed
    TMR2_PeriodCountSet(0xF);
    switch (current_state) {
        
        case ROTATE_DOCK: {
            TMR2_PeriodCountSet(0x4);
            uint16_t moveup_angles[NUM_SERVOS] = {getAngle(0), getAngle(1), calculateAngle(get_docking_servo_angles(target_boat)[2]), getAngle(3)};
            move_servo_to_int(moveup_angles);
            switch(previous_state) {
                case STILL: {
                    next_state = (arm_mode == PLACE) ? RETURN : MOVE_UP_DOCK;
                    break;
                }
                case IDLE: {
                    next_state = MOVE_UP_DOCK;
                    break;
                }
                default: {
                    next_state = MOVE_UP_DOCK;
                    break;
                }
            }
            break;
        }

        
        case PICKUP: {
            const uint8_t* angles = get_docking_servo_angles(target_boat);
            move_servo_to_angles(angles);
            next_state = (arm_mode == PLACE) ? MAGNET_ON : MAGNET_OFF;
            break;
        }
            
        case MAGNET_ON: {
            enableMagnet();
            next_state = (arm_mode == PLACE) ? MOVE_UP_DOCK/*IDLE*/ : MOVE_UP_BOARD;
            break;
        }
        
        case MOVE_UP_DOCK: {
            const uint8_t* angles = get_docking_servo_angles_up(target_boat);
            move_servo_to_angles(angles);
            switch(previous_state) {
                case MAGNET_ON: {
                    next_state = STILL;
                                //process_fsm = false;  // FSM complete, reset flag

                    break;
                }
                case ROTATE_DOCK: {
                    next_state = PICKUP;
                    break;
                }
                case WAIT: {
                    next_state = STILL;
                }
            }
            break;
        }
        
        case STILL: {
            uint16_t moveup_angles[NUM_SERVOS] = {calculateAngle(43), getAngle(1), getAngle(2), calculateAngle(45)};
            move_servo_to_int(moveup_angles);
            switch(previous_state) {
                case MOVE_UP_DOCK: {
                    next_state = (arm_mode == PLACE) ? ROTATE_BOARD : RETURN;
                    break;
                }
                case MOVE_UP_BOARD: {
                    next_state = ROTATE_DOCK;
                    break;
                }
            }
            break;

        }
        
        case ROTATE_BOARD: {
            TMR2_PeriodCountSet(0x5);
            uint16_t moveup_angles[NUM_SERVOS] = {getAngle(0), getAngle(1), calculateAngle(get_grid_servo_angles(target_x, target_y)[2]), getAngle(3)};
            move_servo_to_int(moveup_angles);
            next_state = MOVE_UP_BOARD;
            break;
        }
        
        case BOAT_ROTATE: {
            TMR2_PeriodCountSet(0x7);
            uint16_t angles[NUM_SERVOS] = {getAngle(0), calculateAngle(get_dependent_servo_angle(target_x, target_y, target_orientation)), getAngle(2), getAngle(3)};
            move_servo_to_int(angles);
            next_state = PLACEMENT;
            break;
        }

        case MOVE_UP_BOARD: {
            uint8_t angles[NUM_SERVOS];
            get_adjusted_servo_angles_up(target_x, target_y, target_orientation, angles);
            move_servo_to_angles(angles);
            switch(previous_state) {
                case ROTATE_BOARD: {
                    next_state = BOAT_ROTATE;
                    break;
                case WAIT: {
                    next_state = STILL;
                    break;
                    }
                case MAGNET_ON: {
                    next_state = STILL;
                    break;
                    }
                }
            }
            break;
        }
        
        case PLACEMENT: {
            uint8_t angles[NUM_SERVOS];
            get_adjusted_servo_angles(target_x, target_y, target_orientation, angles);
            move_servo_to_angles(angles);
            next_state = (arm_mode == PLACE) ? MAGNET_OFF : MAGNET_ON;
            break;
        }
        
        case MAGNET_OFF: {
            disableMagnet();
            start_fsm_delay();
            next_state = WAIT;
            break;
        }

        case WAIT: {
            if (!delay_done) return;
            switch(previous_state) {
                case MAGNET_OFF: {
                    next_state = (arm_mode == PLACE) ? MOVE_UP_BOARD : MOVE_UP_DOCK;
                    break;
                }
                case STILL: {
                    
                }
            }
            break;
        }
                    
        case RETURN: {
            uint8_t idle_angles[NUM_SERVOS] = {43, 45, 25, 45};
            move_servo_to_angles(idle_angles);
            next_state = IDLE;
            process_fsm = false;  // FSM complete, reset flag
            break;
            }

        case IDLE:
        default:
            break;
    }
    previous_state = current_state;
    current_state = next_state;
}