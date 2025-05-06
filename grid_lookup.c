/* 
 * File:   grid_lookup.C
 * Author: aevern
 * 
 * Created on March 24, 2025, 11:59 PM
 */

#include "grid_lookup.h"
// P6-P5-P8-P7
const GridPosition grid_angles[GRID_SIZE][GRID_SIZE] = {
    { { {15, 68, 161, 37}, 69, 69}, { {20, 62, 153, 48}, 162, 62},
      { {43, 55, 150, 69}, 152, 59}, { {59, 51, 148, 88}, 150, 51},
      { {76, 49, 144, 97}, 147, 49} },

    { { {14, 52, 147, 32}, 54, 54}, { {23, 49, 143, 48}, 147, 50},
      { {34, 44, 139, 65}, 145, 44}, { {50, 40, 139, 77}, 141, 43},
      { {73, 40, 136, 97}, 140, 40} },
      
    { { {12, 32, 128, 26}, 32, 32}, { {23, 34, 130, 48}, 134, 36},
      { {41, 33, 128, 68}, 131, 33}, { {56, 30, 129, 82}, 133, 30},
      { {71, 28, 129, 97}, 132, 28} },
      
    { { {11, 15, 112, 33}, 19, 19}, { {30, 16, 113, 56}, 115, 16},
      { {43, 21, 117, 70}, 118, 21}, { {59, 23, 119, 86}, 120, 23},
      { {76, 23, 119, 98}, 122, 23} },
      
    { { {21, 9, 95, 44}, 105, 8}, { {39, 106, 101, 63}, 106, 106},
      { {52, 106, 105, 77}, 106, 106}, { {64, 111, 110, 88}, 111, 111},
      { {80, 111, 111, 101}, 111, 111} },
};

const GridPosition grid_angles_up[GRID_SIZE][GRID_SIZE] = {
    { { {35, 68, 161, 30}, 69, 69}, { {45, 62, 153, 40}, 162, 62},
      { {60, 55, 150, 60}, 152, 59}, { {72, 51, 148, 71}, 150, 51},
      { {95, 49, 144, 85}, 147, 49} },

    { { {35, 52, 147, 25}, 54, 54}, { {45, 49, 143, 40}, 147, 50},
      { {50, 110, 139, 50}, 145, 44}, { {70, 110, 139, 70}, 141, 43},
      { {90, 34, 136, 85}, 140, 40} },
      
    { { {30, 110, 128, 20}, 32, 32}, { {45, 110, 130, 40}, 134, 36},
      { {55, 110, 128, 50}, 131, 33}, { {70, 110, 129, 70}, 133, 30},
      { {85, 28, 129, 80}, 132, 28} },
      
    { { {35, 110, 114, 30}, 19, 19}, { {55, 110, 113, 50}, 115, 16},
      { {50, 110, 117, 50}, 118, 21}, { {70, 110, 119, 70}, 125, 23},
      { {85, 173, 119, 80}, 122, 23} },
      
    { { {40, 110, 95, 35}, 105, 8}, { {55, 110, 101, 55}, 106, 106},
      { {59, 110, 105, 61}, 106, 106}, { {73, 110, 110, 75}, 111, 111},
      { {95, 173, 111, 90}, 111, 111} },
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

