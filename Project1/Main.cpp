#include <stdio.h>
#include "Lista.h"

int main() {
	Lista list = Lista::Lista();
	list.push(11);
	list.insert(10);
	list.insert(12);
	list.insert(13);
	list.push(12);
	list.printAll();
	list.~Lista();
	printf("OK");

	return 0;
}
