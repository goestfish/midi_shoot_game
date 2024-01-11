
#Bowei Kou

all:  tags headers lab3

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



tags: *.c
	ctags -R .


headers: *.c tags
	headers.sh


%.o:%.c *.h
	gcc -std=c99 -pedantic -Wformat -Wreturn-type -g -c $< -o $@


