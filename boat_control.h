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

//typedef struct {
//    uint8_t x;           // Grid X position
//    uint8_t y;           // Grid Y position
//    uint8_t is_vertical; // 0 = Horizontal, 1 = Vertical
//    uint8_t is_docked;  // 1 = At docking station, 0 = On grid
//} BoatState;

extern const DockingPosition docking_positions[NUM_BOATS];
extern const DockingPosition docking_up[NUM_BOATS];
//extern BoatState boats[NUM_BOATS];                   

//void init_boats();
//void move_boat(uint8_t boat_id, uint8_t x, uint8_t y, uint8_t is_vertical);
//void return_boat_to_dock(uint8_t boat_id);
const uint8_t* get_docking_servo_angles(uint8_t boat_id);
const uint8_t* get_docking_servo_angles_up(uint8_t boat_id);

#endif	/* BOAT_CONTROL_H */

