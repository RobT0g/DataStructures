#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int info;
    struct no* prox;
	struct no* ant;
}No;

typedef struct lista{
    No* inicio;
    No* fim;
    int tamanho;
}Lista;

Lista* inicializarLista(){
    //Alocação de Memória dinâmica para struct lista
    Lista* lista = (Lista*) malloc(sizeof(Lista));
    if(lista == NULL){ //verifica se memória foi alocada
        printf("ERRO!!\nMemória Indisponível para criar Lista.");
        exit(1);
    }
    lista->inicio = lista->fim = NULL;  //inicializa referência para inicio e fim
    lista->tamanho = 0;  //inicializa o var tamanho da lista vazia.
    return lista;
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

int verificarTamanho(Lista* lista){
    return lista->tamanho;
}

void inserirNoInicio(Lista* lista, int valor){
    No* novo = criarNo(valor);
    novo->prox = lista->inicio;
    if(lista->inicio == NULL){
        lista->fim = novo;
    }
    lista->inicio = novo;
    lista->tamanho++;
}

void inserirNoFim(Lista* lista, int valor){
    if(lista->inicio == NULL){
        inserirNoInicio(lista, valor);
    }else{
        No* novo = criarNo(valor);
        No* ultimo = lista->fim;
        ultimo->prox = novo;
		novo->ant = ultimo;
        novo->prox = NULL;
        lista->fim = novo;
        lista->tamanho++;
    }
}

void imprimir(Lista* lista){
    No* no;
    for(no=lista->inicio; no != NULL; no = no->prox){
        printf("%d", no->info);
        if(no->prox != NULL){
            printf(" --> ");
        }
    }
    printf("\n");
}

void inserirNoMeio(Lista* lista, int valor, int posicao){
    if((posicao > lista->tamanho+1)||(posicao<1)){//Teste de Posição Válida
        printf("ERRO!\nPosição Inválida");
        exit(1);
    }
    if(posicao == 1){
        inserirNoInicio(lista, valor);
    }else{
        if(posicao > lista->tamanho){
            inserirNoFim(lista, valor);
        }else{
            No* novo = criarNo(valor);
            No* anterior = NULL;
            No* atual = lista->inicio;
            int i;
            for(i=1;i<posicao;i++){
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = novo;
			novo->ant = anterior;
            novo->prox = atual;
			atual->ant = novo;
            lista->tamanho++;
        }
    }
}

void removerDoInicio(Lista* lista){
    if(lista->tamanho == 0){
        printf("ERRO!!\nLista Vazia.");
        exit(1);
    }
    No* no = lista->inicio;
	if(lista->tamanho > 1){
		lista->inicio->prox->ant = NULL;
	}
    lista->inicio = no->prox;
    free(no);
    if(lista->inicio == NULL){
        lista->fim = NULL;
    }
    lista->tamanho--;
}

void removerDoFim(Lista* lista){
    if(lista->tamanho == 0){
        printf("ERRO!!\nLista Vazia.");
        exit(1);
    }
    if(lista->tamanho==1){
        removerDoInicio(lista);
    }else{
        No* anterior = NULL;
        No* ultimo = lista->inicio;
        int i;
        for(i=1;i<lista->tamanho;i++){
            anterior = ultimo;
            ultimo = ultimo->prox;
        }
        anterior->prox = NULL;
        free(ultimo);
        lista->fim = anterior;
        lista->tamanho--;
    }

}

void removerDoMeio(Lista* lista, int posicao){
    if((posicao > lista->tamanho+1)||(posicao<1)){//Teste de Posição Válida
        printf("ERRO!\nPosição Inválida");
        exit(1);
    }
    if(lista->tamanho == 0){
        printf("ERRO!!\nLista Vazia.");
        exit(1);
    }
    if(posicao == 1){
        removerDoInicio(lista);
    }else{
        if(posicao == lista->tamanho){
            removerDoFim(lista);
        }else{
            No* anterior = NULL;
            No* atual = lista->inicio;
            int i;
            for(i=1;i<posicao;i++){
                anterior = atual;
                atual = atual->prox;
            }
            anterior->prox = atual->prox;
			atual->prox->ant = anterior;
            free(atual);
            lista->tamanho--;
        }
    }
}

int buscarElemento(Lista* lista, int valor){
    if(lista->inicio == NULL){
        printf("Lista Vazia.\n");
        return 0;
    }
    No* no;
    for(no=lista->inicio; no!=NULL; no=no->prox){
        if(no->info == valor){
            return 1;
        }
    }
    return 0;
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    int num, posicao, opcao;
    Lista* lista;
    lista = inicializarLista();
    do{
        printf("\n--------------------------------------------------------\n");
        printf("01 - Exibir Lista.\n");
        printf("02 - Inserir no Inicio\n");
        printf("03 - Inserir no Meio\n");
        printf("04 - Inserir no Fim\n");
        printf("05 - Remover do Inicio\n");
        printf("06 - Remover do Meio\n");
        printf("07 - Remover do Fim\n");
        printf("08 - Buscar Elemento\n");
        printf("09 - Tamanho da Lista\n");
        printf("0 - SAIR\n");
        printf("\n--------------------------------------------------------\n");
        scanf("%d",&opcao);
        switch(opcao){
        case 1:
            imprimir(lista);
            break;
        case 2:
            printf("Digite o valor que deseja inserir: ");
            scanf("%d",&num);
            inserirNoInicio(lista, num);
            break;

        case 3:
            printf("Digite o valor que deseja inserir: ");
            scanf("%d",&num);
            printf("Digite a posição que deseja inserir o elemento: ");
            scanf("%d",&posicao);
            inserirNoMeio(lista, num, posicao);
            break;
        case 4:
            printf("Digite o valor que deseja inserir: ");
            scanf("%d",&num);
            inserirNoFim(lista, num);
            break;
        case 5:
            removerDoInicio(lista);
            break;
        case 6:
            printf("Digite a posição que deseja remover o elemento: ");
            scanf("%d",&posicao);
            removerDoMeio(lista, posicao);
            break;
        case 7:
            removerDoFim(lista);
            break;
        case 8:
            printf("Digite o número que está procurando: ");
            scanf("%d",&num);
            if(buscarElemento(lista,num)){
                printf("O elemento %d está presente na lista.\n",num);
            }else{
                printf("O elemento %d não está presente na lista!\n",num);
            }
            break;
        case 9:
            printf("A Lista Contêm %d elementos.\n",verificarTamanho(lista));
            break;
        default:
            printf("Digite uma opção válida!\n");
        }
    }while(opcao != 0);
    return 0;
}