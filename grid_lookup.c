/* 
 * File:   grid_lookup.C
 * Author: aevern
 * 
 * Created on March 24, 2025, 11:59 PM
 */

#include "grid_lookup.h"
// P6-P5-P8-P7
const GridPosition grid_angles[GRID_SIZE][GRID_SIZE] = {
    { { {23, 110, 161, 37}, 70, 70}, { {30, 110, 153, 48}, 110, 110},
      { {47, 110, 150, 69}, 152, 56}, { {59, 110, 148, 79}, 150, 51},
      { {78, 60, 144, 95}, 147, 49} },

    { { {18, 110, 144, 29}, 50, 50}, { {30, 110, 142, 52}, 147, 50},
      { {44, 110, 138, 66}, 146, 46}, { {54, 110, 138, 78}, 140, 40},
      { {72, 34, 135, 90}, 140, 40} },
      
    { { {18, 110, 125, 30}, 32, 32}, { {26, 110, 125, 43}, 110, 110},
      { {45, 110, 127, 68}, 135, 35}, { {56, 110, 128, 78}, 133, 30},
      { {72, 28, 127, 92}, 132, 28} },
      
    { { {21, 110, 104, 35}, 9, 9}, { {30, 110, 110, 48}, 110, 110},
      { {39, 110, 114, 63}, 110, 40}, { {56, 110, 117, 77}, 125, 23},
      { {73, 173, 118, 91}, 123, 23} },
      
    { { {25, 110, 87, 44}, 105, 9}, { {34, 110, 96, 55}, 105, 105},
      { {46, 110, 102, 67}, 110, 110}, { {60, 110, 107, 80}, 111, 111},
      { {80, 173, 109, 99}, 110, 110} },
};

const GridPosition grid_angles_up[GRID_SIZE][GRID_SIZE] = {
    { { {30, 110, 161, 30}, 70, 70}, { {40, 110, 153, 40}, 110, 110},
      { {50, 110, 150, 60}, 152, 56}, { {60, 110, 148, 70}, 150, 51},
      { {85, 60, 144, 80}, 147, 49} },

    { { {20, 110, 144, 20}, 50, 50}, { {35, 110, 142, 35}, 147, 50},
      { {50, 110, 138, 50}, 146, 46}, { {60, 110, 138, 70}, 140, 40},
      { {80, 34, 135, 80}, 140, 40} },
      
    { { {30, 110, 125, 20}, 32, 32}, { {30, 110, 128, 30}, 110, 110},
      { {40, 110, 127, 50}, 135, 35}, { {60, 110, 128, 70}, 133, 30},
      { {80, 28, 127, 80}, 132, 28} },
      
    { { {30, 110, 104, 30}, 9, 9}, { {40, 110, 110, 40}, 110, 110},
      { {50, 110, 114, 50}, 110, 40}, { {60, 110, 117, 70}, 125, 23},
      { {80, 173, 118, 80}, 123, 23} },
      
    { { {30, 110, 87, 30}, 105, 9}, { {40, 110, 96, 50}, 105, 105},
      { {50, 110, 102, 60}, 110, 110}, { {70, 110, 107, 70}, 111, 111},
      { {90, 173, 109, 90}, 110, 110} },
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

