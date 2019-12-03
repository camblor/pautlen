%{
#include <stdio.h> /*para poder utilizar funiones de C (printf)*/
#include <stdlib.h>
#include <stdbool.h> /*para booleanos*/
#include "tokens.h" /*donde estan almacenadas las claves*/
%}

%union
 {
 char* cadena;
 int numero;
 }

%token <main> TOK_MAIN
%token <return> TOK_RETURN
%token <array> TOK_ARRAY
%token <int> TOK_INT
%token <bool> TOK_BOOLEAN
%token <scanf> TOK_SCANF
%token <printf> TOK_PRINTF
%token <if> TOK_IF
%token <else> TOK_ELSE
%token <while> TOK_WHILE
%token <"||"> TOK_OR
%token <"&&"> TOK_AND
%token <"!="> TOK_DISTINTO
%token <"=="> TOK_IGUAL
%token <"<="> TOK_MENORIGUAL
%token <">="> TOK_MAYORIGUAL
%token <function> TOK_FUNCTION
%token <true> TOK_TRUE
%token <false> TOK_FALSE
%token <letra> TOK_IDENTIFICADOR
%token <numero> TOK_CONSTANTE_ENTERA


%start programa

%%

programa:   TOK_MAIN '{'declaraciones funciones sentencias'}'
                      {
                        fprintf(salida, "R1:\t <programa> ::= MAIN {<declaraciones> <funciones> <sentencias>}")
                      }
                      ;

declaraciones: declaracion
                      {
                        fprintf(salida, "R2:\t <declaraciones> ::= declaracion"\n);
                      }
                      |declaracion declaraciones
                      {
                        fprintf(salida, "R3:\t <declaraciones> ::= <declaracion> <declaraciones>\n");
                      }
                      ;

declaracion: clase identificadores ';'
                      {
                        fprintf(salida, "R4:\t <declaracion> ::= <clase> <identificadores> ;\n");
                      }
                      ;

clase: clase_escalar
                      {
                        fprintf(salida, "R5:\t <clase> ::= <clase_escalar>\n");
                      }
                      |clase_vector
                      {
                        fprintf(salida, "R7:\t <clase> ::= <clase_vector>\n");
                      }
                      ;

clase_escalar: tipo
                    {
                      fprintf(salida, "R9:\t <clase_escalar> ::= <tipo>\n");
                    }
                    ;

tipo:  TOK_INT
                      {
                        fprintf(salida, "R10:\t <tipo> ::= INT\n");
                      }
                      | TOK_BOOLEAN
                      {
                        fprintf(salida, "R11:\t <tipo> ::= BOOLEAN\n");
                      }
                      ;

clase_vector: TOK_ARRAY tipo '['constante_entera']'
                      {
                        fprintf(salida, "R15:\t <clase_vector> ::= ARRAY <tipo> [<constante_entera>]\n");
                      }
                      ;

identificadores: identificador
                      {
                        fprintf(salida, "R18:\t <identificadores> ::= <identificador>\n");
                      }
                      | identificador ',' identificadores
                      {
                        fprintf(salida, "R19:\t <identificadores> ::= <identificador> , <identificadores>\n");
                      }
                      ;

funciones: funcion funciones
                      {
                        fprintf(salida, "R20\t <funciones> ::= <funcion> <funciones>\n");
                      }
                      ;

funcion: TOK_FUNCTION tipo identificador '(' parametros_funcion ')' '{'declaraciones_funcion sentencias '}'
                      {
                        fprintf(salida, "R22:\t <funciones> ::= FUNCTION (<parametros_funcion>) {<declaraciones_funcion> <sentencias>}\n");
                      }
                      ;

