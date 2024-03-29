%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdbool.h>
  #include "../inc/alfa.h"
  #include "../inc/tabla.h"



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
  int tipoErrorSemantico = -1;
  /*Diferenciar globales y locales*/
  int ambito;

  /*Informacion de lo que estamos analizando*/
  int categoria_actual = 0;
  int clase_actual = 0;
  int tipo_actual = 0;
  int tamanio_vector_actual = 0;
  int num_variables_locales_actual = 0;
  int pos_variable_local_actual = 0;
  int num_parametros_actual = 0;
  int pos_parametro_actual = 0;
  int num_parametros_llamada_actual = 0;
  int llamada_funcion = 0;
  int return_funcion = 0;

  extern int etiqueta;


  /*Tablas de simbolos*/
  extern dataItem** tablaGlobal;
  extern dataItem** tablaLocal;

  extern dataItem** tablaActual;

  dataItem* itemActual;
  extern datainfo * infoActual;

  char nombreFuncion[100];

  int retorno=0;

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
%type <atributos> llamadaAFuncion
%type <atributos> argumento


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
%token TOK_NOT
%token TOK_DISTINTO
%token TOK_IGUAL
%token TOK_MENOR
%token TOK_MAYOR
%token TOK_MENORIGUAL
%token TOK_MAYORIGUAL
%token TOK_COMA
%token TOK_PUNTOYCOMA
%token TOK_LLAVEIZQUIERDA
%token TOK_LLAVEDERECHA
%token TOK_CORCHETEIZQUIERDO
%token TOK_CORCHETEDERECHO
%token TOK_PARENTESISIZQUIERDO
%token TOK_PARENTESISDERECHO
%token TOK_MENOS
%token TOK_MAS
%token TOK_ASTERISCO
%token TOK_DIVISION
%token TOK_FUNCTION
%token TOK_TRUE
%token TOK_FALSE
%token TOK_ERROR
%token TOK_ASIGNACION

%left TOK_MAS TOK_MENOS TOK_ASTERISCO TOK_DIVISION
%left TOK_OR TOK_AND
%left TOK_DISTINTO TOK_IGUAL


%left TOK_MENOR TOK_MAYOR TOK_MAYORIGUAL TOK_MENORIGUAL
%right TOK_NOT


%start programa

%%

programa: TOK_MAIN TOK_LLAVEIZQUIERDA escritura1 declaraciones escritura2 funciones escritura3 sentencias TOK_LLAVEDERECHA
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
        |declaracion declaraciones

declaracion: clase identificadores TOK_PUNTOYCOMA

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

clase_vector: TOK_ARRAY tipo TOK_CORCHETEIZQUIERDO TOK_CONSTANTE_ENTERA TOK_CORCHETEDERECHO
        {
          /* Obtenemos clase */
          clase_actual = VECTOR;
          tamanio_vector_actual = $4.valor_entero;
          categoria_actual = VARIABLE;
          if (tamanio_vector_actual>MAX_TAMANIO_VECTOR || tamanio_vector_actual<1){
            error = -1;
            tipoErrorSemantico = 2;
            yyerror ($4.lexema);
            return -1;
          }

          
        }

identificadores: identificador
        |identificador TOK_COMA identificadores

funciones: funcion funciones
        |

funcion: fn_declaration sentencias TOK_LLAVEDERECHA
        {
          fprintf(salida, ";R22:\t<funcion> ::= function <tipo> <identificador> (<parametros_funcion>) {<declaraciones_funcion> <sentencias>}\n");
          vaciar(tablaActual);
          tablaActual = tablaGlobal;
        }


fn_declaration : fn_name TOK_PARENTESISIZQUIERDO parametros_funcion TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA declaraciones_funcion
        {
          itemActual = buscaElemento(tablaLocal, $1.lexema);
          if(itemActual == NULL){
              error = -1;
              tipoErrorSemantico = 1;
              yyerror($1.lexema);
              return -1;
          }
          itemActual->data->num_parametros = num_parametros_actual;
          itemActual = buscaElemento(tablaGlobal, $1.lexema);

          if(itemActual == NULL){
              error = -1;
              tipoErrorSemantico = 1;
              yyerror($1.lexema);
              return -1;
          }
          itemActual->data->num_parametros = num_parametros_actual;

          strcpy($$.lexema, $1.lexema);

          declararFuncion(salida, $1.lexema, num_variables_locales_actual);
        }

