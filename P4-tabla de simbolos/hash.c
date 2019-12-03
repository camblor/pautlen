#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define SIZE 20


/*
Struct: dataItem
Descripcion: Elemento de la tabla de simbolos
*/
struct _dataItem {
   int data;   
   char* key;
};

/*
Struct: tablaSimbolos
Descripcion: tabla de simbolos del compilador
*/

typedef struct _dataItem dataItem;


struct _tablaSimbolos{
   int nElementos;
   dataItem** elementos;
};

typedef struct _tablaSimbolos tablaSimbolos;

 dataItem* hashArray[SIZE]; 
 dataItem* dummyItem;
 dataItem* item;



/*
Funcion: crearTabla()
Descripcion: Crea la tabla de simbolos.
*/
tablaSimbolos* crearTabla(){

   tablaSimbolos* tabla = NULL;

   tabla = malloc(sizeof(tablaSimbolos));
   tabla->nElementos = 0;
   tabla->elementos = NULL;

   return tabla;

}



/*
Funcion: insertarElemento(tablaSimbolos* tabla, void *elemento)
Descripcion: Inserta un elemento en la tabla de simbolos.
TODO: hash al elemento para insertarlo
*/
void insertarElemento(tablaSimbolos* tabla, void *elemento){

   /* Si no hay elementos reserva memoria para el primero*/
   if(tabla->nElementos == 0){
      tabla->nElementos = 1;
      tabla->elementos = malloc(sizeof(dataItem*) * tabla->nElementos);
      if(tabla->elementos == NULL){
         tabla->nElementos = 0;
         fprintf(stderr, "Error de reserva de memoria al insertar elemento.");
         return;
      }
   }

   /* Si ya hay elementos entonces reserva memoria para uno más e insertalo */
   else{
      
      tabla->nElementos++;
      tabla->elementos = realloc(tabla->elementos, sizeof(dataItem*) * tabla->nElementos);

      if(tabla->elementos == NULL){
         tabla->nElementos = 0;
         fprintf(stderr, "Error de reserva de memoria al insertar elemento.");
         return;
      }
   }
}


/*
Funcion: liberaTabla(tablaSimbolos* tabla)
Descripcion: Libera la tabla de simbolos.
*/
void liberaTabla(tablaSimbolos* tablaSim){
   int nElem = tablaSim->nElementos;
   int i;

   for(i=0; i < nElem; i++){
      free(tablaSim->elementos[i]);
   }
   free(tablaSim->elementos);
   free(tablaSim);
}


int hashCode(char* key) {
    int sum = 0;
    int i;
    int length = strlen(key);

    for(i=0; i<length; i++){
        sum += key[i];
    }
   return sum % SIZE;
}

 dataItem *search(char* key) {
   //get the hash 
   int hashIndex = hashCode(key);  
	
   //move in array until an empty 
   while(hashArray[hashIndex] != NULL) {
	
      if( strcmp(hashArray[hashIndex]->key, key) == 0 )
         return hashArray[hashIndex]; 
			
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }        
	
   return NULL;        
}

void insert(char* key,int data) {

   dataItem *item = (dataItem*) malloc(sizeof(dataItem));
   item->data = data;  
   item->key = key;

   if(search(key) != NULL){
       return;
   }

   //get the hash 
   int hashIndex = hashCode(key);
   

   //move in array until an empty or deleted cell
   while(hashArray[hashIndex] != NULL && (strcmp(hashArray[hashIndex]->key, "") != 0)) {
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }
	
   hashArray[hashIndex] = item;
}

dataItem* delete(dataItem* item) {
   char* key = item->key;

   //get the hash 
   int hashIndex = hashCode(key);

   //move in array until an empty
   while(hashArray[hashIndex] != NULL) {
	
      if(strcmp(hashArray[hashIndex]->key, key) == 0) {
         dataItem* temp = hashArray[hashIndex]; 
			
         //assign a dummy item at deleted position
         hashArray[hashIndex] = dummyItem; 
         return temp;
      }
		
      //go to next cell
      ++hashIndex;
		
      //wrap around the table
      hashIndex %= SIZE;
   }      
	
   return NULL;        
}

void display() {
   int i = 0;
	
   for(i = 0; i<SIZE; i++) {
	
      if(hashArray[i] != NULL)
         printf(" (%s,%d)",hashArray[i]->key,hashArray[i]->data);
      else
         printf(" ~~ ");
   }
	
   printf("\n");
}




int main() {


   tablaSimbolos* prueba = NULL;

   dummyItem = ( dataItem*) malloc(sizeof( dataItem));
   dummyItem->data = -1;  
   dummyItem->key = ""; 

   prueba = crearTabla();
   liberaTabla(prueba);

   insert("1", 20);
   insert("2", 70);
   insert("42", 80);
   insert("4", 25);
   insert("12", 44);
   insert("14", 32);
   insert("14", 32);
   insert("14", 33);
   insert("17", 11);
   insert("13", 78);
   insert("37", 97);

   display();
   item = search("37");

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }

   delete(item);
   item = search("37");

   if(item != NULL) {
      printf("Element found: %d\n", item->data);
   } else {
      printf("Element not found\n");
   }
}





/*

DeclararGlobal(id, desc_id):
   if tablasimbolosglobal -> get(id) == NULL:
      tablasimbolosglobal->set(id, desc_id);
      return ok;
   else:
      return error;


UsoGlobal(id):
   dato = tablassimbolosglobal getid
   if dato is null
      return err;
   else:
      return dato;


DeclararLocal(id, dest_id):
   if tablasimboloslocal get id is null
      tablasimboloslocal set id, desc_id
      return ok
   else
      return error 

UsoLocal(id):
   dato = tablasimboloslocal getid;
   if dato == null:
      dato = tablasimbolosglobal set id, descid
      if dato is null:
         return error
      else:
         return dato

declararfuncion(id, desc_id):
   if tablasimbolosglobal getid isnt null:
      return error
   else
      tablasimbolosglobal set id, desc_id
      tablasimboloslocal init
      tablasimboloslocal set id, descid
      return ok;



*/