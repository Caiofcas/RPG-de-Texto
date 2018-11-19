#include <stdio.h>
#include <stdlib.h>

#include "TabelaSim.h"

TabSim CriaTabela(int tam){
    int i;
    TabSim Tabela;
    Tabela.indices = malloc(tam*sizeof(Lista));
    Tabela.tam = tam;

    for(i = 0; i< tam; i++)
        Tabela.indices[i] = CriaLista();

    return Tabela;
}

int InsereTabSim(TabSim t, char *n, void *val)
{
    int h = n[0];

    t.indices[h] = InsereLista(t.indices[h],val);

    return t.indices[h] == NULL;
}

void* BuscaTabSim(TabSim t, char* n, int(*fcomp)(void*,void*))
{
    int h = n[0];
    return BuscaNaLista(t.indices[h],n,fcomp);
}

int RetiraTabSim(TabSim t, char *n,int(*fcomp)(void*,void*))
{
    int h = n[0];

    void *el = BuscaNaLista(t.indices[h], n,fcomp);

    el = RetiraDaLista(t.indices[h],el,fcomp);

    return el != NULL;
}

void DestroiTabSim(TabSim t)
{
    for(int i = 0;i<t.tam;i++)
        DestroiLista(t.indices[i]);
    free(t.indices);
}