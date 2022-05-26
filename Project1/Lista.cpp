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

void Lista::printAll() {
	this->iterate(lista->tam, true);
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
