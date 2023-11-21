#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct estrutura {
    int chave;
    //infos adicionais
    struct estrutura* prox;
}NO;

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

void inverterLista(NO* *ini){
    NO* ant = NULL;
    NO* prox;
    NO* atual = *ini;

    while (atual)
    {
        prox = atual->prox;
        atual->prox = ant;
        ant = atual;
        atual = prox;
    }
    
    *ini = ant;
}

void exibirRecursiva(NO* p){
    if (!p) return;
    printf("%i ", p->chave);
    exibirRecursiva(p->prox);
}

void exibirInversaRecursiva(NO* p){
    if (!p) return;
    exibirInversaRecursiva(p->prox);
    printf("%i ", p->chave);
}

void inversaoRecursiva(NO* *ini, NO* atual, NO* ant){
    if (atual) 
    {
        inversaoRecursiva(ini, atual->prox, atual);
        atual->prox = ant;
    }
    else *ini = ant;
}

int main(){
    lista l;
    inicializa(&l);
    inserir(&l, 10);
    inserir(&l, 20);
    inserir(&l, 30);
    exibir(&l);

    inverterLista(&l.inicio);
    exibir(&l);

    return 0;
}