%{
#include <stdio.h> /*para poder utilizar funiones de C (printf)*/
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> /*para booleanos*/
#include "../inc/alfa.h"
#include "../inc/y.tab.h"



extern int linea;
extern int columna;
extern int error;
extern bool invalidchar;
extern bool longitud;
extern int yyleng;
extern char *yytext;
extern FILE * salida;

%}

%option noyywrap

NUMERO [0-9]
LETRA [a-zA-Z]

%%
main {columna+=yyleng;return TOK_MAIN;}
array {columna+=yyleng;return TOK_ARRAY;}
int {columna+=yyleng;return TOK_INT;}
boolean {columna+=yyleng;return TOK_BOOLEAN;}
scanf {columna+=yyleng;return TOK_SCANF;}
printf {columna+=yyleng;return TOK_PRINTF;}
if {columna+=yyleng;return TOK_IF;}
else {columna+=yyleng;return TOK_ELSE;}
while {columna+=yyleng;return TOK_WHILE;}
";" {columna+=yyleng;return TOK_PUNTOYCOMA;}
"," {columna+=yyleng;return TOK_COMA;}
"{" {columna+=yyleng;return TOK_LLAVEIZQUIERDA;}
"}" {columna+=yyleng;return TOK_LLAVEDERECHA;}
"[" {columna+=yyleng;return TOK_CORCHETEIZQUIERDO;}
"]" {columna+=yyleng;return TOK_CORCHETEDERECHO;}
"(" {columna+=yyleng;return TOK_PARENTESISIZQUIERDO;}
")" {columna+=yyleng;return TOK_PARENTESISDERECHO;}
"+" {columna+=yyleng;return TOK_MAS;}
"-" {columna+=yyleng;return TOK_MENOS;}
"*" {columna+=yyleng;return TOK_ASTERISCO;}
"/" {columna+=yyleng;return TOK_DIVISION;}
"||" {columna+=yyleng;return TOK_OR;}
"&&" {columna+=yyleng;return TOK_AND;}
"!" {columna+=yyleng;return TOK_NOT;}
"!=" {columna+=yyleng;return TOK_DISTINTO;}
"==" {columna+=yyleng;return TOK_IGUAL;}
"<=" {columna+=yyleng;return TOK_MENORIGUAL;}
">=" {columna+=yyleng;return TOK_MAYORIGUAL;}
"<" {columna+=yyleng;return TOK_MENOR;}
">" {columna+=yyleng;return TOK_MAYOR;}
"=" {columna+=yyleng;return TOK_ASIGNACION;}
true {columna+=yyleng;return TOK_TRUE;}
false {columna+=yyleng;return TOK_FALSE;}
function {columna+=yyleng;return TOK_FUNCTION;}
return {columna+=yyleng;return TOK_RETURN;}
{LETRA}[{a-zA-Z0-9}]{0,99} {columna+=yyleng;strcpy(yylval.atributos.lexema,yytext);return TOK_IDENTIFICADOR;}
{NUMERO}{1,100} {columna+=yyleng;strcpy(yylval.atributos.lexema, yytext);yylval.atributos.valor_entero=atoi(yytext);return TOK_CONSTANTE_ENTERA;}
\t {columna += 4;}
" " {columna++;}
\n 	{linea++;columna=1;}
"//".*\n {linea ++;columna=1;}
{LETRA}[{a-zA-Z0-9}]{100,}	{longitud=true;fprintf(stderr, "****Error en [lin %d, col %d]: identificador demasiado largo (%s)\n",linea,columna,yytext);error = 1;return TOK_ERROR;}
. {invalidchar=true;fprintf(stderr, "****Error en [lin %d, col %d]: simbolo no permitido (%s)\n",linea,columna,yytext);error = 1;return TOK_ERROR;}

%%
