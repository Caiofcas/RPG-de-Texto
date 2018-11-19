#include "TabelaSim.h"

typedef union u{
	Lista atributos;
	Lista saidas;
} det;

typedef struct elemento {
	char *nome, *longa, *curta; // Descricoes do elemento

	char **artigos; /* Artigos referente ao nome do elemento
					   0 - Definido direto
					   1 - Definido indireto
					   2 - Indefinido direto
					   3 - Indefinido indireto
					   Usamos apenas o 0 e 2 nesta fase...*/
	
	short int ativo, visivel, conhecido; /* Numeros que indicam se o
											elemento ja esta acessivel no jogo*/
	
	Lista conteudo; // Lista de conteudos dentro do elemento
	
	Lista acoes; // Lista de funcoes executaveis para este elemento
	
	int(*animacao)(struct elemento*, struct elemento*);
	
	det detalhe; //Atributo ou Saidas
	
	int tipo; // 0-objeto 1-lugar

}Elemento;

typedef int (*func)(Elemento*, Elemento*);

Elemento* CriaElemento(char* nome, char* curta, char* longa, func animacao, 
					   int tipo, Lista acoes, det detalhe, char ** artigos);

int ComparaElementos(void* a, void*b);

void ImprimeElCompleta(void* e);