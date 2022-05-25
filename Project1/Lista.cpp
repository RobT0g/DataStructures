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
	No* no = this->lista->ini;
	No* prox;
	for (int i = 0; i < this->lista->tam; i++) {
		prox = no->prox;
		free(no);
		no = prox;
	}
	free(this->lista);
}

No* Lista::createNo(int valor) {
	No* no1 = (No*)malloc(sizeof(No));
	if (no1 == NULL) {
		printf("ERRO! Faltou memória!");
		return NULL;
	}
	no1->valor = valor;
	return no1;
}

No* Lista::iterate(int pos, bool print) {
	if (pos > this->lista->tam) {
		printf("Erro! Posição não existe na lista!");
		return NULL;
	}
	No* no = this->lista->ini;
	printf("Value at %d: %d;", 0, no->valor);
	for (int i = 0; i < pos; i++) {
		no = no->prox;
		if(print)
			printf("Value at %d: %d;\n", i+1, no->valor);
	}
	return no;
}

No* Lista::getNoAt(int pos) {
	return this->iterate(pos, false);
}

int Lista::getAt(int pos){
	No* no = this->getNoAt(pos);
	if (no == NULL) {
		return NULL;
	}
	return no->valor;
}

void Lista::insert(int valor){
	No* no = this->createNo(valor);
	if (this->lista->ini == NULL) {
		this->lista->fim = this->lista->ini = no;
	}
	else {
		no->prox = this->lista->ini;
		this->lista->ini = no;
	}
	this->lista->tam++;
}

void Lista::push(int valor){
	if (this->lista->ini == NULL) {
		this->insert(valor);
	}
	else {
		No* no = this->createNo(valor);
		lista->fim->prox = no;
		lista->fim = no;
		this->lista->tam++;
	}
}

void Lista::insertAt(int valor, int pos){
	if (pos == 0) {
		this->insert(valor);
	}
	else if (pos == this->lista->tam) {
		this->push(valor);
	}
	else {
		No* no = this->createNo(valor);
		No* prev = this->getNoAt(pos - 1);
		no->prox = prev->prox;
		prev->prox = no;
		this->lista->tam++;
	}
}

void Lista::printAll() {
	this->iterate(this->lista->tam-1, true);
}
