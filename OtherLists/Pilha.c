#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int info;
    struct no* prox;
}No;

typedef struct pilha{
    No* inicio;
    No* fim;
    int tamanho;
}Pilha;

Pilha* inicializarpilha(){
    //Alocação de Memória dinâmica para struct pilha
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));
    if(pilha == NULL){ //verifica se memória foi alocada
        printf("ERRO!!\nMemória Indisponível para criar pilha.");
        exit(1);
    }
    pilha->inicio = pilha->fim = NULL;  //inicializa referência para inicio e fim
    pilha->tamanho = 0;  //inicializa o var tamanho da pilha vazia.
    return pilha;
}

No* criarNo(int valor){
    No* novo = (No*) malloc(sizeof(No));
    if(novo == NULL){ //verifica se memória foi alocada
        printf("ERRO!!\nMemória Indisponível para criar Nó.");
        exit(1);
    }
    novo->info = valor;
    return novo;
}

int verificarTamanho(Pilha* pilha){
    return pilha->tamanho;
}

void inserir(Pilha* pilha, int valor){
    No* novo = criarNo(valor);
    if(pilha->tamanho == 0){
        pilha->fim = pilha->inicio = novo;
    } else{
        No* ultimo = pilha->fim;
        ultimo->prox = novo;
        novo->prox = NULL;
        pilha->fim = novo;
    }
    pilha->tamanho++;
}

void imprimir(Pilha* pilha){
    if(pilha->tamanho == 1){
        printf("%d", pilha->inicio->info);
    } else{
        No* no;
        for(no=pilha->inicio; no != NULL; no = no->prox){
            printf("%d", no->info);
            if(no->prox != NULL){
                printf(" --> ");
            }
        }
        printf("\n");
    }
}

void remover(Pilha* pilha){
    if(pilha->tamanho == 0){
        printf("ERRO!!\nLista Vazia.");
        exit(1);
    }
    if(pilha->tamanho == 1){
        No* no = pilha->inicio;
        pilha->inicio = pilha->fim = NULL;
        free(no);
    } else{
        No* anterior = NULL;
        No* ultimo = pilha->inicio;
        int i;
        for(i=1;i<pilha->tamanho;i++){
            anterior = ultimo;
            ultimo = ultimo->prox;
        }
        anterior->prox = NULL;
        free(ultimo);
        pilha->fim = anterior;
    }
    pilha->tamanho--;
}

int buscarElemento(Pilha* pilha, int valor){
    if(pilha->inicio == NULL){
        printf("pilha Vazia.\n");
        return 0;
    }
    No* no;
    for(no=pilha->inicio; no!=NULL; no=no->prox){
        if(no->info == valor){
            return 1;
        }
    }
    return 0;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num, posicao, opcao;
    Pilha* pilha;
    pilha = inicializarpilha();
    do{
        printf("\n--------------------------------------------------------\n");
        printf("01 - Exibir pilha.\n");
        printf("02 - Inserir na pilha (fim)\n");
        printf("03 - Remover da pilha (fim)\n");
        printf("04 - Buscar Elemento\n");
        printf("05 - Tamanho da pilha\n");
        printf("0 - SAIR\n");
        printf("\n--------------------------------------------------------\n");
        scanf("%d",&opcao);
        if(opcao == 1){
            imprimir(pilha);
            
        } else if(opcao == 2){
            printf("Digite o valor que deseja inserir: ");
            scanf("%d",&num);
            inserir(pilha, num);
        }
        else if(opcao == 3){
            remover(pilha);
        }
        else if(opcao == 4){
            printf("Digite o número que está procurando: ");
            scanf("%d",&num);
            if(buscarElemento(pilha,num)){
                printf("O elemento %d está presente na pilha.\n",num);
            }else{
                printf("O elemento %d não está presente na pilha!\n",num);
            }
        }
        else if(opcao == 5){
            printf("A pilha Contêm %d elementos.\n",verificarTamanho(pilha));
        }
        else{
            printf("Digite uma opção válida!\n");
        }
    }while(opcao != 0);
    return 0;
}