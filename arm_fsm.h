/* 
 * File:   arm_fsm.h
 * Author: aevern
 *
 * Created on March 25, 2025, 10:38 AM
 */

#ifndef ARM_FSM_H
#define	ARM_FSM_H

#include <stdint.h>
#include <stdbool.h>

typedef enum {
    IDLE,
    PICKUP,
    MAGNET_ON,
    MOVE_UP_DOCK,
    MIDDLE1,
    MIDDLE2,
    ROTATE_BOARD,
    BOAT_ROTATE,
    PLACEMENT,
    MAGNET_OFF,
    WAIT,
    MIDDLE3,
    ROTATE_DOCK,
    RETURN
} ArmState;

typedef enum {
    PLACE,
    REMOVE
} ArmMode;

void arm_fsm_init();
void arm_fsm_update();
void arm_set_target(uint8_t boat_id, uint8_t x, uint8_t y, uint8_t is_vertical, ArmMode mode);
bool arm_is_busy();  // Check if FSM is still running
void delay();
void start_fsm_delay(ArmState next);

#endif	/* ARM_FSM_H */

