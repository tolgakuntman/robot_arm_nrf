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
// PLACE ORDER = IDLE > ROTATE_DOCK > MOVE_UP_DOCK > PICKUP > MAGNET_ON > MOVE_UP_DOCK > STILL > ROTATE_BOARD > MOVE_UP_BOARD > BOAT_ROTATE_BOARD > PLACEMENT > MAGNET_OFF > WAIT > MOVE_UP_BOARD > STILL > ROTATE_DOCK > RETURN
// RETURN ORDER = IDLE > ROTATE_BOARD > MOVE_UP_BOARD > BOAT_ROTATE_BOARD > PLACEMENT > MAGNET_ON > MOVE_UP_BOARD > BOAT_ROTATE_DOCK > STILL > ROTATE_DOCK > MOVE_UP_DOCK > PICKUP > MAGNET_OFF > WAIT > MOVE_UP_DOCK > STILL > RETURN 
typedef enum {
    IDLE,    
    ROTATE_DOCK,
    PICKUP,
    MAGNET_ON,
    MOVE_UP_DOCK,
    STILL,
    ROTATE_BOARD,
    BOAT_ROTATE_BOARD,
    BOAT_ROTATE_DOCK,
    MOVE_UP_BOARD,
    PLACEMENT,
    MAGNET_OFF,
    WAIT,
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
void start_fsm_delay();//ArmState next);
void set_magnet_strength();

#endif	/* ARM_FSM_H */

