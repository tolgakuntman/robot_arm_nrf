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
    MIDDLE1,
    MIDDLE2,
    BOAT_ROTATE,
    PLACEMENT,
    MAGNET_OFF,
    MIDDLE3,
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

#endif	/* ARM_FSM_H */

