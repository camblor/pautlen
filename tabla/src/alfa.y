%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>
  #include "../inc/alfa.h"
  #include "../inc/tabla.h"
  

  tipo_atributos hola;

  void yyerror(const char *error);
  extern int linea ,columna;
  extern FILE *yyin;
  extern FILE *salida;
  extern int yylex();
  extern int yyleng;
  extern bool invalidchar;
  extern bool longitud;

  /*Diferenciar globales y locales*/
  int ambito;

  /*Informacion de lo que estamos analizando*/
  int categoria_actual;
  int clase_actual;
  int tipo_actual;
  int tamanio_vector_actual;
  int num_variables_locales_actual;
  int pos_variable_local_actual;
  int num_parametros_actual;
  int pos_parametro_actual;

  /*Tablas de simbolos*/
  extern dataItem** tablaGlobal;
  extern dataItem** tablaLocal;

  extern dataItem** tablaActual;

  dataItem* itemActual;
  extern datainfo * infoActual;

%}

%union
 {
  tipo_atributos atributos;
 }

%token <atributos> TOK_IDENTIFICADOR
%token <atributos> TOK_CONSTANTE_REAL
%token <atributos> TOK_CONSTANTE_ENTERA

%type <atributos> condicional
%type <atributos> comparacion
%type <atributos> elemento_vector
%type <atributos> exp
%type <atributos> constante
%type <atributos> constante_entera
%type <atributos> constante_logica
%type <atributos> identificador


%token TOK_MAIN
%token TOK_RETURN
%token TOK_ARRAY
%token TOK_INT
%token TOK_BOOLEAN
%token TOK_SCANF
%token TOK_PRINTF
%token TOK_IF
%token TOK_ELSE
%token TOK_WHILE
%token TOK_OR
%token TOK_AND
%token TOK_DISTINTO
%token TOK_IGUAL
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_FUNCTION
%token TOK_TRUE
%token TOK_FALSE
%token TOK_ERROR

%left '+' '-' '*' '/'
%left TOK_OR TOK_AND
%left TOK_DISTINTO TOK_IGUAL
%left '<' '>' TOK_MAYORIGUAL TOK_MENORIGUAL
%left '!'


%start programa

%%

programa: TOK_MAIN '{'declaraciones funciones sentencias'}'
        {
          /*fprintf(salida, ";R1:\t<programa> ::= main { <declaraciones> <funciones> <sentencias> }\n");*/
          escribir_fin(salida);
          
        }


declaraciones: declaracion
        {
          /*fprintf(salida, ";R2:\t<declaraciones> ::= <declaracion>\n");*/
        }
        |declaracion declaraciones
        {
          /*fprintf(salida, ";R3:\t<declaraciones> ::= <declaracion> <declaraciones>\n");*/
        }

declaracion: clase identificadores ';'
        {
          /*fprintf(salida, ";R4:\t<declaracion> ::= <clase> <identificadores> ;\n");*/
        }

clase: clase_escalar
        {
          /*fprintf(salida, ";R5:\t<clase> ::= <clase_escalar>\n");*/
          
        }
        |clase_vector
        {
          fprintf(salida, ";R6:\t<clase> ::= <clase_vector>\n");
        }

clase_escalar: tipo
        {
          clase_actual = ESCALAR;
          /*fprintf(salida, ";R9:\t<clase_escalar> ::= <tipo>\n");*/
        }

tipo: TOK_INT
        {
          tipo_actual = INT;
          /*fprintf(salida, ";R10:\t<tipo> ::= int\n");*/
        }
        |TOK_BOOLEAN
        {
          tipo_actual = BOOLEAN;
          fprintf(salida, ";R11:\t<tipo> ::= boolean\n");
        }

clase_vector: TOK_ARRAY tipo '['TOK_CONSTANTE_ENTERA']'
        {
          clase_actual = VECTOR;
          tamanio_vector_actual = $4.valor_entero;
          fprintf(salida, ";R15:\t<clase_vector> ::= array <tipo> [TOK_CONSTANTE_ENTERA]\n");
          
        }

