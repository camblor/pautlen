#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../inc/alfa.h"
#include "../inc/y.tab.h"

FILE *yyin;
FILE *salida;
int error = 0;

int linea = 1;
int columna = 1;
bool longitud = false;
bool invalidchar = false;

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    printf("\n ERROR PARAMETROS\n\t./pruebaMorfo ficheroentrada ficherosalida\n");
    return 0;
  }

  yyin = fopen(argv[1], "r");
  if (yyin == NULL)
  {
    printf("\n ERROR ABRIR FICHERO ENTRADA\n");
    return 0;
  }
  salida = fopen(argv[2], "w");
  if (salida == NULL)
  {
    printf("\n ERROR ABRIR FICHERO SALIDA\n");
    fclose(yyin);
    return 0;
  }
  yyparse();

  fclose(salida);
  fclose(yyin);
  return 0;
}
