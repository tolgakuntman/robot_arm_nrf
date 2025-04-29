# 1 "grid_lookup.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/opt/microchip/xc8/v2.50/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "grid_lookup.c" 2







# 1 "./grid_lookup.h" 1
# 11 "./grid_lookup.h"
# 1 "/opt/microchip/xc8/v2.50/pic/include/c99/stdint.h" 1 3



# 1 "/opt/microchip/xc8/v2.50/pic/include/c99/musl_xc8.h" 1 3
# 5 "/opt/microchip/xc8/v2.50/pic/include/c99/stdint.h" 2 3
# 26 "/opt/microchip/xc8/v2.50/pic/include/c99/stdint.h" 3
# 1 "/opt/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 1 3
# 133 "/opt/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef unsigned __int24 uintptr_t;
# 148 "/opt/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef __int24 intptr_t;
# 164 "/opt/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 194 "/opt/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 235 "/opt/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 27 "/opt/microchip/xc8/v2.50/pic/include/c99/stdint.h" 2 3

typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 148 "/opt/microchip/xc8/v2.50/pic/include/c99/stdint.h" 3
# 1 "/opt/microchip/xc8/v2.50/pic/include/c99/bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "/opt/microchip/xc8/v2.50/pic/include/c99/stdint.h" 2 3
# 12 "./grid_lookup.h" 2





typedef struct {
    uint8_t angles[4];
    uint8_t angle_h;
    uint8_t angle_v;
} GridPosition;

extern const GridPosition grid_angles[5][5];
extern const GridPosition grid_angles_up[5][5];
extern uint8_t angles[4];

const uint8_t* get_grid_servo_angles(uint8_t x, uint8_t y);
uint8_t get_dependent_servo_angle(uint8_t x, uint8_t y, uint8_t is_vertical);
void get_adjusted_servo_angles(uint8_t x, uint8_t y, uint8_t is_vertical, uint8_t* out_angles);
void get_adjusted_servo_angles_up(uint8_t x, uint8_t y, uint8_t is_vertical, uint8_t* out_angles);
# 9 "grid_lookup.c" 2

const GridPosition grid_angles[5][5] = {
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

const GridPosition grid_angles_up[5][5] = {
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
    if (x < 5 && y < 5) {
        return grid_angles[x][y].angles;
    }
}

uint8_t get_dependent_servo_angle(uint8_t x, uint8_t y, uint8_t is_vertical) {
    if (x < 5 && y < 5) {
        return is_vertical ? grid_angles[x][y].angle_v : grid_angles[x][y].angle_h;
    }
    return 0;
}

void get_adjusted_servo_angles(uint8_t x, uint8_t y, uint8_t is_vertical, uint8_t* out_angles) {
    for (int i = 0; i < 4; ++i) {
        out_angles[i] = grid_angles[x][y].angles[i];
    }

    out_angles[1] = is_vertical ? grid_angles[x][y].angle_v : grid_angles[x][y].angle_h;

}

void get_adjusted_servo_angles_up(uint8_t x, uint8_t y, uint8_t is_vertical, uint8_t* out_angles) {
    for (int i = 0; i < 4; ++i) {
        out_angles[i] = grid_angles_up[x][y].angles[i];
    }

    out_angles[1] = is_vertical ? grid_angles_up[x][y].angle_v : grid_angles_up[x][y].angle_h;

}
