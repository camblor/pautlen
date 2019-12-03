lex.yy.c: alfa.l
					flex alfa.l

alfa: alfa.c lex.yy.c
			gcc -o alfa lex.yy.c alfa.c

clean:
			 rm -r alfa lex.yy.c


run:
			@echo ">>>>>>Running alfa with files entrada1.txt and salida1.txt"
			./alfa entrada1.txt salida1.txt

all:
			flex alfa.l
			gcc -o alfa lex.yy.c alfa.c
