
all:  tags headers lab2


lab2: lab2.o n2.o input.o bits.o output.o sim.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses

p_bits: p_bits.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses

p_sim: p_sim.o bits.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses

p_check: p_check.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses

p_radian: p_radian.o
	gcc -g -o $@ $^ -lm -L. -lmidi -lncurses



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


tags: *.c
	ctags -R .

headers: *.c tags
	headers.sh


	gcc -std=c99 -pedantic -Wformat -Wreturn-type -g -c $< -o $@


