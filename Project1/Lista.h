#pragma once
#include <stdlib.h>
struct no {
	int valor;
	struct no* prox;
};

struct lista {
	struct no* ini;
	struct no* fim;
	int tam;
};

typedef struct no No;
typedef struct lista List;

class Lista{
public:
	Lista();
	~Lista();
	int getAt(int pos);
	void insert(int valor);
	void push(int valor);
	void insertAt(int valor, int pos);
	void printAll();
	No* getFirst();

private:
	List* lista;
	No* createNo(int valor);
	No* iterate(int pos, bool print);
	No* getNoAt(int pos);
};

