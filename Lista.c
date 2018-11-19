#include "Lista.h"

Lista CriaLista()
{
    Lista l;
    l = NULL;
    return l;
}

void DestroiLista(Lista l)
{
    //Destroi toda a lista.
    Lista p, q;
	if (l != NULL)
    {
	    p = l;
	    while (p -> prox != NULL)
        {
	    	q = p;
	    	p = p -> prox;
	    	free(q);
	    }
	    free(p);
	}
    free(l);
}

Lista InsereLista (Lista l, void * novo_val) 
{
    // Insere no inicio da lista
    Lista novo_elo = (Lista) malloc(sizeof(Elo));
    novo_elo -> val = novo_val;
    novo_elo -> prox = l;
    return novo_elo;
}

Lista BuscaNaLista (Lista l, void *val_buscado, int(* func_comp)(void*,void*) )
{
    //Busca na lista usando uma funcao de comparacao
    Lista p = l;

    while(p != NULL)
    {

        if( (*func_comp)(val_buscado,p->val) )
            return p;

        p = p->prox;
    }

    return NULL;
}

Lista RetiraDaLista(Lista l, void *val, int(* func_comp)(void*,void*))
{
    //Retira da lista usando uma funcao de comparacao na busca
    Lista p = l, ant;
    ant = p;

    while(p!=NULL)
    {
        
        if((*func_comp)(val,p->val))
        {

            if(p == l){
                //Se for o primeiro elemento da lista
                l = l->prox;
            } 

            else {
                ant->prox = p->prox;
            }

        }

        ant = p;
        p = p->prox;

    }

    return l;
}