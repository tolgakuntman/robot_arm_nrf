/* 
 * File:   boat_control.h
 * Author: aevern
 *
 * Created on March 25, 2025, 8:51 AM
 */

#ifndef BOAT_CONTROL_H
#define	BOAT_CONTROL_H

#include <stdint.h>

#define GRID_SIZE 5
#define NUM_BOATS 4
#define NUM_SERVOS 4

typedef struct {
    uint8_t angles[NUM_SERVOS]; // Servo angles for docking
} DockingPosition;

extern const DockingPosition docking_positions[NUM_BOATS];
extern const DockingPosition docking_up[NUM_BOATS];

const uint8_t* get_docking_servo_angles(uint8_t boat_id);
const uint8_t* get_docking_servo_angles_up(uint8_t boat_id);

#endif	/* BOAT_CONTROL_H */

