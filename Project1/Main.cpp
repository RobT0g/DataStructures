#include <stdio.h>
#include "Lista.h"

int main() {
	Lista list = Lista::Lista();
	list.insertAt(0, 1);
	list.push(11);
	list.insert(10);
	list.insert(12);
	list.insert(13);
	list.push(12);
	list.insertAt(5, 7);
	list.insertAt(9, 3);
	list.printAll();
	list.removeFirst();
	list.removeLast();
	list.removeAt(4);
	list.printAll();
	list.~Lista();
	printf("OK");

	return 0;
}
