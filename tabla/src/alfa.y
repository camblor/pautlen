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
  extern int error;
  extern FILE *yyin;
  extern FILE *salida;
  extern int yylex();
  extern int yyleng;
  extern bool invalidchar;
  extern bool longitud;

  char itoa[100];
  int cuantos_no;
  int tipoErrorSemantico = 0;
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

  extern int etiqueta;


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
%type <atributos> if_exp
%type <atributos> if_exp_sentencias
%type <atributos> while_exp_sentencias
%type <atributos> while_exp
%type <atributos> while
%type <atributos> fn_declaration
%type <atributos> fn_name
%type <atributos> idpf


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

programa: TOK_MAIN '{'escritura1 declaraciones escritura2 funciones escritura3 sentencias'}'
        {
          /* Final del fichero */
          escribir_fin(salida);
        }

escritura1:
        {
          escribir_subseccion_data(salida);
          escribir_cabecera_bss(salida);

        }

escritura2:
        {
          escribir_segmento_codigo(salida);

        }

escritura3:
        {
          escribir_inicio_main(salida);
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

clase: clase_escalar | clase_vector

clase_escalar: tipo
        {
          /* Obtenemos clase */
          clase_actual = ESCALAR;
          /* Tipo se obtiene en tipo */
        }

tipo: TOK_INT
        {
          /* Obtenemos tipo */
          tipo_actual = INT;
        }
        |TOK_BOOLEAN
        {
          /* Obtenemos tipo */
          tipo_actual = BOOLEAN;
        }

clase_vector: TOK_ARRAY tipo '['TOK_CONSTANTE_ENTERA']'
        {
          /* Obtenemos clase */
          clase_actual = VECTOR;
          tamanio_vector_actual = $4.valor_entero;
          if (tamanio_vector_actual>64 || tamanio_vector_actual<1){
            error = -1;
            tipoErrorSemantico = 2;
            yyerror ($4.lexema);
            return -1;
          }
        }

identificadores: identificador
        {
          /*fprintf(salida, ";R18:\t<identificadores> ::= <identificador>\n");*/
        }
        |identificador ',' identificadores
        {
          /*fprintf(salida, ";R19:\t<identificadores> ::= <identificador> , <identificadores>\n");*/
        }

funciones: funcion funciones
        {
          /*fprintf(salida, ";R20:\t<funciones> ::= <funcion> <funciones>\n");*/
        }
        |
        {
          /*fprintf(salida, ";R21:\t<funciones> ::= \n");*/
        }

funcion: fn_declaration sentencias '}'
        {
          fprintf(salida, ";R22:\t<funcion> ::= function <tipo> <identificador> (<parametros_funcion>) {<declaraciones_funcion> <sentencias>}\n");
          vaciar(tablaActual);
          tablaActual = tablaGlobal;
          itemActual = buscaElemento(tablaActual, $1.lexema);

          if(itemActual == NULL){
            printf("ERROR - No creo que sea posible pero compruebo\n");
          }

          itemActual->data->num_parametros = num_parametros_actual;
        }


fn_declaration : fn_name '('parametros_funcion ')' '{' declaraciones_funcion
        {
          itemActual = buscaElemento(tablaActual, $1.lexema);

          if(itemActual == NULL){
            printf("ERROR - No creo que sea posible pero compruebo\n");
          }
          itemActual->data->num_parametros = num_parametros_actual;
          strcpy($$.lexema, $1.lexema);

          declararFuncion(salida, $1.lexema, num_variables_locales_actual);
        }

fn_name : TOK_FUNCTION tipo TOK_IDENTIFICADOR
        {
          itemActual = buscaElemento(tablaActual, $3.lexema);

          if(itemActual != NULL){
            printf("ERROR - YA EXISTE IDENTIFICADOR\n");
          }
          else{
            strcpy($$.lexema, $3.lexema);
            categoria_actual = FUNCION;
            clase_actual = ESCALAR;
            num_variables_locales_actual = 0;
            pos_variable_local_actual = 1;
            num_parametros_actual = 0;
            pos_parametro_actual = 0;

            infoActual = malloc(sizeof(datainfo));
            infoActual->categoria = categoria_actual;
            infoActual->clase = clase_actual;
            infoActual->tipo = tipo_actual;
            infoActual->tamanio_vector = tamanio_vector_actual;
            infoActual->num_variables_locales = num_variables_locales_actual;
            infoActual->pos_variable_local = pos_variable_local_actual;
            infoActual->num_parametros = num_parametros_actual;
            infoActual->pos_parametro = pos_parametro_actual;

            insertaElemento(tablaActual, $3.lexema, infoActual);
            tablaActual = tablaLocal;
            insertaElemento(tablaActual, $3.lexema, infoActual);
          }
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

parametro_funcion: tipo idpf
        {
          fprintf(salida, ";R27:\t<parametro_funcion> ::= <tipo> <TOK_IDENTIFICADOR>\n");
        }

idpf: TOK_IDENTIFICADOR
        {

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
            printf("ERROR\n");
          }

          strcpy($$.lexema,$1.lexema);
          num_parametros_actual++;
          pos_parametro_actual++;
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

sentencia_simple: asignacion | lectura | escritura | retorno_funcion

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
          itemActual = buscaElemento(tablaGlobal, $1.lexema);
          if(itemActual == NULL){
            error = -1;
            tipoErrorSemantico = 1;
            yyerror($1.lexema);
            return -1;
          }

          else if (itemActual->data->categoria == FUNCION){
            error = -1;
            tipoErrorSemantico = 8;
            yyerror($1.lexema);
            return -1;
          }

          else if(itemActual->data->clase == VECTOR){
            error = -1;
            tipoErrorSemantico = 8;
            yyerror($1.lexema);
            return -1;
          }

          else if(itemActual->data->tipo != $3.tipo){
            error = -1;
            tipoErrorSemantico = 8;
            yyerror($1.lexema);
            return -1;
          }

          else{
            $1.valor_entero = $3.valor_entero;
            asignar(salida, $1.lexema, $3.es_direccion);
          }



        }
        |elemento_vector '=' exp
        {
          /*fprintf(salida, "R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");*/
        }

elemento_vector: TOK_IDENTIFICADOR'['exp']'
        {

          itemActual = buscaElemento(tablaActual, $1.lexema);
          if (itemActual==NULL){
            tipoErrorSemantico=1;
            yyerror($1.lexema);
          }

          if (itemActual->data->categoria==FUNCION){
            error = -1;
            tipoErrorSemantico=9;
            yyerror($1.lexema);
            return -1;
          }
          printf("Tipo variable: %d\n", itemActual->data->categoria);
          if (itemActual->data->categoria!=VECTOR){
            error = -1;
            tipoErrorSemantico=9;
            yyerror($1.lexema);
            return -1;
          }

          if($3.tipo!=INT){
            error = -1;
            tipoErrorSemantico=10;
            yyerror($1.lexema);
            return -1;
          }
          $$.tipo = VECTOR;
          $$.es_direccion=1;
          escribir_elemento_vector(salida, $1.lexema, itemActual->data->tamanio_vector, $1.es_direccion);


          /*fprintf(salida, ";R48:\t<elemento_vector> ::= TOK_IDENTIFICADOR[<exp>]\n");*/
        }

condicional: if_exp_sentencias
        {
          fprintf(salida, ";R50:\t<condicional> ::= if (<exp>) {<sentencias>}\n");
        }
        | if_exp_sentencias TOK_ELSE '{' sentencias '}'
        {
          /*fprintf(salida, ";R51:\t<condicional> ::= if (<exp>) {<sentencias>} then {<sentencias>}\n");*/


        }

if_exp_sentencias: if_exp sentencias '}'
        {
          $$.etiqueta = $1.etiqueta;
          ifthenelse_fin(salida, $1.etiqueta);
        }
if_exp: TOK_IF '(' exp ')' '{'
        {

          if($3.tipo != BOOLEAN){
            error = -1;
            tipoErrorSemantico = 5;
            yyerror($3.lexema);
            return -1;
          }
          else {
            $$.etiqueta = etiqueta++;
            ifthenelse_fin_then(salida, $$.etiqueta);
          }
        }

bucle: while_exp_sentencias
        {
          fprintf(salida, ";R52:\t<bucle> ::= while (<exp>) {<sentencias>}\n");
        }

while_exp_sentencias: while_exp sentencias '}'
        {
          $$.etiqueta = $1.etiqueta;
          while_fin(salida, $1.etiqueta);
        }

while_exp: while '(' exp ')' '{'
        {
          if($3.tipo != BOOLEAN){
            error = -1;
            tipoErrorSemantico = 6;
            yyerror($1.lexema);
            return -1;
          }
          else {
            $$.etiqueta = $1.etiqueta;
            while_exp_pila(salida, $3.es_direccion, $$.etiqueta);
          }
        }

while: TOK_WHILE
        {
          $$.etiqueta = etiqueta++;
          while_inicio(salida, $$.etiqueta);
        }

lectura: TOK_SCANF TOK_IDENTIFICADOR
        {

          itemActual = buscaElemento(tablaActual, $2.lexema);
          if(!itemActual){
            error = -1;
            tipoErrorSemantico = 1;
            yyerror($2.lexema);
            return -1;
          }
          else if(itemActual->data->categoria == FUNCION){
            error = -1;
            tipoErrorSemantico = 0;
            yyerror($2.lexema);
            return -1;
          }
          else if(itemActual->data->clase != ESCALAR){
            error = -1;
            tipoErrorSemantico = 0;
            yyerror($2.lexema);
            return -1;
          }
          else{
            leer(salida, itemActual->lexema, itemActual->data->tipo);
          }
          /*fprintf(salida, ";R54:\t<lectura> ::= scanf <TOK_IDENTIFICADOR>\n");*/
        }

        escritura: TOK_PRINTF exp
                {
                  /*fprintf(salida, ";R56:\t<escritura> ::= printf <exp>\n");*/
                  if ($2.es_direccion == 1){
                  itemActual = buscaElemento(tablaActual, $2.lexema);
                  if(!itemActual){
                    error = -1;
                    tipoErrorSemantico = 1;
                    yyerror($2.lexema);
                  return -1;
                  }
                    escribir(salida, $2.es_direccion, $2.tipo);
                  }
                  else
                    escribir(salida, $2.es_direccion, $2.tipo);

                }

retorno_funcion: TOK_RETURN exp
        {
          /*retornarFuncion(fd_asm, 0);*/
          /*retornarFuncion(fd_asm, 1);*/
        }

exp: exp '+' exp
        {
          /* Sumamos las dos expresiones */
          if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN){
          error = -1;
          tipoErrorSemantico = 3;
          yyerror($1.lexema);
          return -1;
          }
          else if ($1.tipo == INT || $3.tipo == INT){
            sumar(salida, $1.es_direccion, $3.es_direccion);
            $$.valor_entero = $1.valor_entero + $3.valor_entero;
            $$.tipo = INT;
            $$.es_direccion=0;
          }
        }
        |exp '-' exp
        {
          /* Restamos las dos expresiones */
          if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN){
            error = -1;
            tipoErrorSemantico = 3;
            yyerror($1.lexema);
            return -1;
          }
          else if($1.tipo == INT || $3.tipo == INT){
            restar(salida, $1.es_direccion, $3.es_direccion);
            $$.valor_entero = $1.valor_entero - $3.valor_entero;
            $$.tipo = INT;
            $$.es_direccion=0;
          }
        }
        |exp '/' exp
        {
          /* Dividimos las dos expresiones */
          if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN){
            error = -1;
            tipoErrorSemantico = 3;
            yyerror($1.lexema);
            return -1;
          }
          else if($1.tipo == INT || $3.tipo == INT){
            dividir(salida, $1.es_direccion, $3.es_direccion);
            $$.valor_entero = $1.valor_entero / $3.valor_entero;
            $$.tipo = INT;
            $$.es_direccion=0;
          }
        }
        |exp '*' exp
        {
          /* Multiplicamos las dos expresiones */
          if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN){
            error = -1;
            tipoErrorSemantico = 3;
            yyerror($1.lexema);
            return -1;
          }
          else if($1.tipo == INT || $3.tipo == INT){
            multiplicar(salida, $1.es_direccion, $3.es_direccion);
            $$.valor_entero = $1.valor_entero * $3.valor_entero;
            $$.tipo = INT;
            $$.es_direccion=0;
          }
        }
        |'-' exp
        {
          /* Multiplicamos por -1 la expresion */
          if ($2.tipo == BOOLEAN){
            error = -1;
            tipoErrorSemantico = 3;
            yyerror($2.lexema);
            return -1;
          }
          cambiar_signo(salida, $2.es_direccion);
          $$.valor_entero = -1 * $2.valor_entero;
          $$.tipo = INT;
          $$.es_direccion=0;
        }
        |exp TOK_AND exp
        {
          /* AND LOGICO entre las dos expresiones */
          if ($1.tipo == INT || $3.tipo == INT){
            error = -1;
            tipoErrorSemantico = 4;
            yyerror($1.lexema);
            return -1;
          }
          y(salida, $1.es_direccion, $3.es_direccion);
          $$.tipo = BOOLEAN;
          $$.es_direccion=0;
          /*fprintf(salida, ";R77:\t<exp> ::= <exp> && <exp>\n");*/
        }
        |exp TOK_OR exp
        {
          /* OR LOGICO entre las dos expresiones */
          if ($1.tipo == INT || $3.tipo == INT){
            error = -1;
            tipoErrorSemantico = 4;
            yyerror($1.lexema);
            return -1;
          }
          o(salida, $1.es_direccion, $3.es_direccion);
          $$.tipo = BOOLEAN;
          $$.es_direccion=0;
          /*fprintf(salida, ";R77:\t<exp> ::= <exp> && <exp>\n");*/
        }
        |'!'exp
        {
          /* NEGAMOS la expresion (logica) */
          if ($2.tipo == INT){
            error = -1;
            tipoErrorSemantico = 4;
            yyerror($2.lexema);
            return -1;
          }
          no(salida, $2.es_direccion, cuantos_no);
          $$.tipo = BOOLEAN;
          $$.es_direccion=0;
          cuantos_no++;
          /*fprintf(salida, ";R77:\t<exp> ::= <exp> && <exp>\n");*/
        }
        |TOK_IDENTIFICADOR
        {

          itemActual = buscaElemento(tablaActual, $1.lexema);

          /*Si no lo encuentra error*/
          if (itemActual == NULL){
            printf("ERROR - Identificador no valido\n");
          }
          /*Si categoria es funicon error*/
          else if(itemActual->data->categoria == FUNCION){
            printf("ERROR - Suma de funciones\n");
          }
          /*Si clase es vector error*/
          else if (itemActual->data->clase == VECTOR){
            printf("ERROR - Suma de vectores\n");
          }
          /*CORRECTO*/
          else {
            $$.tipo = itemActual->data->tipo;
            $$.es_direccion = 1;
            $$.valor_entero = $1.valor_entero;


            /* Asignamos valor */
            printf("metido %s\n", $1.lexema);
            escribir_operando(salida, $1.lexema, $$.es_direccion);
          }
          /* TODO: Escritura en ensamblador de la introduccion en la pila de la dirección del identificador: push dword  _$1.lexema */
          /*fprintf(salida, ";R80:\t<exp> ::= <TOK_IDENTIFICADOR>\n");*/
        }
        |constante
        {
          $$.tipo = $1.tipo;
          $$.es_direccion = $1.es_direccion;
          /*fprintf(salida, ";R81:\t<exp> ::= <constante>\n");*/
        }
        |'('exp')'
        {
          /*fprintf(salida, ";R82:\t<exp> ::= (<exp>)\n");*/
          $$.tipo = $2.tipo;
          $$.es_direccion = $2.es_direccion;
        }
        |'('comparacion')'
        {
          /*fprintf(salida, ";R83:\t<exp> ::= <comparacion>\n");*/
          $$.tipo = $2.tipo;
          $$.es_direccion = $2.es_direccion;
        }
        |elemento_vector
        {
          $$.tipo = $1.tipo;
          $$.es_direccion = $1.es_direccion;
          /*fprintf(salida, ";R85:\t<exp> ::= <elemento_vector>\n");*/
        }
        |TOK_IDENTIFICADOR '('lista_expresiones')'
        {
          /*fprintf(salida, ";R88:\t<exp> ::= <TOK_IDENTIFICADOR> (<lista_expresiones>)\n");*/
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
          if (($1.tipo == INT) && ($3.tipo == INT)){
            if($3.es_direccion==1 && $1.es_direccion==1){
              igual(salida, $1.es_direccion, $3.es_direccion, etiqueta);
              etiqueta++;
              $$.tipo = BOOLEAN;
              $$.es_direccion = 0;

            }
          }
        }
        |exp TOK_DISTINTO exp
        {
          /*fprintf(salida, ";R94:\t<comparacion> ::= <exp> != <exp>\n");*/
          if (($1.tipo == INT) && ($3.tipo == INT)){
            if($3.es_direccion==1 && $1.es_direccion==1){
              distinto(salida, $1.es_direccion, $3.es_direccion, etiqueta);
              etiqueta++;
              $$.tipo = BOOLEAN;
              $$.es_direccion = 0;
            }
          }
        }
        |exp TOK_MENORIGUAL exp
        {
          /*fprintf(salida, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");*/
          if (($1.tipo == INT) && ($3.tipo == INT)){
            if($3.es_direccion==1 && $1.es_direccion==1){
              menor_igual(salida, $1.es_direccion, $3.es_direccion, etiqueta);
              etiqueta++;
              $$.tipo = BOOLEAN;
              $$.es_direccion = 0;
            }
          }
        }
        |exp TOK_MAYORIGUAL exp
        {
          /*fprintf(salida, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");*/
          if (($1.tipo == INT) && ($3.tipo == INT)){
            if($3.es_direccion==1 && $1.es_direccion==1){
              mayor_igual(salida, $1.es_direccion, $3.es_direccion, etiqueta);
              etiqueta++;
              $$.tipo = BOOLEAN;
              $$.es_direccion = 0;
            }
          }
        }
        |exp '<' exp
        {
          /*fprintf(salida, ";R97:\t<comparacion> ::= <exp> < <exp>\n");*/
          if (($1.tipo == INT) && ($3.tipo == INT)){
            if($3.es_direccion==1 && $1.es_direccion==1){
              menor(salida, $1.es_direccion, $3.es_direccion, etiqueta);
              etiqueta++;
              $$.tipo = BOOLEAN;
              $$.es_direccion = 0;
            }
          }
        }
        |exp '>' exp
        {
          /*fprintf(salida, ";R98:\t<comparacion> ::= <exp> > <exp>\n");*/
          if (($1.tipo == INT) && ($3.tipo == INT)){
            if($3.es_direccion==1 && $1.es_direccion==1){
              mayor(salida, $1.es_direccion, $3.es_direccion, etiqueta);
              etiqueta++;
              $$.tipo = BOOLEAN;
              $$.es_direccion = 0;
            }
          }
        }

