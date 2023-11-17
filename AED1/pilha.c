#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura {
    int chave;
    struct estrutura *prox;
} NO;

typedef struct {
    NO* inicio;
}lista;

void inicializa(lista* l){
    l->inicio = NULL;
}

void exibir (NO* p){
    while (p) 
    {
        printf("%i ", p->chave);
        p = p->prox;
    }
    printf("\n");
}

NO* busca(lista* l, int ch, NO* *ant){
    *ant = NULL;
    NO* p = l->inicio;
    while(p){
        if (p->chave == ch) return p;
        else if (p->chave > ch) return NULL;
        *ant = p;
        p = p->prox;
    }
    return NULL;
}

bool inserir(lista* l, int ch){
    NO* ant = NULL;
    NO* atual = busca(l, ch, &ant);
    if (atual) return false; //Elemento já existe
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    if(ant){ //Elemento no meio
        novo->prox = ant->prox;
        ant->prox = novo;        
    } else {//Elemento no começo ou lista vazia
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    return true;
}



typedef struct {
    NO* topo;
} PILHA;

// Inicialização da pilha
void inicializarPdinam(PILHA* p) {
    p->topo = NULL;
}

// Inserir item no topo
void push(int ch, PILHA* p) {
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = p->topo;
    p->topo = novo;
}

// Retirar a chave do topo ou -1
int pop(PILHA* p) {
    NO* aux;
    int ch;

    if(!p->topo) return(-1);//pilha vazia
    aux = p->topo;
    ch = aux->chave;
    p->topo = p->topo->prox;
    free(aux);
    return(ch);
}

// Quantos elementos existem
int tamanhoPdinam(PILHA* p) {
    NO* p1 = p->topo;
    int tam = 0;
    while(p1) 
    {
        tam++;
        p1 = p1->prox;
    }
    return(tam);
}

//Retorna uma cópia invertida da lista utilizando 
//uma pilha dinâmica como estrutura auxiliar.
NO* copiaInvertida(NO* p){
    if (!p) return (NULL);//lista vazia
    
    PILHA aux;
    lista lresp;
    inicializa(&lresp);
    inicializarPdinam(&aux);
    
    while (p)
    {
        push(p->chave, &aux);
        p = p->prox;
    }

    while (aux.topo)
    {
        inserir(&lresp, pop(&aux));
    }

    return (lresp.inicio);
}



int main() {
    lista l1;
    lista l2;
    inicializa(&l1);
    inserir(&l1, 10);
    inserir(&l1, 20);
    inserir(&l1, 30);
    exibir(l1.inicio);

    l2.inicio = copiaInvertida(l1.inicio);
    exibir(l2.inicio);

    return 0;
}