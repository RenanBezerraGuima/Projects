#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura {
    int chave;

    struct estrutura* prox;
} no;

typedef struct {
    no* inicio;
}lista;

void inicializa(lista* l){
    l->inicio = NULL;
}

void exibir (lista* l){
    no* p = l->inicio;
    while (p) 
    {
        printf("%i ", p->chave);
        p = p->prox;
    }
    printf("\n");
}

bool excluirPrimeiro (lista* l){
    no* inicio = l->inicio;
    if (inicio == NULL) return false;
    else 
    {
        no* p = inicio->prox;
        free(inicio);
        l->inicio = p;
    } 
    return true;
}

bool anexarlistaVazia (lista* l, int ch){
    no* novo = (no*) malloc (sizeof(no));
    novo->chave = ch;
    l->inicio = novo;
    novo->prox = NULL;

    return true;
}

int main () {
    lista l;
    inicializa(&l);
    anexarlistaVazia(&l, 15);
    exibir(&l);

    excluirPrimeiro(&l);
    exibir(&l);
    
    return 0;
}