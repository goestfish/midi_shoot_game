
#Author: Bowei Kou

#Makefile for lab 1-4.  You need to add you name to this file in the comments
# You will need to add a entry to create your zip file

#change the last dependency for each new lab
all:  tags headers lab2

#this entry has to change for lab 2 - 4
# NEVER compile .c files with this rule - it lacks needed compile time flags
# There is an entry below that turns .c files into .o files

lab2: lab2.o n2.o input.o bits.o output.o sim.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses

#Prototype

p_bits: p_bits.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses

p_sim: p_sim.o bits.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses

p_check: p_check.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses

p_radian: p_radian.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses


#include "n2.h"
#this is where you create an entry to build yuour zip file
#it will also update with new labs

#Make zip file.
lab2.zip: makefile *.c *.h README_LAB2
	zip $@ $^
	rm -rf install
	mkdir install
	unzip lab2.zip -d install
	cp n2.o install/
	cp libmidi.a install/
	make -C install -r lab2
	make -C install -r p_sim
	make -C install -r p_bits
	make -C install -r p_check
	make -C install -r p_radian
	rm -rf install

#this entry stays for C code labs
tags: *.c
	ctags -R .

# this entry stays for C code labs
headers: *.c tags
	headers.sh


# this entry takes care of C files depending on header files
# It has the flags for compiling the c code
# It you don't like makefiles, consider typing the following line a few
# thousand times this semester and reconsider.
# Be sure that this one doesn't get an inserted line break anywhere
%.o:%.c *.h
	gcc -std=c99 -pedantic -Wformat -Wreturn-type -g -c $< -o $@


