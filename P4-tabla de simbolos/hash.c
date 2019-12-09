#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hash.h"

#define SIZE 100

/*
Struct: dataItem
Descripcion: Elemento de la tabla de simbolos
*/
struct _dataItem
{
   int data;
   char *key;
};

dataItem *tablaGlobal[SIZE];
dataItem **tablaLocal = NULL;

int ambito = 0;
dataItem *dummyItem;

int hashCode(char *key)
{
   int sum = 0;
   int i;
   int length = strlen(key);

   for (i = 0; i < length; i++)
   {
      sum += key[i];
   }
   return sum % SIZE;
}

/*
Funcion: search
Descripcion: Busca un elemento en la tabla hash pasada como argumento
*/
dataItem *search(dataItem **tabla, char *key)
{
   /*get the hash*/
   int hashIndex = hashCode(key);

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

   //get the hash
   int hashIndex = hashCode(key);

   //move in array until an empty or deleted cell
   while (tabla[hashIndex] != NULL && (strcmp(tabla[hashIndex]->key, "") != 0))
   {
      //go to next cell
      ++hashIndex;

      //wrap around the table
      hashIndex %= SIZE;
   }

   tabla[hashIndex] = item;
   return 1;
}

dataItem *delete (dataItem **tabla, dataItem *item)
{
   char *key = item->key;

   //get the hash
   int hashIndex = hashCode(key);

   //move in array until an empty
   while (tabla[hashIndex] != NULL)
   {

      if (strcmp(tabla[hashIndex]->key, key) == 0)
      {
         dataItem *temp = tabla[hashIndex];

         //assign a dummy item at deleted position
         tabla[hashIndex] = dummyItem;
         return temp;
      }

      //go to next cell
      ++hashIndex;

      //wrap around the table
      hashIndex %= SIZE;
   }

   return NULL;
}

void display(dataItem **tabla)
{
   int i = 0;

   for (i = 0; i < SIZE; i++)
   {

      if (tabla[i] != NULL)
      {
         printf(" (%s,%d)", tabla[i]->key, tabla[i]->data);
      }

      else
      {
         printf(" ~~ ");
      }

      if (i % 10 == 0 && i > 0)
      {
         printf("\n");
      }
   }

   printf("\n");
}

void liberaTabla(dataItem **tabla)
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

   for (i = 0; i < len; i < i++)
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

   for (i = 0; i < len; i < i++)
   {
      if (
          i + 5 < len &&
          string[i] == 'c' &&
          string[i + 1] == 'i' &&
          string[i + 2] == 'e' &&
          string[i + 3] == 'r' &&
          string[i + 4] == 'r' &&
          string[i + 5] == 'e'
      )
      {
         return 1;
      }
   }
   return 0;
}

int main()
{
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
            ambito=1;
         } else if (checkCierre(dato)){
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
         } else{
            ambito = 0;
         }
      }
   }

   display(tablaGlobal);
   printf("--------------------------\n");
   display(tablaLocal);
   printf("USOLOCAL: %s-%d\n", usoGlobal("uno")->key, usoGlobal("uno")->data);

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

int declararGlobal(char *id, int desc_id)
{
   return insert(tablaGlobal, id, desc_id);
}

dataItem *usoGlobal(char *id)
{
   return search(tablaGlobal, id);
}

int declararLocal(char *id, int desc_id)
{
   insert(tablaLocal, id, desc_id);
}

dataItem *usoLocal(char *id)
{
   return search(tablaLocal, id);
}


int declararFuncion(char* id, int desc_id){
   int i;
   if(search(tablaGlobal, id) == NULL){
      insert(tablaGlobal, id, desc_id);
      if (tablaLocal!=NULL){
         liberaTabla(tablaLocal);
      }
      tablaLocal = malloc(sizeof(dataItem*) * SIZE);
      for(i=0;i<SIZE;i++){
         tablaLocal[i] = NULL;
      }
      insert(tablaLocal, id, desc_id);

      //INICIALIZA LOCAL
      return 1;
   } else{
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