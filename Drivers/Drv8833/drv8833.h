#ifndef __DRV8833_H__
#define __DRV8833_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx.h"

typedef enum {
    MOTOR_L = 0,
    MOTOR_R,
    MAX_MOTORS
} MOTOR;

typedef enum {
    BACKWARD = 0,
    FORWARD,
    STOP,
    MAX_MOTION
} MOTION;

HAL_StatusTypeDef drv8833_init();

void set_duty_cycle(MOTOR motor, MOTION motion, uint8_t duty_cycle);

void stop_motors();
void move_forward(uint8_t speed);
void accelerate_forward(uint8_t final_speed, uint8_t step_delay);
void move_backward(uint8_t speed);
void turn_left(uint8_t speed);
void turn_right(uint8_t speed);
void rotate_right(uint8_t speed);
void rotate_left(uint8_t speed);
void stop_micromouse();
void decelerate_stop(uint8_t current_speed, uint8_t step_delay);

#ifdef __cplusplus
}
#endif

#endif
