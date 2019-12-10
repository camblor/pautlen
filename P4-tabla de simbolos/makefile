CC = gcc
CFLAGS = -g -Wall -ansi -pedantic
OBJS = hash.o prueba_tabla.o

all: prueba_tabla

prueba_tabla: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o prueba_tabla
	rm -f *.o

prueba_tabla.o: prueba_tabla.o
	$(CC) $(CFLAGS) -c prueba_tabla.c

hash.o: hash/hash.c
	$(CC) $(CFLAGS) -c hash/hash.c

exec:
	./prueba_tabla

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all  ./prueba_tabla

clean:
	rm -f *.o