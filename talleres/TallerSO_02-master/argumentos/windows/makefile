.phony: clean

all: saludo argumentos manejo_argumentos

saludo: saludo.o
	gcc -o saludo saludo.o

saludo.o: saludo.c
	gcc -c saludo.c

clean:
	rm -f saludo argumentos manejo_argumentos
	rm -f *.o