constante: constante_logica
        {
          $$.tipo = $1.tipo;
          $$.es_direccion = $1.es_direccion;
        }
        | constante_entera
        {
          $$.tipo = $1.tipo;
          $$.es_direccion = $1.es_direccion;
        }

constante_logica: TOK_TRUE
        {
          $$.tipo = BOOLEAN;
          $$.es_direccion = 0;
        }
        |TOK_FALSE
        {
          $$.tipo = BOOLEAN;
          $$.es_direccion = 0;
        }

constante_entera: TOK_CONSTANTE_ENTERA
        {
          /* Sintesis del valor */
          $$.valor_entero = $1.valor_entero;
          $$.tipo = INT;
          $$.es_direccion = 0;

          /* Transformamos entero a string para adaptarnos al formato de generacion */
          sprintf(itoa, "%d", $1.valor_entero);

          /* Asignamos valor */
          escribir_operando(salida, itoa, $$.es_direccion);
        }

identificador: TOK_IDENTIFICADOR
        {
          if(tablaActual==tablaLocal){
            pos_variable_local_actual++;
            num_variables_locales_actual++;
          }

          categoria_actual = VARIABLE;
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
            error = -1;
            tipoErrorSemantico = 13;
            yyerror($1.lexema);
            return -1;
          }
        }


