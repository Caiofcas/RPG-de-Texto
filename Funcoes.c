#include "Funcoes.h"

int TemFuncao (Elemento * item, func Funcao) {
	// Verifica se a funcao existe na lista de acoes do elemento

	Lista p = item -> acoes;

	while (p != NULL) {

		if (p -> val == Funcao)
			return 1;

		p = p -> prox;
	}

	return 0;
}

int TemOItem (Elemento * item, Elemento * personagem) {
	// Verifica se existe o elemento item no inventario do personagem

	Lista p = personagem -> conteudo;

	while (p != NULL && !ComparaElementos(p -> val, item))
		p = p -> prox;

	if (p == NULL)
		return 0;

	return 1;
}

int Destrancar (Elemento * porta, Elemento * personagem) {
	/* Tenta destrancar a porta, verificando se a chave eh a que abre a porta
	   selecionada pelo jogador.*/

	if (!TemFuncao(porta, Destrancar)) {
		printf("Nao eh possivel fazer isso...\n");
		return 0;
	}

	if (porta -> ativo == 1) {
		printf("Esta porta ja foi aberta!\n");
		return 0;
	}

	Elemento * chave = porta -> detalhe.atributos -> val;
	Elemento * novaSala = porta -> detalhe.atributos -> prox -> val;

	if (TemOItem(chave, personagem)) {
		personagem -> conteudo = RetiraDaLista(personagem -> conteudo, chave, ComparaElementos);
		novaSala -> ativo = 1;
		porta -> ativo = 1;
		printf("%s %s foi aberta!\n", porta -> artigos[0], porta -> nome);
		return 1;
	}

	printf("Voce precisa da chave para abrir %s %s...\n", porta -> artigos[0], porta -> nome);
	return 0;
}

int Pegar (Elemento* obj, Elemento* personagem) {
	//Retira o elemento da sala e coloca no inventario do personagem
	Elemento * sala = personagem -> detalhe.atributos -> val;

	if (obj -> tipo || !TemFuncao(obj, Pegar)) {
		printf("Nao eh possivel fazer isso...\n");
		return 0;
	}

	printf("Voce pegou %c %s\n", obj -> artigos[0][0] + 32, obj -> nome);

	sala -> conteudo = RetiraDaLista(sala -> conteudo, obj, ComparaElementos);
	personagem -> conteudo = InsereLista(personagem -> conteudo, obj);

	return 1;
}

int Inspecionar (Elemento * item, Elemento * personagem) {
	/* Ao inspecionar um item, todo o conteudo que pode estar nele vai
	   para o inventario do personagem */

	Lista p;
    p = item -> conteudo;
    Elemento * q;

    if (!TemFuncao(item, Inspecionar)) {
    	printf("Nao eh possivel fazer isso...\n");
    	return 0;
    }

    if (item -> conhecido == 1) {
    	printf("Voce ja inspecionou %c %s\n", item -> artigos[0][0] + 32, item -> nome);
    	return 0;
    }

    printf("Inspecionando %c %s voce obteve os seguintes itens:\n", item -> artigos[0][0] + 32, item -> nome);

    while (p != NULL) {
    	q = p -> val;
    	printf("%s %s\n", q -> artigos[2], q -> nome);
        personagem -> conteudo = InsereLista(personagem -> conteudo, q);
        item -> conteudo = RetiraDaLista(item -> conteudo, q, ComparaElementos);
        p = p -> prox;
    }

    item -> conhecido = 1;
    return 1;
}

int Destruir (Elemento * item, Elemento * personagem) {
	// Destroi algum elemento que ha na sala, tirando ele da lista de conteudos dela

	if (!TemFuncao(item, Destruir) || !TemOItem(item -> detalhe.atributos -> val, personagem)) {
		printf("Nao eh possivel fazer isso...\n");
		return 0;
	}

	Lista p = item -> conteudo;
	Elemento * local = personagem -> detalhe.atributos -> val;
	Elemento * ferramenta = item -> detalhe.atributos -> val;
	
	local -> conteudo = RetiraDaLista(local -> conteudo, item, ComparaElementos);

	printf("%s %s quebrou, mas %c %s foi destruid%c!\n", 
		ferramenta -> artigos[0], ferramenta -> nome, 
		item -> artigos[0][0] + 32, item -> nome, item -> artigos[0][0] + 32);

	printf("Os seguites itens cairam d%c %s:\n", 
		    item -> artigos[0][0] + 32, item -> nome);

	Elemento * q;

	// Os elementos dentro do item destruido sao dropados no chao da sala.
	while (p != NULL) {
		q = p -> val;
		printf("%s %s\n", q -> artigos[2], q -> nome);
		local -> conteudo = InsereLista(local -> conteudo, q);
		p = p -> prox;
	}

	// Ferramenta usada na detruicao eh quebrada (tirada de seu inventario)
	personagem -> conteudo = RetiraDaLista(personagem -> conteudo, ferramenta, ComparaElementos);

	return 1;
}

int Ir (Elemento * local, Elemento * personagem) {
	// Personagem muda de sala

	Lista objetos;
	Elemento * objeto;

	//Verifica se o local ja foi liberado e se eh mesmo uma sala
	if (local -> ativo == 1 && local -> tipo) {

		if (local -> conhecido == 1) // Se a sala eh nova, descricao longa
			printf("%s\n", local -> curta);

		else {
			objetos = local -> conteudo;
			printf("%s\n", local -> longa);

			while (objetos != NULL) {
				objeto = objetos -> val;
				printf("%s %s\n", objeto -> artigos[2], objeto -> nome);
				objetos = objetos->prox;
			}
			
		}

		personagem -> detalhe.atributos -> val = local;
		local -> conhecido = 1;
		return 1;
	}

	printf("Nao eh possivel fazer isso...\n");
	return 0;
}

int Estripar (Elemento * corpo, Elemento * personagem) {
	// Faz o mesmo que destruir, porem o nome faz mais sentido num corpo hehe
	return Destruir (corpo, personagem);
}