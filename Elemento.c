#include "Elemento.h"

Elemento* CriaElemento (char * nome, char * curta, char * longa, func animacao,
					   int tipo, Lista acoes, det detalhe, char ** artigos) {
	//Cria o elemento, atribuindo os atributos de acordo com os parametros

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
	el->artigos = artigos;

	return el;
}

int ComparaElementos (void * a, void * b) {
	//Compara alguns atributos dos elementos, para verificar se sao exatamente os mesmos

	Elemento * e1 = a, * e2 = b;

	return (e1 -> tipo == e2 -> tipo) 
			&& (!strcmp(e1 -> nome, e2 -> nome)) 
			&& (!strcmp(e1 -> curta, e2 -> curta));
}

void ImprimeElCompleta (void * e) {
	//Imprime algumas informacoes sobre o Elemento.

	Elemento * e1 = (Elemento *)e;
	char tipo[7];

	if(e1->tipo)
		strcpy(tipo,"Lugar");
	else
		strcpy(tipo,"Objeto");

	printf("Nome:%s\nTipo:%s\nDescrição:\n%s\n",e1 -> nome, tipo, e1 -> longa);
}
