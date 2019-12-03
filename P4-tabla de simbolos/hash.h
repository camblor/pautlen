#ifndef HASH_H
#define HASH_H

typedef struct _dataItem dataItem;
typedef struct _tablaSimbolos tablaSimbolos;


tablaSimbolos* crearTabla();
void insertarElemento(tablaSimbolos*, void*);
void liberaTabla(tablaSimbolos* );

#endif