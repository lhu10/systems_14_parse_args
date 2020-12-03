all: main.o
	gcc -o work14 main.o

main.o: main.c
	gcc -c main.c

run: 
	./work14

clean: 
	rm *.o
