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

int main(){
	Lista* lista = inicializarLista();
	
	return 0;
}
