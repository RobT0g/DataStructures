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

No* getNoAt(int pos, Lista *lista){
	if(pos > lista->tam){
		printf("Erro o item não está na lista!");
	} else {
		No *item = lista->ini;
		for(int i = 0; i < pos; i++){
			item = item->prox;
		}
		return item;
	}
}

int getInfoAt(int pos, Lista *lista){
	return getNoAt(pos, lista)->valor;
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
	if(lista->ini == NULL){
		addNoIni(valor, lista);
	} else {
		No *no = criarNo(valor);
		lista->fim->prox = no;
		lista->fim = no;
		lista->tam++;
	}
	
}

void addNoAt(int valor, int pos, Lista* lista){
	No *no = criarNo(valor);
	if(pos > lista->tam || pos < 0){
		printf("ERRO!! Não há essa pos na lista!");
	} else {
		No* ant = getNoAt(pos-1, lista);
		printf("\n%d - \n", ant->valor);
		no->prox = ant->prox;
		ant->prox = no;
		lista->tam++;
	}
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
	printf("----------------------\n");
	addNoAt(20, 3, lista);
	addNoAt(21, 2, lista);
	addNoAt(20, 7, lista);
	for(int i = 0; i < lista->tam; i++){
		printf("Item at %d: %d\n", (i+1), getInfoAt(i, lista));
	}
	
	return 0;
}
