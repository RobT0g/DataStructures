#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"

int main() {
	Lista list = Lista();
	int num, pos, opt;
	do{
		printf("\n---------------------------------------------------\n");
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
		scanf_s("%d", &opt);
		switch (opt) {
			case 1:
				list.printAll();
				break;
			case 2:
				printf("Insira o valor a ser inserido: ");
				scanf_s("%d", &num);
				list.insert(num);
				break;
			case 3:
				printf("Insira o valor a ser inserido: ");
				scanf_s("%d", &num);
				printf("Insira a posição§Ã£o na qual será inserido: ");
				scanf_s("%d", &pos);
				list.insertAt(num, pos);
				break;
			case 4:
				printf("Insira o valor a ser inserido: ");
				scanf_s("%d", &num);
				list.push(num);
				break;
			case 5:
				list.removeFirst();
				break;
			case 6:
				printf("Insira a posição na qual será retirado: ");
				scanf_s("%d", &pos);
				list.removeAt(pos);
				break;
			case 7:
				list.removeLast();
				break;
			case 8:
				printf("Insira o valor a ser buscado: ");
				scanf_s("%d", &num);
				if(list.inlist(num) != 0)
					printf("O valor está na lista.\n");
				else
					printf("O valor nao esta na lista.\n");
				break;
			case 9:
				printf("O tamanho e %d.", list.getTam());
				break;
			case 0:
				printf("Ok! Finalizamos aqui.");
				break;
			default:
				printf("ERRO! Opção inválida.");
		}
	} while(opt != 0);
	
	return 0;
}
