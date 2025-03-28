/* 
 * File:   arm_fsm.C
 * Author: aevern
 * 
 * Created on March 25, 2025, 10:38 AM
 */

#include "arm_fsm.h"
#include "servo.h"
#include "boat_control.h"

static ArmState current_state, next_state = IDLE;
static ArmMode arm_mode = PLACE;
static uint8_t target_boat;
static uint8_t target_x, target_y;
static uint8_t target_orientation;
static volatile bool process_fsm = false;
static volatile bool state_done = true;

void arm_fsm_init() {
    current_state = next_state = IDLE;
    process_fsm = false;
    state_done = true;
    init_boats();
}

void arm_set_target(uint8_t boat_id, uint8_t x, uint8_t y, uint8_t is_vertical, ArmMode mode) {
    if (current_state == IDLE) {
        target_boat = boat_id;
        target_x = x;
        target_y = y;
        target_orientation = is_vertical;
        arm_mode = mode;
        current_state = (mode == PLACE) ? PICKUP : MIDDLE3;
        process_fsm = true;
    }
}

bool arm_is_busy() {
    return process_fsm;  // Returns true if FSM is running
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
            next_state = (arm_mode == PLACE) ? MIDDLE1 : MIDDLE2;
            break;
        }
            
        case MIDDLE1:{
            uint8_t middle1_angles[NUM_SERVOS] = {43, 90, 25, 45};
            move_servo_to_angles(middle1_angles);
            next_state = (arm_mode == PLACE) ? MIDDLE2 : PICKUP;
            break;
        }

        case MIDDLE2: {
            uint8_t middle2_angles[NUM_SERVOS] = {43, 90, 115, 45};
            move_servo_to_angles(middle2_angles);
            next_state = (arm_mode == PLACE) ? PLACEMENT : MIDDLE1;
            break;
        }
        
        case BOAT_ROTATE: {
            
            break;
        }

        case PLACEMENT: {
            move_boat(target_boat, target_x, target_y, target_orientation);
            next_state = (arm_mode == PLACE) ? MAGNET_OFF : MAGNET_ON;
            break;
        }

        case MAGNET_OFF: {
            disableMagnet();
            if (arm_mode == REMOVE) {
                return_boat_to_dock(target_boat);
            }
            next_state = (arm_mode == PLACE) ? MIDDLE3 : RETURN;
            break;
        }
        
        case MIDDLE3: {
            uint8_t middle2_angles[NUM_SERVOS] = {43, 90, 115, 45};
            move_servo_to_angles(middle2_angles);
            next_state = (arm_mode == PLACE) ? RETURN : PLACEMENT;
            break;
        }
            
        case RETURN: {
            uint8_t idle_angles[NUM_SERVOS] = {43, 90, 25, 45};
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