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
//#include "mcc_generated_files/timer/tmr0.h"


static ArmState current_state, next_state = IDLE;
static ArmMode arm_mode = PLACE;
static uint8_t target_boat;
static uint8_t target_x, target_y;
static uint8_t target_orientation;
static volatile bool process_fsm = false;
static volatile bool state_done = true;
static volatile bool delay_done = true;
static ArmState delay_next_state;  // Store where to go after delay

void arm_fsm_init() {
    initServo();
    current_state = next_state = IDLE;
    process_fsm = false;
    state_done = true;
    TMR0_OverflowCallbackRegister(delay);
    //init_boats();
}

void arm_set_target(uint8_t boat_id, uint8_t x, uint8_t y, uint8_t is_vertical, ArmMode mode) {
    if (current_state == IDLE) {
        target_boat = boat_id;
        target_x = x;
        target_y = y;
        target_orientation = is_vertical;
        arm_mode = mode;
        current_state = (mode == PLACE) ? PICKUP/* BOAT_ROTATE*/ : ROTATE_BOARD;
        process_fsm = true;
    }
}

bool arm_is_busy() {
    return process_fsm;  // Returns true if FSM is running
}

void delay() {
    delay_done = true;
    TMR0_Stop();  // Optional: Stop the timer if you only want one-shot delay
}

void start_fsm_delay(ArmState next) {
    delay_done = false;
    delay_next_state = next;

    TMR0_Start();
}


void arm_fsm_update() {
    if (!process_fsm || servoMovement()) return;  // Only process when needed

    switch (current_state) {
        case PICKUP: {
            const uint8_t* angles = get_docking_servo_angles(target_boat);
            move_servo_to_angles(angles);
            next_state = (arm_mode == PLACE) ? MAGNET_ON : MAGNET_OFF;
            break;
        }
            
        case MAGNET_ON: {
            enableMagnet();
            next_state = (arm_mode == PLACE) ? /*MIDDLE1*/ MOVE_UP_DOCK/* PLACEMENT*/ : MIDDLE3;
            break;
        }
        
        case MOVE_UP_DOCK: {
            uint16_t moveup_angles[NUM_SERVOS] = {calculateAngle(50), getAngle(1), getAngle(2), calculateAngle(41)};
            move_servo_to_int(moveup_angles);
            next_state = MIDDLE1;
            break;
        }
            
        case MIDDLE1:{
            uint16_t middle1_angles[NUM_SERVOS] = {calculateAngle(50), getAngle(1), getAngle(2), calculateAngle(55)};
            move_servo_to_int(middle1_angles);
            //uint8_t middle1_angles[NUM_SERVOS] = {43, 90, 25, 45};
            //move_servo_to_angles(middle1_angles);
            next_state = (arm_mode == PLACE) ? /*MIDDLE2*/ ROTATE_BOARD : PICKUP;
            break;
        }

        case MIDDLE2: {
            uint8_t middle2_angles[NUM_SERVOS] = {47, 90, 115, 50};
            move_servo_to_angles(middle2_angles);
            next_state = (arm_mode == PLACE) ? PLACEMENT : MIDDLE1;
            break;
        }
        
        case ROTATE_BOARD: {
            uint16_t moveup_angles[NUM_SERVOS] = {getAngle(0), getAngle(1), calculateAngle(get_grid_servo_angles(target_x, target_y)[2]), getAngle(3)};
            move_servo_to_int(moveup_angles);
            next_state = (arm_mode == PLACE) ? BOAT_ROTATE : PLACEMENT;
            break;
        }
        
        case BOAT_ROTATE: {
            uint16_t moveup_angles[NUM_SERVOS] = {getAngle(0), calculateAngle(get_dependent_servo_angle(target_x, target_y, target_orientation)), getAngle(2), getAngle(3)};
            move_servo_to_int(moveup_angles);
            next_state = PLACEMENT;
            break;
        }

        case PLACEMENT: {
            uint8_t angles[NUM_SERVOS];
            get_adjusted_servo_angles(target_x, target_y, target_orientation, angles);
            move_servo_to_angles(angles);

            //uint16_t p_angles[NUM_SERVOS] = (calculateAngle(get_grid_servo_angles(target_x, target_y)[0]), getAngle(1), getAngle(2), calculateAngle(get_grid_servo_angles(target_x, target_y)[3]));
            //move_servo_to_int(p_angles);
            //move_boat(target_boat, target_x, target_y, target_orientation);
            next_state = (arm_mode == PLACE) ? MAGNET_OFF : MAGNET_ON;
              //          next_state = IDLE;
            //process_fsm = false;  // FSM complete, reset flag

            break;
        }

        case MAGNET_OFF: {
            disableMagnet();
//            if (arm_mode == REMOVE) {
//                return_boat_to_dock(target_boat);
//            }
            //next_state = (arm_mode == PLACE) ? WAIT/*RETURN*/ : RETURN;
            start_fsm_delay((arm_mode == PLACE) ? MIDDLE3 : RETURN);
            next_state = WAIT;
            break;
        }
        
        case WAIT: {
            if (!delay_done) return;  // Don?t move on until delay is done
            next_state = delay_next_state;
            break;
        }
        
        case MIDDLE3: {
            uint16_t middle2_angles[NUM_SERVOS] = {calculateAngle(50), getAngle(1), getAngle(2), calculateAngle(55)};
            move_servo_to_int(middle2_angles);
            next_state = (arm_mode == PLACE) ? RETURN : MIDDLE1;
            break;
        }
        
        case ROTATE_DOCK: {
            uint16_t moveup_angles[NUM_SERVOS] = {getAngle(0), getAngle(1), calculateAngle(get_docking_servo_angles(target_boat)[2]), getAngle(3)};
            move_servo_to_int(moveup_angles);
            next_state = PLACEMENT;
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
    
    current_state = next_state;
}