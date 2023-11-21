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
	if (n == 0) return (NULL);
	NO* inicio = (NO*) malloc(sizeof(NO));
	inicio->ant = NULL;
	inicio->prox = NULL;
	inicio->chave = 1; 
		
	if (n > 1) 
	{
		int i = 2;
		NO* p = inicio;
		while(i <= n)
		{
			NO* novo = (NO*) malloc(sizeof(NO));
			novo->chave = i;
			novo->ant = p;
			novo->prox = NULL;
			p->prox = novo;
			p = p->prox;
			i++;
		}
        return (inicio);
	}
	else return (inicio);
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
    NO* ponteiro = l->inicio;
    if (!p) return;//Lista vazia
    else if (p->prox == NULL) return;//Já é o último

    if (ponteiro == p) 
    {
        l->inicio = p->prox;
        l->inicio->ant = NULL;
    }

    else 
    {
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
    }

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