task2c: task2c.o util.o start.o
	ld -ggdb -melf_i386 start.o task2c.o util.o -o task2c
	
task2c.o: task2c.c util.o
	gcc -ggdb -m32 -Wall -ansi -c -nostdlib -fno-stack-protector task2c.c -o task2c.o

util.o:	util.c
	gcc -ggdb -m32 -Wall -ansi -c -nostdlib -fno-stack-protector util.c -o util.o

start.o: start.s
	nasm -ggdb -f elf start.s -o start.o
	
clean:
	rm task2c *.o
