# 1 "boat_control.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/opt/microchip/xc8/v2.50/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "boat_control.c" 2







# 1 "./boat_control.h" 1
# 11 "./boat_control.h"
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
# 12 "./boat_control.h" 2





typedef struct {
    uint8_t angles[4];
} DockingPosition;

extern const DockingPosition docking_positions[4];
extern const DockingPosition docking_up[4];

const uint8_t* get_docking_servo_angles(uint8_t boat_id);
const uint8_t* get_docking_servo_angles_up(uint8_t boat_id);
# 9 "boat_control.c" 2
# 1 "./grid_lookup.h" 1
# 17 "./grid_lookup.h"
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
# 10 "boat_control.c" 2
# 1 "./servo.h" 1
# 14 "./servo.h"
# 1 "/opt/microchip/xc8/v2.50/pic/include/c99/stdbool.h" 1 3
# 15 "./servo.h" 2
# 1 "./mcc_generated_files/timer/tmr0.h" 1
# 40 "./mcc_generated_files/timer/tmr0.h"
# 1 "./mcc_generated_files/timer/tmr0_deprecated.h" 1
# 41 "./mcc_generated_files/timer/tmr0.h" 2
# 169 "./mcc_generated_files/timer/tmr0.h"
void TMR0_Initialize(void);







void TMR0_Deinitialize(void);
# 186 "./mcc_generated_files/timer/tmr0.h"
void TMR0_Start(void);
# 195 "./mcc_generated_files/timer/tmr0.h"
void TMR0_Stop(void);
# 204 "./mcc_generated_files/timer/tmr0.h"
uint16_t TMR0_CounterGet(void);
# 213 "./mcc_generated_files/timer/tmr0.h"
void TMR0_CounterSet(uint16_t counterValue);
# 222 "./mcc_generated_files/timer/tmr0.h"
void TMR0_Reload(void);
# 231 "./mcc_generated_files/timer/tmr0.h"
void TMR0_PeriodSet(uint16_t periodCount);
# 240 "./mcc_generated_files/timer/tmr0.h"
uint16_t TMR0_PeriodGet(void);







uint16_t TMR0_MaxCountGet(void);







void TMR0_TMRInterruptEnable(void);







void TMR0_TMRInterruptDisable(void);







void TMR0_ISR(void);







void TMR0_OverflowCallbackRegister(void (* CallbackHandler)(void));
# 16 "./servo.h" 2

typedef struct {

    uint16_t currAngle;
    uint16_t nextAngle;
} servoMotor;
# 30 "./servo.h"
extern servoMotor servos[4];

void isrTim0();
void enableMagnet();
void disableMagnet();
uint16_t calculateAngle(uint8_t angleDeg);
void initServo();
void enablePWM();
void move_servo_to_angles(const uint8_t* angles);
void move_servo_to_int(const uint16_t* intAngles);
_Bool servoMovement();
uint16_t getAngle(uint8_t i);
# 11 "boat_control.c" 2


const DockingPosition docking_positions[4] = {
    { {21, 45, 41, 40} },
    { {38, 28, 23, 61} },
    { {55, 21, 15, 80} },
    { {54, 42, 32, 77} }
};

const DockingPosition docking_up[4] = {
    { {35, 45, 42, 38} },
    { {60, 28, 23, 53} },
    { {73, 21, 15, 75} },
    { {70, 42, 33, 70} }
};

const uint8_t* get_docking_servo_angles(uint8_t boat_id) {
    return docking_positions[boat_id].angles;
}

const uint8_t* get_docking_servo_angles_up(uint8_t boat_id) {
    return docking_up[boat_id].angles;
}
