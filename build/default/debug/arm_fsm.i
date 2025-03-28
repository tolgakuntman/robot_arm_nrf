# 1 "arm_fsm.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/Applications/microchip/xc8/v2.50/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "arm_fsm.c" 2







# 1 "./arm_fsm.h" 1
# 11 "./arm_fsm.h"
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
# 12 "./arm_fsm.h" 2
# 1 "/Applications/microchip/xc8/v2.50/pic/include/c99/stdbool.h" 1 3
# 13 "./arm_fsm.h" 2

typedef enum {
    IDLE,
    PICKUP,
    MAGNET_ON,
    MIDDLE1,
    MIDDLE2,
    BOAT_ROTATE,
    PLACEMENT,
    MAGNET_OFF,
    MIDDLE3,
    RETURN
} ArmState;

typedef enum {
    PLACE,
    REMOVE
} ArmMode;

void arm_fsm_init();
void arm_fsm_update();
void arm_set_target(uint8_t boat_id, uint8_t x, uint8_t y, uint8_t is_vertical, ArmMode mode);
_Bool arm_is_busy();
# 9 "arm_fsm.c" 2
# 1 "./servo.h" 1
# 15 "./servo.h"
# 1 "./mcc_generated_files/timer/tmr0.h" 1
# 40 "./mcc_generated_files/timer/tmr0.h"
# 1 "./mcc_generated_files/timer/tmr0_deprecated.h" 1
# 40 "./mcc_generated_files/timer/tmr0.h" 2
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
_Bool servoMovement();
# 10 "arm_fsm.c" 2
# 1 "./boat_control.h" 1
# 17 "./boat_control.h"
typedef struct {
    uint8_t angles[4];
} DockingPosition;

typedef struct {
    uint8_t x;
    uint8_t y;
    uint8_t is_vertical;
    uint8_t is_docked;
} BoatState;

extern const DockingPosition docking_positions[4];
extern BoatState boats[4];

void init_boats();
void move_boat(uint8_t boat_id, uint8_t x, uint8_t y, uint8_t is_vertical);
void return_boat_to_dock(uint8_t boat_id);
const uint8_t* get_docking_servo_angles(uint8_t boat_id);
# 11 "arm_fsm.c" 2

static ArmState current_state, next_state = IDLE;
static ArmMode arm_mode = PLACE;
static uint8_t target_boat;
static uint8_t target_x, target_y;
static uint8_t target_orientation;
static volatile _Bool process_fsm = 0;
static volatile _Bool state_done = 1;

void arm_fsm_init() {
    current_state = next_state = IDLE;
    process_fsm = 0;
    state_done = 1;
    init_boats();
}

void arm_set_target(uint8_t boat_id, uint8_t x, uint8_t y, uint8_t is_vertical, ArmMode mode) {
    if (current_state == IDLE) {
        target_boat = boat_id;
        target_x = x;
        target_y = y;
        target_orientation = is_vertical;
        arm_mode = mode;
        current_state = (mode == PLACE) ? PICKUP : MIDDLE3;
        process_fsm = 1;
    }
}

_Bool arm_is_busy() {
    return process_fsm;
}

void arm_fsm_update() {
    if (!process_fsm || servoMovement()) return;

    switch (current_state) {
        case PICKUP: {
            const uint8_t* angles = get_docking_servo_angles(target_boat);
            move_servo_to_angles(angles);
            next_state = (arm_mode == PLACE) ? MAGNET_ON : MAGNET_OFF;
            break;
        }

        case MAGNET_ON: {
            enableMagnet();
            next_state = (arm_mode == PLACE) ? MIDDLE1 : MIDDLE2;
            break;
        }

        case MIDDLE1:{
            uint8_t middle1_angles[4] = {43, 90, 25, 45};
            move_servo_to_angles(middle1_angles);
            next_state = (arm_mode == PLACE) ? MIDDLE2 : PICKUP;
            break;
        }

        case MIDDLE2: {
            uint8_t middle2_angles[4] = {43, 90, 115, 45};
            move_servo_to_angles(middle2_angles);
            next_state = (arm_mode == PLACE) ? PLACEMENT : MIDDLE1;
            break;
        }

        case BOAT_ROTATE: {

            break;
        }

        case PLACEMENT: {
            move_boat(target_boat, target_x, target_y, target_orientation);
            next_state = (arm_mode == PLACE) ? MAGNET_OFF : MAGNET_ON;
            break;
        }

        case MAGNET_OFF: {
            disableMagnet();
            if (arm_mode == REMOVE) {
                return_boat_to_dock(target_boat);
            }
            next_state = (arm_mode == PLACE) ? MIDDLE3 : RETURN;
            break;
        }

        case MIDDLE3: {
            uint8_t middle2_angles[4] = {43, 90, 115, 45};
            move_servo_to_angles(middle2_angles);
            next_state = (arm_mode == PLACE) ? RETURN : PLACEMENT;
            break;
        }

        case RETURN: {
            uint8_t idle_angles[4] = {43, 90, 25, 45};
            move_servo_to_angles(idle_angles);
            next_state = IDLE;
            process_fsm = 0;
            break;
            }

        case IDLE:
        default:
            break;
    }

    current_state = next_state;
}
