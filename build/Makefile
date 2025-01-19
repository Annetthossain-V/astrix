# makefile to build the astrix x86 binary

CC = gcc
LD = g++
ASM = as
CXX = g++
RS = gccr

CFLAGS_D = -O0 -std=c23 -c -I../ -g -Wall -Wno-unused-variable
LDFLAGS = -static
CXXFLAGS_D = -O0 -c -g -std=c++23 -Wall -Wno-unused-variable

CFLAGS_R = -O2 -std=c23 -c -Werror -march=x86-64-v2 -msse4.2 -I../ -Wall -Wno-unused-variable
CXXFLAGS_R = -O2 -c -Werror -std=c++23 -march=x86-64-v2 -msse4.2 -Wall -Wno-unused-variable
SOURCE := $(wildcard ../src/source/*.c)
SOURCE_CXX := $(wildcard ../src/cxx/*.cxx)
AXXFILE := $(wildcard ../src/asm/*.S)
OBJFILE := $(patsubst ../src/source/%.c, %.o, $(wildcard ../src/source/*.c))
OBJFILE_ASM := $(patsubst ../src/asm/%.S, %.o, $(wildcard ../src/asm/*.S))
OBJFILE_CXX := $(patsubst ../src/cxx/%.cxx, %.o, $(wildcard ../src/cxx/*.cxx))


MAINC = ../src/main.c

OBJ_DIR = bin/

OUTFILE = astrix

build:
	$(CC) $(CFLAGS_D) $(SOURCE) $(MAINC)
	$(CXX)  $(AXXFILE) -c -O3
	$(CXX) $(SOURCE_CXX) $(CXXFLAGS_D)
	$(LD) $(LDFLAGS) $(OBJFILE) $(OBJFILE_ASM) $(OBJFILE_CXX) main.o -o $(OUTFILE) 
	mv $(OBJFILE) $(OBJFILE_ASM) $(OBJFILE_CXX) main.o $(OBJ_DIR)


release:
	$(CC) $(CFLAGS_R) $(MAINC) $(SOURCE)
	$(CXX) $(AXXFILE) -c -O3
	$(CXX) $(SOURCE_CXX) $(CXXFLAGS_R)
	$(LD) $(LDFLAGS) $(OBJFILE) $(OBJFILE_ASM) $(OBJFILE_CXX) main.o -o $(OUTFILE)
	mv $(OBJFILE) $(OBJFILE_ASM) $(OBJFILE_CXX) main.o $(OBJ_DIR)
	strip $(OUTFILE)

clean:
	rm $(OBJ_DIR)*
