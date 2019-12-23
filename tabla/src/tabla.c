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


struct _info{
   int categoria;
   int clase;
   int tipo;
   int tamano;
};

int hash(char *lexema);

int strsearch(char *string, char character);



int ambito = 0;
dataItem *dummyItem;


/*
Funcion: tablaInit
Desc: Inicializa la tabla de simbolos global
*/
dataItem** tablaInit(){
   int i;
   dataItem** tabla = (dataItem**) malloc(sizeof(dataItem*) * SIZE);
   if(tabla == NULL){
      fprintf(stderr, "Error creacion tabla de simbolos\n");
      return NULL;
   }

   for(i=0;i<SIZE;i++){
      tabla[i] = NULL;
   }
   return tabla;
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

   if (tabla==NULL)
   printf("tabla es NULL");

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
Funcion: vaciar
Descripcion: vacia la tabla hash pasada como argumento
*/
void vaciar(dataItem **tabla)
{
   int i = 0;

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
void liberaTabla(dataItem **tabla)
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
      vaciar(tablaLocal);
      /*Insercion de la propia funcion en la tabla local*/
      insertaElemento(tablaLocal, id, desc_id);
      return 1;
   }
   else
   {
      return 0;
   }
}
