# 1 "grid_lookup.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/Applications/microchip/xc8/v2.50/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "grid_lookup.c" 2







# 1 "./grid_lookup.h" 1
# 11 "./grid_lookup.h"
# 1 "/Applications/microchip/xc8/v2.50/pic/include/c99/stdint.h" 1 3



# 1 "/Applications/microchip/xc8/v2.50/pic/include/c99/musl_xc8.h" 1 3
# 5 "/Applications/microchip/xc8/v2.50/pic/include/c99/stdint.h" 2 3
# 26 "/Applications/microchip/xc8/v2.50/pic/include/c99/stdint.h" 3
# 1 "/Applications/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 1 3
# 133 "/Applications/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef unsigned __int24 uintptr_t;
# 148 "/Applications/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef __int24 intptr_t;
# 164 "/Applications/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 194 "/Applications/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 235 "/Applications/microchip/xc8/v2.50/pic/include/c99/bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 27 "/Applications/microchip/xc8/v2.50/pic/include/c99/stdint.h" 2 3

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
# 148 "/Applications/microchip/xc8/v2.50/pic/include/c99/stdint.h" 3
# 1 "/Applications/microchip/xc8/v2.50/pic/include/c99/bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 149 "/Applications/microchip/xc8/v2.50/pic/include/c99/stdint.h" 2 3
# 12 "./grid_lookup.h" 2





typedef struct {
    uint8_t angles[4];
    uint8_t angle_h;
    uint8_t angle_v;
} GridPosition;

extern const GridPosition grid_angles[5][5];
extern uint8_t angles[4];

const uint8_t* get_grid_servo_angles(uint8_t x, uint8_t y);
uint8_t get_dependent_servo_angle(uint8_t x, uint8_t y, uint8_t is_vertical);
# 9 "grid_lookup.c" 2

const GridPosition grid_angles[5][5] = {
    { { {82, 110, 140, 98}, 50, 50 }, { {85, 110, 140, 100}, 50, 50 },
      { {85, 110, 140, 100}, 50,50 }, { {85, 110, 140, 100}, 50, 50 },
      { {85, 173, 107, 90}, 50, 50 } },

    { { {88, 48, 33, 63}, 38, 43 }, { {83, 53, 38, 58}, 43, 48 },
      { {78, 58, 43, 53}, 48, 53 }, { {73, 63, 48, 48}, 53, 58 },
      { {68, 68, 53, 43}, 58, 63 } }

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