parametros_funcion: parametro_funcion resto_parametros_funcion
                      {
                        fprintf(salida, "R23:\t <parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
                      }
                      ;

resto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion
                      {
                        fprintf(salida, "R25:\t <resto_parametros_funcion> ::= ; <parametro_funcion> <resto_parametros_funcion>\n");
                      }
                      ;

parametro_funcion: tipo identificador
                      {
                        fprintf(salidam "R27:\t <parametro_funcion> ::= <tipo> <identificador>\n");
                      }
                      ;

declaraciones_funcion: declaraciones
                      {
                        fprintf(salida, "R28:\t <declaraciones_funcion> ::= <declaraciones>\n");
                      }
                      ;

sentencias: sentencia
                      {
                        fprintf(salida, "R30:\t <sentencias> ::= <sentencia>\n");
                      }
                      | sentencia sentencias
                      {
                        fprintf(salida, "R31:\t <sentencias> ::= <sentencia> <sentencias>\n");
                      }
                      ;

sentencia: sentencia_simple ';'
                      {
                        fprintf(salida, "R32:\t <sentencia> ::= <sentencia_simple> ;\n");
                      }
                      | bloque
                      {
                      fprintf(salida, "R33:\t <sentencia> ::= <bloque>\n");
                      }
                      ;

sentencia_simple: asignacion
                      {
                        fprintf(salida, "R34:\t <sentencia_simple> ::= <asignacion>\n");
                      }
                      | lectura
                      {
                        fprintf(salida, "R35:\t <sentencia_simple> ::= <lectura>\n");
                      }
                      | escritura
                      {
                        fprintf(salida, "R36:\t <sentencia_simple> ::= <escritura>\n");
                      }
                      | retorno_funcion
                      {
                        fprintf(salida, "R38:\t <sentencia_simple> ::= <retorno_funcion>\n");
                      }
                      ;

bloque: condicional
                      {
                        fprintf(salida, "R40:\t <bloque> ::= <condicional>\n");
                      }
                      | bucle
                      {
                        fprintf(salida, "R41:\t <bloque> ::= <bucle>\n");
                      }
                      ;

asignacion: identificador '=' exp
                      {
                        fprintf(salida, "R43:\t <asignacion> ::= <identificador> = <exp>\n");
                      }
                      | elemento_vector '=' exp
                      {
                        fprintf(salida, "R44:\t <asignacion> ::= <elemento_vector> = <exp>\n");
                      }
                      ;

elemento_vector: identificador '['exp']'
                      {
                        fprintf(salidam "R48:\t <elemento_vector> ::= <identificador> [<exp>]\n");
                      }
                      ;

condicional: TOK_IF '(' exp ')' '{' sentencias '}'
                      {
                        fprintf(salida, "R50:\t <condicional> ::= IF (<exp>) {<sentencias>}\n");
                      }
                      | TOK_IF '(' exp ')' '{' sentencias '}' TOK_ELSE '(' exp ')' '{' sentencias '}'
                      {
                        fprintf(salida, "R51:\t <condicional> ::= IF (<exp>) {<sentencias>} ELSE {<sentencias>}\n");
                      }
                      ;

bucle: TOK_WHILE '(' exp ')' '{'sentencias '}'
                      {
                        fprintf(salida, "R52:\t <bucle> ::= WHILE (<exp>) {<sentencias>}\n");
                      }
                      ;

lectura: TOK_SCANF identificador
                      {
                        fprintf(salida, "R54:\t <lectura> ::= SCANF <identificador>\n");
                      }
                      ;

escritura: TOK_PRINTF exp
                      {
                        fprintf(salida, "R56:\t <escritura> ::= PRINTF <exp>\n");
                      }
                      ;

retorno_funcion: TOK_RETURN exp
                      {
                        fprintf(salida,"R61:\t <retorno_funcion> ::= RETURN <exp>\n");
                      }
                      ;

exp: exp '+' exp
                      {
                        fprintf(salida, "R72:\t <exp> ::= <exp> + <exp>\n");
                      }
                      | exp '-' exp
                      {
                        fprintf(salida, "R73:\t <exp> ::= <exp> - <exp>\n");
                      }
                      | exp '/' exp
                      {
                        fprintf(salida, "R74:\t <exp> ::= <exp> / <exp>\n");
                      }
                      | exp '*' exp
                      {
                        fprintf(salida, "R75:\t <exp> ::= <exp> * <exp>\n");
                      }
                      | '-' exp
                      {
                        fprintf(salida, "R76:\t <exp> ::= - <exp>\n");
                      }
                      | exp TOK_AND exp
                      {
                        fprintf(salida, "R77:\t <exp> ::= <exp> && <exp>\n");
                      }
                      | exp TOK_OR exp
                      {
                        fprintf(salida, "R78:\t <exp> ::= <exp> || <exp>\n");
                      }
                      | '!'exp
                      {
                        fprintf(salida, "R79:\t <exp> ::= !<exp>\n");
                      }
                      | identificador
                      {
                        fprintf(salida, "R80:\t <exp> ::= <identificador>\n");
                      }
                      | constante
                      {
                        fprintf(salida, "R81:\t <exp> ::= <constante>\n");
                      }
                      | '('exp')'
                      {
                        fprintf(salida, "R82:\t <exp> ::= (<exp>)\n");
                      }
                      | '('comparacion')'
                      {
                        fprintf(salida, "R83:\t <exp> ::= (<comparacion>)\n");
                      }
                      | elemento_vector
                      {
                        fprintf(salida, "R85:\t <exp> ::= <elemento_vector>\n");
                      }
                      | identificador '('lista_expresiones')'
                      {
                        fprintf(salida, "R88:\t <exp> ::= <identificador> (<lista_expresiones>)\n");
                      }
                      ;

lista_expresiones: exp resto_lista_expresiones:
                      {
                        fprintf(salida, "R89:\t <lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");
                      }
                      ;

resto_lista_expresiones: ',' exp resto_lista_expresiones
                      {
                        fprintf(salida, "R91:\t <resto_lista_expresiones> ::= , <exp> <resto_lista_expresiones>"\n);
                      }
                      ;

comparacion: exp TOK_IGUAL exp
                      {
                        fprintf(salida, "R93:\t <comparacion> ::= <exp> == <exp>\n");
                      }
                      | exp TOK_DISTINTO exp
                      {
                        fprintf(salida, "R94:\t <comparacion> ::= <exp> != <exp>\n");
                      }
                      | exp "<=" exp
                      {
                        fprintf(salida, "R95:\t <comparacion> ::= <exp> <= <exp>\n");
                      }
                      | exp TOK_MAYORIGUAL exp
                      {
                        fprintf(salida, "R96:\t <comparacion> ::= <exp> => <exp>\n");
                      }
                      | exp '<' exp
                      {
                        fprintf(salida, "R97:\t <comparacion> ::= <exp> < <exp>\n");
                      }
                      | exp '>' exp
                      {
                        fprintf(salida, "R98:\t <comparacion> ::= <exp> > <exp>\n");
                      }
                      ;

constante: constante_logica
                      {
                        fprintf(salida, "R99:\t <constante> ::= <constante_logica>\n");
                      }
                      | constante_entera
                      {
                        fprintf(salida, "R100:\t <constante> ::= <constante_entera>\n");
                      }
                      ;

constante_logica: TOK_TRUE
                      {
                        fprintf(salida, "R102:\t <constante_logica> ::= true\n");
                      }
                      | TOK_FALSE
                      {
                        fprintf(salida, "R103:\t <constante_logica> ::= false\n");
                      }
                      ;

constante_entera: numero
                      {
                        fprintf(salida, "R104:\t <constante_entera> ::= TOK_CONSTANTE_ENTERA\n");
                      }
                      ;
numero:  digito
                      {
                        fprintf(salida, "R105:\t <numero> ::= TOK_CONSTANTE_ENTERA\n");
                      }
                      |numero digito
                      {
                        fprintf(salida, "R106:\t <numero> ::= TOK_CONSTANTE_ENTERA\n");
                      }
                      ;

identificador: letra
                      {
                        fprintf(salida, "R108:\t <identificador> ::= TOK_IDENTIFICADOR\n");
                      }
                      |letra cola_identificador
                      {
                        fprintf(salida, "R109:\t <identificador> ::= TOK_IDENTIFICADOR\n");
                      }
                      ;

cola_identificador: alfanumerico
                      {
                        fprintf(salida, "R110:\t <cola_identificador> ::= TOK_IDENTIFICADOR\n");
                      }
                      |alfanumerico cola_identificador
                      {
                        fprintf(salida, "R111:\t <cola_identificador> ::= TOK_IDENTIFICADOR\n");
                      }
                      ;

alfanumerico: letra
                      {
                        fprintf(salida, "R112:\t <alfanumerico> ::= <letra>\n");
                      }
                      |digito
                      {
                        fprintf(salida, "R113:\t <alfanumerico> ::= <digito>");
                      }
                      ;

letra: TOK_IDENTIFICADOR
                      {
                        fprintf(salida, "R114:\t <letra> ::= TOK_IDENTIFICADOR\n");
                      }
                      ;

digito: TOK_CONSTANTE_ENTERA
                      {
                        fprintf(salida, "R115:\t <digito> ::= TOK_CONSTANTE_ENTERA\n");
                      }
                      ;

%%
