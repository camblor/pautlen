#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hash.h"

#define _GNU_SOURCE
#define SIZE 100

int main()
{
    dataItem *tablaGlobal[SIZE];
    dataItem **tablaLocal = NULL;

    int ambito = 0;
    /*Variables*/
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *test = NULL;
    char *dato = NULL;
    char *valor = NULL;

    /*Abrimos el fichero*/
    fp = fopen("entrada", "r");
    if (fp == NULL)
    {
        exit(EXIT_FAILURE);
    }

    /* Leemos el fichero */
    while ((read = getline(&line, &len, fp)) != -1)
    {

        /* Si en la linea hay un espacio (2 columnas) */
        if (strsearch(line, ' '))
        {
            /* Se sacan ambos valores */
            test = strtok(line, " ");
            int i = 0;
            while (test != NULL)
            {
                if (i == 0)
                {
                    dato = test;
                }
                else
                {
                    valor = test;
                    valor[strlen(valor) - 1] = 0;
                }
                i++;
                test = strtok(NULL, " ");
            }

            /* Se comprueba si es la declaracion de una funcion */

            if (checkFuncion(dato))
            {
                printf("FUNCION\n");
                declararFuncion(dato, atoi(valor));
                ambito = 1;
            }
            else if (checkCierre(dato))
            {
                printf("CIERRE\n");
                ambito = 2;
            }

            /* Se insertan en la tabla */
            if (ambito == 0)
            {
                if (declararGlobal(dato, atoi(valor)) == 1)
                {
                    printf("INSERTADO\n");
                }
                else
                {
                    printf("NO-INSERTADO\n");
                }
            }
            else if (ambito == 1)
            {
                if (declararLocal(dato, atoi(valor)) == 1)
                {
                    printf("INSERTADO\n");
                }
                else
                {
                    printf("NO-INSERTADO\n");
                }
            }
            else
            {
                ambito = 0;
            }
        }
    }

    display(tablaGlobal);
    printf("--------------------------\n");
    display(tablaLocal);

    /*Liberar recursos*/
    fclose(fp);
    if (line)
    {
        free(line);
    }
    liberaTabla(tablaLocal);
    liberaTabla(tablaGlobal);
    exit(EXIT_SUCCESS);
}