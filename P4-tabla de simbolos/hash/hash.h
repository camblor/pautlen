#ifndef HASH_H
#define HASH_H

typedef struct _dataItem dataItem;

int hash(char *key);
dataItem *search(dataItem** tabla, char *key);
void display(dataItem** tabla);
int strsearch(char *string, char character);
int insert(dataItem** tabla, char *key, int data);
int declararGlobal(char* id, int desc_id);
dataItem* usoGlobal(char* id);
int declararLocal(char* id, int desc_id);
dataItem* usoLocal(char* id);
int declararFuncion(char* id, int desc_id);

#endif