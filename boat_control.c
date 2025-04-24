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

const uint8_t* get_docking_servo_angles(uint8_t boat_id) {
    return docking_positions[boat_id].angles;
}

const uint8_t* get_docking_servo_angles_up(uint8_t boat_id) {
    return docking_up[boat_id].angles;
}
