line_splitter: line_splitter.o util.o start.o
	ld -ggdb -melf_i386 start.o line_splitter.o util.o -o line_splitter
	
line_splitter.o: line_splitter.c util.o
	gcc -ggdb -m32 -Wall -ansi -c -nostdlib -fno-stack-protector line_splitter.c -o line_splitter.o

util.o:	util.c
	gcc -ggdb -m32 -Wall -ansi -c -nostdlib -fno-stack-protector util.c -o util.o

start.o: start.s
	nasm -ggdb -f elf start.s -o start.o
	
clean:
	rm line_splitter *.o
