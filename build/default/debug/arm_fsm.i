# 1 "arm_fsm.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "/opt/microchip/xc8/v2.50/pic/include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "arm_fsm.c" 2







# 1 "./arm_fsm.h" 1
# 11 "./arm_fsm.h"
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
# 12 "./arm_fsm.h" 2
# 1 "/opt/microchip/xc8/v2.50/pic/include/c99/stdbool.h" 1 3
# 13 "./arm_fsm.h" 2


typedef enum {
    IDLE,
    ROTATE_DOCK,
    PICKUP,
    MAGNET_ON,
    MOVE_UP_DOCK,
    STILL,
    ROTATE_BOARD,
    BOAT_ROTATE,
    MOVE_UP_BOARD,
    PLACEMENT,
    MAGNET_OFF,
    WAIT,



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
void delay();
void start_fsm_delay();
# 9 "arm_fsm.c" 2
# 1 "./servo.h" 1
# 15 "./servo.h"
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
# 10 "arm_fsm.c" 2
# 1 "./boat_control.h" 1
# 17 "./boat_control.h"
typedef struct {
    uint8_t angles[4];
} DockingPosition;
# 28 "./boat_control.h"
extern const DockingPosition docking_positions[4];
extern const DockingPosition docking_up[4];





const uint8_t* get_docking_servo_angles(uint8_t boat_id);
const uint8_t* get_docking_servo_angles_up(uint8_t boat_id);
# 11 "arm_fsm.c" 2
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
# 12 "arm_fsm.c" 2



static ArmState current_state, next_state, previous_state = IDLE;
static ArmMode arm_mode = PLACE;
static uint8_t target_boat;
static uint8_t target_x, target_y;
static uint8_t target_orientation;
static volatile _Bool process_fsm = 0;
static volatile _Bool state_done = 1;
static volatile _Bool delay_done = 1;

void arm_fsm_init() {
    initServo();
    current_state = next_state = previous_state = IDLE;
    process_fsm = 0;
    state_done = 1;
    TMR0_OverflowCallbackRegister(delay);

}

void arm_set_target(uint8_t boat_id, uint8_t x, uint8_t y, uint8_t is_vertical, ArmMode mode) {
    if (current_state == IDLE) {
        target_boat = boat_id;
        target_x = x;
        target_y = y;
        target_orientation = is_vertical;
        arm_mode = mode;
        current_state = (mode == PLACE) ? ROTATE_DOCK : ROTATE_BOARD;
        process_fsm = 1;
    }
}

_Bool arm_is_busy() {
    return process_fsm;
}

void delay() {
    delay_done = 1;
    TMR0_Stop();
}

void start_fsm_delay(){
    delay_done = 0;


    TMR0_Start();
}


void arm_fsm_update() {
    if (!process_fsm || servoMovement()) return;

    switch (current_state) {

        case ROTATE_DOCK: {
            uint16_t moveup_angles[4] = {getAngle(0), getAngle(1), calculateAngle(get_docking_servo_angles(target_boat)[2]), getAngle(3)};
            move_servo_to_int(moveup_angles);
            switch(previous_state) {
                case STILL: {
                    next_state = (arm_mode == PLACE) ? RETURN : MOVE_UP_DOCK;
                    break;
                }

                default: {
                    next_state = PICKUP;
                    break;
                }
            }

            break;
        }


        case PICKUP: {
            const uint8_t* angles = get_docking_servo_angles(target_boat);
            move_servo_to_angles(angles);
            next_state = (arm_mode == PLACE) ? MAGNET_ON : MAGNET_OFF;
            break;
        }

        case MAGNET_ON: {
            enableMagnet();
            next_state = (arm_mode == PLACE) ? MOVE_UP_DOCK : MOVE_UP_BOARD;
            break;
        }

        case MOVE_UP_DOCK: {
            const uint8_t* angles = get_docking_servo_angles_up(target_boat);
            move_servo_to_angles(angles);


            switch(previous_state) {
                case MAGNET_ON: {
                    next_state = STILL;
                    break;
                }
                case ROTATE_DOCK: {
                    next_state = PICKUP;
                    break;
                }
                case WAIT: {
                    next_state = STILL;
                }
            }
            next_state = STILL;
            break;
        }

        case STILL: {
            uint16_t moveup_angles[4] = {calculateAngle(43), getAngle(1), getAngle(2), calculateAngle(45)};
            move_servo_to_int(moveup_angles);
            switch(previous_state) {
                case MOVE_UP_DOCK: {
                    next_state = (arm_mode == PLACE) ? ROTATE_BOARD : RETURN;
                    break;
                }
                case MOVE_UP_BOARD: {
                    next_state = ROTATE_DOCK;
                    break;
                }
            }

            break;

        }

        case ROTATE_BOARD: {
            uint16_t moveup_angles[4] = {getAngle(0), getAngle(1), calculateAngle(get_grid_servo_angles(target_x, target_y)[2]), getAngle(3)};
            move_servo_to_int(moveup_angles);
            next_state = BOAT_ROTATE;
            break;
        }

        case BOAT_ROTATE: {
            uint16_t angles[4] = {getAngle(0), calculateAngle(get_dependent_servo_angle(target_x, target_y, target_orientation)), getAngle(2), getAngle(3)};
            move_servo_to_int(angles);
            next_state = MOVE_UP_BOARD;
            break;
        }

        case MOVE_UP_BOARD: {
            uint8_t angles[4];
            get_adjusted_servo_angles_up(target_x, target_y, target_orientation, angles);
            move_servo_to_angles(angles);
            switch(previous_state) {
                case BOAT_ROTATE: {
                    next_state = PLACEMENT;
                    break;
                case WAIT: {
                    next_state = STILL;
                    break;
                    }
                case MAGNET_ON: {
                    next_state = STILL;
                    break;
                    }
                }
            }
            break;
        }

        case PLACEMENT: {
            uint8_t angles[4];
            get_adjusted_servo_angles(target_x, target_y, target_orientation, angles);
            move_servo_to_angles(angles);




            next_state = (arm_mode == PLACE) ? MAGNET_OFF : MAGNET_ON;



            break;
        }
# 199 "arm_fsm.c"
        case MAGNET_OFF: {
            disableMagnet();




            start_fsm_delay();
            next_state = WAIT;
            break;
        }

        case WAIT: {
            if (!delay_done) return;
            switch(previous_state) {
                case MAGNET_OFF: {
                    next_state = (arm_mode == PLACE) ? MOVE_UP_BOARD : MOVE_UP_DOCK;
                    break;
                }
            }

            break;
        }
# 237 "arm_fsm.c"
        case RETURN: {
            uint8_t idle_angles[4] = {43, 45, 25, 45};
            move_servo_to_angles(idle_angles);
            next_state = IDLE;
            process_fsm = 0;
            break;
            }

        case IDLE:
        default:
            break;
    }
    previous_state = current_state;
    current_state = next_state;
}
