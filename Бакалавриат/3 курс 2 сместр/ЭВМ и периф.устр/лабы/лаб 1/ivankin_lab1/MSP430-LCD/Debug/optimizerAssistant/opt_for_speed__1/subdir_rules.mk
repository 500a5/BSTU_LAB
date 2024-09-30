################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
RS485.obj: ../RS485.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/TI/ccsv5/tools/compiler/msp430_4.2.2/bin/cl430" -vmsp --abi=eabi -Ooff --opt_for_speed=1 --include_path="C:/TI/ccsv5/ccs_base/msp430/include" --include_path="C:/TI/ccsv5/tools/compiler/msp430_4.2.2/include" --advice:power=all -g --define=__MSP430F1611__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="RS485.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

TIMERA.obj: ../TIMERA.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/TI/ccsv5/tools/compiler/msp430_4.2.2/bin/cl430" -vmsp --abi=eabi -Ooff --opt_for_speed=1 --include_path="C:/TI/ccsv5/ccs_base/msp430/include" --include_path="C:/TI/ccsv5/tools/compiler/msp430_4.2.2/include" --advice:power=all -g --define=__MSP430F1611__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="TIMERA.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/TI/ccsv5/tools/compiler/msp430_4.2.2/bin/cl430" -vmsp --abi=eabi -Ooff --opt_for_speed=1 --include_path="C:/TI/ccsv5/ccs_base/msp430/include" --include_path="C:/TI/ccsv5/tools/compiler/msp430_4.2.2/include" --advice:power=all -g --define=__MSP430F1611__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

msp430_initialize_unused_interrrupt_vectors.obj: ../msp430_initialize_unused_interrrupt_vectors.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/TI/ccsv5/tools/compiler/msp430_4.2.2/bin/cl430" -vmsp --abi=eabi -Ooff --opt_for_speed=1 --include_path="C:/TI/ccsv5/ccs_base/msp430/include" --include_path="C:/TI/ccsv5/tools/compiler/msp430_4.2.2/include" --advice:power=all -g --define=__MSP430F1611__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="msp430_initialize_unused_interrrupt_vectors.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

sysfunc.obj: ../sysfunc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: MSP430 Compiler'
	"C:/TI/ccsv5/tools/compiler/msp430_4.2.2/bin/cl430" -vmsp --abi=eabi -Ooff --opt_for_speed=1 --include_path="C:/TI/ccsv5/ccs_base/msp430/include" --include_path="C:/TI/ccsv5/tools/compiler/msp430_4.2.2/include" --advice:power=all -g --define=__MSP430F1611__ --diag_warning=225 --display_error_number --diag_wrap=off --printf_support=minimal --preproc_with_compile --preproc_dependency="sysfunc.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


