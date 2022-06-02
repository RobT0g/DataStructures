#pragma once

struct no {
	int valor;
	struct no* ant;
	struct no* prox;
};

struct lista {
	struct no* ini;
	struct no* fim;
	int tam;
};

typedef struct no No;
typedef struct lista List;

class Lista2{
public:
	Lista2();
	~Lista2();
	int getAt(int pos);
	void insert(int valor);
	void push(int valor);
	void insertAt(int valor, int pos);
	void removeFirst();
	void removeLast();
	void removeAt(int pos);
	void printAll();
	No* getFirst();

private:
	List* lista;
	No* createNo(int valor);
	No* iterate(int pos, bool print);
	No* getNoAt(int pos);
};

