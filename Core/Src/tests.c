#include "tests.h"

void testAccWithCircle(uint8_t speed_input, int16_t *AccData) {
  uint8_t speed = speed_input;
  int16_t dx = 20;  // this variable needs to be determined based on the range
                    // of the accelerometer
  mpu6500_get_acc(AccData);
  int16_t xdir_init = AccData[0];
  int16_t ydir_init = AccData[1];
  int16_t zdir_init = AccData[2];
  int counter = 0;
  while (counter < 10) {
    rotate_right(speed);
    while (1) {
      mpu6500_get_acc(AccData);
      if ((xdir_init - dx <= AccData[0]&&AccData[0] <= xdir_init + dx) &&
          (ydir_init - dx <= AccData[1]&&AccData[1] <= ydir_init + dx)) {
        break;
      }
    }
    rotate_left(speed);
    while (1) {
      mpu6500_get_acc(AccData);
      if ((xdir_init - dx <= AccData[0]&&AccData[0] <= xdir_init + dx) &&
          (ydir_init - dx <= AccData[1]&&AccData[1] <= ydir_init + dx)) {
        break;
      }
    }
    counter = counter + 1;
  }
  stop_micromouse();
}
void testGyroWithCircle(uint8_t speed_input, int16_t *GyroData) {
  uint8_t speed = speed_input;
  int16_t dx = 20;  // this variable needs to be determined based on the range
                    // of the gyroscope
  mpu6500_get_gyro(GyroData);
  int16_t xdir_init = GyroData[0];
  int16_t ydir_init = GyroData[1];
  int16_t zdir_init = GyroData[2];
  int counter = 0;
  while (counter < 10) {
    rotate_right(speed);
    while (1) {
      mpu6500_get_gyro(GyroData);
      if ((xdir_init - dx <= GyroData[0]&&GyroData[0] <= xdir_init + dx) &&
          (ydir_init - dx <= GyroData[1]&&GyroData[1] <= ydir_init + dx)) {
        break;
      }
    }
    rotate_left(speed);
    while (1) {
      mpu6500_get_gyro(GyroData);
      if ((xdir_init - dx <= GyroData[0]&&GyroData[0] <= xdir_init + dx) &&
          (ydir_init - dx <= GyroData[1]&&GyroData[1] <= ydir_init + dx)) {
        break;
      }
    }
    counter = counter + 1;
  }
  stop_micromouse();
}
void timedMoveInDir(uint8_t speed_input, int time, int dir) {
  // dir = 1 -> forwards
  // dir = -1 -> backwards
  uint8_t speed = speed_input;
  uint8_t step_delay = 5;

  if (dir > 0) {
    move_forward(speed);
  } else {
    move_backward(speed);
  }
  while (time > 0) {
    HAL_Delay(step_delay);
    time = time - 1;
  }
  stop_micromouse();
}

void MoveForwardsForNumSeconds(uint8_t speed_input, int time) {
  timedMoveInDir(speed_input, time, 1);
}
void MoveBackwardsForNumSeconds(uint8_t speed_input, int time) {
  timedMoveInDir(speed_input, time, -1);
}

void figureEightWithAcc(uint8_t speed_input, int16_t *AccData) {
  uint8_t speed = speed_input;
  mpu6500_get_acc(AccData);
  int16_t xdir_init = AccData[0];
  int16_t ydir_init = AccData[1];
  int16_t zdir_init = AccData[2];
  int16_t dx = 20;

  turn_left(speed);
  while (1) {
    mpu6500_get_acc(AccData);
    if ((xdir_init - dx <= AccData[0]&&AccData[0] <= xdir_init + dx) &&
        (ydir_init - dx <= AccData[1]&&AccData[1] <= ydir_init + dx)) {
      break;
    }
  }
  turn_right(speed);
  while (1) {
    mpu6500_get_acc(AccData);
    if ((xdir_init - dx <= AccData[0]&&AccData[0] <= xdir_init + dx) &&
        (ydir_init - dx <= AccData[1]&&AccData[1] <= ydir_init + dx)) {
      break;
    }
  }
  stop_micromouse();
}
void figureEightWithGyro(uint8_t speed_input, int16_t *GyroData) {
  uint8_t speed = speed_input;
  mpu6500_get_gyro(GyroData);
  int16_t xdir_init = GyroData[0];
  int16_t ydir_init = GyroData[1];
  int16_t zdir_init = GyroData[2];
  int16_t dx = 20;
  turn_left(speed);
  while (1) {
    mpu6500_get_gyro(GyroData);
    if ((xdir_init - dx <= GyroData[0]&&GyroData[0] <= xdir_init + dx) &&
        (ydir_init - dx <= GyroData[1]&&GyroData[1] <= ydir_init + dx)) {
      break;
    }
  }
  turn_right(speed);
  while (1) {
    mpu6500_get_gyro(GyroData);
    if ((xdir_init - dx <= GyroData[0]&&GyroData[0] <= xdir_init + dx) &&
        (ydir_init - dx <= GyroData[1]&&GyroData[1] <= ydir_init + dx)) {
      break;
    }
  }
  stop_micromouse();
}
