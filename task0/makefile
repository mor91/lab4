task0: main.o
	gcc -o task0 main.o
	
main.o: main.c
	gcc -m32 -Wall -ansi -c -nostdlib -fno-stack-protector main.c -o 	 main.o

clean:
	rm split_line main.o
