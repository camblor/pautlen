%{
#include <stdio.h> /*para poder utilizar funiones de C (printf)*/
#include <stdlib.h>
#include <stdbool.h> /*para booleanos*/
#include "tokens.h" /*donde estan almacenadas las claves*/
#include "y.tab.h"

extern int linea;
extern int columna;
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
main {columna+=yyleng; return TOK_MAIN; }
array {columna+=yyleng; return TOK_ARRAY; }
int {columna+=yyleng; return TOK_INT; }
bool {columna+=yyleng; return TOK_BOOLEAN; }
scanf {columna+=yyleng; return TOK_SCANF; }
printf {columna+=yyleng; return TOK_PRINTF; }
if {columna+=yyleng; return TOK_IF; }
else {columna+=yyleng; return TOK_ELSE; }
while {columna+=yyleng; return TOK_WHILE; }
";" {columna+=yyleng; return yytext[0]; }
"," {columna+=yyleng; return yytext[0]; }
"{" {columna+=yyleng; return yytext[0]; }
"}" {columna+=yyleng; return yytext[0]; }
"[" {columna+=yyleng; return yytexy[0];}
"]" {columna+=yyleng; return yytext[0]; }
"(" {columna+=yyleng; return yytext[0]; }
")" {columna+=yyleng; return yytext[0]; }
"+" {columna+=yyleng; return yytext[0]; }
"-" {columna+=yyleng; return yytext[0]; }
"*" {columna+=yyleng; return yytext[0]; }
"/" {columna+=yyleng; return yytext[0]; }
"||" {columna+=yyleng; return TOK_OR; }
"&&" {columna+=yyleng; return TOK_AND; }
"!" {columna+=yyleng; return yytext[0]; }
"!=" {columna+=yyleng; return TOK_DISTINTO;}
"==" {columna+=yyleng; return TOK_IGUAL; }
"<=" {columna+=yyleng; return TOK_MENORIGUAL; }
">=" {columna+=yyleng; return TOK_MAYORIGUAL; }
"<" {columna+=yyleng; return yytext[0]; }
">" {columna+=yyleng; return yytext[0]; }
"=" {columna+=yyleng; return yytext[0]; }
true {columna+=yyleng; return TOK_TRUE; }
false {columna+=yyleng; return TOK_FALSE; }
function {columna+=yyleng; return TOK_FUNCTION;}
return {columna+=yyleng; return TOK_RETURN; }
{LETRA}[{a-zA-Z0-9}]{0,99} 	{columna+=yyleng; return TOK_IDENTIFICADOR;}
{NUMERO}{1,100} 					{columna+=yyleng; return TOK_CONSTANTE_ENTERA;}
\t {columna += 4;}
" " {columna++;}
\n 	{linea++; columna=1;}
"//".*\n {linea ++;columna=1;}
{LETRA}[{a-zA-Z0-9}]{100,}	 	{longitud=true; return TOK_ERROR;}
. {invalidchar=true; return TOK_ERROR;}
%%
