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
OBJFILE := $(patsubst ../src/source/%.c, %.o, $(wildcard ../src/source/*.c))
OBJFILE_ASM := $(patsubst ../src/asm/%.S, %.o, $(wildcard ../src/asm/*.S))
OBJFILE_S := crit.o


MAINC = ../src/main.c

OBJ_DIR = bin/

OUTFILE = astrix

build:
	$(CC) $(CFLAGS_D) $(SOURCE) $(MAINC)
	$(ASM) ../src/asm/crit.s -o crit.o
	$(LD) $(LDFLAGS) $(OBJFILE) $(OBJFILE_ASM) $(OBJFILE_S) -o $(OUTFILE) 
	mv $(OBJFILE) $(OBJ_DIR)


release:
	$(CC) $(CFLAGS_R) $(MAINC) $(SOURCE)
	$(ASM) ../src/asm/crit.s -o crit.o
	$(LD) $(LDFLAGS) $(OBJFILE) $(OBJFILE_ASM) $(OBJFILE_S) -o $(OUTFILE)
	mv $(OBJFILE) $(OBJ_DIR)
	strip $(OUTFILE)

clean:
	rm $(OBJ_DIR)*
