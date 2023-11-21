#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool inserirRepitidas(lista* l, int ch){
    NO* ant = NULL;
    NO* p = l->inicio;

    NO* novo = (NO*) malloc (sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;

    if (!p) //lista vazia
    {
        l->inicio = novo;
        return (true);
    }

    while (p)
    {
        ant = p;
        p = p->prox;
    }    
    ant->prox = novo;
    return (true);
}

//Dada uma lista ligada dinâmica l não ordenada que admite repetição de chaves, 
//e um valor de chave x, excluir todas as ocorrências de x na lista.
void excluirOcorrencias(lista* l, int x){
    NO* ant = NULL;
    NO* p = l->inicio;

    while (p)
    {
        if (p->chave == x) 
        {
            if (ant) ant->prox = p->prox;
            else l->inicio = p->prox;

            NO* aux = p->prox;
            free (p);
            p = aux;
        }
        else 
        {
            ant = p;
            p = p->prox;
        }
    }
}

//Dada uma lista ligada dinâmica apontada por *p, crie uma cópia da mesma (usando um malloc para cada elemento 
//e fazendo as devidas ligações), e retorne um novo ponteiro indicando o começo da lista assim criada.
NO* copia(NO* p){
    NO* fim = NULL;
    NO* inicio = NULL;

    while (p)
    {
        NO* novo = (NO*) malloc(sizeof(NO));
        novo->chave = p->chave;
        novo->prox = NULL;

        if (!fim) inicio = novo; //Primeiro da lista
        else fim->prox = novo;

        fim = novo;
        p = p->prox;
    }
    return (inicio);
}

int main () {
    lista l;
    inicializa(&l);
    inserirRepitidas(&l, 10);
    inserirRepitidas(&l, 20);
    inserirRepitidas(&l, 30);
    inserirRepitidas(&l, 40);
    exibirRecursiva(l.inicio);
    printf("\n");
    inversaoRecursiva(&l.inicio, l.inicio, NULL);
    exibirRecursiva(l.inicio);

    return 0;
}