#include "Lista.h"

typedef struct tabela{
    Lista* indices;
    int tam;
} TabSim;

TabSim CriaTabela(int tam);

int InsereTabSim(TabSim t, char *n, void *val, size_t tam_tipo);

void *BuscaTabSim(TabSim t, char *n, int(*fcomp)(void*,void*) );

int RetiraTabSim(TabSim t, char *n, int(*fcomp)(void*,void*));

void DestroiTabSim(TabSim t);