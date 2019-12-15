#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../inc/tabla.h"
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define SIZE 100

/*
Struct: dataItem
Descripcion: Elemento de la tabla de simbolos
*/
struct _dataItem
{
   int data;
   char *lexema;
};

int hash(char *lexema);
void display(dataItem **tabla);
int strsearch(char *string, char character);



int ambito = 0;
dataItem *dummyItem;


/*
Funcion: tablaInit
Desc: Inicializa la tabla de simbolos global
*/
dataItem** tablaInit(){
   dataItem** tablaGlobal = (dataItem**) malloc(sizeof(dataItem*) * SIZE);
   if(tablaGlobal == NULL){
      fprintf(stderr, "Error creacion tabla de simbolos\n");
      return NULL;
   }
   return tablaGlobal;
}

/*
Funcion: hash
Desc: Genera el hash de un string pasado como argumento.
*/
int hash(char *str)
{
   unsigned long hash = 5381;
   int c;
   while ((c = *str++))
   {
      hash = ((hash << 5) + hash) + c;
   }
   return hash % SIZE;
}

/*
Funcion: search
Descripcion: Busca un elemento en la tabla hash pasada como argumento
*/
dataItem *buscaElemento(dataItem **tabla, char *lexema)
{
   /*get the hash*/
   int hashIndex = hash(lexema);

   /*move in array until an empty*/
   while (tabla[hashIndex] != NULL)
   {

      if (strcmp(tabla[hashIndex]->lexema, lexema) == 0)
         return tabla[hashIndex];

      /*go to next cell*/
      ++hashIndex;

      /*wrap around the table*/
      hashIndex %= SIZE;
   }

   return NULL;
}

/*
Funcion: insertaElemento
Descripcion: inserta un elemento en la tabla hash pasada como argumento
*/
int insertaElemento(dataItem **tabla, char *lexema, int data)
{
   int hashIndex;

   dataItem *item = (dataItem *)malloc(sizeof(dataItem));
   item->lexema = malloc(strlen(lexema) * sizeof(char) + sizeof(char));
   strcpy(item->lexema, lexema);
   item->data = data;

   if (buscaElemento(tabla, lexema) != NULL)
   {
      free(item->lexema);
      free(item);
      return 0;
   }

   /*get the hash*/
   hashIndex = hash(lexema);

   /*move in array until an empty or deleted cell*/
   while (tabla[hashIndex] != NULL && (strcmp(tabla[hashIndex]->lexema, "") != 0))
   {
      /*go to next cell*/
      ++hashIndex;

      /*wrap around the table*/
      hashIndex %= SIZE;
   }

   tabla[hashIndex] = item;
   return 1;
}

/*
Funcion: eliminaElemento
Descripcion: elimina un elemento en la tabla hash pasada como argumento
*/
dataItem* eliminaElemento(dataItem **tabla, dataItem *item)
{
   char *lexema = item->lexema;

   /*get the hash*/
   int hashIndex = hash(lexema);

   /*move in array until an empty*/
   while (tabla[hashIndex] != NULL)
   {

      if (strcmp(tabla[hashIndex]->lexema, lexema) == 0)
      {
         dataItem *temp = tabla[hashIndex];

         /*assign a dummy item at deleted position*/
         tabla[hashIndex] = dummyItem;
         return temp;
      }

      /*go to next cell*/
      ++hashIndex;

      /*wrap around the table*/
      hashIndex %= SIZE;
   }

   return NULL;
}

/*
Funcion: display
Descripcion: imprime la tabla hash pasada como argumento
*/
void display(dataItem **tabla)
{
   int i = 0;
   int j = 0;

   for (i = 0; i < SIZE; i++)
   {

      if (tabla[i] != NULL)
      {
         printf(" (%s,%d)", tabla[i]->lexema, tabla[i]->data);
         j++;
      }

      if (j % 10 == 0 && j > 0)
      {
         printf("\n");
      }
   }

   printf("\n");
}

/*
Funcion: liberaTabla
Descripcion: libera la tabla hash pasada como argumento
*/
void liberaTablaGlobal(dataItem **tabla)
{
   int i;

   for (i = 0; i < SIZE; i++)
   {
      if (tabla[i] != NULL)
      {
         free(tabla[i]->lexema);
         free(tabla[i]);
      }
   }
}

/*
Funcion: liberaTabla
Descripcion: libera la tabla hash pasada como argumento
*/
void liberaTablaLocal(dataItem **tabla)
{
   liberaTablaGlobal(tabla);
   free(tabla);
}

int strsearch(char *string, char character)
{
   int len = strlen(string);
   int i;

   for (i = 0; i < len; i++)
   {
      if (string[i] == character)
      {
         return 1;
      }
   }
   return 0;
}

int checkFuncion(char *string)
{
   int len = strlen(string);
   int i;

   for (i = 0; i < len; i++)
   {
      if (
          i + 6 < len &&
          string[i] == 'f' &&
          string[i + 1] == 'u' &&
          string[i + 2] == 'n' &&
          string[i + 3] == 'c' &&
          string[i + 4] == 'i' &&
          string[i + 5] == 'o' &&
          string[i + 6] == 'n')
      {
         return 1;
      }
   }
   return 0;
}

int checkCierre(char *string)
{
   int len = strlen(string);
   int i;

   for (i = 0; i < len; i++)
   {
      if (
          i + 5 < len &&
          string[i] == 'c' &&
          string[i + 1] == 'i' &&
          string[i + 2] == 'e' &&
          string[i + 3] == 'r' &&
          string[i + 4] == 'r' &&
          string[i + 5] == 'e')
      {
         return 1;
      }
   }
   return 0;
}

/*
Funcion: declararGlobal
Desc: Declara variable global
*/
int declararGlobal(dataItem** tablaGlobal, char *id, int desc_id)
{
   return insertaElemento(tablaGlobal, id, desc_id);
}

/*
Funcion: usoGlobal
Desc: Usa variable global
*/
dataItem *usoGlobal(dataItem** tablaGlobal, char *id)
{
   return buscaElemento(tablaGlobal, id);
}

/*
Funcion: declararLocal
Desc: Declara variable local
*/
int declararLocal(dataItem** tablaLocal, char *id, int desc_id)
{
   return insertaElemento(tablaLocal, id, desc_id);
}

/*
Funcion: usoLocal
Desc: Usa variable local
*/
dataItem *usoLocal(dataItem** tablaLocal, char *id)
{
   return buscaElemento(tablaLocal, id);
}

/*
Funcion: declararFuncion
Desc: Declara funcion global y abre ambito local
*/
int tablaDeclararFuncion(dataItem** tablaGlobal, dataItem** tablaLocal, char *id, int desc_id)
{
   int i;
   if (buscaElemento(tablaGlobal, id) == NULL)
   {
      /*Ambito global*/
      insertaElemento(tablaGlobal, id, desc_id);
      /*Nuevo ambito local*/
      if (tablaLocal != NULL)
      {
         liberaTablaLocal(tablaLocal);
      }
      /*Creacion tabla local*/
      tablaLocal = malloc(sizeof(dataItem *) * SIZE);
      if (tablaLocal == NULL)
      {
         fprintf(stderr, "ERROR MEMORIA\n");
         exit(EXIT_FAILURE);
      }
      for (i = 0; i < SIZE; i++)
      {
         tablaLocal[i] = NULL;
      }
      /*Insercion de la propia funcion en la tabla local*/
      insertaElemento(tablaLocal, id, desc_id);
      return 1;
   }
   else
   {
      return 0;
   }
}
