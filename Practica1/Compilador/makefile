ejemplo5:
	gcc -c ejemplo5.c generacion.c generacion.h
	gcc -o ejemplo5 ejemplo5.c generacion.c generacion.h -lm
	./ejemplo5 ejemplo5.asm
	nasm -g -o ejemplo5.o -f elf32 ejemplo5.asm
	gcc -m32 -o ejemplo5 ejemplo5.o alfalib.o

ejemplo4:
	gcc -c ejemplo4.c generacion.c generacion.h
	gcc -o ejemplo4 ejemplo4.c generacion.c generacion.h -lm
	./ejemplo4 ejemplo4.asm
	nasm -g -o ejemplo4.o -f elf32 ejemplo4.asm
	gcc -m32 -o ejemplo4 ejemplo4.o alfalib.o

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
	rm -r ejemplo5.asm ejemplo5 generacion.h.gch generacion.o ejemplo5.o ejemplo4.asm ejemplo4 ejemplo4.o ejemplo6.asm ejemplo6 ejemplo6.o
