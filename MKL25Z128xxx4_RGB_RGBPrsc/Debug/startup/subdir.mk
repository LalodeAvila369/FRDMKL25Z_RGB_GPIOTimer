################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../startup/startup_mkl25z4.c 

OBJS += \
./startup/startup_mkl25z4.o 

C_DEPS += \
./startup/startup_mkl25z4.d 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -D__REDLIB__ -DCPU_MKL25Z128VLK4_cm0plus -DCPU_MKL25Z128VLK4 -DSDK_OS_BAREMETAL -DFSL_RTOS_BM -DSDK_DEBUGCONSOLE=0 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -I"C:\Users\eddea\Documents\MCUXpressoIDE_11.1.1_3241\workspace\MKL25Z128xxx4_RGB_RGBPrsc\board" -I"C:\Users\eddea\Documents\MCUXpressoIDE_11.1.1_3241\workspace\MKL25Z128xxx4_RGB_RGBPrsc\source" -I"C:\Users\eddea\Documents\MCUXpressoIDE_11.1.1_3241\workspace\MKL25Z128xxx4_RGB_RGBPrsc" -I"C:\Users\eddea\Documents\MCUXpressoIDE_11.1.1_3241\workspace\MKL25Z128xxx4_RGB_RGBPrsc\drivers" -I"C:\Users\eddea\Documents\MCUXpressoIDE_11.1.1_3241\workspace\MKL25Z128xxx4_RGB_RGBPrsc\CMSIS" -I"C:\Users\eddea\Documents\MCUXpressoIDE_11.1.1_3241\workspace\MKL25Z128xxx4_RGB_RGBPrsc\utilities" -I"C:\Users\eddea\Documents\MCUXpressoIDE_11.1.1_3241\workspace\MKL25Z128xxx4_RGB_RGBPrsc\startup" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m0plus -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


