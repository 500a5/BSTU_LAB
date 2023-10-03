################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/TI/ccsv6/tools/compiler/msp430_4.3.4

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./I2C.obj" \
"./keys.obj" \
"./lcd.obj" \
"./leds.obj" \
"./main.obj" \
"./msp430_initialize_unused_interrrupt_vectors.obj" \
"./sysfunc.obj" \
"./uart.obj" \
"../lnk_msp430f1611.cmd" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
MSP430-USB.out \

EXE_OUTPUTS__QUOTED += \
"MSP430-USB.out" \

BIN_OUTPUTS += \
MSP430-USB.hex \

BIN_OUTPUTS__QUOTED += \
"MSP430-USB.hex" \


# All Target
all: MSP430-USB.out

# Tool invocations
MSP430-USB.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: MSP430 Linker'
	"C:/TI/ccsv6/tools/compiler/msp430_4.3.4/bin/cl430" -vmsp --abi=eabi -Ooff --advice:power="all" -g --define=__MSP430F1611__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal -z -m"MSP430-USB.map" --heap_size=80 --stack_size=80 --use_hw_mpy=16 --cinit_hold_wdt=on -i"C:/TI/ccsv6/ccs_base/msp430/include" -i"C:/TI/ccsv6/tools/compiler/msp430_4.3.4/lib" -i"C:/TI/ccsv6/tools/compiler/msp430_4.3.4/include" --reread_libs --warn_sections --display_error_number --diag_wrap=off --xml_link_info="MSP430-USB_linkInfo.xml" --rom_model -o "MSP430-USB.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

MSP430-USB.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: MSP430 Hex Utility'
	"C:/TI/ccsv6/tools/compiler/msp430_4.3.4/bin/hex430" --memwidth=8 --romwidth=8 -o "MSP430-USB.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "I2C.pp" "keys.pp" "lcd.pp" "leds.pp" "main.pp" "msp430_initialize_unused_interrrupt_vectors.pp" "sysfunc.pp" "uart.pp" 
	-$(RM) "I2C.obj" "keys.obj" "lcd.obj" "leds.obj" "main.obj" "msp430_initialize_unused_interrrupt_vectors.obj" "sysfunc.obj" "uart.obj" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

