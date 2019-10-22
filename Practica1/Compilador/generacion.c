#include "generacion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VARIABLE 1
int not = 0;
int getiqueta = -1;
int cimapila = -1;

/*
    CODIGO PARA LA GENERACION DE CABECERAS
*/

/* FUNCIÓN PARA PODER HACER EL CÓDIGO MULTIPLATAFORMA U OTROS PARÁMETROS GENERALES TAL VEZ SE PUEDA QUEDAR VACÍA */
void escribir_cabecera_compatibilidad(FILE *fpasm)
{
    fprintf(fpasm, "segment compatibilidad\n");
}

void escribir_subseccion_data(FILE *fpasm)
{
    /*Declaracion del segmento de datos*/
    fprintf(fpasm, "segment .data \n");
    /*Declaracion del error de dividir entre 0*/
    fprintf(fpasm, "\terr_div0 db \"Error al dividir entre 0\"\n");
}

/*
FUNCIÓN PARA ESCRIBIR EL INICIO DE LA SECCIÓN .bss:
AL MENOS HAY QUE DECLARAR LA VARIABLE AUXILIAR PARA GUARDAR EL PUNTERO DE PILA __esp
*/
void escribir_cabecera_bss(FILE *fpasm)
{

    fprintf(fpasm, "segment .bss \n\t__esp resd 1\n");
}

/* 
tipo no hace falta porque para nosotros todo es entero en esta versión, se deja por compatibilidad con futuras versiones*/
/*
GENERA EL CÓDIGO ASOCIADO EN LA SECCIÓN .bss PARA DECLARAR UNA VARIABLE CON
SU NOMBRE (HAY QUE PRECEDER DE _)
EL TAMANO (1 PARA VARIABLES QUE NO SEAN VECTORES O SU TAMANO EN OTRO CASO
TIPO NOSOTROS USAREMOS ESTE AÑO ENTERO O BOOLEANO
*/
void declarar_variable(FILE *fpasm, char *nombre, int tipo, int tamano)
{
    /*Control de errores*/
    if ((fpasm == NULL) || ((strcmp(nombre, "") == 0) || (nombre == NULL)) || ((tipo != ENTERO) && (tipo != BOOLEANO)) || (tamano <= 0))
    {
        fprintf(stderr, "ERROR EN FUN: declarar_variable\n");
        return;
    }

    fprintf(fpasm, "\t_%s resd %d\n", nombre, tamano);

    return;
}

/*
ESCRIBE EL INICIO DE LA SECCIÓN DE CÓDIGO
DECLARACIONES DE FUNCIONES QUE SE TOMARAN DE OTROS MODULOS
DECLARACION DE main COMO ETIQUETA VISIBLE DESDE EL EXTERIOR
*/
void escribir_segmento_codigo(FILE *fpasm)
{

    fprintf(fpasm, "segment .text\n\tglobal main\n\textern scan_int, print_int, scan_float, scan_boolean, print_boolean\n\textern print_endofline, print_blank, print_string\n\textern alfa_malloc, alfa_free, ld_float\n");
}

/*
    CODIGO PARA LA GENERACION DEL PROGRAMA PRINCIPAL
*/

/*
ESCRIBE EL PRINCIPIO DEL CÓDIGO PROPIAMENTE DICHO
ETIQUETA DE INICIO
SALVAGUARDA DEL PUNTERO DE PILA (esp) EN LA VARIABLE A TAL EFECTO (__esp)
*/
void escribir_inicio_main(FILE *fpasm)
{

    fprintf(fpasm, "main:\n\tmov dword [__esp] , esp\n");
}

/*
ESCRITURA DEL FINAL DEL PROGRAMA
GESTIÓN DE ERROR EN TIEMPO DE EJECUCIÓN (DIVISION POR 0)
RESTAURACION DEL PUNTERO DE PILA A PARTIR DE LA VARIABLE __esp
SENTENCIA DE RETORNO DEL PROGRAMA
*/
void escribir_fin(FILE *fpasm)
{

    fprintf(fpasm, "\tjmp fin\ndivision_cero:\n\tpush dword err_div0\n\tcall print_string\n\tadd esp, 4\n\tcall print_endofline\n\tjmp fin\nfin:\n\tmov dword esp, [__esp]\n\tret\n");
}

