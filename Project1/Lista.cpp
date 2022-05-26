#include "Lista.h"
#include <stdio.h>

Lista::Lista(void){
	this->lista = (List*) malloc(sizeof(Lista));
	if (this->lista == NULL) {
		printf("ERRO! Faltou memória!");
		exit(1);
	}
	this->lista->ini = this->lista->fim = NULL;
	this->lista->tam = 0;
}

Lista::~Lista(void){
	if (this->lista->tam != 0) {
		No* cur = this->lista->ini;
		while (cur) {
			No* next = cur->prox;
			free(cur);
			cur = next;
		}
		this->lista->ini = this->lista->fim = NULL;
		this->lista->tam = 0;
	}
	//free(this->lista);
}

No* Lista::createNo(int valor) {
	No* no = (No*)malloc(sizeof(No));
	if (no == NULL) {
		printf("ERRO! Faltou memória!");
		exit(1);
	}
	no->valor = valor;
	no->prox = NULL;
	return no;
}

No* Lista::iterate(int pos, bool print) {
	if (this->lista->tam == 0 || pos > this->lista->tam) {
		return NULL;
	}
	No* no = lista->ini;
	for (int i = 1; i < pos; i++) {
		if (print)
			printf("Value at %d - %d;\n", i, no->valor);
		no = no->prox;
	}
	if (print)
		printf("Value at %d - %d;\n", pos, no->valor);
	return no;
}

No* Lista::getFirst() {
	return this->lista->ini;
}

No* Lista::getNoAt(int pos) {
	return this->iterate(pos, false);
}

int Lista::getAt(int pos) {
	No* no = this->iterate(pos, false);
	if (no) {
		return no->valor;
	}
	return 0;
}

void Lista::printAll() {
	printf("\n--------------\n");
	this->iterate(lista->tam, true);
	printf("--------------\n");
}

void Lista::insert(int valor) {
	No* no = this->createNo(valor);
	if (lista->ini == NULL) {
		lista->ini = lista->fim = no;
	}else {
		no->prox = lista->ini;
		lista->ini = no;
	}
	lista->tam++;
}

void Lista::push(int valor) {
	if (lista->ini == NULL) {
		this->insert(valor);
	}else {
		No* no = this->createNo(valor);
		lista->fim->prox = no;
		no->prox = NULL;
		lista->fim = no;
		lista->tam++;
	}
}

void Lista::insertAt(int valor, int pos) {
	if (this->lista->tam == 0 || pos == 1)
		this->insert(valor);
	else if (pos == this->lista->tam+1) {
		this->push(valor);
	}
	else if (pos > 0 && pos <= this->lista->tam) {
		No* no = this->getNoAt(pos-1);
		if (no) {
			No* novo = this->createNo(valor);
			novo->prox = no->prox;
			no->prox = novo;
			this->lista->tam++;
		}
	}
	else {
		printf("ERRO! Posição inválida!");
	}
}

void Lista::removeFirst() {
	if (this->lista->tam > 0) {
		No* first = this->lista->ini;
		this->lista->ini = first->prox;
		this->lista->tam--;
		free(first);
		if (this->lista->tam == 0) {
			this->lista->fim = NULL;
		}
	}
	
}

void Lista::removeLast() {
	if (this->lista->tam < 2)
		this->removeFirst();
	else {
		No* prev = this->iterate(this->lista->tam - 1, false);
		No* last = prev->prox;
		prev->prox = NULL;
		this->lista->fim = prev;
		this->lista->tam--;
		free(last);
	}
}

void Lista::removeAt(int pos) {
	if (pos == 1) {
		this->removeFirst();
	}
	else if (pos == this->lista->tam) {
		this->removeLast();
	}
	else if (pos > 1 && pos < this->lista->tam) {
		No* prev = this->iterate(pos - 1, false);
		No* cur = prev->prox;
		prev->prox = cur->prox;
		this->lista->tam--;
		free(cur);
	}
}
