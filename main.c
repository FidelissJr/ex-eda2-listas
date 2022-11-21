#include <stdio.h>

typedef struct no{
    struct no *pai;
    struct no *esquerda;
    struct no *direita;
    float v;
} No;

typedef struct arvore{
    struct no *raiz;
} Arvore;

Arvore* Cria();
int Vazia(Arvore *arvore);

int main(){
    Arvore *arvore = Cria();
}

Arvore* Cria(){
    Arvore *arvore = malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    return arvore;
}

int Vazia(Arvore *arvore){
    return (arvore -> raiz == NULL);
}

No* Adicionar(Arvore *arvore, No* pai, float valor){
    No *no = malloc(sizeof(no));
    no->pai = pai;
    no->direita = NULL;
    no->esquerda = NULL;
    no->v = valor;
}

void Percorrer(No *no){
    if(no != NULL){
        Percorrer(no->esquerda);
        Percorrer(no->direita);
    }
}

void AdicionaNo(Arvore *arvore, float valor){
    No *no = malloc(sizeof(no));
    no->pai = NULL;
    no->direita = NULL;
    no->esquerda = NULL;
    no->v = valor;
    if(arvore->raiz == NULL){
        arvore->raiz = no;
    } 
    else{
        
    }
}


