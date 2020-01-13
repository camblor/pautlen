# project name (generate executable with this name)
TARGET   = ejemplo7

CC       = gcc
# compiling flags here
CFLAGS   =  -I. -g

LINKER   = gcc
# linking flags here
LFLAGS   =  -I. -lm

# change these to proper directories where each file should be
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
INCDIR   = inc

rm       = rm -f

all: alfa

alfa:  y.tab.o lex.yy.o tabla.o generacion.o compilador.o
	 $(CC) $(CFLAGS) -o $@ $(OBJDIR)/compilador.o $(OBJDIR)/y.tab.o $(OBJDIR)/lex.yy.o $(OBJDIR)/tabla.o $(OBJDIR)/generacion.o

compilador.o: $(SRCDIR)/compilador.c y.tab.c
	$(CC) -c $(CFLAGS) $<
	mv $@ $(OBJDIR)

tabla.o: $(SRCDIR)/tabla.c
	$(CC) -c $(CFLAGS) $<
	mv $@ $(OBJDIR)

generacion.o: $(SRCDIR)/generacion.c
	$(CC) -c $(CFLAGS) $<
	mv $@ $(OBJDIR)

lex.yy.o: lex.yy.c y.tab.c
	$(CC) -c -lfl $(CFLAGS) $(SRCDIR)/$<
	mv $@ $(OBJDIR)

lex.yy.c: $(SRCDIR)/alfa.l
	flex $^
	mv $@ $(SRCDIR)

y.tab.o: y.tab.c
	$(CC) -c $(CFLAGS) $(SRCDIR)/$<
	mv $@ $(OBJDIR)

y.tab.c: $(SRCDIR)/alfa.y
	bison -d -y -v $^
	mv y.tab.c $(SRCDIR)
	mv y.tab.h $(INCDIR)
	mv y.output $(BINDIR)

exec:
	./alfa entrada.alfa output.asm

valgrind:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./alfa entrada.txt output

nasm:
	nasm -felf32 output.asm
	gcc -m32 -o salida output.o alfalib.o

.PHONY: clean
clean:
	@$(rm) $(OBJDIR)/*
	@$(rm) hola.txt alfa output.asm output.o salida
	@$(rm) $(SRCDIR)/y.tab.c 
	@$(rm) $(SRCDIR)/lex.yy.c
	@$(rm) $(BINDIR)/y.output
	@$(rm) $(INCDIR)/y.tab.h

	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"