#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Definição de uma lista de 
//dados Genéricos

typedef struct elo{
    struct elo * prox;
    void * val;   
} Elo;

typedef Elo* Lista;

// Cria e retorna uma lista vazia

Lista CriaLista ();

// Destroi a lista l liberando todos os seus elos

void DestroiLista (Lista l);

// Imprime todos os elementos da Lista l utilizando a 
// funcao passada em funcao_de_print

void ImprimeLista (Lista l, void(* func_print)(void *),char sep);

// Insere no Inicio da Lista l o elemento novo_val

Lista InsereLista (Lista l, void * novo_val);

// Devolve um ponteiro para o Elo onde o val_buscado se encontra
// ou NULL se o val_buscado não estiver na lista

Elo *BuscaNaLista (Lista l, void *val_buscado, int(* func_comp)(void*,void*) );

// Retira da lista l o elo que contém o valor val, devolvendo o elo
// ou NULL se ele não for encontrado

Lista RetiraDaLista (Lista l, void *val, int(* func_comp)(void*,void*));