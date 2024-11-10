################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Pwm/pwm.c 

OBJS += \
./Drivers/Pwm/pwm.o 

C_DEPS += \
./Drivers/Pwm/pwm.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Pwm/%.o Drivers/Pwm/%.su Drivers/Pwm/%.cyclo: ../Drivers/Pwm/%.c Drivers/Pwm/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/ThreadSafe -I../Drivers/Drv8833 -I../Drivers/Logger -I../Drivers/Mpu6500 -I../Drivers/Pwm -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Pwm

clean-Drivers-2f-Pwm:
	-$(RM) ./Drivers/Pwm/pwm.cyclo ./Drivers/Pwm/pwm.d ./Drivers/Pwm/pwm.o ./Drivers/Pwm/pwm.su

.PHONY: clean-Drivers-2f-Pwm

