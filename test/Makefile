# makefile to build the astrix x86 binary

CC = gcc
LD = gcc
ASM = as
CXX = g++
RS = gccr

CFLAGS = -O1 -std=c23 -c
LDFLAGS = -static

SOURCE := $(wildcard ../src/source/*.c)
OBJFILE := $(wildcard *.o)

MAINC = ../src/main.c

OBJ_DIR = bin/

OUTFILE = astrix

build:
	$(CC) $(CFLAGS) $(MAINC) $(SOURCE)
	$(ASM) ../src/asm/crit.s -o crit.o
	$(LD) $(LDFLAGS) $(OBJFILE) -o $(OUTFILE)
	mv $(OBJFILE) $(OBJ_DIR)
	#strip $(OUTFILE)

clean:
	rm $(OBJ_DIR)*
