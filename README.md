# Proyecto de Autómatas y Lenguajes

Prácticas de la asignatura Proyecto de Autómatas y Lenguajes - Ing.Informática - UAM 2019/2020

## Practica 1 - Compilador

Por el momento hemos creado un programa que transforma de C a ensamblador.

Ahora estamos trabajando en la tabla de simbolos y el analizador lexico (flex)


### Utilizacion

```bash
  	make
  	cd bin
	./ejemplo ejemplo.asm
	nasm -g -o ../obj/ejemplo7.o -f elf32 ejemplo7.asm
	gcc -m32 -o ejemplo7 ../obj/ejemplo7.o ../obj/alfalib.o
```

## Autores

Alfonso Camblor

Jorge Hernán
