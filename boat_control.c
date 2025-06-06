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
    { {20, 45, 47, 40} },  // Boat 0   P6-P5-P8-P7
    { {35, 28, 31, 60} },  // Boat 1
    { {55, 21, 24, 79} },  // Boat 2
    { {52, 42, 38, 78} }   // Boat 3
};

const DockingPosition docking_up[NUM_BOATS] = {
    { {35, 45, 47, 38} },  // Boat 0   P6-P5-P8-P7
    { {60, 28, 31, 53} },  // Boat 1
    { {73, 21, 24, 75} },  // Boat 2
    { {70, 42, 38, 70} }   // Boat 3
};

const uint8_t* get_docking_servo_angles(uint8_t boat_id) {
    return docking_positions[boat_id].angles;
}

const uint8_t* get_docking_servo_angles_up(uint8_t boat_id) {
    return docking_up[boat_id].angles;
}
