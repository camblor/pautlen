#include "generacion_omicron.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VARIABLE 1

/*14*/
/* FUNCIÓN PARA PODER HACER EL CÓDIGO MULTIPLATAFORMA U OTROS PARÁMETROS GENERALES TAL VEZ SE PUEDA QUEDAR VACÍA */
void escribir_cabecera_compatibilidad(FILE *fpasm)
{
    fprintf(fpasm, "segment compatibilidad\n");
}

/*13*/
void escribir_subseccion_data(FILE *fpasm)
{
    /*Declaracion del segmento de datos*/
    fprintf(fpasm, "segment .data \n");
    /*Declaracion del error de dividir entre 0*/
    fprintf(fpasm, "err_div0 db \"Error al dividir entre 0\"\n");
}

/*12*/

/*
FUNCIÓN PARA ESCRIBIR EL INICIO DE LA SECCIÓN .bss:
AL MENOS HAY QUE DECLARAR LA VARIABLE AUXILIAR PARA GUARDAR EL PUNTERO DE PILA __esp
*/
void escribir_cabecera_bss(FILE *fpasm)
{

    fprintf(fpasm, "segment .bss \n\t __esp resd 1\n");
}

/*11*/

/* tipo no hace falta porque para nosotros todo es entero en esta versión, se deja por compatibilidad con futuras versiones*/
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

/*10*/

/*
ESCRIBE EL INICIO DE LA SECCIÓN DE CÓDIGO
DECLARACIONES DE FUNCIONES QUE SE TOMARAN DE OTROS MODULOS
DECLARACION DE main COMO ETIQUETA VISIBLE DESDE EL EXTERIOR
*/
void escribir_segmento_codigo(FILE *fpasm)
{

    char cadena[] = "segment .text \n\t global main \n\t extern scan_int print_int scan_float print_boolean \n\t extern print_endofline, print_blank, print_string\n\t extern alfa_malloc, alfa_free, ld_float";
    fprintf(fpasm, cadena);
}

/*9*/

/*
ESCRIBE EL PRINCIPIO DEL CÓDIGO PROPIAMENTE DICHO
ETIQUETA DE INICIO
SALVAGUARDA DEL PUNTERO DE PILA (esp) EN LA VARIABLE A TAL EFECTO (__esp)
*/
void escribir_inicio_main(FILE *fpasm)
{

    fprintf(fpasm, "main:\n\tmov dword [__esp] , esp\n");
}

/*8*/

/*
ESCRITURA DEL FINAL DEL PROGRAMA
GESTIÓN DE ERROR EN TIEMPO DE EJECUCIÓN (DIVISION POR 0)
RESTAURACION DEL PUNTERO DE PILA A PARTIR DE LA VARIABLE __esp
SENTENCIA DE RETORNO DEL PROGRAMA
*/
void escribir_fin(FILE *fpasm)
{

    char cadena[] = "jmp fin\ndivision_cero:\npush dword err_div0\ncall print_string\nadd esp, 4\ncall print_endofline\njmp fin\nfin:\nmov dword esp, [__esp]\nret\n";
    fprintf(fpasm, cadena);
}

/*7*/

/*
SE INTRODUCE EL OPERANDO nombre EN LA PILA
SI ES UNA VARIABLE (es_variable == 1) HAY QUE PRECEDER EL NOMBRE DE _
EN OTRO CASO, SE ESCRIBE TAL CUAL
*/
void escribir_operando(FILE *fpasm, char *nombre, int es_variable)
{

    char *aux = "push dword ";
    char *elem1 = "[_";
    char *elem2 = "]";

    if (!fpasm)
        return;

    if (es_variable == 1)
        fprintf(fpasm, "\tpush dword _%s\n", nombre);
    else
        fprintf(fpasm, "\tpush dword %s\n", nombre);

    return;
}

/*6*/

