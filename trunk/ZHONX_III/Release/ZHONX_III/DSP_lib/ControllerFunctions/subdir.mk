################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_init_f32.c \
../ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_init_q15.c \
../ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_init_q31.c \
../ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_reset_f32.c \
../ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_reset_q15.c \
../ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_reset_q31.c \
../ZHONX_III/DSP_lib/ControllerFunctions/arm_sin_cos_f32.c \
../ZHONX_III/DSP_lib/ControllerFunctions/arm_sin_cos_q31.c 

OBJS += \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_init_f32.o \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_init_q15.o \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_init_q31.o \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_reset_f32.o \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_reset_q15.o \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_reset_q31.o \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_sin_cos_f32.o \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_sin_cos_q31.o 

C_DEPS += \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_init_f32.d \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_init_q15.d \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_init_q31.d \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_reset_f32.d \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_reset_q15.d \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_pid_reset_q31.d \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_sin_cos_f32.d \
./ZHONX_III/DSP_lib/ControllerFunctions/arm_sin_cos_q31.d 


# Each subdirectory must supply rules for building sources it contributes
ZHONX_III/DSP_lib/ControllerFunctions/%.o: ../ZHONX_III/DSP_lib/ControllerFunctions/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -D__weak=__attribute__((weak)) -DARM_MATH_CM4 -D__packed=__attribute__((__packed__)) -DUSE_HAL_DRIVER -DSTM32F405xx -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Enslavements\Straight_Controls" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Peripherals\Gyroscope" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Enslavements\PID" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Peripherals\Display\inc" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Drivers\CMSIS\Device\ST\STM32F4xx\Include" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Peripherals\Encoders" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Peripherals\Telemeters" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Peripherals\TimeBase" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Peripherals\Tests" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Peripherals\Expander" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Drivers\CMSIS\Include" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Drivers\STM32F4xx_HAL_Driver\Inc" -I"C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Inc" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


