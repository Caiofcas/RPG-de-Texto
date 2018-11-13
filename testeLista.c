#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void imprimeInteiro(void* i)
{
    printf("%d", *(int *)i);
}

int comparaInteiros(void* a, void*b)
{
    int i_a = *(int*)a, i_b = *(int *) b;
    return i_a == i_b;
}

int main()
{
    //Função que cria a lista;
    Lista l = CriaLista();
    printf("%p\n",l);

    //Impressão de lista vazia:
    printf("\nlista:\n");
    ImprimeLista(l,imprimeInteiro,'\n');

    //Inserção de Elementos
    int a = 20, b = 10, c= -8;
    l = InsereLista(l,&a,sizeof(a));
    printf("\nLista:\n");
    ImprimeLista(l,imprimeInteiro,'\n');

    l = InsereLista(l,&b,sizeof(b));
    l = InsereLista(l,&c,sizeof(c));
    printf("\nLista:\n");
    ImprimeLista(l,imprimeInteiro,'\n');

    //Uma lista maior
    int i;
    for(i = 0;i<100;i++){
        l = InsereLista(l,&i,sizeof(i));
    }
    printf("\nLista com os novos números:\n");
    ImprimeLista(l,imprimeInteiro,' ');

    //Testanto a função de busca
    printf("\n\n");
    
    Elo* el = NULL;
    el = BuscaNaLista(l,&a,comparaInteiros);
    printf("Busca do elemento 20 na lista\n");
    printf("valor retornado pela função : %p\n",el);
    if(el != NULL) printf("Valor encontrado: %d\n",*(int*) el->val);

    a = -1;
    el = BuscaNaLista(l,&a,comparaInteiros); 

    printf("Busca do Elemento -1 na lista:");
    printf("\nValor retornado pela função: %p\n",el);

    //Testando a função de remoção
    a = 65;
    el = RetiraDaLista(l,&a,comparaInteiros);
    printf("%p\t%d\n",el,*(int*)el->val);
    
    printf("\nLista apos a remoção do 65:\n");
    ImprimeLista(l,imprimeInteiro,' ');
    printf("\n");

    for(i = 30;i<51;i++){
        el = RetiraDaLista(l,&i,comparaInteiros);
    }

    printf("\nLista apos a remoção dos números 30-50:\n");
    ImprimeLista(l,imprimeInteiro,' ');
    printf("\n");
    
    //Função Destroi lista
    DestroiLista(l);
    printf("Cabeça da lista : \n%p",l); /*PROBLEMA: Deveria ser NULL*/
}