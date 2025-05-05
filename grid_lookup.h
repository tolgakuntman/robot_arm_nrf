/* 
 * File:   grid_lookup.h
 * Author: aevern
 *
 * Created on March 24, 2025, 11:59 PM
 */

#ifndef GRID_LOOKUP_H
#define	GRID_LOOKUP_H

#include <stdint.h>

#define NUM_SERVOS 4
//#define DEP_SERVO 2 // The servo affected by orientation
#define GRID_SIZE 5

typedef struct {
    uint8_t angles[NUM_SERVOS];  // Fixed angles for 4 servos
    uint8_t angle_h;             // Dependent servo (horizontal)
    uint8_t angle_v;             // Dependent servo (vertical)
} GridPosition;

extern const GridPosition grid_angles[GRID_SIZE][GRID_SIZE];
extern const GridPosition grid_angles_up[GRID_SIZE][GRID_SIZE];
extern uint8_t angles[NUM_SERVOS];

const uint8_t* get_grid_servo_angles(uint8_t x, uint8_t y);
uint8_t get_dependent_servo_angle(uint8_t x, uint8_t y, uint8_t is_vertical);
void get_adjusted_servo_angles(uint8_t x, uint8_t y, uint8_t is_vertical, uint8_t* out_angles);
void get_adjusted_servo_angles_up(uint8_t x, uint8_t y, uint8_t is_vertical, uint8_t* out_angles);

#endif	/* GRID_LOOKUP_H */

