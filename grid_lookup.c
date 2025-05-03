/* 
 * File:   grid_lookup.C
 * Author: aevern
 * 
 * Created on March 24, 2025, 11:59 PM
 */

#include "grid_lookup.h"
// P6-P5-P8-P7
const GridPosition grid_angles[GRID_SIZE][GRID_SIZE] = {
    { { {23, 110, 161, 41}, 68, 68}, { {31, 110, 153, 56}, 162, 62},
      { {46, 110, 150, 71}, 152, 55}, { {61, 110, 148, 85}, 150, 51},
      { {76, 60, 144, 97}, 147, 49} },

    { { {19, 110, 149, 32}, 52, 52}, { {30, 110, 143, 52}, 147, 49},
      { {40, 110, 139, 66}, 145, 44}, { {55, 110, 139, 79}, 141, 40},
      { {74, 34, 136, 95}, 140, 40} },
      
    { { {14, 110, 128, 26}, 32, 32}, { {31, 110, 126, 52}, 134, 34},
      { {43, 110, 128, 67}, 131, 33}, { {56, 110, 129, 82}, 133, 30},
      { {72, 28, 129, 94}, 132, 28} },
      
    { { {20, 110, 114, 42}, 15, 15}, { {30, 110, 113, 56}, 115, 16},
      { {43, 110, 117, 70}, 118, 21}, { {59, 110, 119, 86}, 123, 23},
      { {76, 173, 119, 98}, 122, 23} },
      
    { { {25, 110, 94, 49}, 105, 9}, { {39, 110, 101, 63}, 106, 106},
      { {52, 110, 105, 77}, 106, 106}, { {66, 110, 110, 88}, 111, 111},
      { {80, 173, 111, 101}, 111, 111} },
};

const GridPosition grid_angles_up[GRID_SIZE][GRID_SIZE] = {
    { { {30, 110, 161, 30}, 68, 68}, { {40, 110, 153, 40}, 162, 62},
      { {50, 110, 150, 60}, 152, 55}, { {60, 110, 148, 70}, 150, 51},
      { {85, 60, 144, 80}, 147, 49} },

    { { {20, 110, 149, 20}, 52, 52}, { {35, 110, 143, 35}, 147, 49},
      { {50, 110, 139, 50}, 145, 44}, { {60, 110, 139, 70}, 141, 40},
      { {80, 34, 136, 80}, 140, 40} },
      
    { { {30, 110, 128, 20}, 32, 32}, { {30, 110, 126, 30}, 134, 34},
      { {40, 110, 128, 50}, 131, 33}, { {60, 110, 129, 70}, 133, 30},
      { {80, 28, 129, 80}, 132, 28} },
      
    { { {30, 110, 114, 30}, 15, 15}, { {40, 110, 113, 40}, 115, 16},
      { {50, 110, 117, 50}, 118, 21}, { {60, 110, 119, 70}, 125, 23},
      { {80, 173, 119, 80}, 122, 23} },
      
    { { {30, 110, 94, 30}, 105, 9}, { {40, 110, 101, 50}, 106, 106},
      { {50, 110, 105, 60}, 106, 106}, { {70, 110, 110, 70}, 111, 111},
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

