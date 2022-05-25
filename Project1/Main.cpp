#include <stdio.h>
#include "Lista.h"

int main() {
	Lista list = Lista::Lista();
	list.insert(10);
	list.insert(16);
	list.insert(20);
	list.push(15);
	list.push(17);
	list.push(1);
	list.push(5);
	list.push(12);
	list.insertAt(19, 2);
	list.insertAt(91, 5);
	list.insertAt(27, 9);
	list.printAll();
	list.~Lista();

	return 0;
}
