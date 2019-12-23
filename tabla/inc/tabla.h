#ifndef HASH_H
#define HASH_H


typedef struct _datainfo {
   int categoria;
   int clase;
   int tipo;
   int tamanio_vector;
   int num_variables_locales;
   int pos_variable_local;
   int num_parametros;
   int pos_parametro;
} datainfo;

typedef struct _dataItem
{
   datainfo *data;
   char *lexema;
} dataItem;




dataItem** tablaInit();
dataItem* buscaElemento(dataItem **tabla, char *lexema);
dataItem* eliminaElemento(dataItem **tabla, dataItem *item);
int insertaElemento(dataItem **tabla, char *lexema, datainfo *data);
void liberaTabla(dataItem **tabla);
int declararGlobal(dataItem** tablaGlobal, char *id, datainfo *desc_id);
dataItem *usoGlobal(dataItem** tablaGlobal, char *id);
int declararLocal(dataItem** tablaLocal, char *id, datainfo *desc_id);
dataItem *usoLocal(dataItem** tablaLocal, char *id);
int tablaDeclararFuncion(dataItem** tablaGlobal, dataItem** tablaLocal, char *id, datainfo *desc_id);
void display(dataItem **tabla);

#endif