patch: patch.o util.o 
	ld -melf_i386 patch.o util.o -o patch.o
	
patch.o: patch.c 
	gcc -m32 -Wall -ansi -c -nostdlib -fno-stack-protector patch.c -o patch.o

util.o:	util.c
	gcc -m32 -Wall -ansi -c -nostdlib -fno-stack-protector util.c -o util.o

	
clean:
	rm patch *.o
