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

//(*p1) e (*p2) são ponteiros para inicio das listas 1 e 2 respectivamente
void removerCompartilhados(NO* *p1, NO* *p2) {
    NO* pl1 = (*p1);
    NO* antl1 = NULL;
    NO* pl2 = (*p2);
    NO* antl2 = NULL;

    // Percorre cada elemento da lista1 comparando o endereço com a lista2 e removendo se for igual
    while (pl1) // Percorre a lista1
    {
        pl2 = (*p2);
        while (pl2) // Percorre a lista2
        {
            if (pl1 == pl2) //Se tiverem o mesmo endereço de memoria
            {
                if (antl1) antl1->prox = pl1->prox; // Se não for o primeiro elemento da lista1
                else (*p1) = pl1->prox; 
                if (antl2) antl2->prox = pl2->prox; // Se não for o primeiro elemento da lista2
                else (*p2) = pl2->prox;
                free(pl1);
                pl1 = (*p1);
                break;
            }
            else
            {
                antl2 = pl2;
                pl2 = pl2->prox;
            }
        }
        antl1 = pl1;
        pl1 = pl1->prox;
    }

    pl1 = (*p1);
    pl2 = (*p2);

    while (pl1->prox)
    {
    pl1 = pl1->prox;
    }
    pl1->prox = (*p1);
    
    while (pl2->prox)
    {
      pl2 = pl2->prox;
    }
    pl2->prox = (*p2);
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

    // inserir2ElementosCompostos(&l1, &l2, 99, 99);
    // exibir(&l1);
    // exibir(&l2);

    removerCompartilhados(&(l1.inicio), &(l2.inicio));

    return 0;
}