/* 
 * File:   grid_lookup.C
 * Author: aevern
 * 
 * Created on March 24, 2025, 11:59 PM
 */

#include "grid_lookup.h"
// P6-P5-P8-P7
const GridPosition grid_angles[GRID_SIZE][GRID_SIZE] = {
    { { {23, 110, 164, 37}, 70, 70}, { {30, 110, 156, 48}, 110, 110},
      { {47, 110, 153, 69}, 152, 56}, { {59, 110, 151, 79}, 150, 51},
      { {76, 60, 144, 97}, 147, 49} },

    { { {18, 110, 147, 29}, 50, 50}, { {30, 110, 145, 52}, 147, 50},
      { {44, 110, 141, 66}, 146, 46}, { {54, 110, 141, 78}, 140, 40},
      { {74, 34, 136, 95}, 140, 40} },
      
    { { {18, 110, 128, 30}, 32, 32}, { {26, 110, 128, 43}, 110, 110},
      { {45, 110, 130, 68}, 135, 35}, { {56, 110, 131, 78}, 133, 30},
      { {72, 28, 129, 94}, 132, 28} },
      
    { { {21, 110, 107, 35}, 9, 9}, { {30, 110, 113, 48}, 110, 110},
      { {39, 110, 117, 63}, 110, 40}, { {56, 110, 120, 77}, 125, 23},
      { {76, 173, 119, 98}, 122, 23} },
      
    { { {25, 110, 90, 44}, 105, 9}, { {34, 110, 99, 55}, 105, 105},
      { {46, 110, 105, 67}, 110, 110}, { {60, 110, 110, 80}, 111, 111},
      { {80, 173, 111, 101}, 111, 111} },
};

const GridPosition grid_angles_up[GRID_SIZE][GRID_SIZE] = {
    { { {30, 110, 164, 30}, 70, 70}, { {40, 110, 156, 40}, 110, 110},
      { {50, 110, 153, 60}, 152, 56}, { {60, 110, 151, 70}, 150, 51},
      { {85, 60, 144, 80}, 147, 49} },

    { { {20, 110, 147, 20}, 50, 50}, { {35, 110, 145, 35}, 147, 50},
      { {50, 110, 141, 50}, 146, 46}, { {60, 110, 141, 70}, 140, 40},
      { {80, 34, 136, 80}, 140, 40} },
      
    { { {30, 110, 128, 20}, 32, 32}, { {30, 110, 131, 30}, 110, 110},
      { {40, 110, 130, 50}, 135, 35}, { {60, 110, 131, 70}, 133, 30},
      { {80, 28, 129, 80}, 132, 28} },
      
    { { {30, 110, 107, 30}, 9, 9}, { {40, 110, 113, 40}, 110, 110},
      { {50, 110, 117, 50}, 110, 40}, { {60, 110, 120, 70}, 125, 23},
      { {80, 173, 119, 80}, 122, 23} },
      
    { { {30, 110, 90, 30}, 105, 9}, { {40, 110, 99, 50}, 105, 105},
      { {50, 110, 105, 60}, 110, 110}, { {70, 110, 110, 70}, 111, 111},
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

