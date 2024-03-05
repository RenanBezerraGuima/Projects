#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura {
    int chave;
    struct estrutura *prox;
    struct estrutura *ant;
} NO;

typedef struct {
    NO* inicio1;
    NO* inicio2;
} DEQUE;

// Inicialização do deque
void inicializarDeque(DEQUE* d) {
    d->inicio1 = NULL;
    d->inicio2 = NULL;
}

void entrarDeque1(int ch, DEQUE* d) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->ant = NULL;
    novo->prox = d->inicio1;
    if(d->inicio1) d->inicio1->ant = novo; // já contém dados
    else d->inicio2 = novo; // 1a. inserção
    d->inicio1 = novo;
}

void entrarDeque2(int ch, DEQUE* d) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;

    if (!(d->inicio2))
    {
        d->inicio1 = novo;
        d->inicio2 = novo;
        novo->ant = NULL;
    }
    else 
    {
        novo->ant = d->inicio2;
        d->inicio2->prox = novo;
        d->inicio2 = novo;
    }
}

void exibir (DEQUE* d){
    NO* p = d->inicio1;
    while (p) 
    {
        printf("%i ", p->chave);
        p = p->prox;
    }
    printf("\n");
}

int main() {
    DEQUE d;
    inicializarDeque(&d);
    entrarDeque2(10, &d);
    entrarDeque2(20, &d);
    entrarDeque2(30, &d);
    exibir(&d);

    return 0;
}