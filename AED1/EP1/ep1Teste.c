#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura {
    int chave;
    //infos adicionais
    struct estrutura* prox;
} NO;

typedef struct {
    NO* inicio;
}lista;

void inicializa(lista* l){
    l->inicio = NULL;
}

void exibir (lista* l){
    NO* p = l->inicio;
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

bool excluir (lista* l, int ch) {
    NO* ant;
    NO* atual = busca (l, ch, &ant);

    if(!atual) return false; //Se não tiver essa chave buscada
    else if (ant) ant->prox = atual->prox; //Se o elemento estver no meio
    else l->inicio = atual->prox;   //Se o elemento for no inicio
    free(atual);

    return true;
}

bool inserir(lista* l, int ch){
    NO* ant;
    NO* atual = busca(l, ch, &ant);
    if (atual) return false; //Elemento já existe
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    if(ant){ //Elemento no meio
        novo->prox = ant->prox;
        ant->prox = novo;        
    } else {//Elemento no comço ou lista vazia
        novo->prox = l->inicio;
        l->inicio = novo;
    }
    return true;
}

bool inserir2ElementosCompostos(lista* l1, lista* l2, int ch1, int ch2){
    NO* ant1 = NULL; 
    NO* ant2 = NULL;

    NO* p1 = l1->inicio;
    NO* p2 = l2->inicio;
    //Acham o ultimo elemento de cada lista (ant1 e ant2)
    while (p1){ 
        ant1 = p1;
        p1 = p1->prox;
    }

    while (p2){
        ant2 = p2;
        p2 = p2->prox;
    }

    NO* novo1 = (NO*) malloc(sizeof(NO));
    NO* novo2 = (NO*) malloc(sizeof(NO));
    novo1->prox = novo2;
    novo1->chave = ch1;
    novo2->prox = NULL;
    novo2->chave = ch2;

    ant1->prox = novo1;
    ant2->prox = novo1;
    return true;
}

typedef struct conjunto {
    NO* elementoConjunto;
    struct conjunto* proximo;
}Conjunto;

typedef struct {
    Conjunto* inicio;
}listaConjunto;

void inicializaConjunto (listaConjunto* l){
    l->inicio = NULL;
}

void adicionarAoConjunto(listaConjunto* conjunto, NO* elemento) {
    Conjunto* novo = (Conjunto*)malloc(sizeof(Conjunto));
    novo->elementoConjunto = elemento;
    novo->proximo = conjunto->inicio;
    conjunto->inicio = novo;
}

void exibirConjunto(listaConjunto* c){
    Conjunto* p = c->inicio;
    while (p) 
    {
        printf("%i ", p->elementoConjunto->chave);
        p = p->proximo;
    }
    printf("\n");
}

int buscaEnd(listaConjunto* c, NO* elemento, NO* *ant){
    Conjunto* p = c->inicio;
    *ant = NULL;

    while (p){
        if(elemento == p->elementoConjunto) return 1; //O mesmo elemento
        *ant = p->elementoConjunto;
        p = p->proximo;
    }
    return 0;
}

void removerCompartilhados(NO* *p1, NO* *p2) {
    listaConjunto c;
    inicializaConjunto(&c);
    NO* ant;

    NO* ponteiro1 = (*p1);

    while (ponteiro1){
        adicionarAoConjunto(&c, ponteiro1);
        ponteiro1 = ponteiro1->prox;
    } 

    NO* ponteiro2 = (*p2);
    NO* temp = ponteiro2;
    while (ponteiro2){
        if(buscaEnd(&c,ponteiro2,&ant)) {
            temp = ponteiro2;
            ponteiro2 = ponteiro2->prox;
            ant->prox = NULL;
            free(temp);
        }
        else ponteiro2 = ponteiro2->prox;
    }
    
    
	return;
}

int main () {
    lista l1;
    lista l2;

    inicializa(&l1);
    inicializa(&l2);

    inserir(&l1,20);
    inserir(&l1,30);
    inserir(&l1,40);
    exibir(&l1);
    
    inserir(&l2,90);
    inserir(&l2,30);
    exibir(&l2);

    inserir2ElementosCompostos(&l1, &l2, 99, 99);
    exibir(&l1);
    exibir(&l2);
    
    removerCompartilhados(&(l1.inicio), &(l2.inicio));
    exibir(&l1);
    exibir(&l2);
    // adicionarAoConjunto(&c, l1.inicio);
    // adicionarAoConjunto(&c, l2.inicio);
    // exibirConjunto(&c);
    
    return 0;
}