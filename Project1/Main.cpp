#include <stdio.h>
#include "Lista.h"

int main() {
	//Lista list = Lista::Lista();
	int num, pos, opcao;
	do{
		printf("\n---------------------------------------------------\n);
		printf("01 - Imprimir Lista;\n");
		printf("02 - Inserir no inicio;\n");
		printf("03 - Inserir no meio;\n");
		printf("04 - Inserir no fim;\n");
		printf("05 - Remover do inicio;\n");
		printf("06 - Remover do meio;\n");
		printf("07 - Remover do fim;\n");
		printf("08 - Buscar elemento;\n");
		printf("09 - Tamanho da lista;\n");
		printf("0 - Finalizar;\n");
		scanf("%d", &opcao);
		if(opcao > 0 && opcao < 10){
			switch(opcao){
				case 1:
					list.printAll();
					break;
				case 2:
					printf("Insira o valor a ser inserido: ");
					scanf("%d", &num);
					list.insert(num);
					break;
				case 3:
					printf("Insira o valor a ser inserido: ");
					scanf("%d", &num);
					printf("Insira a posição na qual será inserido: ");
					scanf("%d", &pos);
					list.insertAt(num, pos);
					break;
				case 4:
					printf("Insira o valor a ser inserido: ");
					scanf("%d", &num);
					list.push(num);
					break;
				case 5:
					list.removeFirst();
					break;
				case 6:
					printf("Insira a posição na qual será retirado: ");
					scanf("%d", &pos);
					list.removeAt(pos);
					break;
				case 7:
					list.removeLast();
					break;
				case 8:
					printf("Insira o valor a ser buscado: ");
					scanf("%d", &num);
					if(list.inlist(num) != 0)
						printf("O valor está na lista.\n");
					else
						printf("O valor nao esta na lista.\n");
				case 9:
					printf("O tamanho e %d.", list.getTam());
			}
		}
	} while(opcao != 0);

	return 0;
}
