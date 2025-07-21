################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/arm/Arm-GNU-Toolchain-arm-none-eabi/14.2-rel1/bin/arm-none-eabi-gcc-14.2.1.exe" -c -mcpu=cortex-m4 -march=armv7e-m -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DPART_TM4C123GH6PM -I"C:/Users/cleme/Documents/I2C_Peripheral_Sim" -I"C:/ti/TivaWare_C_Series-2.2.0.295" -I"C:/arm/Arm-GNU-Toolchain-arm-none-eabi/14.2-rel1/arm-none-eabi/include" -Og -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -Wall -specs="nosys.specs" -MMD -MP -MF"$(basename $(<F)).d" -MT"$(@)"  -v $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