identificadores: identificador
        {
          /*fprintf(salida, ";R18:\t<identificadores> ::= <identificador>\n");*/
        }
        |identificador ',' identificadores
        {
          /*fprintf(salida, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");*/
          escribir_segmento_codigo(salida);
          escribir_inicio_main(salida);
        }

funciones: funcion funciones
        {
          /*fprintf(salida, ";R20:\t<funciones> ::= <funcion> <funciones>\n");*/
        }
        |
        {
          /*fprintf(salida, ";R21:\t<funciones> ::= \n");*/
        }

funcion: TOK_FUNCTION tipo identificador '('parametros_funcion')' '{'declaraciones_funcion sentencias'}'
        {
          fprintf(salida, ";R22:\t<funcion> ::= function <tipo> <identificador> (<parametros_funcion>) {<declaraciones_funcion> <sentencias>}\n");
        }

parametros_funcion: parametro_funcion resto_parametros_funcion
        {
          fprintf(salida, ";R23:\t<parametros_funcion> ::= <parametro_funcion> <resto_parametros_funcion>\n");
        }
        |
        {
          fprintf(salida, ";R24:\t<parametros_funcion> ::= \n");
        }

resto_parametros_funcion: ';' parametro_funcion resto_parametros_funcion
        {
          fprintf(salida, ";R25:\t<resto_parametros_funcion> ::= ;<parametro_funcion> <resto_parametros_funcion>\n");
        }
        |
        {
          fprintf(salida, ";R26:\t<resto_parametros_funcion> ::= \n");
        }

parametro_funcion: tipo TOK_IDENTIFICADOR
        {
          fprintf(salida, ";R27:\t<parametro_funcion> ::= <tipo> <TOK_IDENTIFICADOR>\n");
        }

declaraciones_funcion: declaraciones
        {
          fprintf(salida, ";R28:\t<declaraciones_funcion> ::= <declaraciones>\n");
        }
        |
        {
          fprintf(salida, ";R29:\t<declaraciones_funcion> ::= \n");
        }

sentencias: sentencia
        {
          /*fprintf(salida, ";R30:\t<sentencias> ::= <sentencia>\n");*/
        }
        | sentencia sentencias
        {
          /*fprintf(salida, ";R31:\t<sentencias> ::= <sentencia> <sentencias>\n");*/
        }

sentencia: sentencia_simple ';'
        {
         /* fprintf(salida, ";R32:\t<sentencia> ::= <sentencia_simple> ;\n");*/
        }
        |bloque
        {
          /*fprintf(salida, ";R33:\t<sentencia> ::= <bloque>");*/
        }

sentencia_simple: asignacion
        {
          /*fprintf(salida, ";R34:\t<sentencia_simple> ::= <asignacion>\n");*/
        }
        |lectura
        {
          
          /*fprintf(salida, ";R35:\t<sentencia_simple> ::= <lectura>\n");*/
        }
        |escritura
        {
          /*fprintf(salida, ";R36:\t<sentencia_simple> ::= <escritura>\n");*/
        }
        |retorno_funcion
        {
          /*fprintf(salida, ";R38:\t<sentencia_simple> ::= <retorno_funcion>\n");*/
        }

bloque: condicional
        {
          fprintf(salida, ";R40:\t<bloque> ::= <condicional>\n");
        }
        |bucle
        {
          fprintf(salida, ";R41:\t<bloque> ::= <bucle>\n");
        }

