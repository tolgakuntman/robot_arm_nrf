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
    { {21, 45, 47, 42} },  // Boat 0   P6-P5-P8-P7
    { {36, 28, 31, 62} },  // Boat 1
    { {56, 21, 24, 81} },  // Boat 2
    { {53, 42, 39, 80} }   // Boat 3
};

const DockingPosition docking_up[NUM_BOATS] = {
    { {35, 45, 47, 38} },  // Boat 0   P6-P5-P8-P7
    { {60, 28, 31, 53} },  // Boat 1
    { {73, 21, 24, 75} },  // Boat 2
    { {70, 42, 39, 70} }   // Boat 3
};

const uint8_t* get_docking_servo_angles(uint8_t boat_id) {
    return docking_positions[boat_id].angles;
}

const uint8_t* get_docking_servo_angles_up(uint8_t boat_id) {
    return docking_up[boat_id].angles;
}
