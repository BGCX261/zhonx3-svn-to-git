################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include ZHONX_III/Src/subdir.mk
-include ZHONX_III/Peripherals/TimeBase/subdir.mk
-include ZHONX_III/Peripherals/Tests/subdir.mk
-include ZHONX_III/Peripherals/Telemeters/subdir.mk
-include ZHONX_III/Peripherals/Gyroscope/subdir.mk
-include ZHONX_III/Peripherals/Expander/subdir.mk
-include ZHONX_III/Peripherals/Encoders/subdir.mk
-include ZHONX_III/Peripherals/Display/src/subdir.mk
-include ZHONX_III/Enslavements/Straight_Controls/subdir.mk
-include ZHONX_III/Enslavements/PID/subdir.mk
-include ZHONX_III/Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include ZHONX_III/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc/subdir.mk
-include ZHONX_III/Drivers/CMSIS/Device/ST/STM32F4xx/Source/Templates/subdir.mk
-include ZHONX_III/DSP_lib/ControllerFunctions/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
ZHONX_III.bin \

SECONDARY_SIZE += \
ZHONX_III.siz \


# All Target
all: ZHONX_III.elf secondary-outputs

# Tool invocations
ZHONX_III.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross ARM C Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mlittle-endian -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O3 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wall -T "C:\Eclipse-ARM\workspace\ZHONX_III\ZHONX_III\Projects\TrueSTUDIO\ZHONX_III Configuration\STM32F405RG_FLASH.ld" -Xlinker --gc-sections -Wl,-Map,"ZHONX_III.map" -Wl,-cref,-u,Reset_Handler -o "ZHONX_III.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ZHONX_III.bin: ZHONX_III.elf
	@echo 'Invoking: Cross ARM GNU Create Flash Image'
	arm-none-eabi-objcopy -O binary "ZHONX_III.elf"  "ZHONX_III.bin"
	@echo 'Finished building: $@'
	@echo ' '

ZHONX_III.siz: ZHONX_III.elf
	@echo 'Invoking: Cross ARM GNU Print Size'
	arm-none-eabi-size --format=berkeley "ZHONX_III.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(SECONDARY_SIZE)$(OBJS)$(C_DEPS)$(ASM_DEPS)$(SECONDARY_FLASH)$(S_DEPS)$(S_UPPER_DEPS) ZHONX_III.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