/*
    CODIGO PARA LA GENERACION DE OPERACIONES
*/

/*
SE INTRODUCE EL OPERANDO nombre EN LA PILA
SI ES UNA VARIABLE (es_variable == 1) HAY QUE PRECEDER EL NOMBRE DE _
EN OTRO CASO, SE ESCRIBE TAL CUAL
*/
void escribir_operando(FILE *fpasm, char *nombre, int es_variable)
{

    if (!fpasm)
        return;
    printf("entra : %s\n", nombre);
    fprintf(fpasm, ";--------Escribir Operando--------%s:%d\n", nombre, es_variable);

    if (es_variable == VARIABLE)
        fprintf(fpasm, "\tpush dword _%s\n", nombre);
    else
        fprintf(fpasm, "\tpush dword %s\n", nombre);

    /*fprintf(fpasm, ";--------Escrito Operando--------\n");*/
    return;
}

/*
ESCRIBE EL CÓDIGO PARA REALIZAR UNA ASIGNACIÓN DE LO QUE ESTÉ EN LA CIMA DE LA PILA A LA VARIABLE nombre
SE RECUPERA DE LA PILA LO QUE HAYA POR EJEMPLO EN EL REGISTRO eax
SI es_variable == 0 (ES UN VALOR) DIRECTAMENTE SE ASIGNA A LA VARIABLE _nombre
EN OTRO CASO es_variable == 1 (ES UNA DIRECCIÓN, UN NOMBRE DE VARIABLE) HAY QUE OBTENER SU VALOR DESREFERENCIANDO
EL VALOR ES [eax]
*/
void asignar(FILE *fpasm, char *nombre, int es_variable)
{

    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable == 0)
    {
        fprintf(fpasm, "\tmov [_%s], eax \n", nombre);
    }
    else
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
        fprintf(fpasm, "\tmov [_%s], eax\n", nombre);
    }
}

void sumar(FILE *fpasm, int es_variable_1, int es_variable_2)
{
    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable_1 == VARIABLE)
    {
        fprintf(fpasm, "\tmov dword eax, [eax]\n");
    }

    if (es_variable_2 == VARIABLE)
    {
        fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tadd eax, ebx\n");
    fprintf(fpasm, "\tpush dword eax\n");
}

void restar(FILE *fpasm, int es_variable_1, int es_variable_2)
{
    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable_1 == VARIABLE)
    {
        fprintf(fpasm, "\tmov dword eax, [eax]\n");
    }

    if (es_variable_2 == VARIABLE)
    {
        fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tsub eax, ebx\n");
    fprintf(fpasm, "\tpush dword eax\n");
}

void multiplicar(FILE *fpasm, int es_variable_1, int es_variable_2)
{
    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable_1 == VARIABLE)
    {
        fprintf(fpasm, "\tmov dword eax, [eax]\n");
    }

    if (es_variable_2 == VARIABLE)
    {
        fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
    }

    fprintf(fpasm, "\timul ebx\n");
    fprintf(fpasm, "\tpush dword eax\n");
}

void dividir(FILE *fpasm, int es_variable_1, int es_variable_2)
{
    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable_1 == VARIABLE)
    {
        fprintf(fpasm, "\tmov dword eax, [eax]\n");
    }

    if (es_variable_2 == VARIABLE)
    {
        fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tmov dword edx, 0\n");
    fprintf(fpasm, "\tcmp ebx, edx\n");
    fprintf(fpasm, "\tje error_div_cero\n");

    fprintf(fpasm, "\tidiv ebx\n");
    fprintf(fpasm, "\tpush dword eax\n");
}

void o(FILE *fpasm, int es_variable_1, int es_variable_2)
{
    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable_1 == VARIABLE)
    {
        fprintf(fpasm, "\tmov dword eax, [eax]\n");
    }

    if (es_variable_2 == VARIABLE)
    {
        fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tor eax, ebx\n");
    fprintf(fpasm, "\tpush dword eax\n");
}

