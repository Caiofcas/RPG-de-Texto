#include "Elemento.h"

int TemFuncao (Elemento * item, func Funcao);
// Verifica se a funcao existe na lista de acoes do elemento

int TemOItem (Elemento * item, Elemento * personagem);
// Verifica se existe o elemento item no inventario do personagem

int Destrancar(Elemento * porta, Elemento * personagem);
/* Tenta destrancar a porta, verificando se a chave eh a que abre a porta
   selecionada pelo jogador.*/

int Pegar(Elemento * obj, Elemento* personagem);
//Retira o elemento da sala e coloca no inventario do personagem

int Inspecionar (Elemento * item, Elemento * personagem);
/* Ao inspecionar um item, todo o conteudo que pode estar nele vai
   para o inventario do personagem */

int Destruir (Elemento * item, Elemento * personagem);
// Destroi algum elemento que ha na sala, tirando ele da lista de conteudos dela

int Ir (Elemento * local, Elemento * personagem);
// Personagem muda de sala

int Estripar (Elemento * corpo, Elemento * personagem);
// Faz o mesmo que destruir, porem o nome faz mais sentido num corpo hehe