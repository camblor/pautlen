#include <stdio.h>
#include <stdbool.h>
#include "tokens.h"

extern int yylex();
extern FILE *yyin;
FILE * fout;
extern int yyleng;
extern char *yytext;
extern int linea, columna;
extern bool longitud, invalidchar;

int main(int argc, char const *argv[]) {

  int ret;


  if (argc !=3){
    printf("Numero de argumentos invalido. Introducir fichero de entrada y fichero de salida\n");
    return -1;
  }
  printf("%s\n", argv[1]);
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

  while(ret!=0 && ret != TOK_ERROR){
    printf("%d\n", ret);
    switch (ret) {
      case 100:
        fprintf(fout, "Reconocido %d: main\n", TOK_MAIN);
        break;

      case 101:
        fprintf(fout, "Reconocido %d: int\n", TOK_INT);
        break;
      case 102:
        fprintf(fout, "Reconocido %d: boolean\n", TOK_BOOLEAN);
        break;
      case 103:
        fprintf(fout, "Reconocido %d: array\n", TOK_ARRAY);
        break;

      case 105:
        fprintf(fout, "Reconocido %d: if\n", TOK_IF);
        break;

      case 106:
        fprintf(fout, "Reconocido %d: else\n", TOK_ELSE);
        break;

      case 107:
        fprintf(fout, "Reconocido %d: while\n", TOK_WHILE);
        break;
      case 108:
        fprintf(fout, "Reconocido %d: scanf\n", TOK_SCANF);
        break;
      case 109:
        fprintf(fout, "Reconocido %d: printf\n", TOK_PRINTF);
        break;

      case 110:
        fprintf(fout, "Reconocido %d: return\n", TOK_RETURN);
        break;
      case 200:
        fprintf(fout, "Reconocido %d: puntoycoma\n", TOK_PUNTOYCOMA);
         break;

      case 201:
        fprintf(fout, "Reconocido %d: coma\n", TOK_COMA);
        break;

      case 202:
        fprintf(fout, "Reconocido %d: parentesisizquierdo\n", TOK_PARENTESISIZQUIERDO);
        break;
      case 203:
        fprintf(fout, "Reconocido %d: parentesisderecho\n", TOK_PARENTESISDERECHO);
        break;
      case 204:
        fprintf(fout, "Reconocido %d: corcheteizquierdo\n", TOK_CORCHETEIZQUIERDO);
        break;
      case 205:
        fprintf(fout, "Reconocido %d: corchetederecho\n", TOK_CORCHETEDERECHO);
        break;
      case 206:
        fprintf(fout, "Reconocido %d: llaveizquierda\n", TOK_LLAVEIZQUIERDA);
        break;

      case 207:
        fprintf(fout, "Reconocido %d: llavederecha\n", TOK_LLAVEDERECHA);
        break;

      case 209:
        fprintf(fout, "Reconocido %d: mas\n", TOK_MAS);
        break;

      case 210:
        fprintf(fout, "Reconocido %d: menos\n", TOK_MENOS);
        break;

      case 212:
        fprintf(fout, "Reconocido %d: asterisco\n", TOK_ASTERISCO);
        break;

      case 216:
        fprintf(fout, "Reconocido %d: igual\n", TOK_IGUAL);
        break;

      case 218:
        fprintf(fout, "Reconocido %d: menorigual\n", TOK_MENORIGUAL);
        break;

      case 219:
        fprintf(fout, "Reconocido %d: mayorigual\n", TOK_MAYORIGUAL);
        break;

      case 220:
        fprintf(fout, "Reconocido %d: menor\n", TOK_MENOR);
        break;

      case 221:
        fprintf(fout, "Reconocido %d: mayor\n", TOK_MAYOR);

      case 300:
        fprintf(fout, "Reconocido %d: identificador %s\n", TOK_IDENTIFICADOR, yytext);
        break;

      case 400:
        fprintf(fout, "Reconocido %d: constante entera %s\n", TOK_CONSTANTE_ENTERA, yytext);
        break;
    }

    ret = yylex();
  }
  return 0;
}