void y(FILE *fpasm, int es_variable_1, int es_variable_2)
{
    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable_1 == VARIABLE)
    {
        fprintf(fpasm, "\tmov dword eax, [eax]\n");
    }

    if (es_variable_2 == VARIABLE)
    {
        fprintf(fpasm, "\tmov dword ebx, [ebx]\n");
    }

    fprintf(fpasm, "\tand eax, ebx\n");
    fprintf(fpasm, "\tpush dword eax\n");
}

/*
GENERA EL CÓDIGO PARA CAMBIAR DE SIGNO LO QUE HAYA EN LA CIMA DE LA PILA
TENIENDO EN CUENTA QUE PUEDE SER UN VALOR INMEDIATO O UNA DIRECCION (VER ASIGNAR)
*/
void cambiar_signo(FILE *fpasm, int es_variable)
{
    if (es_variable == 1)
    {
        fprintf(fpasm, "\tpop dword eax\n");
        fprintf(fpasm, "\tmov dword eax, [eax]\n");
        fprintf(fpasm, "\timul eax, -1\n");
        fprintf(fpasm, "\tpush eax\n");
    }
    else
    {
        fprintf(fpasm, "\tpop dword eax\n");
        fprintf(fpasm, "\timul eax, -1\n");
        fprintf(fpasm, "\tpush eax\n");
    }
}

/*
GENERA EL CÓDIGO PARA NEGAR COMO VALOR LÓGICO LO QUE HAYA EN LA CIMA DE LA PILA
TENIENDO EN CUENTA QUE PUEDE SER UN VALOR INMEDIATO O UNA DIRECCION (VER ASIGNAR)
COMO ES NECESARIO UTILIZAR ETIQUETAS, SE SUPONE QUE LA VARIABLE cuantos_no ES UN
CONTADOR QUE ASEGURA QUE UTILIZARLO COMO AÑADIDO AL NOMBRE DE LAS ETIQUETAS QUE
USEMOS (POR EJEMPLO cierto: O falso: ) NOS ASEGURARÁ QUE CADA LLAMADA A no
UTILIZA UN JUEGO DE ETIQUETAS ÚNICO
*/
void no(FILE *fpasm, int es_variable, int cuantos_no)
{
    char eax[6] = "";
    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable == 0)
        fprintf(fpasm, "\tcmp dword %s, 0\n", strcpy(eax, "eax"));
    else
        fprintf(fpasm, "\tcmp dword %s, 0\n", strcpy(eax, "[eax]"));

    fprintf(fpasm, "\tje no_es0_%d\n", cuantos_no);

    fprintf(fpasm, "\tcmp dword %s, 1\n", eax);
    fprintf(fpasm, "\tje no_es1_%d\n", cuantos_no);

    fprintf(fpasm, "\tjmp no_fin_%d\n", cuantos_no);
    fprintf(fpasm, "\tno_es0_%d:\n", cuantos_no);

    fprintf(fpasm, "\tpush dword 1\n");
    fprintf(fpasm, "\tjmp no_fin_%d\n", cuantos_no);
    fprintf(fpasm, "\tno_es1_%d:\n", cuantos_no);
    fprintf(fpasm, "\tpush dword 0\n");
    fprintf(fpasm, "\tno_fin_%d:\n", cuantos_no);
}

/*
GENERA EL CÓDIGO PARA COMPARAR SI LO QUE HAY EN LAS DOS PRIMERAS (DESDE LA CIMA)
POSICIONES DE LA PILA ES IGUAL, TENIENDO EN CUENTA QUE HAY QUE INDICAR SI SON DIRECCIONES O NO
*/
void igual(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    fprintf(fpasm, "pop dword eax\n");
    fprintf(fpasm, " pop dword ebx\n");

    if (es_variable1 == VARIABLE)
    { /* Si es variable es = 1 */
        fprintf(fpasm, "mov dword eax, [eax]");
    }

    if (es_variable2 == VARIABLE)
    { /* Si es variable es = 1 */
        fprintf(fpasm, "mov dword ebx, [ebx]");
    }

    fprintf(fpasm, "cmp eax, ebx\n");
    fprintf(fpasm, "je igual\n");
    fprintf(fpasm, "push dword 0\n");
    fprintf(fpasm, "igual:\n");
    fprintf(fpasm, "push dword 1\n");
}

