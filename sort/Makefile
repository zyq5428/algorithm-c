OBJECT 	:= $(wildcard *.c)
TARGET	:= $(patsubst %.c, %.elf, $(wildcard *.c))

all: $(TARGET)


$(TARGET): %.elf:%.c
	gcc -g $< -o $@

