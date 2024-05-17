# Имя программы и собранного бинарника
TARGET = k1946vm014

# каталог в который будет осуществляться сборка, что бы не засерать остальные каталоги
BUILD_DIR = build

#флаги для компилятора 
MCU = atmega8535
OPT = -Os
C_FLAGS = -mmcu=$(MCU) $(OPT) -Wall
DEFINES = \
-D__AVR_ATmega8535__ \
-DF_CPU=8000000UL

C_INCLUDES =  \
-I$(AVRGCC_LIBS) \
-Iinc

C_SOURCES = \
src/k1946vm014.c \
src/functions.c 

# параметры для AVRDUDE
DUDE_MCU = m8535
DUDE_BCLOCK = 16kHz

# служебные переменные
OBJ_FILES = $(C_SOURCES:.c=.o)
ASM_FILES = $(C_SOURCES:.c=.s)
OUT_OBJ = $(addprefix $(BUILD_DIR)/, $(notdir $(OBJ_FILES)))

# правила для сборки

all: $(TARGET).hex

$(TARGET).hex: $(TARGET).elf
	$(AVRGCC_BINS)avr-objcopy -j .text -j .data -O ihex $(BUILD_DIR)/$< $(BUILD_DIR)/$@

$(TARGET).elf: $(OBJ_FILES) $(ASM_FILES)
	mkdir -p $(BUILD_DIR)
	$(AVRGCC_BINS)avr-gcc $(C_FLAGS) $(DEFINES) $(OUT_OBJ) -o $(BUILD_DIR)/$@

%.o: %.c
	mkdir -p $(BUILD_DIR)
	echo $^
	$(AVRGCC_BINS)avr-gcc -c $(C_FLAGS) $(DEFINES) $(C_INCLUDES) $< -o $(BUILD_DIR)/$(@F)

%.s: %.c
	echo $^
	$(AVRGCC_BINS)avr-gcc -S -g3 $(C_FLAGS) $(DEFINES) $(C_INCLUDES) $< -o $(BUILD_DIR)/$(@F)

clean:
	rm -f $(BUILD_DIR)/*

prog: $(TARGET).hex
	avrdude -p $(DUDE_MCU) -B $(DUDE_BCLOCK) -c usbasp -P usb -U flash:w:$(BUILD_DIR)/$(TARGET).hex:i

read_eeprom:
	avrdude -p $(DUDE_MCU) -B $(DUDE_BCLOCK) -c usbasp -P usb -U eeprom:r:eeprom.hex:i

write_eeprom: eeprom.hex
	avrdude -p $(DUDE_MCU) -B $(DUDE_BCLOCK) -c usbasp -P usb -U eeprom:w:eeprom.hex