fn_name : TOK_FUNCTION tipo TOK_IDENTIFICADOR
        {
          return_funcion = 0;
          itemActual = buscaElemento(tablaActual, $3.lexema);

          if(itemActual != NULL){
              error = -1;
              tipoErrorSemantico = 1;
              yyerror($3.lexema);
              return -1;
          }
          else{
            strcpy($$.lexema, $3.lexema);
            categoria_actual = FUNCION;
            clase_actual = ESCALAR;
            num_variables_locales_actual = 0;
            pos_variable_local_actual = 0;
            num_parametros_actual = 0;
            pos_parametro_actual = 0;


            infoActual = malloc(sizeof(datainfo));
            infoActual->categoria = FUNCION;
            infoActual->clase = clase_actual;
            infoActual->tipo = tipo_actual;
            infoActual->tamanio_vector = tamanio_vector_actual;
            infoActual->num_variables_locales = num_variables_locales_actual;
            infoActual->pos_variable_local = pos_variable_local_actual;
            infoActual->num_parametros = num_parametros_actual;
            infoActual->pos_parametro = pos_parametro_actual;            

            if(!insertaElemento(tablaActual, $3.lexema, infoActual)){
              error = -1;
              tipoErrorSemantico = 13;
              yyerror($3.lexema);
              return -1;
            }

            tablaActual = tablaLocal;
            infoActual = malloc(sizeof(datainfo));
            infoActual->categoria = FUNCION;
            infoActual->clase = clase_actual;
            infoActual->tipo = tipo_actual;
            infoActual->tamanio_vector = tamanio_vector_actual;
            infoActual->num_variables_locales = num_variables_locales_actual;
            infoActual->pos_variable_local = pos_variable_local_actual;
            infoActual->num_parametros = num_parametros_actual;
            infoActual->pos_parametro = pos_parametro_actual;

            if(!insertaElemento(tablaActual, $3.lexema, infoActual)){
              error = -1;
              tipoErrorSemantico = 13;
              yyerror($3.lexema);
              return -1;
            }

            categoria_actual = 0;
            clase_actual = 0;
            tipo_actual = 0;
          }
        }

parametros_funcion: parametro_funcion resto_parametros_funcion
        |

resto_parametros_funcion: TOK_PUNTOYCOMA parametro_funcion resto_parametros_funcion
        |

parametro_funcion: tipo idpf

idpf: TOK_IDENTIFICADOR
        {

          infoActual = malloc(sizeof(datainfo));
          infoActual->categoria = categoria_actual;
          infoActual->clase = clase_actual;
          infoActual->tipo = tipo_actual;
          infoActual->tamanio_vector = tamanio_vector_actual;
          infoActual->num_variables_locales = num_variables_locales_actual;
          infoActual->pos_variable_local = pos_variable_local_actual;
          infoActual->num_parametros = ++num_parametros_actual;
          infoActual->pos_parametro = pos_parametro_actual++;

          if(!insertaElemento(tablaLocal, $1.lexema, infoActual)){
              error = -1;
              tipoErrorSemantico = 13;
              yyerror($1.lexema);
              return -1;
          }


          strcpy($$.lexema,$1.lexema);
        }

declaraciones_funcion: declaraciones
        |

sentencias: sentencia
        | sentencia sentencias

sentencia: sentencia_simple TOK_PUNTOYCOMA
        |bloque

sentencia_simple: asignacion | lectura | escritura | retorno_funcion

bloque: condicional
        {
          fprintf(salida, ";R40:\t<bloque> ::= <condicional>\n");
        }
        |bucle
        {
          fprintf(salida, ";R41:\t<bloque> ::= <bucle>\n");
        }

