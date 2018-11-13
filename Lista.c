#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

Lista CriaLista()
{
    Lista l;
    l = NULL;
    return l;
}

void DestroiLista(Lista l)
{
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

Lista InsereLista (Lista l, void *novo_val, size_t tam_tipo) 
{
    Lista novo_elo = (Lista) malloc(sizeof(Elo));

    novo_elo->val = malloc(tam_tipo);

    // Esse loop copia (byte por byte) o que está em novo_val
    // para o nosso novo elo da lista
    // P.S: char ocupa 1 byte
    for(int i = 0;i < tam_tipo;i++)
        *(char *)(novo_elo->val + i) = *(char*)(novo_val+i);
    
    //Insere no inicio
    novo_elo->prox = l;
    l = novo_elo;

    return l;
}

void ImprimeLista(Lista l, void(* func_print)(void *), char sep)
{
    Lista p = l;
    while(p != NULL)
    {
        (*func_print)(p->val);
        printf("%c",sep);
        p = p->prox;
    }

}

Lista BuscaNaLista (Lista l, void *val_buscado, int(* func_comp)(void*,void*) )
{
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
    Lista p = l,ant;
    ant = p;
    while(p!=NULL)
    {
        if((*func_comp)(val,p->val))
        {
            if(p == l){
                //Se for o primeiro elemento da lista
                l = p->prox;
            } else {
                ant->prox =  p->prox;
            }
            return p;
        }
        ant = p;
        p = p->prox;
    }

    return NULL;
}