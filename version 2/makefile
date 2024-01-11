
#Bowei Kou

#Makefile for lab 1-4.  You need to add you name to this file in the comments
# You will need to add a entry to create your zip file

#change the last dependency for each new lab
all:  tags headers lab3

#this entry has to change for lab 2 - 4
# NEVER compile .c files with this rule - it lacks needed compile time flags
# There is an entry below that turns .c files into .o files

lab3: lab3.o n2.o input.o bits.o output.o sim.o memory.o callbacks.o Ai.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses -llinkedlist

#Prototype

p_memory: p_memory.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses -llinkedlist

p_color: p_color.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses -llinkedlist

p_XY: p_XY.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses -llinkedlist

p_data: p_data.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses -llinkedlist


#this is where you create an entry to build yuour zip file
#it will also update with new labs

lab3.zip: makefile *.c *.h n2.o libmidi.a liblinkedlist.a README_LAB3
	zip $@ $^
	rm -rf install
	mkdir install
	unzip $@ -d install
	make -C install -r p_memory
	make -C install -r p_color
	make -C install -r p_XY
	make -C install -r p_data
	make -C install lab3
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