/*
ESCRIBE EL CÓDIGO PARA REALIZAR UNA ASIGNACIÓN DE LO QUE ESTÉ EN LA CIMA DE LA PILA A LA VARIABLE nombre
SE RECUPERA DE LA PILA LO QUE HAYA POR EJEMPLO EN EL REGISTRO eax
SI es_variable == 0 (ES UN VALOR) DIRECTAMENTE SE ASIGNA A LA VARIABLE _nombre
EN OTRO CASO es_variable == 1 (ES UNA DIRECCIÓN, UN NOMBRE DE VARIABLE) HAY QUE OBTENER SU VALOR DESREFERENCIANDO
EL VALOR ES [eax]
*/
void asignar(FILE *fpasm, char *nombre, int es_variable)
{

    fprintf(fpasm, "pop dword eax\n");

    if (es_variable == 0)
    {
        fprint(fpasm, "\tmov [_%s], eax \n", nombre);
    }
    else
    {
        fprintf(fpasm, "\tmov eax, [eax]\n");
        fprintf(fpasm, "\tmov [_%s], eax\n", nombre)
    }
}

/*5*/

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

/*4*/

/*
GENERA EL CÓDIGO PARA CAMBIAR DE SIGNO LO QUE HAYA EN LA CIMA DE LA PILA
TENIENDO EN CUENTA QUE PUEDE SER UN VALOR INMEDIATO O UNA DIRECCION (VER ASIGNAR)
*/
/*neg (-x) vs no*/
/*imul -> neg*/
void cambiar_signo(FILE *fpasm, int es_variable)
{
    if (es_variable == 1)
    {
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "mov dword eax, [eax]"\n);
        fprintf(fpasm, "imul eax, -1\n");
        fprintf(fpasm, "push eax\n");
    }
    else
    {
        fprintf(fpasm, "pop dword eax\n");
        fprintf(fpasm, "imul eax, -1\n");
        fprintf(fpasm, "push eax\n");
    }
}

/*3*/

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

    fprintf(fpasm, "\tcmp eax, 0\nje _uno\npush dword 0\njmp _fin_not\nuno: push dword 1\nfin_not:\n");

    if (es_variable == VARIABLE)
    {
        fprintf(fpasm, "\tcmp eax, 0\nje _uno\npush dword 0\njmp _fin_not\n\n_uno:\npush dword 1\n\n_fin_not:\n");
    }
    else
    {
        fprintf(fpasm, "\tmov eax, [eax]\n\ncmp eax, 0\nje _uno\n\nmov eax, 0\njmp _fin_not\n\n_uno:\nmov eax, 1\n\n_fin_not:\npush eax\n")
    }
}

/*2*/

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
    fprintf(fpasm, "jg mayor\n");
    fprintf(fpasm, "push dword 0\n");
    fprintf(fpasm, "mayor:\n");
    fprintf(fpasm, "push dword 1\n");
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

    fprintf(fpasm, "\tPUSH DWORD _%s\n", nombre);
    if (tipo == ENTERO)
    {
        fprintf(fpasm, "\tCALL scan_int\n");
    }
    else if (tipo == BOOLEANO)
    {
        fprintf(fpasm, "\tCALL scan_boolean\n");
    }
    fprintf(fpasm, "\tADD esp, 4\n");
}

/*
GENERA EL CÓDIGO PARA ESCRIBIR POR PANTALLA LO QUE HAYA EN LA CIMA DE LA PILA
TENIENDO EN CUENTA QUE PUEDE SER UN VALOR INMEDIATO (es_referncia == 0) O UNA
DIRECCION (es_variable == 1) Y QUE HAY QUE LLAMAR A LA CORRESPONDIENTE
FUNCIÓN DE ALFALIB (print_int O print_boolean) DEPENDIENTO DEL TIPO (tipo == BOOLEANO
O ENTERO )
*/
void escribir(FILE *fpasm, int es_variable, int tipo)
{

    if (!fpasm)
        return;

    if (es_variable == 1)
    {
        fprintf(fpasm, "\tPOP DWORD eax\n");
        fprintf(fpasm, "\tMOV eax, [eax]\n");
        fprintf(fpasm, "\tPUSH DWORD eax\n");
    }
    if (tipo == ENTERO)
    {
        fprintf(fpasm, "\tCALL print_int\n");
    }
    else if (tipo == BOOLEANO)
    {
        fprintf(fpasm, "\tCALL print_boolean\n");
    }

    fprintf(fpasm, "\tADD esp, 4\n");
    fprintf(fpasm, "\tCALL print_endofline\n");
}
