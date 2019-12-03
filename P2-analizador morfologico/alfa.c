/****************************************************************
** Programa que recibe dos ficheros. El primero contiene el programa a analizar y en el segundo escribe el analisis.
** Muestra los errores por pantalla (stderr)
** Jorge Hernán y Alfonso Camblor
** Pareja 9, Grupo 1311
*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tokens.h"

extern int yylex();
extern FILE *yyin;
FILE * fout;
extern int yyleng;
extern char *yytext;
int linea = 1;
int columna = 1;
bool longitud = false;
bool invalidchar = false;
int main(int argc, char const *argv[]) {

  int ret;


  if (argc !=3){
    printf("Numero de argumentos invalido. Introducir fichero de entrada y fichero de salida\n");
    return -1;
  }
   yyin = fopen(argv[1], "r");
   if(!yyin){
     printf("Error al abrir el fichero de entrada\n");
     return -1;
   }

   fout = fopen(argv[2], "w");
   if(!fout){
     printf("Error al abrir el fichero de salida\n");
     return -1;
   }

  ret = yylex();

  while(ret!=0){
    switch (ret) {
      case 100:
        fprintf(fout, "Reconocido %d: main\n", TOK_MAIN);
        columna+= 4;
        break;

      case 101:
        fprintf(fout, "Reconocido %d: int\n", TOK_INT);
        columna+= 3;
        break;
      case 102:
        fprintf(fout, "Reconocido %d: boolean\n", TOK_BOOLEAN);
        columna+= 4;
        break;
      case 103:
        fprintf(fout, "Reconocido %d: array\n", TOK_ARRAY);
        columna+= 5;
        break;

      case 105:
        fprintf(fout, "Reconocido %d: if\n", TOK_IF);
        columna+=2;
        break;

      case 106:
        fprintf(fout, "Reconocido %d: else\n", TOK_ELSE);
        columna+=4;
        break;

      case 107:
        fprintf(fout, "Reconocido %d: while\n", TOK_WHILE);
        columna+=5;
        break;
      case 108:
        fprintf(fout, "Reconocido %d: scanf\n", TOK_SCANF);
        columna+=5;
        break;
      case 109:
        fprintf(fout, "Reconocido %d: printf\n", TOK_PRINTF);
        columna+=6;
        break;

      case 110:
        fprintf(fout, "Reconocido %d: return\n", TOK_RETURN);
        columna+=6;
        break;

      case 200:
        fprintf(fout, "Reconocido %d: puntoycoma\n", TOK_PUNTOYCOMA);
         columna+=1;
         break;

      case 201:
        fprintf(fout, "Reconocido %d: coma\n", TOK_COMA);
        columna+=1;
        break;

      case 202:
        fprintf(fout, "Reconocido %d: parentesisizquierdo\n", TOK_PARENTESISIZQUIERDO);
        columna+=1;
        break;

      case 203:
        fprintf(fout, "Reconocido %d: parentesisderecho\n", TOK_PARENTESISDERECHO);
        columna+=1;
        break;

      case 204:
        fprintf(fout, "Reconocido %d: corcheteizquierdo\n", TOK_CORCHETEIZQUIERDO);
        columna+=1;
        break;

      case 205:
        fprintf(fout, "Reconocido %d: corchetederecho\n", TOK_CORCHETEDERECHO);
        columna+=1;
        break;

      case 206:
        fprintf(fout, "Reconocido %d: llaveizquierda\n", TOK_LLAVEIZQUIERDA);
        columna+=1;
        break;

      case 207:
        fprintf(fout, "Reconocido %d: llavederecha\n", TOK_LLAVEDERECHA);
        columna+=1;
        break;

      case 208:
        fprintf(fout, "Reconocido %d: asignacion\n", TOK_ASIGNACION);
        columna+=1;
        break;

      case 209:
        fprintf(fout, "Reconocido %d: mas\n", TOK_MAS);
        columna+=1;
        break;

      case 210:
        fprintf(fout, "Reconocido %d: menos\n", TOK_MENOS);
        columna+=1;
        break;

      case 211:
        fprintf(fout, "Reconocido %d: division\n", TOK_DIVISION);
        columna+=1;
        break;

      case 212:
        fprintf(fout, "Reconocido %d: asterisco\n", TOK_ASTERISCO);
        columna+=1;
        break;

      case 213:
        fprintf(fout, "Reconocido %d: AND\n", TOK_AND);
        columna+=2;
        break;

      case 214:
        fprintf(fout, "Reconocido %d: OR\n", TOK_OR);
        columna+=2;
        break;
      case 215:
        fprintf(fout, "Reconocido %d: NOT\n", TOK_NOT);
        columna+=1;
        break;

      case 216:
        fprintf(fout, "Reconocido %d: igual\n", TOK_IGUAL);
        columna+=1;
        break;
      case 217:
        fprintf(fout, "Reconocido %d\n: distinto", TOK_DISTINTO);
        columna+=2;
        break;

      case 218:
        fprintf(fout, "Reconocido %d: menorigual\n", TOK_MENORIGUAL);
        columna+=1;
        break;

      case 219:
        fprintf(fout, "Reconocido %d: mayorigual\n", TOK_MAYORIGUAL);
        columna+=1;
        break;

      case 220:
        fprintf(fout, "Reconocido %d: menor\n", TOK_MENOR);
        columna+=1;
        break;

      case 221:
        fprintf(fout, "Reconocido %d: mayor\n", TOK_MAYOR);
        columna+=1;
        break;

      case 300:
        fprintf(fout, "Reconocido %d: identificador %s\n", TOK_IDENTIFICADOR, yytext);
        columna+=yyleng;
        break;

      case 400:
        fprintf(fout, "Reconocido %d: constante entera %s\n", TOK_CONSTANTE_ENTERA, yytext);
        columna+=yyleng;
        break;

      case 401:
        fprintf(fout, "Reconocido %d: TRUE\n", TOK_TRUE);
        columna+=4;
        break;

      case 402:
        fprintf(fout, "Reconocido %d: FALSE\n", TOK_FALSE);
        columna+=5;
        break;

      case -1:
        if (invalidchar){
          fprintf(stderr, "****Error en [lin %d, col %d]: simbolo no permitido (%s)\n", linea, columna, yytext);
          return -1;
        }

        else if (longitud){
          fprintf(stderr, "****Error en [lin %d, col %d]: identificador demasiado largo (%s)\n", linea, columna, yytext);
          return -1;
        }
        else
          break;
    }

    ret = yylex();
  }
  return 0;
}
