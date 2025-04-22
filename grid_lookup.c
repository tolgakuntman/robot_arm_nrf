/* 
 * File:   grid_lookup.C
 * Author: aevern
 * 
 * Created on March 24, 2025, 11:59 PM
 */

#include "grid_lookup.h"
// P6-P5-P8-P7
const GridPosition grid_angles[GRID_SIZE][GRID_SIZE] = {
    { { {23, 110, 161, 37}, 110, 110}, { {30, 110, 153, 48}, 110, 110},
      { {44, 110, 148, 65}, 110, 110}, { {59, 110, 145, 79}, 110, 110},
      { {74, 60, 142, 91}, 150, 60} },

    { { {18, 110, 144, 29}, 110, 110}, { {28, 110, 140, 46}, 110, 110},
      { {40, 110, 138, 60}, 110, 110}, { {56, 110, 135, 76}, 110, 110},
      { {72, 34, 135, 90}, 140, 34} },
      
    { { {18, 110, 125, 30}, 110, 110}, { {26, 110, 125, 43}, 110, 110},
      { {38, 110, 126, 58}, 110, 110}, { {55, 110, 126, 75}, 110, 110},
      { {71, 28, 127, 91}, 132, 28} },
      
    { { {21, 110, 104, 35}, 110, 110}, { {30, 110, 110, 48}, 110, 110},
      { {40, 110, 114, 60}, 110, 110}, { {56, 110, 116, 77}, 110, 110},
      { {73, 173, 116, 91}, 132, 23} },
      
    { { {26, 110, 87, 43}, 110, 110}, { {34, 110, 96, 55}, 110, 110},
      { {46, 110, 102, 67}, 110, 110}, { {60, 110, 107, 80}, 110, 110},
      { {80, 173, 109, 94}, 110, 110} },
};

//void set_servo_angles(uint8_t x, uint8_t y, uint8_t is_vertical) {
//    if (x < GRID_SIZE && y < GRID_SIZE) {
//        return is_vertical ? grid_angles[x][y].angle_v : grid_angles[x][y].angle_h;
//    }
//}

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
