#ifndef HASH_H
#define HASH_H

typedef struct _dataItem
{
   int data;
   char *lexema;
} dataItem;

dataItem** tablaInit();
dataItem* buscaElemento(dataItem **tabla, char *lexema);
dataItem* eliminaElemento(dataItem **tabla, dataItem *item);
int insertaElemento(dataItem **tabla, char *lexema, int data);
void liberaTabla(dataItem **tabla);
int declararGlobal(dataItem** tablaGlobal, char *id, int desc_id);
dataItem *usoGlobal(dataItem** tablaGlobal, char *id);
int declararLocal(dataItem** tablaLocal, char *id, int desc_id);
dataItem *usoLocal(dataItem** tablaLocal, char *id);
int tablaDeclararFuncion(dataItem** tablaGlobal, dataItem** tablaLocal, char *id, int desc_id);
void display(dataItem **tabla);

#endif