/*
GENERA EL CÓDIGO PARA COMPARAR SI LO QUE HAY EN LAS DOS PRIMERAS (DESDE LA CIMA)
POSICIONES DE LA PILA ES DISTINTO, TENIENDO EN CUENTA QUE HAY QUE INDICAR SI SON
DIRECCIONES O NO
*/
void distinto(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    fprintf(fpasm, "pop dword eax\n");
    fprintf(fpasm, " pop dword ebx\n");

    if (es_variable1 == VARIABLE)
    { /* Si es variable es = 1 */
        fprintf(fpasm, "mov dword eax, [eax]");
    }

    if (es_variable2 == VARIABLE)
    { /* Si es variable es = 1 */
        fprintf(fpasm, "mov dword ebx, [ebx]");
    }

    fprintf(fpasm, "cmp eax, ebx\n");
    fprintf(fpasm, "jne distinto\n");
    fprintf(fpasm, "push dword 0\n");
    fprintf(fpasm, "distinto:\n");
    fprintf(fpasm, "push dword 1\n");
}

/*
GENERA EL CÓDIGO PARA COMPARAR SI LO QUE HAY EN LA PRIMERA POSICION DE LA PILA
ES MENOR O IGUAL A LA SEGUNDA POSICION, TENIENDO EN CUENTA QUE HAY QUE INDICAR
SI SON DIRECCIONES O NO
*/
void menor_igual(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    fprintf(fpasm, "pop dword eax\n");
    fprintf(fpasm, " pop dword ebx\n");

    if (es_variable1 == VARIABLE)
    { /* Si es variable es = 1 */
        fprintf(fpasm, "mov dword eax, [eax]");
    }

    if (es_variable2 == VARIABLE)
    { /* Si es variable es = 1 */
        fprintf(fpasm, "mov dword ebx, [ebx]");
    }

    fprintf(fpasm, "cmp eax, ebx\n");
    fprintf(fpasm, "jle menor_igual\n");
    fprintf(fpasm, "push dword 0\n");
    fprintf(fpasm, "menor_igual:\n");
    fprintf(fpasm, "push dword 1\n");
}

/*
GENERA EL CÓDIGO PARA COMPARAR SI LO QUE HAY EN LA PRIMERA POSICION DE LA PILA
ES MAYOR O IGUAL A LA SEGUNDA POSICION, TENIENDO EN CUENTA QUE HAY QUE INDICAR
SI SON DIRECCIONES O NO
*/
void mayor_igual(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    fprintf(fpasm, "pop dword eax\n");
    fprintf(fpasm, " pop dword ebx\n");

    if (es_variable1 == VARIABLE)
    { /* Si es variable es = 1 */
        fprintf(fpasm, "mov dword eax, [eax]");
    }

    if (es_variable2 == VARIABLE)
    { /* Si es variable es = 1 */
        fprintf(fpasm, "mov dword ebx, [ebx]");
    }

    fprintf(fpasm, "cmp eax, ebx\n");
    fprintf(fpasm, "jge mayor_igual\n");
    fprintf(fpasm, "push dword 0\n");
    fprintf(fpasm, "mayor_igual:\n");
    fprintf(fpasm, "push dword 1\n");
}

/*
GENERA EL CÓDIGO PARA COMPARAR SI LO QUE HAY EN LA PRIMERA POSICION DE LA PILA
ES MENOR A LA SEGUNDA POSICION, TENIENDO EN CUENTA QUE HAY QUE INDICAR
SI SON DIRECCIONES O NO
*/
void menor(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    fprintf(fpasm, "pop dword eax\n");
    fprintf(fpasm, " pop dword ebx\n");

    if (es_variable1 == VARIABLE)
    { /* Si es variable es = 1 */
        fprintf(fpasm, "mov dword eax, [eax]");
    }

    if (es_variable2 == VARIABLE)
    { /* Si es variable es = 1 */
        fprintf(fpasm, "mov dword ebx, [ebx]");
    }

    fprintf(fpasm, "cmp eax, ebx\n");
    fprintf(fpasm, "jl menor\n");
    fprintf(fpasm, "push dword 0\n");
    fprintf(fpasm, "menor:\n");
    fprintf(fpasm, "push dword 1\n");
}

