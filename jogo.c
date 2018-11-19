#include "Funcoes.h"



int main()
{
    // Criando alguns atributos para os elementos:
    det detalhes;
    detalhes.atributos = CriaLista();
    detalhes.saidas = CriaLista();

    char ** artigosMasc = malloc(sizeof(char *) * 4);
    artigosMasc[0] = "O";
    artigosMasc[2] = "Um";

    char ** artigosFem = malloc(sizeof(char *) * 4);
    artigosFem[0] = "A";
    artigosFem[2] = "Uma";

    // Criacao da personagem
    Elemento * personagem;

    personagem = CriaElemento("Luke", 
    	"Voce eh o personagem principal do jogo.", 
    	"Seu nome eh Luke, tem 26 anos, trabalha com \
    	programacao e perdeu sua memoria sobre o que \
    	aconteceu na noite passada.", NULL, 0, NULL, detalhes, artigosMasc);
    personagem -> detalhe.atributos = CriaLista();

    //Criacao dos elementos que possuem a funcao Destrancar na lista de acoes

    Lista funcoes;
    funcoes = CriaLista();
	funcoes = InsereLista(funcoes, Destrancar);

	Elemento * porta, * PortaBanheiro, * PortaSalao, 
			   * PortaDaSalaDeEstar, * PortaDaCozinha, * portaprincipal;

	porta = CriaElemento("porta", "Porta de madeira", 
		"Porta de madeira levemente avermelhada. Será que está aberta? ", 
		NULL, 0, funcoes, detalhes, artigosFem);
	porta -> ativo = 0;

	PortaBanheiro = CriaElemento ("porta do banheiro", "Porta do banheiro", 
		"Uma porta de madeira simples com uma tranca, leva ao banheiro", 
		NULL, 0, funcoes, detalhes, artigosFem);
	PortaBanheiro -> ativo = 0;

	PortaSalao = CriaElemento("porta do salao",  "Porta do salao", 
		"Uma porta de madeira simples com uma tranca, leva ao salao", 
		NULL, 0, funcoes, detalhes, artigosFem);
	PortaSalao -> ativo = 0;

	PortaDaSalaDeEstar = CriaElemento("porta da sala de estar", 
		"Porta de madeira escura", 
		"Essa porta pode me levar a algum lugar interessante.\
		 Parece que preciso de uma senha pra destrancar o cadeado dela.", 
		NULL, 0, funcoes, detalhes, artigosFem);
	PortaDaSalaDeEstar -> ativo = 0;

	PortaDaCozinha = CriaElemento("porta da cozinha", "Porta de aluminio", 
		"Essa porta me leva à cozinha. POsso achar coizas muito úteis lá", 
		NULL, 0, funcoes, detalhes, artigosFem);
	PortaDaCozinha -> ativo = 0;

	portaprincipal = CriaElemento("porta principal", 
		"Porta de madeira clara", 
		"Essa é a porta principal. Se conseguir abri-la estarei livre", 
		NULL, 0, funcoes, detalhes, artigosFem);
	portaprincipal -> ativo = 0;
	
	DestroiLista(funcoes);

	//Criacao dos elementos que possuem a funcao Pegar na lista de acoes

	funcoes = CriaLista();
	funcoes = InsereLista(funcoes, Pegar);

	Elemento * chavedaporta, * marreta, * chavedacozinha, * ChaveDoSalao, 
			* estilete, * ChaveBanheiro, * Senha, * Machado, * ChavePorta; 

	chavedaporta = CriaElemento("Chave da Porta", 
		"Chave", 
		"Uma chave de bronze comum. Acho que consigo\
		 usa-la pra Destrancar a porta.",
		NULL, 0, funcoes, detalhes, artigosFem);

	marreta = CriaElemento("Marreta", 
		"Grande marreta, acho que consigo usa-la pra algo.", 
		"Grande marreta e pesada, com cabo de madeira e\
		 levemente enferrujada, talvez consiga usa-la", 
		NULL, 0, funcoes, detalhes, artigosFem);

	chavedacozinha = CriaElemento("Chave da cozinha", 
		"Chave", 
		"Uma chave de bronze comum, parece\
		 que ela abre a porta da cozinha.", 
		NULL, 0, funcoes, detalhes, artigosFem);

	ChaveDoSalao = CriaElemento("Chave do Salao", 
		"Chave",
		"Parece que esta chave abre a porta para o salao principal.", 
		NULL, 0, funcoes, detalhes, artigosFem);

	estilete = CriaElemento("Estilete", 
		"Um estilete, e bem afiado", 
		"Um estilete vermelho, levemente enferrujado,\
		 mas ainda sim bem afiado. Poderia cortar minha pele com facilidade", 
		NULL, 0, funcoes, detalhes, artigosMasc);

	ChaveBanheiro = CriaElemento("Chave do Banheiro", 
		"Chave", 
		"Uma chave, parece servir para Destrancar o banheiro?", 
		NULL, 0, funcoes, detalhes, artigosFem);

	Senha = CriaElemento("Senha da porta", 
		"Um papel com uma senha anotada", 
		"Um papel com uma senha anotada, sera que\
		 consigo Destrancar alguma porta com ela?",
		NULL, 0, funcoes, detalhes, artigosFem);

	Machado = CriaElemento("Machado", 
		"Um machado comum", 
		"Um machado, posso tentar destruir coisas com ele!", 
		NULL, 0, funcoes, detalhes, artigosMasc);

	ChavePorta = CriaElemento("Chave da porta principal", 
		"Chave", 
		"Uma chave, parece servir para destrancar a porta principal!", 
		NULL, 0, funcoes, detalhes, artigosFem);

	DestroiLista(funcoes);

	//Criacao dos elementos que possuem a funcao Inspecionar na lista de acoes

	funcoes = CriaLista();
	funcoes = InsereLista(funcoes, Inspecionar);

	Elemento * cama, * JanelaGradeada, * abajur, * ArmarioCozinha;

	cama = CriaElemento("Cama", 
		"Cama velha. talvez esconda algo.", 
		"Cama de solteiro com madeira envelhecida pelos\
		 cupins. Parece haver algo embaixo dela", 
		NULL, 0, funcoes, detalhes, artigosFem);
	cama -> conhecido = 0;
	cama -> conteudo = CriaLista();
	cama -> conteudo = InsereLista(cama -> conteudo, marreta);

	JanelaGradeada = CriaElemento("Janela Gradeada", 
		"Uma janela com uma grade", 
		"Uma janela com uma grade de metal, talvez eu\
		 deveria inspecionar o que tem do lado de fora?",
		NULL, 0, funcoes, detalhes, artigosFem);
	JanelaGradeada -> conhecido = 0;
	JanelaGradeada -> conteudo = CriaLista();
	JanelaGradeada -> conteudo = InsereLista(JanelaGradeada -> conteudo, ChaveBanheiro);

	abajur = CriaElemento("Abajur", 
		"Abajur sujo. Tem algo brilhante ao lado.", 
		"Oh meu Deus,um corpo!! deve estar aqui há pouco\
		 tempo, ainda não se decompôs. Espero não ser o próximo.", 
		NULL, 0, funcoes, detalhes, artigosMasc);
	abajur -> conhecido = 0;
	abajur -> conteudo = CriaLista();
	abajur -> conteudo = InsereLista(abajur -> conteudo, chavedacozinha);

	ArmarioCozinha = CriaElemento("Armario da cozinha", 
		"Um armario qualquer", 
		"Um armario, talvez devesse inspeciona-lo", 
		NULL, 0, funcoes, detalhes, artigosMasc);
	ArmarioCozinha -> conhecido = 0;
	ArmarioCozinha -> conteudo = CriaLista();
	ArmarioCozinha -> conteudo = InsereLista(ArmarioCozinha -> conteudo, Senha);

	//Criacao dos elementos que possuem a funcao Destruir na lista de acoes

	funcoes = CriaLista();
	funcoes = InsereLista(funcoes, Destruir);

	Elemento * parederachada, * ArmarioSala;

	parederachada = CriaElemento("Parede Rachada", 
		"Se eu tivesse algo para quebrar essa parede...", 
		"Essa parede parece frágil e envelhecida, há\
		 uma grande rachadura. Se eu tivesse algo para\
		 quebra-la e ver o que tem atrás....", 
		NULL, 0, funcoes, detalhes, artigosFem);
	parederachada -> conteudo = CriaLista();
	parederachada -> conteudo = InsereLista(parederachada -> conteudo, chavedaporta);
	parederachada -> detalhe.atributos = CriaLista();
	parederachada -> detalhe.atributos = InsereLista(parederachada -> detalhe.atributos, marreta);

	ArmarioSala = CriaElemento("Armario da sala", 
		"Um armario velho", 
		"Um armario velho trancado, se eu tivesse algo \
		 para destrui-lo talvez eu consiguisse ver o que\
		 tem dentro dele",
		NULL, 0, funcoes, detalhes, artigosMasc);
	ArmarioSala -> conteudo = CriaLista();
	ArmarioSala -> conteudo = InsereLista(ArmarioSala -> conteudo, ChavePorta);
	ArmarioSala -> detalhe.atributos = CriaLista();
	ArmarioSala -> detalhe.atributos = InsereLista(ArmarioSala -> detalhe.atributos, Machado);

	DestroiLista(funcoes);
	//Criacao dos elementos que possuem a funcao Estripar na lista de acoes

	funcoes = CriaLista();
	funcoes = InsereLista(funcoes, Estripar);
	funcoes = InsereLista(funcoes, Destruir);

	Elemento * corpo;

	corpo = CriaElemento("Corpo da Banheira", 
		"Ha um corpo na banheira, morreu não faz muito tempo.", 
		"Oh meu Deus, um corpo!! deve estar aqui há pouco tempo,\
		 ainda não se decompôs. Espero não ser o próximo.", 
		NULL, 0, funcoes, detalhes, artigosMasc);
	corpo -> conteudo = InsereLista(corpo -> conteudo, ChaveDoSalao);
	corpo -> detalhe.atributos = CriaLista();
	corpo -> detalhe.atributos = InsereLista(corpo -> detalhe.atributos, estilete);

	DestroiLista(funcoes);
	//Criacao dos elementos que possuem a funcao Ir na lista de acoes

	funcoes = CriaLista();
	funcoes = InsereLista(funcoes, Ir);

	Elemento * quarto, * corredor, * banheiro, * salao, * cozinha, * sala, *Fora;

	quarto = CriaElemento("Quarto", 
		"Voce esta no quarto", 
		"Um quarto que parece ha tempos desabitado,\
		 ha tracas na parede e muito po espalhado.", 
		NULL, 1, funcoes, detalhes, artigosMasc);
	quarto -> conteudo = InsereLista(quarto -> conteudo, parederachada);
	quarto -> conteudo = InsereLista(quarto -> conteudo, cama);
	quarto -> conteudo = InsereLista(quarto -> conteudo, porta);
	quarto -> ativo = 1;

	corredor = CriaElemento("Corredor", 
		"Voce esta no corredor", 
		"No corredor ha alguns pedacos de carpete faltando\
		 e baratas perambulando, voce acha estranho tudo isso.", 
		NULL, 1, funcoes, detalhes, artigosMasc);
	corredor -> conteudo = InsereLista(corredor -> conteudo, PortaBanheiro);
	corredor -> conteudo = InsereLista(corredor -> conteudo, PortaSalao);
	corredor -> conteudo = InsereLista(corredor -> conteudo, JanelaGradeada);
	corredor -> ativo = 0;

	banheiro = CriaElemento("Banheiro", 
		"Voce esta no banheiro", 
		"Voce avista um corpo morto dentro da banheira com\
		 pontos recem costurados na barriga e fica com vontade de vomitar.", 
		NULL, 1, funcoes, detalhes, artigosMasc);
	banheiro -> conteudo = CriaLista();
	banheiro -> conteudo = InsereLista(banheiro -> conteudo, corpo);
	banheiro -> conteudo = InsereLista(banheiro -> conteudo, estilete);
	banheiro -> ativo = 0;

	salao = CriaElemento("Salao", 
		"Voce esta no salao", 
		"O salao eh muito vazio, ha apenas um abajur, voce\
		 se pergunta como que alguem conseguiria morar ali.", 
		NULL, 1, funcoes, detalhes, artigosMasc);
	salao -> conteudo = InsereLista(salao -> conteudo, abajur);
	salao -> conteudo = InsereLista(salao -> conteudo, PortaDaSalaDeEstar);
	salao -> conteudo = InsereLista(salao -> conteudo, PortaDaCozinha);
	salao -> conteudo = InsereLista(salao -> conteudo, portaprincipal);
	salao -> ativo = 0;

	cozinha = CriaElemento("Cozinha", 
		"Voce esta na cozinha", 
		"Esta toda destruida, de intacto temos apenas um armario.", 
		NULL, 1, funcoes, detalhes, artigosFem);
	cozinha -> conteudo = CriaLista();
	cozinha -> conteudo = InsereLista(cozinha -> conteudo, ArmarioCozinha);
	cozinha -> ativo = 0;

	sala = CriaElemento("Sala", 
		"Voce esta na sala",
		"Ha um machado exposto na parede e um\
		 armario fragil de madeira trancado.", 
		NULL, 1, funcoes, detalhes, artigosFem);
	sala -> conteudo = CriaLista();
	sala -> conteudo = InsereLista(sala -> conteudo, Machado);
	sala -> conteudo = InsereLista(sala -> conteudo, ArmarioSala);
	sala -> ativo = 0;

	Fora = CriaElemento("Lado de fora",
		"Lado de fora da casa",
		"Finalmente voce esta livre desta casa horrenda! Agora fuja para e peca ajuda para alguem!",
		NULL, 1, funcoes, detalhes, artigosMasc);
	Fora -> ativo = 0;

	/* O primeiro elemento dos atributos de cada porta eh a chave
	   que abre ela, e o segundo eh a sala que ela libera quando destrancada. */

	porta -> detalhe.atributos = CriaLista();
	PortaBanheiro -> detalhe.atributos = CriaLista();
	PortaSalao -> detalhe.atributos = CriaLista();
	PortaDaCozinha -> detalhe.atributos = CriaLista();
	PortaDaSalaDeEstar -> detalhe.atributos = CriaLista();
	portaprincipal -> detalhe.atributos = CriaLista();

	porta -> detalhe.atributos = InsereLista(porta -> detalhe.atributos, corredor);
	porta -> detalhe.atributos = InsereLista(porta -> detalhe.atributos, chavedaporta);
	PortaBanheiro -> detalhe.atributos = InsereLista(PortaBanheiro -> detalhe.atributos, banheiro);
	PortaBanheiro -> detalhe.atributos = InsereLista(PortaBanheiro -> detalhe.atributos, ChaveBanheiro);
	PortaSalao -> detalhe.atributos = InsereLista(PortaSalao -> detalhe.atributos, salao);
	PortaSalao -> detalhe.atributos = InsereLista(PortaSalao -> detalhe.atributos, ChaveDoSalao);
	PortaDaCozinha -> detalhe.atributos = InsereLista(PortaDaCozinha -> detalhe.atributos, cozinha);
	PortaDaCozinha -> detalhe.atributos = InsereLista(PortaDaCozinha -> detalhe.atributos, chavedacozinha);
	PortaDaSalaDeEstar -> detalhe.atributos = InsereLista(PortaDaSalaDeEstar -> detalhe.atributos, sala);
	PortaDaSalaDeEstar -> detalhe.atributos = InsereLista(PortaDaSalaDeEstar -> detalhe.atributos, Senha);
	portaprincipal -> detalhe.atributos = InsereLista(portaprincipal -> detalhe.atributos, Fora);
	portaprincipal -> detalhe.atributos = InsereLista(portaprincipal -> detalhe.atributos, ChavePorta);

    // Vetor de comandos
    func * v = malloc(sizeof(func) * 27);
	v[0] = Inspecionar; // Inspeciona a cama e pega a marreta
    v[1] = Destruir; // Destroi a parede rachada
    v[2] = Pegar; // Pega a chave que dropou da parede
    v[3] = Destrancar; // Destranca a porta pro corredor
    v[4] = Ir; // Vai pro corredor
    v[5] = Inspecionar; // Inspeciona a janela e pega a chave do banheiro
    v[6] = Destrancar; // Destranca a porta do banheiro
    v[7] = Ir; // Vai pro banheiro
    v[8] = Pegar; // Pega o estilete
    v[9] = Estripar; // Estripa o corpo na banheira
    v[10] = Pegar; // Pega a chave que esta no corpo, que abre o salao
    v[11] = Ir; // Vai pro corredor
    v[12] = Destrancar; // Abre a porta pro salao
    v[13] = Ir; // Vai pro salao
    v[14] = Inspecionar; // Inspeciona o abajur e pega a chave da cozinha escondida nele
    v[15] = Destrancar; // Destranca a porta da cozinha
    v[16] = Ir; // Vai pra cozinha
    v[17] = Inspecionar; // Inspeciona o armari e pega a chave da sala de estar
    v[18] = Ir; // Vai pro salao
    v[19] = Destrancar; // Destranca a porta pra sala
    v[20] = Ir; // Vai pra sala
    v[21] = Pegar; // Pega o machado na parede
    v[22] = Destruir; // Destroi o armario e obtem a chave da porta principal
    v[23] = Pegar; // Pega a chave da porta principal
    v[24] = Ir; // Vai pro salao
    v[25] = Destrancar; // Destranca a porta principal
    v[26] = Ir; // Sai da casa e o jogo acaba!

    /* Este vetor contem as instrucoes para finalizar o jogo e
       utiliza todas as funcoes possiveis desta versao */

    personagem -> detalhe.atributos = InsereLista(personagem -> detalhe.atributos, quarto); // Inicia a sala inicial
    Lista p;
    int i;

    //Estoria inicial:
    printf("Você acorda sem lembrar de nada do que aconteceu\
    	 na noite passada em um quarto que aparenta ser velho\
    	 e há tempos desabitado com tudo caindo aos pedaços, entra\
    	 em desespero por não saber quem pode ter te colocado\
    	 ali e sabe que precisa fugir o mais rápido possível!\n");

    // Descricao longa do quarto inicial
    printf("%s\n", quarto -> longa);

    Elemento * obj, * local;
    Lista objetos;
    objetos = quarto -> conteudo;

    // Lista dos objetos do quarto
	while (objetos != NULL) {
		obj = objetos -> val;
		printf("%s %s\n", obj -> artigos[2], obj->nome);
		objetos = objetos -> prox;
	}

	// Execucao de cada comando do vetor
    for (i = 0; i < 27; i++) {

    	if (i == 4 || i == 11)
    		v[i](corredor, personagem); // Vai pra corredor

    	else if (i == 7)
    		v[i](banheiro, personagem); // Vai pro banheiro

    	else if (i == 13 || i == 18 || i == 24)
    		v[i](salao, personagem); // Vai pro salao

    	else if (i == 16)
    		v[i](cozinha, personagem); // Vai pra cozinha

    	else if (i == 20)
    		v[i](sala, personagem); // Vai pra sala

    	else if (i == 26)
    		v[i](Fora, personagem); // Sai da casa

    	else {
    		local = personagem -> detalhe.atributos -> val;
    		p = local -> conteudo;

    		// Testa o comando em todos os itens da sala e executa onde for possivel/

    		while (p != NULL && !v[i](p -> val, personagem))
    			p = p -> prox;

    	}

    }

    printf("Parabens, voce escapou da casa!\n");

    // O jogo esta terminado
    return 0;
}