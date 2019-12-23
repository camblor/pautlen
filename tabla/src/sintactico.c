#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../inc/tabla.h"
#include "../inc/alfa.h"
#include "../inc/y.tab.h"


FILE *yyin;
FILE *salida;
int error = 0;

int linea = 1;
int columna = 1;
bool longitud = false;
bool invalidchar = false;
dataItem** tablaGlobal;
dataItem** tablaLocal;
dataItem** tablaActual;
datainfo * infoActual;

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

  tablaGlobal = tablaInit();
  tablaLocal = tablaInit();
  tablaActual = tablaGlobal;
  
  
  yyparse();
  display(tablaGlobal);

  liberaTabla(tablaGlobal);
  if(tablaLocal != NULL){
    liberaTabla(tablaLocal);
  }
  

  fclose(salida);
  fclose(yyin);
  return 0;
}
