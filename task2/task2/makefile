flame2: flame2.o util.o start.o
	ld -ggdb -melf_i386 start.o flame2.o util.o -o flame2
	
flame2.o: flame2.c util.o
	gcc -ggdb -m32 -Wall -ansi -c -nostdlib -fno-stack-protector flame2.c -o flame2.o

util.o:	util.c
	gcc -ggdb -m32 -Wall -ansi -c -nostdlib -fno-stack-protector util.c -o util.o

start.o: start.s
	nasm -ggdb -f elf start.s -o start.o
	
clean:
	rm flame2 *.o