asignacion: TOK_IDENTIFICADOR TOK_ASIGNACION exp
        {
          fprintf(salida, ";R43:\t<asignacion> ::= <TOK_IDENTIFICADOR> = <exp>\n");
          
          if(tablaActual == tablaGlobal){
            
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

          else{
            itemActual = buscaElemento(tablaLocal, $1.lexema);
            if(itemActual == NULL){
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
              escribirIdentificadorLocal (salida, itemActual->data->categoria,num_parametros_actual, itemActual->data->pos_parametro,itemActual->data->pos_variable_local,0);
			        asignarIdentLocal(salida, $3.es_direccion);
            }
          }
          



        }
        |elemento_vector TOK_ASIGNACION exp
        {
          
          if($3.tipo!=$1.tipo)
          {
            error=-1;
            tipoErrorSemantico=8;
            yyerror("vector");
            return -1;
          }
          if(categoria_actual==FUNCION){
            asignarElemVec(salida, 1);
          } else{
            asignarElemVec(salida, 0);
          }          
          fprintf(salida, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
          categoria_actual = 0;
        }

elemento_vector: TOK_IDENTIFICADOR TOK_CORCHETEIZQUIERDO exp TOK_CORCHETEDERECHO
        {
          if(tablaActual == tablaGlobal){
            itemActual = NULL;
            itemActual = buscaElemento(tablaGlobal, $1.lexema);

            if (itemActual==NULL){
              error = -1;
              tipoErrorSemantico=1;
              yyerror($1.lexema);
              return -1;
            }            

            if (itemActual->data->categoria==FUNCION){
              error = -1;
              tipoErrorSemantico=9;
              yyerror($1.lexema);
              return -1;
            }
            if (itemActual->data->clase!=VECTOR){
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
            $$.es_direccion=1;
            strcpy($$.lexema, $1.lexema);
            $$.tipo = itemActual->data->tipo;
            escribir_elemento_vector(salida, $1.lexema, itemActual->data->tamanio_vector, $1.es_direccion);
          }
          else{
            itemActual = buscaElemento(tablaLocal, $1.lexema);
            if (itemActual==NULL){
              itemActual = buscaElemento(tablaGlobal, $1.lexema);
              if (itemActual==NULL){
                error = -1;
                tipoErrorSemantico=1;
                yyerror($1.lexema);
                return -1;
              }

              if (itemActual->data->categoria==FUNCION){
                error = -1;
                tipoErrorSemantico=9;
                yyerror($1.lexema);
                return -1;
              }
              
              if (itemActual->data->clase!=VECTOR){
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
              $$.es_direccion=1;
              strcpy($$.lexema, $1.lexema);
              $$.tipo = itemActual->data->tipo;
              escribir_elemento_vector(salida, $1.lexema, itemActual->data->tamanio_vector, $1.es_direccion);
              }

              if (itemActual->data->categoria==FUNCION){
              error = -1;
              tipoErrorSemantico=9;
              yyerror($1.lexema);
              return -1;
            }
            if (itemActual->data->clase!=VECTOR){
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
            $$.es_direccion=1;
            strcpy($$.lexema, $1.lexema);
            $$.tipo = itemActual->data->tipo;
            escribir_elemento_vector(salida, $1.lexema, itemActual->data->tamanio_vector, $1.es_direccion);
          }
          fprintf(salida, ";R48:\t<elemento_vector> ::= TOK_IDENTIFICADOR[<exp>]\n");
        }

condicional: if_exp_sentencias
        {
          ifthenelse_fin(salida, $1.etiqueta);
          fprintf(salida, ";R50:\t<condicional> ::= if (<exp>) {<sentencias>}\n");
        }
        | if_exp_sentencias TOK_ELSE TOK_LLAVEIZQUIERDA sentencias TOK_LLAVEDERECHA
        {
          ifthenelse_fin(salida, $1.etiqueta);
          fprintf(salida, ";R51:\t<condicional> ::= if (<exp>) {<sentencias>} then {<sentencias>}\n");
        }


if_exp: TOK_IF TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA
        {

          if($3.tipo != BOOLEAN){
            error = -1;
            tipoErrorSemantico = 5;
            yyerror($3.lexema);
            return -1;
          }
          else {
            $$.etiqueta = etiqueta++;
            ifthen_inicio(salida, $3.es_direccion?1:0, $$.etiqueta);
          }
        }

if_exp_sentencias: if_exp sentencias TOK_LLAVEDERECHA
        {
          $$.etiqueta = $1.etiqueta;
          ifthenelse_fin_then(salida, $1.etiqueta);
        }

bucle: while_exp_sentencias
        {
          fprintf(salida, ";R52:\t<bucle> ::= while (<exp>) {<sentencias>}\n");
        }

while_exp_sentencias: while_exp sentencias TOK_LLAVEDERECHA
        {
          $$.etiqueta = $1.etiqueta;
          while_fin(salida, $1.etiqueta);
        }

while_exp: while TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO TOK_LLAVEIZQUIERDA
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

          if(tablaActual==tablaGlobal){
            itemActual = buscaElemento(tablaGlobal, $2.lexema);
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
          }

          else{

            itemActual = buscaElemento(tablaLocal, $2.lexema);
            if(!itemActual){
              itemActual = buscaElemento(tablaGlobal, $2.lexema);
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
              escribirIdentificadorLocal (salida, itemActual->data->categoria,num_parametros_actual, itemActual->data->pos_parametro,itemActual->data->pos_variable_local,0);
              escribirScanfFuncion(salida, itemActual->data->tipo);
            }

          }

          
          /*fprintf(salida, ";R54:\t<lectura> ::= scanf <TOK_IDENTIFICADOR>\n");*/
        }
        | TOK_SCANF elemento_vector
        {
          if(categoria_actual==FUNCION){
            asignarElemVec(salida, 1);
          } else{
            asignarElemVec(salida, 0);
          }          
          fprintf(salida, ";R44:\t<asignacion> ::= <elemento_vector> = <exp>\n");
          categoria_actual = 0;
        }

escritura: TOK_PRINTF exp
        {
          fprintf(salida, ";R56:\t<escritura> ::= printf <exp>\n");
        
          if($2.es_direccion){
            if(tablaActual == tablaGlobal){
              itemActual = buscaElemento(tablaGlobal, $2.lexema);
              if(!itemActual){
                error = -1;
                tipoErrorSemantico = 1;
                yyerror($2.lexema);
                return -1;
              }
              escribir(salida, 1, itemActual->data->tipo);
            } 
          
            else
            {
              itemActual = buscaElemento(tablaLocal, $2.lexema);
              if(!itemActual){

                itemActual = buscaElemento(tablaGlobal, $2.lexema);
                if(!itemActual){
                  error = -1;
                  tipoErrorSemantico = 1;
                  yyerror($2.lexema);
                  return -1;
                }
                escribir(salida, 1, itemActual->data->tipo);
              } else{
                escribir(salida, 1, itemActual->data->tipo);
              }
              
            }
            
            
          } else{
            escribir(salida, 0, $2.tipo);
          }
          

        }


retorno_funcion: initretorno exp
        {

          if($2.es_direccion){
            if(tablaLocal==tablaGlobal)
            {
              error=-1;
              tipoErrorSemantico=11;
              yyerror("\n");
              return -1;
            }
            itemActual = buscaElemento(tablaLocal, $2.lexema);
            
            if(itemActual == NULL)
            {
              error=-1;
              tipoErrorSemantico=1;
              yyerror($2.lexema);
              return -1;
            }

            if($2.tipo!=itemActual->data->tipo)
            {
              error=-1;
              tipoErrorSemantico=8;
              yyerror($2.lexema);
              return -1;
            }
            
            
          }
          retornarFuncion(salida, $2.es_direccion);
          retorno = 0;
        }

initretorno: TOK_RETURN
        {
          retorno = 1;
        }



exp: exp TOK_MAS exp
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
        |exp TOK_MENOS exp
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
        |exp TOK_DIVISION exp
        {
          /* Dividimos las dos expresiones */
          if ($1.tipo == BOOLEAN || $3.tipo == BOOLEAN){
            error = -1;
            tipoErrorSemantico = 3;
            yyerror($1.lexema);
            return -1;
          }
          else if($3.valor_entero == 0 && !$3.es_direccion){
            error = -1;
            yyerror("Division entre 0");
            return -1;
          }
          else if($1.tipo == INT || $3.tipo == INT){
            dividir(salida, $1.es_direccion, $3.es_direccion);
            $$.valor_entero = $1.valor_entero / $3.valor_entero;
            $$.tipo = INT;
            $$.es_direccion=0;
          }
        }
        |exp TOK_ASTERISCO exp
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
        |TOK_MENOS exp
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
        |TOK_NOT exp
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
          

          if(tablaActual==tablaGlobal){
            itemActual = buscaElemento(tablaGlobal, $1.lexema);

            /*Si no lo encuentra error*/
            if (itemActual == NULL){
              error=-1;
              tipoErrorSemantico=1;
              yyerror($1.lexema);
              return -1;
            }
            /*Si categoria es funicon error*/
            else if(itemActual->data->categoria == FUNCION){
              error = -1;
              tipoErrorSemantico = 8;
              yyerror($1.lexema);
              return -1;
            }
            /*CORRECTO*/
            else {
              
              $$.tipo = itemActual->data->tipo;
              
              $$.es_direccion = 1;
              $$.valor_entero = $1.valor_entero;
              strcpy($$.lexema, $1.lexema);
              
              categoria_actual = itemActual->data->categoria;




              /* Asignamos valor */
              escribir_operando(salida, $1.lexema, $$.es_direccion);
            }
            /*fprintf(salida, ";R80:\t<exp> ::= <TOK_IDENTIFICADOR>\n");*/
          }



          else{

            itemActual = buscaElemento(tablaLocal, $1.lexema);

            /*Si no lo encuentra error*/
            if (itemActual == NULL){
              itemActual = buscaElemento(tablaGlobal, $1.lexema);

              /*Si no lo encuentra error*/
              if (itemActual == NULL){
                error=-1;
                tipoErrorSemantico=1;
                yyerror($1.lexema);
                return -1;
              }
              /*Si categoria es funicon error*/
              else if(itemActual->data->categoria == FUNCION){
                error = -1;
                tipoErrorSemantico = 8;
                yyerror($1.lexema);
                return -1;
              }
              /*CORRECTO*/
              else {
                $$.tipo = itemActual->data->tipo;
                
                $$.es_direccion = 1;
                $$.valor_entero = $1.valor_entero;
                categoria_actual = itemActual->data->categoria;
                

                /* Asignamos valor */
                escribir_operando(salida, itemActual->lexema, $$.es_direccion);
              }
            }
            /*Si categoria es funicon error*/
            else if(itemActual->data->categoria == FUNCION){
              error = -1;
              tipoErrorSemantico = 8;
              yyerror($1.lexema);
              return -1;
            }
            /*CORRECTO*/
            else {
              $$.tipo = itemActual->data->tipo;
              $$.es_direccion = 1;
              $$.valor_entero = $1.valor_entero;
              categoria_actual = itemActual->data->categoria;


              /* Asignamos valor */
              escribirIdentificadorLocal (salida, itemActual->data->categoria,num_parametros_actual, itemActual->data->pos_parametro,itemActual->data->pos_variable_local,0);
            }
            /*fprintf(salida, ";R80:\t<exp> ::= <TOK_IDENTIFICADOR>\n");*/

          }
        }


        |constante
        {
          $$.tipo = $1.tipo;
          $$.es_direccion = $1.es_direccion;
          fprintf(salida, ";R81:\t<exp> ::= <constante>\n");
        }
        |TOK_PARENTESISIZQUIERDO exp TOK_PARENTESISDERECHO
        {
          /*fprintf(salida, ";R82:\t<exp> ::= (<exp>)\n");*/
          $$.tipo = $2.tipo;
          $$.es_direccion = $2.es_direccion;
        }
        |comparacion
        {
          /*fprintf(salida, ";R83:\t<exp> ::= <comparacion>\n");*/
          $$.tipo = $1.tipo;
          $$.es_direccion = $1.es_direccion;
        }
        |elemento_vector
        {
          $$.tipo = $1.tipo;
          $$.es_direccion = $1.es_direccion;
          fprintf(salida, ";R85:\t<exp> ::= <elemento_vector>\n");
        }
        |llamadaAFuncion TOK_PARENTESISIZQUIERDO lista_expresiones TOK_PARENTESISDERECHO
        {

          itemActual = buscaElemento(tablaGlobal, $1.lexema);
          if(itemActual == NULL)
          {
            error=-1;
            tipoErrorSemantico=1;
            yyerror($1.lexema);
            return -1;
          }
          if(itemActual->data->categoria != FUNCION)
          {
            error=-1;
            tipoErrorSemantico=8;
            yyerror($1.lexema);
            return -1;
          }
          if(itemActual->data->num_parametros != num_parametros_llamada_actual){
            error=-1;
            tipoErrorSemantico=7;
            yyerror($1.lexema);
            return -1;
          }
          
          fprintf(salida, ";R88:\t<exp> ::= <TOK_IDENTIFICADOR> (<lista_expresiones>)\n");
          llamarFuncion(salida, $1.lexema, 1);
          categoria_actual = FUNCION;
          llamada_funcion = 0;
        }


llamadaAFuncion: TOK_IDENTIFICADOR
        {
          itemActual = buscaElemento(tablaGlobal, $1.lexema);
          if(itemActual == NULL)
          {
            error=-1;
            tipoErrorSemantico=1;
            yyerror($1.lexema);
            return -1;
          }
          if(itemActual->data->categoria != FUNCION)
          {
            error=-1;
            tipoErrorSemantico=8;
            yyerror($1.lexema);
            return -1;
          }
          if(llamada_funcion) {
            error = -1;
            tipoErrorSemantico = 12;
            yyerror($1.lexema);
            return -1;
          }
          llamada_funcion = 1;
          num_parametros_llamada_actual=0;
          strcpy($$.lexema,$1.lexema);
          $$.tipo = itemActual->data->tipo;
          
          
        }


lista_expresiones: argumento resto_lista_expresiones
        {
          llamada_funcion = 0;
          num_parametros_llamada_actual++;
        }
        |
        {
          llamada_funcion = 0;
        }

argumento: exp
{
  if($1.es_direccion){
    argumentoFuncionVariable(salida);
  }
}

resto_lista_expresiones: TOK_COMA argumento resto_lista_expresiones
        {
          num_parametros_llamada_actual++;
        }
        |

comparacion: exp TOK_IGUAL exp
        {
          /*fprintf(salida, ";R93:\t<comparacion> ::= <exp> == <exp>\n");*/
          
          igual(salida, $1.es_direccion, $3.es_direccion, etiqueta);
          etiqueta++;
          $$.tipo = BOOLEAN;
          $$.es_direccion = 0;
        }
        |exp TOK_DISTINTO exp
        {
          /*fprintf(salida, ";R94:\t<comparacion> ::= <exp> != <exp>\n");*/
          
          distinto(salida, $1.es_direccion, $3.es_direccion, etiqueta);
          etiqueta++;
          $$.tipo = BOOLEAN;
          $$.es_direccion = 0;
        }
        |exp TOK_MENORIGUAL exp
        {
          /*fprintf(salida, ";R95:\t<comparacion> ::= <exp> <= <exp>\n");*/
          if (($1.tipo == INT) && ($3.tipo == INT)){
              menor_igual(salida, $1.es_direccion, $3.es_direccion, etiqueta);
              etiqueta++;
              $$.tipo = BOOLEAN;
              $$.es_direccion = 0;
          }else
          {
            error=-1;
            tipoErrorSemantico=3;
            yyerror("\n");
            return -1;
          }
        }
        |exp TOK_MAYORIGUAL exp
        {
          /*fprintf(salida, ";R96:\t<comparacion> ::= <exp> >= <exp>\n");*/
          if (($1.tipo == INT) && ($3.tipo == INT)){
              mayor_igual(salida, $1.es_direccion, $3.es_direccion, etiqueta);
              etiqueta++;
              $$.tipo = BOOLEAN;
              $$.es_direccion = 0;
          } else
          {
            error=-1;
            tipoErrorSemantico=3;
            yyerror("\n");
            return -1;
          }
        }
        |exp TOK_MENOR exp
        {
          /*fprintf(salida, ";R97:\t<comparacion> ::= <exp> < <exp>\n");*/
          if (($1.tipo == INT) && ($3.tipo == INT)){
              menor(salida, $1.es_direccion, $3.es_direccion, etiqueta);
              etiqueta++;
              $$.tipo = BOOLEAN;
              $$.es_direccion = 0;
          } else
          {
            error=-1;
            tipoErrorSemantico=3;
            yyerror("\n");
            return -1;
          }
        }
        |exp TOK_MAYOR exp
        {
          /*fprintf(salida, ";R98:\t<comparacion> ::= <exp> > <exp>\n");*/
          if (($1.tipo == INT) && ($3.tipo == INT)){
              mayor(salida, $1.es_direccion, $3.es_direccion, etiqueta);
              etiqueta++;
              $$.tipo = BOOLEAN;
              $$.es_direccion = 0;
          } else
          {
            error=-1;
            tipoErrorSemantico=3;
            yyerror("\n");
            return -1;
          }
        }

constante: constante_logica
        {
          clase_actual = ESCALAR;
          categoria_actual = VARIABLE;
          $$.tipo = $1.tipo;
          $$.es_direccion = $1.es_direccion;
          
        }
        | constante_entera
        {
          clase_actual = ESCALAR;
          categoria_actual = VARIABLE;
          $$.tipo = $1.tipo;
          $$.es_direccion = $1.es_direccion;
        }

constante_logica: TOK_TRUE
        {
          $$.tipo = BOOLEAN;
          $$.valor_entero = 1;
          $$.es_direccion = 0;
          
          escribir_operando(salida, "1", $$.es_direccion);
        }
        |TOK_FALSE
        {
          $$.tipo = BOOLEAN;
          $$.es_direccion = 0;
          escribir_operando(salida, "0", $$.es_direccion);
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
          if(tablaActual == tablaGlobal)
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

          categoria_actual = 0;
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
          fprintf(stderr, "****Error semantico en lin %d: Operacion aritmetica con operandos boolean.\n", linea);
        else if (tipoErrorSemantico==4)
          fprintf(stderr, "****Error semantico en lin %d: Operacion logica con operandos int.\n", linea);
        else if (tipoErrorSemantico==5)
          fprintf(stderr, "****Error semantico en lin %d: Condicional con condicion de tipo int.\n", linea);
        else if (tipoErrorSemantico==6)
          fprintf(stderr, "****Error semantico en lin %d: Bucle con condicion de tipo int.\n", linea);
        else if (tipoErrorSemantico==7)
          fprintf(stderr, "****Error semantico en lin %d: Numero incorrecto de parametros en llamada a funcion.\n", linea);
        else if (tipoErrorSemantico==8)
          fprintf(stderr, "****Error semantico en lin %d: Asignacion incompatible.\n", linea);
        else if (tipoErrorSemantico==9)
          fprintf(stderr, "****Error semantico en lin %d: Intento de indexacion de una variable que no es de tipo vector.\n", linea);
        else if (tipoErrorSemantico==10)
          fprintf(stderr, "****Error semantico en lin %d: El indice en una operacion de indexacion tiene que ser de tipo entero\n", linea);
        else if (tipoErrorSemantico==11)
          fprintf(stderr, "****Error semantico en lin %d: Sentencia de retorno fuera del cuerpo de una función.\n", linea);
        else if (tipoErrorSemantico==12)
          fprintf(stderr, "****Error semantico en lin %d: No esta permitido el uso de llamadas a funciones como parametros de otras funciones.\n", linea);
        else if (tipoErrorSemantico==13){
          fprintf(stderr, "****Error semantico en lin %d: Declaracion duplicada.\n", linea);
        }
    		else
    			fprintf(stderr,"****Error semantico en lin %d: Funcion <%s> sin sentencia de retorno.\n",linea,perror);
    }
    else if (error == 0){
      fprintf(stderr, "****Error sintactico en [lin %d, col %d]\n", linea, columna-1);
    }
    error = 0;
    fclose(salida);

    liberaTabla(tablaLocal);
    liberaTabla(tablaGlobal);
    error = 0;
}
