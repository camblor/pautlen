########################################################
# $@: es lo que esta a la izq del ':'
# $<: es el 1º item en la lista de dependencias
# $^: es la lista de items en la lista de dependencias a la drcha ':'

CC=gcc
CFLAGS= -g
#######################################################
COMPRIMIR = *.c *.h *.I *.txt Makefile lib_afnd_64.a
FLEX = lex.yy.*
BISON = y.tab.*
PRUEBAS = 
SALIDAS = misalida_sin_1.txt misalida_sin_2.txt misalida_sin_3.txt
EJEC = pruebaSintactico
######################################################

all: pruebaSintactico misalida

pruebaSintactico: pruebaSintactico.o y.tab.o lex.yy.o
	 $(CC) $(CFLAGS) -o $@ $^

pruebaSintactico.o: pruebaSintactico.c y.tab.c
	$(CC) -c $(CFLAGS) $<

lex.yy.o: lex.yy.c y.tab.c
	$(CC) -c -lfl $(CFLAGS) $<

lex.yy.c: alfa.l
	flex $^

y.tab.o: y.tab.c
	$(CC) -c $(CFLAGS) $<

y.tab.c: alfa.y
	bison -d -y -v $^

misalida: $(SALIDAS) pruebaSintactico

misalida_sin_1.txt: pruebaSintactico
	./$^ $(PRUEBAS)entrada_sin_1.txt $(PRUEBAS)$@

misalida_sin_2.txt: pruebaSintactico
	./$^ $(PRUEBAS)entrada_sin_2.txt $(PRUEBAS)$@

misalida_sin_3.txt: pruebaSintactico
	./$^ $(PRUEBAS)entrada_sin_3.txt $(PRUEBAS)$@

.PHONY : clean
	clean:
			rm -rf *.o pruebaSintactico

clear:
		rm -rf *.o misalida_sin_1.txt misalida_sin_2.txt misalida_sin_3.txt pruebaSintactico

clean: clear
		rm -rf $(FLEX) $(BISON)

dist: $(COMPRIMIR)
	tar -czvf HerasMarcos_PastorOriana_morfo.tar $^
