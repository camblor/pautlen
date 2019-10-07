main0:
	gcc -o ej main_0_generacion.c generacion.c generacion.h -lm
	./ej ej0.asm
	nasm -g -o ej0.o -f elf32 ej0.asm
	gcc -m32 -o ej0 ej0.o alfalib.o

main2:
	gcc -o ej main_2_generacion.c generacion.c generacion.h -lm
	./ej ej2.asm
	nasm -g -o ej2.o -f elf32 ej2.asm
	gcc -m32 -o ej2 ej2.o alfalib.o

main:
	gcc -o ej main_generacion.c generacion.c generacion.h -lm
	./ej ejmain.asm
	nasm -g -o ejmain.o -f elf32 ejmain.asm
	gcc -m32 -o ejmain ejmain.o alfalib.o

all: main0