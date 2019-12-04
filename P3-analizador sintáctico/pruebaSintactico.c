#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "y.tab.h"
FILE *yyin;
FILE *salida;
int error = 1;
int linea = 1;
int columna = 1;
bool longitud = false;
bool invalidchar = false;

int main (int argc, char **argv)
{
  if(argc!=3)
  {
    printf("\n ERROR PARAMETROS\n\t./pruebaMorfo ficheroentrada ficherosalida\n");
    return 0;
  }
  printf("Abriendo fichero de entrada\n" );
  yyin=fopen(argv[1],"r");
  if(yyin==NULL)
    {printf("\n ERROR ABRIR FICHERO ENTRADA\n");
    return 0;
    }
  printf("Abriendo fichero de salida\n" );
  salida=fopen(argv[2],"w");
  if(salida==NULL)
    {printf("\n ERROR ABRIR FICHERO SALIDA\n");
    fclose(yyin);
    return 0;
    }
  printf("Empezando analisis sintactico\n");
  if(yyparse()!=0){
    printf("\nERROR EN EL ANALISIS SINTACTICO\n");
  }

  else
    printf("\nANALISIS SINTACTICO TERMINADO CON EXITO\n");
  fclose(salida);
  fclose(yyin);
  return 0;
}
