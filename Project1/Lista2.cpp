#include "Lista2.h"
#include <stdlib.h>

Lista2::Lista2() {
	this->lista = (List*)malloc(sizeof(List));
	this->lista->ini = this->lista->fim = NULL;
	this->lista->tam = 0;
}
