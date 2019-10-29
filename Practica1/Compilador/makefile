ejemplo5:
	gcc -c ejemplo5.c generacion.c generacion.h
	gcc -o ejemplo5 ejemplo5.c generacion.c generacion.h -lm
	./ejemplo5 ejemplo5.asm
	nasm -g -o ejemplo5.o -f elf32 ejemplo5.asm
	gcc -m32 -o ejemplo5 ejemplo5.o alfalib.o

ejemplo6:
	gcc -c ejemplo6.c generacion.c generacion.h
	gcc -o ejemplo6 ejemplo6.c generacion.c generacion.h -lm
	./ejemplo6 ejemplo6.asm
	nasm -g -o ejemplo6.o -f elf32 ejemplo6.asm
	gcc -m32 -o ejemplo6 ejemplo6.o alfalib.o

debug5:
	nasm -g -o ejemplo5.o -f elf32 ejemplo5.asm
	gcc -m32 -o ejemplo5 ejemplo5.o alfalib.o

clean:
	rm -r ej0.asm ej0.o ejemplo5.asm ejemplo5 generacion.h.gch generacion.o ejemplo5.o
