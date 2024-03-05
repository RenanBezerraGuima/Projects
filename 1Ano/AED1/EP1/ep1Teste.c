#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//para que seja possivel adicionar elementos ao fim sem percocer ela inteira.
// E depois disso ter uma lista conjunto que está em ordem com a lista1 (que eu já vou ter quando adicionar elementos ao fim da lista)
// para poder excluir o elemento da lista1 e da lista conjunto ao mesmo tempo


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
    novo->proximo = NULL;
    if (conjunto->inicio == NULL) conjunto->inicio = novo;
    else 
    {
        Conjunto* p = conjunto->inicio;
        while (p->proximo)
        {
            p = p->proximo;
        }
        p->proximo = novo;
    }
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

//Função Funciona
int buscaConjunto(listaConjunto* c, NO* elemento, NO* *ant, Conjunto* *antConjunto){
    Conjunto* p = c->inicio;
    *ant = NULL;
    *antConjunto = NULL;

    while (p){
        if(elemento == p->elementoConjunto) return 1; //O mesmo elemento
        else if (*antConjunto == NULL) *antConjunto = c->inicio;
        else *antConjunto = p;
        *ant = p->elementoConjunto;
        p = p->proximo;
    }
    return 0;
}

void removerCompartilhados(NO* *p1, NO* *p2) {
    listaConjunto c;
    inicializaConjunto(&c);

    NO* ponteiro1 = (*p1);//Inicio lista1

    while (ponteiro1){
        adicionarAoConjunto(&c, ponteiro1);
        ponteiro1 = ponteiro1->prox;
    } 

    NO* ponteiro2 = (*p2);//Inicio lista2
    NO* antl2 = NULL;
    NO* antLista = NULL;
    Conjunto* antConjunto = NULL;

    while (ponteiro2) 
    {
        NO* temp = ponteiro2->prox;
        if (buscaConjunto(&c, ponteiro2, &antLista, &antConjunto))
        {
            if (!antLista) 
            {
                (*p2) = ponteiro2->prox;
                c.inicio = c.inicio->proximo;
                (*p1) = (*p1)->prox;
            }
            else 
            {
                antLista->prox = antLista->prox->prox; // Tira de l1
                antConjunto->proximo = antConjunto->proximo->proximo; // Tira do Conjunto
                if (antl2) {
                    antl2->prox = antl2->prox->prox;// Tira de l2
                }
            }
            free(ponteiro2);
        }
        ponteiro2 = temp;
        antl2 = ponteiro2;
    }
    
    Conjunto* p = c.inicio;
    while (p)
    {
        Conjunto* temp = p;
        p = p->proximo;
        free(temp);
    }
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

    // exibir(&l1);
    // exibir(&l2);

    return 0;
}