/*
GENERA EL CÓDIGO PARA COMPARAR SI LO QUE HAY EN LA PRIMERA POSICION DE LA PILA
ES MAYOR A LA SEGUNDA POSICION, TENIENDO EN CUENTA QUE HAY QUE INDICAR
SI SON DIRECCIONES O NO
*/
void mayor(FILE *fpasm, int es_variable1, int es_variable2, int etiqueta)
{
    fprintf(fpasm, "\tpop dword edx\n");
    if (es_variable2 == VARIABLE)
    { /* Si es variable es = 1 */
        fprintf(fpasm, "\tmov dword edx, [edx]\n");
    }

    fprintf(fpasm, "\tpop dword eax\n");

    if (es_variable1 == VARIABLE)
    { /* Si es variable es = 1 */
        fprintf(fpasm, "\tmov dword eax, [eax]\n");
    }

    fprintf(fpasm, "\tcmp eax, edx\n");
    fprintf(fpasm, "\tjg mayor%d\n", etiqueta);
    fprintf(fpasm, "\tpush dword 0\n");
    fprintf(fpasm, "\tjmp fin_mayor%d\n", etiqueta);
    fprintf(fpasm, "mayor%d:\n", etiqueta);
    fprintf(fpasm, "\tpush dword 1\n");
    fprintf(fpasm, "fin_mayor%d:\n", etiqueta);
}

/*1*/

/*
GENERA EL CÓDIGO PARA LEER UNA VARIABLE DE NOMBRE nombre Y TIPO tipo (ESTE
AÑO SÓLO USAREMOS ENTERO Y BOOLEANO) DE CONSOLA LLAMANDO A LAS CORRESPONDIENTES
FUNCIONES DE ALFALIB (scan_int Y scan_boolean)
*/
void leer(FILE *fpasm, char *nombre, int tipo)
{

    if (!fpasm || !nombre)
        return;

    fprintf(fpasm, "\tpush dword _%s\n", nombre);
    if (tipo == ENTERO)
    {
        fprintf(fpasm, "\tcall scan_int\n");
    }
    else if (tipo == BOOLEANO)
    {
        fprintf(fpasm, "\tcall scan_boolean\n");
    }
    fprintf(fpasm, "\tadd esp, 4\n");
}

/*
GENERA EL CÓDIGO PARA ESCRIBIR POR PANTALLA LO QUE HAYA EN LA CIMA DE LA PILA
TENIENDO EN CUENTA QUE PUEDE SER UN VALOR INMEDIATO (es_referncia == 0) O UNA
DIRECCION (es_variable == 1) Y QUE HAY QUE LLAMAR A LA CORRESPONDIENTE
FUNCIÓN DE ALFALIB (print_int O print_boolean) DEPENDIENTO DEL TIPO (tipo == BOOLEANO
O ENTERO )
*/

/*
  mov eax, 0xDEADBEEF
  push eax
  push message
  call printf
  add esp, 8
*/



void escribir(FILE *fpasm, int es_variable, int tipo)
{

    if (!fpasm)
        return;

    if (es_variable == 1)
    {
        fprintf(fpasm, "\tpop dword eax\n");
        fprintf(fpasm, "\tmov eax, [eax]\n");
        fprintf(fpasm, "\tpush dword eax\n");
    }

    if (tipo == ENTERO)
    {
        fprintf(fpasm, "\tcall print_int\n");
    }
    else if (tipo == BOOLEANO)
    {
        fprintf(fpasm, "\tcall print_boolean\n");
    }

    fprintf(fpasm, "\tadd esp, 4\n");
    fprintf(fpasm, "\tcall print_endofline\n");
}

void declararFuncion(FILE *fd_asm, char *nombre_funcion, int num_var_loc)
{
    if (!fd_asm || !nombre_funcion)
        return;

    fprintf(fd_asm, "\t_%s:\n", nombre_funcion);
    fprintf(fd_asm, "\tpush ebp\n");
    fprintf(fd_asm, "\tmov ebp, esp\n");
    int aux = 4 * num_var_loc;
    fprintf(fd_asm, "\tsub esp, %d\n", aux);
}

