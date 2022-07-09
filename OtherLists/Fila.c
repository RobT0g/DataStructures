#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int info;
    struct no* prox;
}No;

typedef struct fila{
    No* inicio;
    No* fim;
    int tamanho;
}Fila;

Fila* inicializarfila(){
    //Alocação de Memória dinâmica para struct fila
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    if(fila == NULL){ //verifica se memória foi alocada
        printf("ERRO!!\nMemória Indisponível para criar fila.");
        exit(1);
    }
    fila->inicio = fila->fim = NULL;  //inicializa referência para inicio e fim
    fila->tamanho = 0;  //inicializa o var tamanho da fila vazia.
    return fila;
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

int verificarTamanho(Fila* fila){
    return fila->tamanho;
}

void inserir(Fila* fila, int valor){
    No* novo = criarNo(valor);
    if(fila->inicio == NULL){
        fila->inicio = fila->fim = novo;
    }else{
        No* ultimo = fila->fim;
        ultimo->prox = novo;
        novo->prox = NULL;
        fila->fim = novo;
    }
    fila->tamanho++;
}

void imprimir(Fila* fila){
    if(fila->tamanho == 1){
        printf("%d", fila->inicio->info);
    } else{
        No* no;
        for(no=fila->inicio; no != NULL; no = no->prox){
            printf("%d", no->info);
            if(no->prox != NULL){
                printf(" --> ");
            }
        }
    }
    printf("\n");
}

void remover(Fila* fila){
    if(fila->tamanho == 0){
        printf("ERRO!!\nfila Vazia.");
        exit(1);
    }
    No* no = fila->inicio;
    fila->inicio = no->prox;
    free(no);
    if(fila->inicio == NULL){
        fila->fim = NULL;
    }
    fila->tamanho--;
}

int buscarElemento(Fila* fila, int valor){
    if(fila->inicio == NULL){
        printf("fila Vazia.\n");
        return 0;
    }
    No* no;
    for(no=fila->inicio; no!=NULL; no=no->prox){
        if(no->info == valor){
            return 1;
        }
    }
    return 0;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num, posicao, opcao;
    Fila* fila;
    fila = inicializarfila();
    do{
        printf("\n--------------------------------------------------------\n");
        printf("01 - Exibir fila.\n");
        printf("02 - Inserir na fila (fim)\n");
        printf("03 - Remover da fila (inicio)\n");
        printf("04 - Buscar Elemento\n");
        printf("05 - Tamanho da fila\n");
        printf("0 - SAIR\n");
        printf("\n--------------------------------------------------------\n");
        scanf("%d",&opcao);
        switch(opcao){
        case 1:
            imprimir(fila);
            break;
        case 2:
            printf("Digite o valor que deseja inserir: ");
            scanf("%d",&num);
            inserir(fila, num);
            break;
        case 3:
            remover(fila);
            break;
        case 4:
            printf("Digite o número que está procurando: ");
            scanf("%d",&num);
            if(buscarElemento(fila,num)){
                printf("O elemento %d está presente na fila.\n",num);
            }else{
                printf("O elemento %d não está presente na fila!\n",num);
            }
            break;
        case 5:
            printf("A fila Contêm %d elementos.\n",verificarTamanho(fila));
            break;
        default:
            printf("Digite uma opção válida!\n");
        }
    }while(opcao != 0);
    return 0;
}