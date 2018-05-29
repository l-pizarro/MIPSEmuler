HEADERS = registro.h lectura_archivos.h programa.h

all: programa.c $(HEADERS)
	gcc -o laboratorio.out main.c programa.c lectura_archivos.c registro.c -Wall -lm -g

clean:
	-rm -f laboratorio.out
run:
	./laboratorio.out
