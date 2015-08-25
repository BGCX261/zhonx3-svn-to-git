################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ZHONX_III/libs/Encoders/Encoders.c 

OBJS += \
./ZHONX_III/libs/Encoders/Encoders.o 

C_DEPS += \
./ZHONX_III/libs/Encoders/Encoders.d 


# Each subdirectory must supply rules for building sources it contributes
ZHONX_III/libs/Encoders/%.o: ../ZHONX_III/libs/Encoders/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall  -g -D__weak=__attribute__((weak)) -D__packed=__attribute__((__packed__)) -DUSE_HAL_DRIVER -DSTM32F405xx -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Drivers\CMSIS\Device\ST\STM32F4xx\Include" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\libs\Encoders" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\libs\Telemeters" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\libs\TimeBase" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\libs\ADXRS620" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\libs\Tests" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\libs\Expander" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\libs\SSD1306\inc" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Drivers\CMSIS\Include" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Drivers\STM32F4xx_HAL_Driver\Inc" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