void retornarFuncion(FILE *fd_asm, int es_variable)
{
    if (!fd_asm)
        return;

    fprintf(fd_asm, "\tpop eax\n");
    if (es_variable == 1)
        fprintf(fd_asm, "\tmov dword eax, [eax]\n");

    fprintf(fd_asm, "\tmov esp, ebp\n");
    fprintf(fd_asm, "\tpop ebp \n");
    fprintf(fd_asm, "\tret\n");
}

void escribirParametro(FILE *fpasm, int pos_parametro, int num_total_parametros)
{

    if (!fpasm)
        return;
    int aux = 4 * (1 + (num_total_parametros - pos_parametro));
    fprintf(fpasm, "\tlea eax, [ebp +%d]\n", aux);
    fprintf(fpasm, "\tpush dword eax\n");
}

void escribirVariableLocal(FILE *fpasm, int posicion_variable_local)
{

    if (!fpasm)
        return;

    int aux = 4 * posicion_variable_local;
    fprintf(fpasm, "\tlea eax, [ebp - %d]\n", aux);
    fprintf(fpasm, "\tpush dword eax\n");
}

void asignarDestinoEnPila(FILE *fpasm, int es_variable)
{
    if (!fpasm)
        return;

    fprintf(fpasm, "\tpop dword ebx\n");
    fprintf(fpasm, "\tpop dword eax\n");
    if (es_variable == 1)
        fprintf(fpasm, "\tmov dword eax, [eax]\n");

    fprintf(fpasm, "\tmov dword [ebx], eax");
}

void operandoEnPilaAArgumento(FILE *fd_asm, int es_variable)
{
    if (!fd_asm)
        return;

    if (es_variable == 1)
    {
        fprintf(fd_asm, "\tpop eax\n");
        fprintf(fd_asm, "\tmov eax, [eax]\n");
        fprintf(fd_asm, "\tpush eax\n");
    }
}

void llamarFuncion(FILE *fd_asm, char *nombre_funcion, int num_argumentos)
{
    if (!fd_asm || !nombre_funcion)
        return;

    fprintf(fd_asm, "\tcall _%s\n", nombre_funcion);
    fprintf(fd_asm, "\tadd esp, 4*%d\n", num_argumentos);
    fprintf(fd_asm, "\tpush dword eax\n");
}

/* 
    CODIGO PARA LA GENERACION DE CONDICIONALES
*/

void ifthenelse_inicio(FILE *fpasm, int exp_es_variable, int etiqueta)
{
    if (!fpasm)
        return;

    fprintf(fpasm, "\tpop eax\n");
    if (exp_es_variable == 1)
        fprintf(fpasm, "\tmov eax, [eax]\n");
    fprintf(fpasm, "\tcmp eax, 0\n");
    fprintf(fpasm, "\tje near fin_then%d\n", etiqueta);
}

void ifthen_inicio(FILE *fpasm, int exp_es_variable, int etiqueta)
{
    if (!fpasm)
        return;

    fprintf(fpasm, "\tpop eax\n");
    if (exp_es_variable == 1)
        fprintf(fpasm, "\tmov eax, [eax]\n");
    fprintf(fpasm, "cmp eax, 0");
    fprintf(fpasm, "\tje near fin_then%d\n", etiqueta);
}

void ifthen_fin(FILE *fpasm, int etiqueta)
{
    if (!fpasm)
        return;

    fprintf(fpasm, "fin_then%d:\n", etiqueta);
}

void ifthenelse_fin_then(FILE *fpasm, int etiqueta)
{
    if (!fpasm)
        return;

    fprintf(fpasm, "\tjmp near fin_ifelse%d\n", etiqueta);
    fprintf(fpasm, "fin_then%d:\n", etiqueta);
}

void ifthenelse_fin(FILE *fpasm, int etiqueta)
{
    if (!fpasm)
        return;

    fprintf(fpasm, "fin_ifelse%d:\n", etiqueta);
}
