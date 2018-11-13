#include<stdio.h>
#include<stdlib.h>
#include "Elemento.h"

Elemento* CriaElemento(char* nome, char* curta, char* longa, int(*animacao)(Elemento*, Elemento*),
					   int tipo, Lista acoes, det detalhe)
{
	Elemento* el = (Elemento*)malloc(sizeof(Elemento));

	el->nome = nome;
	el->curta = curta;
	el->longa = longa;

	el->animacao = animacao;

	el->ativo = el->conhecido = el->visivel = 0; //por padrão

	el->conteudo = CriaLista();
	el->acoes = acoes;
	el->tipo = tipo;
	el->detalhe = detalhe;

	return el;
}

int ComparaElementos(void* a, void*b)
{
	Elemento e1 = *(Elemento *)a, e2 = *(Elemento *)b;

	return (e1.tipo==e2.tipo) && (!strcmp(e1.nome,e2.nome)) && (!strcmp(e1.curta,e2.curta));
}

void ImprimeElCompleta(void* e)
{
	Elemento *e1 = (Elemento *)e;
	char tipo[7];

	if(e1->tipo) {
		strcpy(tipo,"Lugar");
	} else {
		strcpy(tipo,"Objeto");
	}

	printf("Nome:%s\nTipo:%s\nDescrição:\n%s\n",e1->nome,tipo,e1->longa);
}
