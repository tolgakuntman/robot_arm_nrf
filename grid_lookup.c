/* 
 * File:   grid_lookup.C
 * Author: aevern
 * 
 * Created on March 24, 2025, 11:59 PM
 */

#include "grid_lookup.h"
// P6-P5-P8-P7
const GridPosition grid_angles[GRID_SIZE][GRID_SIZE] = {
    { { {23, 68, 161, 41}, 68, 68}, { {31, 62, 153, 56}, 162, 62},
      { {44, 55, 150, 69}, 152, 59}, { {61, 51, 148, 85}, 150, 51},
      { {76, 49, 144, 97}, 147, 49} },

    { { {19, 52, 147, 32}, 54, 54}, { {28, 49, 143, 50}, 147, 50},
      { {40, 44, 139, 66}, 145, 44}, { {55, 40, 139, 79}, 141, 40},
      { {74, 40, 136, 95}, 140, 40} },
      
    { { {14, 32, 128, 26}, 32, 32}, { {31, 34, 126, 52}, 134, 34},
      { {43, 33, 128, 67}, 131, 33}, { {56, 30, 129, 82}, 133, 30},
      { {72, 28, 129, 94}, 132, 28} },
      
    { { {15, 15, 114, 35}, 19, 19}, { {30, 16, 113, 56}, 115, 16},
      { {43, 21, 117, 70}, 118, 21}, { {59, 23, 119, 86}, 123, 23},
      { {76, 23, 119, 98}, 122, 23} },
      
    { { {21, 9, 95, 44}, 105, 8}, { {39, 106, 101, 63}, 106, 106},
      { {52, 106, 105, 77}, 106, 106}, { {66, 111, 110, 88}, 111, 111},
      { {80, 111, 111, 101}, 111, 111} },
};

const GridPosition grid_angles_up[GRID_SIZE][GRID_SIZE] = {
    { { {35, 68, 161, 30}, 68, 68}, { {45, 62, 153, 40}, 162, 62},
      { {60, 55, 150, 60}, 152, 59}, { {70, 51, 148, 70}, 150, 51},
      { {90, 49, 144, 85}, 147, 49} },

    { { {35, 52, 147, 25}, 54, 54}, { {45, 49, 143, 40}, 147, 50},
      { {50, 110, 139, 50}, 145, 44}, { {70, 110, 139, 70}, 141, 40},
      { {85, 34, 136, 85}, 140, 40} },
      
    { { {30, 110, 128, 20}, 32, 32}, { {45, 110, 126, 40}, 134, 34},
      { {55, 110, 128, 50}, 131, 33}, { {70, 110, 129, 70}, 133, 30},
      { {80, 28, 129, 80}, 132, 28} },
      
    { { {35, 110, 114, 30}, 19, 19}, { {55, 110, 113, 50}, 115, 16},
      { {50, 110, 117, 50}, 118, 21}, { {70, 110, 119, 70}, 125, 23},
      { {80, 173, 119, 80}, 122, 23} },
      
    { { {40, 110, 95, 35}, 105, 8}, { {55, 110, 101, 55}, 106, 106},
      { {60, 110, 105, 60}, 106, 106}, { {75, 110, 110, 75}, 111, 111},
      { {90, 173, 111, 90}, 111, 111} },
};

const uint8_t* get_grid_servo_angles(uint8_t x, uint8_t y) {
    if (x < GRID_SIZE && y < GRID_SIZE) {
        return grid_angles[x][y].angles;
    }
}

uint8_t get_dependent_servo_angle(uint8_t x, uint8_t y, uint8_t is_vertical) {
    if (x < GRID_SIZE && y < GRID_SIZE) {
        return is_vertical ? grid_angles[x][y].angle_v : grid_angles[x][y].angle_h;
    }
    return 0; // Default fallback
}

void get_adjusted_servo_angles(uint8_t x, uint8_t y, uint8_t is_vertical, uint8_t* out_angles) {
    for (int i = 0; i < NUM_SERVOS; ++i) {
        out_angles[i] = grid_angles[x][y].angles[i];
    }
    // Override servo [1] based on orientation
    out_angles[1] = is_vertical ? grid_angles[x][y].angle_v : grid_angles[x][y].angle_h;
    
}

void get_adjusted_servo_angles_up(uint8_t x, uint8_t y, uint8_t is_vertical, uint8_t* out_angles) {
    for (int i = 0; i < NUM_SERVOS; ++i) {
        out_angles[i] = grid_angles_up[x][y].angles[i];
    }
    // Override servo [1] based on orientation
    out_angles[1] = is_vertical ? grid_angles_up[x][y].angle_v : grid_angles_up[x][y].angle_h;
    
}

