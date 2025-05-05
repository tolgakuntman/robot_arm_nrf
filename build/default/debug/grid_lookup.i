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
    { { {20, 68, 161, 40}, 68, 68}, { {31, 62, 153, 56}, 162, 62},
      { {43, 55, 150, 69}, 152, 59}, { {59, 51, 148, 85}, 150, 51},
      { {76, 49, 144, 97}, 147, 49} },

    { { {19, 52, 147, 32}, 54, 54}, { {28, 49, 143, 50}, 147, 50},
      { {38, 44, 139, 67}, 145, 44}, { {55, 40, 139, 79}, 141, 40},
      { {73, 40, 136, 97}, 140, 40} },

    { { {12, 32, 128, 26}, 32, 32}, { {31, 34, 126, 52}, 134, 34},
      { {43, 33, 128, 67}, 131, 33}, { {56, 30, 129, 82}, 133, 30},
      { {71, 28, 129, 97}, 132, 28} },

    { { {15, 15, 114, 35}, 19, 19}, { {30, 16, 113, 56}, 115, 16},
      { {43, 21, 117, 70}, 118, 21}, { {59, 23, 119, 86}, 120, 23},
      { {76, 23, 119, 98}, 122, 23} },

    { { {21, 9, 95, 44}, 105, 8}, { {39, 106, 101, 63}, 106, 106},
      { {52, 106, 105, 77}, 106, 106}, { {66, 111, 110, 88}, 111, 111},
      { {80, 111, 111, 101}, 111, 111} },
};

const GridPosition grid_angles_up[5][5] = {
    { { {35, 68, 161, 30}, 68, 68}, { {45, 62, 153, 40}, 162, 62},
      { {60, 55, 150, 60}, 152, 59}, { {70, 51, 148, 70}, 150, 51},
      { {95, 49, 144, 85}, 147, 49} },

    { { {35, 52, 147, 25}, 54, 54}, { {45, 49, 143, 40}, 147, 50},
      { {50, 110, 139, 50}, 145, 44}, { {70, 110, 139, 70}, 141, 40},
      { {90, 34, 136, 85}, 140, 40} },

    { { {30, 110, 128, 20}, 32, 32}, { {45, 110, 126, 40}, 134, 34},
      { {55, 110, 128, 50}, 131, 33}, { {70, 110, 129, 70}, 133, 30},
      { {85, 28, 129, 80}, 132, 28} },

    { { {35, 110, 114, 30}, 19, 19}, { {55, 110, 113, 50}, 115, 16},
      { {50, 110, 117, 50}, 118, 21}, { {70, 110, 119, 70}, 125, 23},
      { {85, 173, 119, 80}, 122, 23} },

    { { {40, 110, 95, 35}, 105, 8}, { {55, 110, 101, 55}, 106, 106},
      { {59, 110, 105, 61}, 106, 106}, { {75, 110, 110, 75}, 111, 111},
      { {95, 173, 111, 90}, 111, 111} },
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
