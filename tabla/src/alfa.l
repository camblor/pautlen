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
main {
    columna+=yyleng; 
    strcpy(yylval.atributos.lexema, yytext); 
    return TOK_MAIN;
}
array {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    return TOK_ARRAY;
}
int {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    return TOK_INT;
}
boolean {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    return TOK_BOOLEAN;
}
scanf {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    return TOK_SCANF;
}
printf {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    return TOK_PRINTF;
}
if {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return TOK_IF;
}
else {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return TOK_ELSE;
}
while {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return TOK_WHILE;
}
";" {
    columna+=yyleng;
    /*strcpy(yylval.atributos.lexema, yytext);*/
    return yytext[0];
}
"," {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    /*fprintf(salida, ";D:\t%s\n", yytext);*/
    return yytext[0];
}
"{" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    return yytext[0];
}
"}" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    return yytext[0];
}
"[" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    return yytext[0];
}
"]" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    return yytext[0];
}
"(" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    return yytext[0];
}
")" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    return yytext[0];
}
"+" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return yytext[0];
}
"-" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return yytext[0];
}
"*" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    return yytext[0];
}
"/" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return yytext[0];
}
"||" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return TOK_OR;
}
"&&" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return TOK_AND;
}
"!" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return yytext[0];
}
"!=" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return TOK_DISTINTO;
}
"==" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return TOK_IGUAL;
}
"<=" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return TOK_MENORIGUAL;
}
">=" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return TOK_MAYORIGUAL;
}
"<" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return yytext[0];
}
">" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return yytext[0];
}
"=" {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    return yytext[0];
}
true {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return TOK_TRUE;
}
false {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return TOK_FALSE;
}
function {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return TOK_FUNCTION;
}
return {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    fprintf(salida, ";D:\t%s\n", yytext);
    return TOK_RETURN;
}
{LETRA}[{a-zA-Z0-9}]{0,99} {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema,yytext);
    return TOK_IDENTIFICADOR;
}
{NUMERO}{1,100} {
    columna+=yyleng;
    strcpy(yylval.atributos.lexema, yytext);
    yylval.atributos.valor_entero=atoi(yytext);
    return TOK_CONSTANTE_ENTERA;
}
\t {
    columna += 4;
}
" " {
    columna++;
}
\n 	{
    linea++;
    columna=1;
}
"//".*\n {
    linea ++;
    columna=1;
}
{LETRA}[{a-zA-Z0-9}]{100,}	{
    longitud=true;
    fprintf(stderr, "****Error en [lin %d, col %d]: identificador demasiado largo (%s)\n",linea,columna,yytext);
    error = 1;
    return TOK_ERROR;
}
. {
    invalidchar=true;
    fprintf(stderr, "****Error en [lin %d, col %d]: simbolo no permitido (%s)\n",linea,columna,yytext);
    error = 1;
    return TOK_ERROR;
}

%%
