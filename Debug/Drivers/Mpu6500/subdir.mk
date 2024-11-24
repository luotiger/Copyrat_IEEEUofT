################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Mpu6500/mpu6500.c 

OBJS += \
./Drivers/Mpu6500/mpu6500.o 

C_DEPS += \
./Drivers/Mpu6500/mpu6500.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Mpu6500/%.o Drivers/Mpu6500/%.su Drivers/Mpu6500/%.cyclo: ../Drivers/Mpu6500/%.c Drivers/Mpu6500/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/ThreadSafe -I"C:/Users/aahan/STM32CubeIDE/workspace_1.16.1/Copyrat_IEEE/Drivers/Mpu6500" -I"C:/Users/aahan/STM32CubeIDE/workspace_1.16.1/Copyrat_IEEE/Drivers/Logger" -I"C:/Users/aahan/STM32CubeIDE/workspace_1.16.1/Copyrat_IEEE/Drivers/Pwm" -I"C:/Users/aahan/STM32CubeIDE/workspace_1.16.1/Copyrat_IEEE/Drivers/Drv8833" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Mpu6500

clean-Drivers-2f-Mpu6500:
	-$(RM) ./Drivers/Mpu6500/mpu6500.cyclo ./Drivers/Mpu6500/mpu6500.d ./Drivers/Mpu6500/mpu6500.o ./Drivers/Mpu6500/mpu6500.su

.PHONY: clean-Drivers-2f-Mpu6500

