################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Drv8833/drv8833.c 

OBJS += \
./Drivers/Drv8833/drv8833.o 

C_DEPS += \
./Drivers/Drv8833/drv8833.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Drv8833/%.o Drivers/Drv8833/%.su Drivers/Drv8833/%.cyclo: ../Drivers/Drv8833/%.c Drivers/Drv8833/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F405xx -DSTM32_THREAD_SAFE_STRATEGY=4 -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Core/ThreadSafe -I../Drivers/Drv8833 -I../Drivers/Logger -I../Drivers/Mpu6500 -I../Drivers/Pwm -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Drv8833

clean-Drivers-2f-Drv8833:
	-$(RM) ./Drivers/Drv8833/drv8833.cyclo ./Drivers/Drv8833/drv8833.d ./Drivers/Drv8833/drv8833.o ./Drivers/Drv8833/drv8833.su

.PHONY: clean-Drivers-2f-Drv8833

