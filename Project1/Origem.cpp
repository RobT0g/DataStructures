#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int valor;
	struct no* prox;
} No;

typedef struct lista {
	No* ini;
	No* fim;
	int tam;
} Lista;

No* getNoAt(int pos, Lista* lista) {
	if (pos > lista->tam) {
		printf("Erro o item nao está na lista!");
	}
	else {
		No* item = lista->ini;
		for (int i = 0; i < pos; i++) {
			item = item->prox;
		}
		return item;
	}
}

int getInfoAt(int pos, Lista* lista) {
	return getNoAt(pos, lista)->valor;
}

Lista* inicializarLista() {
	Lista* lista = (Lista*)malloc(sizeof(Lista));
	if (lista == NULL) {
		printf("ERRO!! Sem memória!");
		exit(1);
	}
	lista->ini = lista->fim = NULL;
	lista->tam = 0;
	return lista;
}

No* criarNo(int valor) {
	No* novo = (No*)malloc(sizeof(No));
	if (novo == NULL) {
		printf("ERRO!! Sem memória!");
		exit(1);
	}
	novo->valor = valor;
	return novo;
}

void addNoIni(int valor, Lista* lista) {
	No* no = criarNo(valor);
	no->prox = lista->ini;
	if (lista->ini == NULL) {
		lista->fim = no;
	}
	lista->ini = no;
	lista->tam++;
}

void addNoFim(int valor, Lista* lista) {
	if (lista->ini == NULL) {
		addNoIni(valor, lista);
	}
	else {
		No* no = criarNo(valor);
		no->prox = NULL;
		lista->fim->prox = no;
		lista->fim = no;
		lista->tam++;
	}

}

void addNoAt(int valor, int pos, Lista* lista) {
	pos--;
	if (pos > lista->tam || pos < 0) {
		printf("ERRO!! Nao há essa pos na lista!");
	} else if(pos == 0){
		addNoIni(valor, lista);
	} else if (pos == lista->tam){
		addNoFim(valor, lista);
	} else {
		No* no = criarNo(valor);
		No* ant = getNoAt(pos - 1, lista);
		no->prox = ant->prox;
		ant->prox = no;
		lista->tam++;
	}
}

void printar(Lista* lista){
	for(No* no = lista->ini; no != NULL; no = no->prox){
		printf("> %d\n", no->valor);
	}
}

int main() {
	Lista* lista = inicializarLista();
	addNoIni(13, lista); 	//13
	addNoIni(0, lista);  	//0, 13
	addNoIni(50, lista);	//50, 0, 13
	addNoIni(10, lista);	//10, 50, 0, 13
	addNoFim(11, lista);	//10, 50, 0, 13, 11
	addNoFim(12, lista);	//10, 50, 0, 13, 11, 12
	addNoFim(11, lista);	//10, 50, 0, 13, 11, 12, 11
	addNoFim(12, lista);	//10, 50, 0, 13, 11, 12, 11, 12
	addNoAt(20, 3, lista);	//10, 50, 20, 0, 13, 11, 12, 11, 12
	addNoAt(21, 2, lista);	//10, 21, 50, 20, 0, 13, 11, 12, 11, 12
	addNoAt(20, 7, lista);  //10, 21, 50, 20, 0, 13, 20, 11, 12, 11, 12
	printar(lista);
	return 0;
}
