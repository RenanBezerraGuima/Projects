#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura {
    int chave;
    int info;
    struct estrutura *prox;
    struct estrutura *ant;
} NO;

typedef struct {
    NO* inicio;
}LISTADUPLA;

void inicializarLista(LISTADUPLA* l) {
    l->inicio = NULL;
}

NO* listaNumerada(int n) {
	NO* inicio = NULL;
    NO* anterior = NULL;
	int i = 1;

	while (i <= n) 
	{
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave = i;
        if (i == 1) 
        {
            inicio = novo;
            novo->ant = NULL;
        }
        else 
        {
            novo->ant = anterior;
            novo->ant->prox = novo;
        }
        novo->prox = NULL;
        i++;
        anterior = novo;
	}

	return (inicio);
}

void exibir (LISTADUPLA* l){
    NO* p = l->inicio;
    if(!p) return;
    while (p) 
    {
        printf("%i ", p->chave);
        p = p->prox;
    }
    printf("\n");
}

void exibirInvertida(LISTADUPLA* l){
    NO* p = l->inicio;
    if(!p) return;
    while (p->prox)
    {
        p = p->prox;
    }

    while (p)
    {
        printf("%i ", p->chave);
        p = p->ant;
    }
    printf("\n");
}

NO* busca(LISTADUPLA* l, int ch){
    NO* ant = NULL;
    NO* p = l->inicio;
    while(p){
        if (p->chave == ch) return p;
        else if (p->chave > ch) return NULL;
        ant = p;
        p = p->prox;
    }
    return NULL;
}

//Dada um ponteiro p garantidamente válido, 
//mover o elemento p para o fim da lista.
void moverParaFim(LISTADUPLA* l, NO* p){
    if (p->prox == NULL) return;//Já é o último

    //Tira o elemento "p" sem dar free
    if (!(p->ant)) l->inicio = p->prox;
    else p->ant->prox = p->prox;
    p->prox->ant = p->ant;

    //Faz o "ponteiro" apontar para o elemento final da lista, 
    //começando em p para economizar tempo
    NO* ponteiro = p;
    while(ponteiro->prox)
    {
        ponteiro = ponteiro->prox;
    }

    ponteiro->prox = p;
    p->ant = ponteiro;
    p->prox = NULL;
}

int main(){
    LISTADUPLA l;
    int n;
    inicializarLista(&l);

    printf("Insira um inteiro n: ");
    scanf("%i", &n);

    l.inicio = listaNumerada(n);
    exibir(&l);
    exibirInvertida(&l);

    printf("Insira o inteiro que deseja mover para o fim da lista: ");
    scanf("%i", &n);
    NO* p = busca(&l, n);
    if (!p) return -1;
    moverParaFim(&l, p);
    exibir(&l);
    exibirInvertida(&l);


    return 0;
}