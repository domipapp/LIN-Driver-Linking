################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include CMSIS/EFM32GG/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: temalabor_usart.axf

# Tool invocations
temalabor_usart.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m3 -mthumb -T "temalabor_usart.ld" -Xlinker --gc-sections -Xlinker -Map="temalabor_usart.map" --specs=nano.specs -o temalabor_usart.axf "./CMSIS/EFM32GG/startup_gcc_efm32gg.o" "./CMSIS/EFM32GG/system_efm32gg.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_system.o" "./emlib/em_usart.o" "./src/main.o" "./src/motor_vezerles.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: temalabor_usart.hex'
	arm-none-eabi-objcopy -O ihex "temalabor_usart.axf" "temalabor_usart.hex"
	@echo ' '

	@echo 'Building bin file: temalabor_usart.bin'
	arm-none-eabi-objcopy -O binary "temalabor_usart.axf" "temalabor_usart.bin"
	@echo ' '

	@echo 'Building s37 file: temalabor_usart.s37'
	arm-none-eabi-objcopy -O srec "temalabor_usart.axf" "temalabor_usart.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "temalabor_usart.axf" -A
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) temalabor_usart.axf
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
