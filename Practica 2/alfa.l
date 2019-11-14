%{
#include <stdio.h> /*para poder utilizar funiones de C (printf)*/
#include <stdlib.h>
#include <stdbool.h> /*para booleanos*/
#include "tokens.h" /*donde estan almacenadas las claves*/

extern int linea;
extern int columna;
extern bool invalidchar;
extern bool longitud;
%}

%option noyywrap


%%
main { return TOK_MAIN; }
array { return TOK_ARRAY; }
int { return TOK_INT; }
bool { return TOK_BOOLEAN; }
scanf { return TOK_SCANF; }
if { return TOK_IF; }
else { return TOK_ELSE; }
while { return TOK_WHILE; }
";" { return TOK_PUNTOYCOMA; }
"," { return TOK_COMA; }
"{" { return TOK_LLAVEIZQUIERDA; }
"}" {return TOK_LLAVEDERECHA; }
"[" {return TOK_CORCHETEIZQUIERDO;}
"]" { return TOK_CORCHETEDERECHO; }
"(" { return TOK_PARENTESISIZQUIERDO; }
")" { return TOK_PARENTESISDERECHO; }
"+" { return TOK_MAS; }
"-" { return TOK_MENOS; }
"*" { return TOK_ASTERISCO; }
"/" { return TOK_DIVISION; }
"||" { return TOK_OR; }
"&&" { return TOK_AND; }
"!" { return TOK_NOT; }
"!=" {return TOK_DISTINTO;}
"==" { return TOK_IGUAL; }
"<=" { return TOK_MENORIGUAL; }
">=" { return TOK_MAYORIGUAL; }
"<" { return TOK_MENOR; }
">" { return TOK_MAYOR; }
"=" { return TOK_ASIGNACION; }
true { return TOK_TRUE; }
false { return TOK_FALSE; }
[a-zA-Z][{a-zA-Z0-9}]{0,99} 	{return TOK_IDENTIFICADOR;}
[0-9]{1,100} 					{return TOK_CONSTANTE_ENTERA;}
\t {columna += 4;}
" " {columna++;}
\n 	{linea++; columna=1;}
"//".*\n {linea ++;columna=1;}
[a-zA-Z][{a-zA-Z0-9}]{100,}	 	{longitud=true; return TOK_ERROR;}
.								{invalidchar=true; return TOK_ERROR;}
%%
