#ifndef __TESTS
#define __TESTS

#include <stdint.h>
#include <stdio.h>

#include "drv8833.h"
#include "mpu6500.h"

// tests the gyro function's ability to acknowledge when mouse has turned a full
// circle
void testGyroWithCircle(uint8_t speed_input, int16_t *GyroData);

// tests the acc function's ability to acknowledge when mouse has turned a full
// circle
void testAccWithCircle(uint8_t speed_input, int16_t *AccData);

// moves the mouse in a certain direction for a certain amount of time
// either forwards or backwards, dir>0 for forwards, otherwise dir<=0 backwards
void timedMoveInDir(uint8_t speed_input, int time, int dir);

// uses the timedMoveInDir to move forwards as specified by the time
void MoveForwardsForNumSeconds(uint8_t speed_input, int time);

// uses the timedMoveInDir to move backwards as specified by the time
void MoveBackwardsForNumSeconds(uint8_t speed_input, int time);

// does a figure eight using the accelerometer
void figureEightWithAcc(uint8_t speed_input, int16_t *AccData);

// does a figure eight using the gyroscope
void figureEightWithGyro(uint8_t speed_input, int16_t *GyroData);

#endif