%%


void yyerror(const char * perror) {
printf("%d\n", error);
    if(error==-1) {
    if (tipoErrorSemantico==0)
    			fprintf(stderr,"****Error semantico en lin %d: %s\n",linea,perror);
    		else if (tipoErrorSemantico==1)
    			fprintf(stderr,"****Error semantico en lin %d: Acceso a variable no declarada (%s).\n",linea,perror);
    		else if (tipoErrorSemantico==2)
    			fprintf(stderr,"****Error semantico en lin %d: El tamanyo del vector <%s> excede los limites permitidos (1,64).\n",linea,perror);
        else if(tipoErrorSemantico==3)
          fprintf(stderr, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.", linea);
        else if (tipoErrorSemantico==4)
          fprintf(stderr, "****Error semantico en lin %d: Operacion logica con operandos int.", linea);
        else if (tipoErrorSemantico==5)
          fprintf(stderr, "****Error semantico en lin %d: Condicional con condicion de tipo int.", linea);
        else if (tipoErrorSemantico==6)
          fprintf(stderr, "****Error semantico en lin %d: Bucle con condicion de tipo int.", linea);
        else if (tipoErrorSemantico==7)
          fprintf(stderr, "****Error semantico en lin %d: Numero incorrecto de parametros en llamada a funcion.", linea);
        else if (tipoErrorSemantico==8)
          fprintf(stderr, "****Error semantico en lin %d: Asignacion incompatible.", linea);
        else if (tipoErrorSemantico==9)
          fprintf(stderr, "****Error semantico en lin %d: Intento de indexacion de una variable que no es de tipo vector.", linea);
        else if (tipoErrorSemantico==10)
          fprintf(stderr, "****Error semantico en lin %d: El indice en una operacion de indexacion tiene que ser de tipo entero", linea);
        else if (tipoErrorSemantico==11)
          fprintf(stderr, "****Error semantico en lin %d: Sentencia de retorno fuera del cuerpo de una función.", linea);
        else if (tipoErrorSemantico==12)
          fprintf(stderr, "****Error semantico en lin %d: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.", linea);
        else if (tipoErrorSemantico==13){
          fprintf(stderr, "****Error semantico en lin %d: Declaracion duplicada.", linea);
        }
    		else
    			fprintf(stderr,"****Error semantico en lin %d: Funcion <%s> sin sentencia de retorno.\n",linea,perror);
    }
    else if (error == 0){
      fprintf(stderr, "****Error sintactico en [lin %d, col %d]\n", linea, columna-1);
    }
    error = 0;
    fclose(salida);

    liberaTabla(tablaActual);
    liberaTabla(tablaGlobal);
    error = 0;
}
