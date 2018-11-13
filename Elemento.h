#include <stdio.h>
#include <string.h>
#include "TabelaSim.h"

typedef union u{
	TabSim atributos;
	Lista saudas;
}det;

typedef struct elemento {
	char *nome, *longa, *curta;

	//0-DefDir,1-DefInd,2-IndefDir,3-IndefInd 
	char **artigos;
	
	short int ativo, visivel, conhecido;
	
	Lista conteudo;
	
	Lista acoes;
	
	int(*animacao)(struct elemento*, struct elemento*);
	
	det detalhe;
	
	int tipo; // 0-objeto 1-lugar
}Elemento;

//typedef int(*func)(*struct elemento, *struct elemento) FPTR;

Elemento* CriaElemento(char* nome, char* curta, char* longa, 
					   int(*animacao)(Elemento*, Elemento*),
					   int tipo, Lista acoes, det detalhe);

void ImprimeElCompleta(void*e);

int ComparaElementos(void* a, void*b);