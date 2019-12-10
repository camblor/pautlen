CC = gcc
CFLAGS = -g
OBJS = hash.o

all: prueba_tabla

prueba_tabla: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o prueba_tabla
	rm -f *.o

hash.o: hash/hash.c
	$(CC) $(CFLAGS) -c hash/hash.c

clean:
	rm -f *.o