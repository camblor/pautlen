ejemplo6:
	gcc -c ejemplo6.c generacion.c generacion.h
	gcc -o ejemplo6 ejemplo6.c generacion.c generacion.h -lm
	./ejemplo6 ejemplo6.asm
	nasm -g -o ejemplo6.o -f elf32 ejemplo6.asm
	gcc -m32 -o ejemplo6 ejemplo6.o alfalib.o
clean:
	rm -r ej0.asm ej0.o ejemplo6.asm ejemplo6 generacion.h.gch generacion.o ejemplo6.o