asignacion: TOK_IDENTIFICADOR '=' exp
        {
          /*fprintf(salida, ";R43:\t<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>\n");*/
          if(buscaElemento(tablaGlobal, $1.lexema) != NULL){
            $1.valor_entero = $3.valor_entero;
          }
        }
        |elemento_vector '=' exp
        {
          fprintf(salida, "R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
        }

elemento_vector: TOK_IDENTIFICADOR'['exp']'
        {
          fprintf(salida, ";R48:\t<elemento_vector> ::= TOK_IDENTIFICADOR[<exp>]\n");
        }

condicional: TOK_IF '('exp')' '{'sentencias'}'
        {
          fprintf(salida, ";R50:\t<condicional> ::= if (<exp>) {<sentencias>}\n");
        }
        |TOK_IF '('exp')' '{'sentencias'}' TOK_ELSE '{'sentencias'}'
        {
          fprintf(salida, ";R51:\t<condicional> ::= if (<exp>) {<sentencias>} then {<sentencias>}\n");
        }

bucle: TOK_WHILE '('exp')' '{'sentencias'}'
        {
          fprintf(salida, ";R52:\t<bucle> ::= while (<exp>) {<sentencias>}\n");
        }

lectura: TOK_SCANF TOK_IDENTIFICADOR
        {
          /* Si al buscar el identificdor en la tabla de símbolos, no está... salir con ERROR */
          /* Si la categoría o la clase no es la adecuada 
          (no se puede leer sobre el id de una función ni en algo queno sea escalar)... 
          salir con ERROR*/
          /* Se aplia la dirección sobre la que se va a leer*/
            /* Generar código para escribir push dword _$2.lexema */
          /* Invoca a la función de librería adecuada al tipo del ID*/
          itemActual = buscaElemento(tablaActual, $2.lexema);
          if(!itemActual){
            printf("ERROR\n");
          } else{

            if (itemActual->data->clase != 1){
              printf("ERROR\n");
            }
            if (tablaActual == tablaGlobal){
              leer(salida, itemActual->lexema, itemActual->data->tipo);
            } else if (tablaActual == tablaLocal){
              printf("ambito local\n");
            } else{
              printf("ERROR AMBITO\n");
            }
            printf("lul: %d\n", itemActual->data->clase);
          }
          /*fprintf(salida, ";R54:\t<lectura> ::= scanf <TOK_IDENTIFICADOR>\n");*/
        }

escritura: TOK_PRINTF exp
        {
          /*fprintf(salida, ";R56:\t<escritura> ::= printf <exp>\n");*/
          escribir(salida, 1, buscaElemento(tablaGlobal, $2.lexema)->data->tipo);
        }

retorno_funcion: TOK_RETURN exp
        {
          /*fprintf(salida, ";R61:\t<retorno_funcion> ::= return <exp>\n");*/
        }

exp: exp '+' exp
        {
          /*fprintf(salida, ";R72:\t<exp> ::= <exp> + <exp>\n");*/
          $$.valor_entero = $1.valor_entero + $3.valor_entero;
        }
        |exp '-' exp
        {
          /*fprintf(salida, ";R73:\t<exp> ::= <exp> - <exp>\n");*/
          $$.valor_entero = $1.valor_entero - $3.valor_entero;
        }
        |exp '/' exp
        {
          /*fprintf(salida, ";R74:\t<exp> ::= <exp> / <exp>\n");*/
          $$.valor_entero = $1.valor_entero / $3.valor_entero;
        }
        |exp '*' exp
        {
          /*fprintf(salida, ";R75:\t<exp> ::= <exp> * <exp>\n");*/
          $$.valor_entero = $1.valor_entero * $3.valor_entero;
        }
        |'-' exp
        {
          /*fprintf(salida, ";R76:\t<exp> ::= -<exp>\n");*/
          $$.valor_entero = -1 * $2.valor_entero;
        }
        |exp TOK_AND exp
        {
          fprintf(salida, ";R77:\t<exp> ::= <exp> && <exp>\n");
        }
        |exp TOK_OR exp
        {
          fprintf(salida, ";R78:\t<exp> ::= <exp> || <exp>\n");
        }
        |'!'exp
        {
          fprintf(salida, ";R79:\t<exp> ::= !<exp>\n");
        }
        |TOK_IDENTIFICADOR
        {
          /*fprintf(salida, ";R80:\t<exp> ::= <TOK_IDENTIFICADOR>\n");*/
        }
        |constante
        {
          /*fprintf(salida, ";R81:\t<exp> ::= <constante>\n");*/
        }
        |'('exp')'
        {
          fprintf(salida, ";R82:\t<exp> ::= (<exp>)\n");
          $$.valor_entero = $2.valor_entero;
        }
        |comparacion
        {
          fprintf(salida, ";R83:\t<exp> ::= <comparacion>\n");
        }
        |elemento_vector
        {
          fprintf(salida, ";R85:\t<exp> ::= <elemento_vector>\n");
        }
        |TOK_IDENTIFICADOR '('lista_expresiones')'
        {
          fprintf(salida, ";R88:\t<exp> ::= <TOK_IDENTIFICADOR> (<lista_expresiones>)\n");
        }

lista_expresiones: exp resto_lista_expresiones
        {
          /*fprintf(salida, "R89:\t<lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");*/
        }
        |
        {
          /*fprintf(salida, "R90:\t<lista_expresiones> ::= \n");*/
        }

resto_lista_expresiones: ',' exp resto_lista_expresiones
        {
          /*fprintf(salida, ";R91:\t<resto_lista_expresiones> ::= <exp> <resto_lista_expresiones>\n");*/
        }
        |
        {
          /*fprintf(salida, ";R92:\t<resto_lista_expresiones> ::= \n");*/
        }

comparacion: exp TOK_IGUAL exp
        {
          /*fprintf(salida, ";R93:\t<comparacion> ::= <exp> == <exp>\n");*/
        }
        |exp TOK_DISTINTO exp
        {
          fprintf(salida, ";R94:\t<comparacion> ::= <exp> != <exp>\n");
        }
        |exp TOK_MENORIGUAL exp
        {
          fprintf(salida, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");
        }
        |exp TOK_MAYORIGUAL exp
        {
          fprintf(salida, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");
        }
        |exp '<' exp
        {
          fprintf(salida, ";R97:\t<comparacion> ::= <exp> < <exp>\n");
        }
        |exp '>' exp
        {
          fprintf(salida, ";R98:\t<comparacion> ::= <exp> > <exp>\n");
        }

constante: constante_logica
        {
          /*fprintf(salida, ";R99:\t<constante> ::= <constante_logica>\n");*/
        }
        |constante_entera
        {
          /*fprintf(salida, ";R100:\t<constante> ::= <constante_entera>\n");*/
        }

constante_logica: TOK_TRUE
        {
          fprintf(salida, ";R102:\t<constante_logica> ::= true\n");
        }
        |TOK_FALSE
        {
          fprintf(salida, ";R103:\t<constante_logica> ::= false\n");
        }

constante_entera: TOK_CONSTANTE_ENTERA
        {
          /*fprintf(salida, ";R104:\t<constante_entera> ::= TOK_CONSTANTE_ENTERA\n");*/
        }

identificador: TOK_IDENTIFICADOR
        {
          /*fprintf(salida, ";R108:\t<identificador> ::= TOK_IDENTIFICADOR\n");*/

          declarar_variable(salida, $1.lexema, tipo_actual, 1);

          infoActual = malloc(sizeof(datainfo));
          infoActual->categoria = categoria_actual;
          infoActual->clase = clase_actual;
          infoActual->tipo = tipo_actual;
          infoActual->tamanio_vector = tamanio_vector_actual;
          infoActual->num_variables_locales = num_variables_locales_actual;
          infoActual->pos_variable_local = pos_variable_local_actual;
          infoActual->num_parametros = num_parametros_actual;
          infoActual->pos_parametro = pos_parametro_actual;
          
          if(!insertaElemento(tablaActual, $1.lexema, infoActual)){
            printf("Ya existe ese elemento\n");
          }
        }


%%


void yyerror(const char * error) {
    if(!error) {
        printf("****Error sintactico en [linea %d, columna %d]\n", linea, columna);
    }
    error = 0;
}
