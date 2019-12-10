#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define SIZE 100

/*
Struct: dataItem
Descripcion: Elemento de la tabla de simbolos
*/
typedef struct _dataItem
{
   int data;
   char *key;
} dataItem;

int hash(char *key);
int procesar(char *input);
dataItem *search(dataItem **tabla, char *key);
void display(dataItem **tabla);
int strsearch(char *string, char character);
int insert(dataItem **tabla, char *key, int data);
int declararGlobal(char *id, int desc_id);
dataItem *usoGlobal(char *id);
int declararLocal(char *id, int desc_id);
dataItem *usoLocal(char *id);
int declararFuncion(char *id, int desc_id);

dataItem *tablaGlobal[SIZE];
dataItem **tablaLocal = NULL;

int ambito = 0;
dataItem *dummyItem;

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
dataItem *search(dataItem **tabla, char *key)
{
   /*get the hash*/
   int hashIndex = hash(key);

   /*printf("HASH = (\"%s\", %d)\n", key, hashIndex);*/

   /*move in array until an empty*/
   while (tabla[hashIndex] != NULL)
   {

      if (strcmp(tabla[hashIndex]->key, key) == 0)
         return tabla[hashIndex];

      /*go to next cell*/
      ++hashIndex;

      /*wrap around the table*/
      hashIndex %= SIZE;
   }

   return NULL;
}

/*
Funcion: insert
Descripcion: inserta un elemento en la tabla hash pasada como argumento
*/
int insert(dataItem **tabla, char *key, int data)
{
   int hashIndex;

   dataItem *item = (dataItem *)malloc(sizeof(dataItem));
   item->key = malloc(strlen(key) * sizeof(char) + sizeof(char));
   strcpy(item->key, key);
   item->data = data;

   if (search(tabla, key) != NULL)
   {
      free(item->key);
      free(item);
      return 0;
   }

   /*get the hash*/
   hashIndex = hash(key);

   /*move in array until an empty or deleted cell*/
   while (tabla[hashIndex] != NULL && (strcmp(tabla[hashIndex]->key, "") != 0))
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
Funcion: delete
Descripcion: elimina un elemento en la tabla hash pasada como argumento
*/
dataItem *delete (dataItem **tabla, dataItem *item)
{
   char *key = item->key;

   /*get the hash*/
   int hashIndex = hash(key);

   /*move in array until an empty*/
   while (tabla[hashIndex] != NULL)
   {

      if (strcmp(tabla[hashIndex]->key, key) == 0)
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
         printf(" (%s,%d)", tabla[i]->key, tabla[i]->data);
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
         free(tabla[i]->key);
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

int procesar(char *input)
{
   /*Variables*/
   int i;
   FILE *fp;
   FILE *output;
   char *line = NULL;
   size_t len = 0;
   ssize_t read;
   char *test = NULL;
   char *dato = NULL;
   char *valor = NULL;

   /*Abrimos el fichero*/
   fp = fopen(input, "r");
   if (fp == NULL)
   {
      exit(EXIT_FAILURE);
   }

   output = fopen("output", "w+");
   if(output == NULL){
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
         i = 0;
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
            if (declararFuncion(dato, atoi(valor)) == 1){
               fprintf(output, "%s\n", dato);
               ambito = 3;
            } else{
               fprintf(output, "-1 %s\n", dato);
               ambito = 2;
            }
            
         }
         else if (checkCierre(dato))
         {
            fprintf(output, "CIERRE\n");
            ambito = 2;
         }

         /* Se insertan en la tabla */
         if (ambito == 0)
         {
            if (declararGlobal(dato, atoi(valor)) == 1)
            {
               fprintf(output, "%s\n", dato);
            }
            else
            {
               fprintf(output, "-1 %s\n", dato);
            }
         }
         else if (ambito == 1)
         {
            if (declararLocal(dato, atoi(valor)) == 1)
            {
               fprintf(output, "%s\n", dato);
            }
            else
            {
              fprintf(output, "-1 %s\n", dato);
            }
         }
         else if (ambito == 2)
         {
            ambito = 0;
         } else if (ambito == 3){
            ambito = 1;
         }
         printf("DECLARACION\n");
      }
      /* Si no hay (son solo búsquedas)*/
      else {
         printf("BUSQUEDA\n");
         fprintf(output, "BUSQUEDA\n");

      }
   }

   display(tablaGlobal);
   printf("--------------------------\n");
   display(tablaLocal);

   /*Liberar recursos*/
   fclose(fp);
   fclose(output);
   if (line)
   {
      free(line);
   }
   liberaTablaLocal(tablaLocal);
   liberaTablaGlobal(tablaGlobal);
   exit(EXIT_SUCCESS);
}

/*
Funcion: declararGlobal
Desc: Declara variable global
*/
int declararGlobal(char *id, int desc_id)
{
   return insert(tablaGlobal, id, desc_id);
}

/*
Funcion: usoGlobal
Desc: Usa variable global
*/
dataItem *usoGlobal(char *id)
{
   return search(tablaGlobal, id);
}

/*
Funcion: declararLocal
Desc: Declara variable local
*/
int declararLocal(char *id, int desc_id)
{
   return insert(tablaLocal, id, desc_id);
}

/*
Funcion: usoLocal
Desc: Usa variable local
*/
dataItem *usoLocal(char *id)
{
   return search(tablaLocal, id);
}

/*
Funcion: declararFuncion
Desc: Declara funcion global y abre ambito local
*/
int declararFuncion(char *id, int desc_id)
{
   int i;
   if (search(tablaGlobal, id) == NULL)
   {
      /*Ambito global*/
      insert(tablaGlobal, id, desc_id);
      /*Nuevo ambito local*/
      if (tablaLocal != NULL)
      {
         liberaTablaLocal(tablaLocal);
      }
      tablaLocal = malloc(sizeof(dataItem *) * SIZE);
      if (tablaLocal == NULL){
         fprintf(stderr, "ERROR MEMORIA\n");
         exit(EXIT_FAILURE);
      }
      for (i = 0; i < SIZE; i++)
      {
         tablaLocal[i] = NULL;
      }
      insert(tablaLocal, id, desc_id);
      return 1;
   }
   else
   {
      return 0;
   }
}

/*

declararfuncion(id, desc_id):
   if tablasimbolosglobal getid isnt null:
      return error
   else
      tablasimbolosglobal set id, desc_id
      tablasimboloslocal init
      tablasimboloslocal set id, descid
      return ok;
*/