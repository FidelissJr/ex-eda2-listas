#include <stdio.h>
#include <stdlib.h>
typedef struct no{
    struct no *pai;
    struct no *esquerda;
    struct no *direita;
    int valor;
} No;

typedef struct arvore{
    struct no *raiz;
} Arvore;

Arvore* Cria();
int Vazia(Arvore *arvore);
void AdicionarDireita(No* no, int valor);
void AdicionarEsquerda(No* no, int valor);
void Percorrer(No *no);
void Adicionar(Arvore *arvore, int valor);

int main(){
    Arvore *arvore = NULL;
    arvore = Cria();
    int op, valor;
    
    do{
        printf("\n0 - Sair\n1 - Adicionar\n2 - Imprimir \n Opcao: \n");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            op = 0;
            break;
        case 1:
            printf("Valor a ser adicionado: ");
            scanf("%d", &valor);
            Adicionar(arvore, valor);
            break;
        case 2:
            Percorrer(arvore->raiz);
            break;
        default:
            printf("Opcao invalida");
        }
    }while(op != 0);
    free(arvore);
}

Arvore* Cria(){
    Arvore *arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

int Vazia(Arvore *arvore){
    return (arvore->raiz == NULL);
}

void Adicionar(Arvore *arvore, int valor){
    if(Vazia(arvore)){
        No *no = (No*)malloc(sizeof(no));
        no->pai = NULL;
        no->direita = NULL;
        no->esquerda = NULL;
        no->valor = valor;
        arvore->raiz = no;
    }
    else{
        if(valor > arvore->raiz->valor)
            AdicionarDireita(arvore->raiz, valor);
        else
            AdicionarEsquerda(arvore->raiz, valor);
    }
}

void Percorrer(No *no){
    if(no != NULL){
        printf("%d-", no->valor);
        Percorrer(no->esquerda);
        Percorrer(no->direita);
    }
}

void AdicionarDireita(No* no, int valor){
    if(no -> direita == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->pai = no;
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->valor = valor;
        no->direita = novo;
    }
    else{
        if(valor > no->direita->valor)
            AdicionarDireita(no->direita, valor);
        else
            (AdicionarEsquerda(no->direita, valor));
    }
}

void AdicionarEsquerda(No* no, int valor){
    if(no -> esquerda == NULL){
        No *novo = (No*)malloc(sizeof(No));
        novo->pai = no;
        novo->direita = NULL;
        novo->esquerda = NULL;
        novo->valor = valor;
        no->esquerda = novo;
    }
    else{
        if(valor > no->esquerda->valor)
            AdicionarDireita(no->esquerda, valor);
        else
            AdicionarEsquerda(no->esquerda, valor);
    }
}



