#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int valor;
	struct no *prox;
} No;

typedef struct lista{
	No *ini;
	No *fim;
	int tam;
} Lista;

int getInfoAt(int pos, Lista *lista){
	if(pos > lista->tam){
		printf("Erro o item não está na lista!");
		return 0;
	}
	No *item = lista->ini;
	for(int i = 0; i < pos; i++){
		item = item->prox;
	}
	return item->valor;
}

Lista* inicializarLista(){
	Lista* lista = (Lista*) malloc(sizeof(Lista));
	if(lista == NULL){
		printf("ERRO!! Sem memória!");
		exit(1);
	}
	lista->ini = lista->fim = NULL;
	lista->tam = 0;
	return lista;
}

No* criarNo(int valor){
	No *novo = (No*) malloc(sizeof(No));
	if(novo == NULL){
		printf("ERRO!! Sem memória!");
		exit(1);
	}
	novo->valor = valor;
	return novo;
}

void addNoIni(int valor, Lista* lista){
	No *no = criarNo(valor);
	no->prox = lista->ini;
	if(lista->ini == NULL){
		lista->fim = no;
	}
	lista->ini = no;
	lista->tam++;
}

void addNoFim(int valor, Lista* lista){
	No *no = criarNo(valor);
	lista->fim->prox = no;
	if(lista->fim == NULL){
		lista->ini = no;
	}
	lista->fim = no;
	lista->tam++;
}

int main(){
	Lista* lista = inicializarLista();
	addNoIni(13, lista);
	addNoIni(0, lista);
	addNoIni(50, lista);
	addNoIni(10, lista);
	addNoFim(11, lista);
	addNoFim(12, lista);
	addNoFim(11, lista);
	addNoFim(12, lista);
	for(int i = 0; i < lista->tam; i++){
		printf("Item at %d: %d\n", (i+1), getInfoAt(i, lista));
	}
	
	return 0;
}
