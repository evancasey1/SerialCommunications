################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS := 


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../main.c \
../SWSerial.c


PREPROCESSING_SRCS +=  \
../software_delay.s


ASM_SRCS += 


OBJS +=  \
main.o \
software_delay.o \
SWSerial.o

OBJS_AS_ARGS +=  \
main.o \
software_delay.o \
SWSerial.o

C_DEPS +=  \
main.d \
software_delay.d \
SWSerial.d

C_DEPS_AS_ARGS +=  \
main.d \
software_delay.d \
SWSerial.d

OUTPUT_FILE_PATH +=Problem2.elf

OUTPUT_FILE_PATH_AS_ARGS +=Problem2.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+=  \
D:/Downloads/libEmSys.a

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler
./main.o: .././main.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=16000000  -I"D:\Program Files\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.209\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega2560 -B "D:\Program Files\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega2560" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	

./SWSerial.o: .././SWSerial.c
	@echo Building file: $<
	@echo Invoking: AVR/GNU C Compiler : 5.4.0
	$(QUOTE)D:\Program Files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -DDEBUG -DF_CPU=16000000  -I"D:\Program Files\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.209\include"  -O1 -ffunction-sections -fdata-sections -fpack-struct -fshort-enums -mrelax -g2 -Wall -mmcu=atmega2560 -B "D:\Program Files\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega2560" -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	




# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler
./software_delay.o: .././software_delay.s
	@echo Building file: $<
	@echo Invoking: AVR/GNU Assembler : 5.4.0
	$(QUOTE)D:\Program Files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -Wa,-gdwarf2 -x assembler-with-cpp -c -mmcu=atmega2560 -B "D:\Program Files\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega2560" -I "D:\Program Files\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.209\include"  -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -mrelax -Wa,-g   -o "$@" "$<" 
	@echo Finished building: $<
	





ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: AVR/GNU Linker : 5.4.0
	$(QUOTE)D:\Program Files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -Wl,-Map="Problem2.map" -Wl,--start-group -Wl,-lm -Wl,-lEmSys  -Wl,--end-group -Wl,-L"C:\Users\caseyem\Downloads" -Wl,-L"D:\Downloads"  -Wl,--gc-sections -mrelax -mmcu=atmega2560 -B "D:\Program Files\Atmel\Studio\7.0\Packs\atmel\ATmega_DFP\1.2.209\gcc\dev\atmega2560"  
	@echo Finished building target: $@
	"D:\Program Files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures  "Problem2.elf" "Problem2.hex"
	"D:\Program Files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -j .eeprom  --set-section-flags=.eeprom=alloc,load --change-section-lma .eeprom=0  --no-change-warnings -O ihex "Problem2.elf" "Problem2.eep" || exit 0
	"D:\Program Files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objdump.exe" -h -S "Problem2.elf" > "Problem2.lss"
	"D:\Program Files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-objcopy.exe" -O srec -R .eeprom -R .fuse -R .lock -R .signature -R .user_signatures "Problem2.elf" "Problem2.srec"
	"D:\Program Files\Atmel\Studio\7.0\toolchain\avr8\avr8-gnu-toolchain\bin\avr-size.exe" "Problem2.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "Problem2.elf" "Problem2.a" "Problem2.hex" "Problem2.lss" "Problem2.eep" "Problem2.map" "Problem2.srec" "Problem2.usersignatures"
	