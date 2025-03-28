/* 
 * File:   grid_lookup.C
 * Author: aevern
 * 
 * Created on March 24, 2025, 11:59 PM
 */

#include "grid_lookup.h"

const GridPosition grid_angles[GRID_SIZE][GRID_SIZE] = {
    { { {82, 110, 140, 98}, 50, 50 }, { {85, 110, 140, 100}, 50, 50 },
      { {85, 110, 140, 100}, 50,50 }, { {85, 110, 140, 100}, 50, 50 },
      { {85, 173, 107, 90}, 50, 50 } },

    { { {88, 48, 33, 63}, 38, 43 }, { {83, 53, 38, 58}, 43, 48 },
      { {78, 58, 43, 53}, 48, 53 }, { {73, 63, 48, 48}, 53, 58 },
      { {68, 68, 53, 43}, 58, 63 } }
    // Add rows 2, 3, and 4...
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