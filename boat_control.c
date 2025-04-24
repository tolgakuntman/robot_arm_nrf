/* 
 * File:   boat_control.C
 * Author: aevern
 * 
 * Created on March 25, 2025, 8:51 AM
 */

#include "boat_control.h"
#include "grid_lookup.h"
#include "servo.h"

// Fixed docking positions
const DockingPosition docking_positions[NUM_BOATS] = {
    { {23, 45, 40, 42} },  // Boat 0   P6-P5-P8-P7
    { {64, 45, 14, 84} },  // Boat 2
    { {42, 45, 22, 67} },  // Boat 1
    { {61, 45, 32, 81} }   // Boat 3
};

const DockingPosition docking_up[NUM_BOATS] = {
    { {30, 45, 40, 30} },  // Boat 0   P6-P5-P8-P7
    { {70, 45, 14, 70} },  // Boat 2
    { {60, 45, 22, 60} },  // Boat 1
    { {70, 45, 32, 70} }   // Boat 3
};


// Dynamic boat positions
//BoatState boats[NUM_BOATS];
//
//void init_boats() {
//    for (uint8_t i = 0; i < NUM_BOATS; i++) {
//        boats[i].is_docked = 1;    // Start docked
//        boats[i].is_vertical = 0;  // Default to horizontal
//    }
//}
//void move_boat(uint8_t boat_id, uint8_t x, uint8_t y, uint8_t is_vertical) {
//    if (boat_id < NUM_BOATS && x < GRID_SIZE && y < GRID_SIZE) {
//        boats[boat_id].x = x;
//        boats[boat_id].y = y;
//        boats[boat_id].is_vertical = is_vertical;
//        move_servo_to_angles(get_grid_servo_angles(x, y));
//        boats[boat_id].is_docked = 0;  // Mark as placed on grid
//    }
//}
//
//void return_boat_to_dock(uint8_t boat_id) {
//    if (boat_id < NUM_BOATS) {
//        boats[boat_id].is_docked = 1;
//    }
//}

const uint8_t* get_docking_servo_angles(uint8_t boat_id) {
    return docking_positions[boat_id].angles;
}

const uint8_t* get_docking_servo_angles_up(uint8_t boat_id) {
    return docking_up[boat_id].angles;
}
