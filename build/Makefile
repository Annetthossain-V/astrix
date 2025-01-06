# makefile to build the astrix x86 binary

CC = gcc
LD = gcc
ASM = as
CXX = g++
RS = gccr
AXX = g++

CFLAGS_D = -O0 -std=c23 -c -Werror -I../src/header -g
LDFLAGS = -static

CFLAGS_R = -O2 -std=c23 -c -Werror -march=x86-64-v2 -msse4.2 -I../src/header


SOURCE := $(wildcard ../src/source/*.c)
AXXFILE := $(wildcard ../src/asm/*.S)
OBJFILE := $(wildcard ./*.o)

MAINC = ../src/main.c

OBJ_DIR = bin/

OUTFILE = astrix

build:
	$(CC) $(CFLAGS_D) $(MAINC) $(SOURCE)
	$(ASM) ../src/asm/crit.s -o crit.o
	$(LD) $(LDFLAGS) $(OBJFILE) -o $(OUTFILE)
	mv *.o $(OBJ_DIR)


release:
	$(CC) $(CFLAGS_R) $(MAINC) $(SOURCE)
	$(ASM) ../src/asm/crit.s -o crit.o
	$(LD) $(LDFLAGS) $(OBJFILE) -o $(OUTFILE)
	mv *.o $(OBJ_DIR)
	strip $(OUTFILE)

clean:
	rm $(OBJ_DIR)*
