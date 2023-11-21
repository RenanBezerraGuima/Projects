#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura{
    int chave;
    int info;
    struct estrutura *prox;
    struct estrutura *ant;
}NO;

typedef struct {
    NO* cabeca;
}LISTA;

void inicializar(LISTA* l) {
    l->cabeca = (NO*) malloc(sizeof(NO));
    l->cabeca->prox = l->cabeca;
    l->cabeca->ant = l->cabeca;
}

// Posição da chave de busca na lista ordenada
NO* buscaSeqOrd(int ch, LISTA l, NO* *ant) {
    NO* p = l.cabeca->prox;
    *ant = l.cabeca;
    l.cabeca->chave = ch; // usa cabeça como sentinela
    while(p->chave < ch) 
    {
        *ant = p;
        p = p->prox;
    }
    if ((p != l.cabeca) && (p->chave == ch)) return(p);
    else return(NULL);
}

// Inserção ordenada sem duplicações
bool inserirElemListaOrd(int ch , LISTA* l) {
    NO* novo;
    NO* ant;
    novo = buscaSeqOrd(ch, *l, &ant);
    if(novo) return(false);
    novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = ant->prox;
    novo->ant = ant;
    novo->prox->ant = novo;
    ant->prox = novo;
    return(true);
}

void exibir(LISTA* l){
    NO* p = l->cabeca->prox;
    while (p != l->cabeca)
    {
        printf("%i ", p->chave);
        p = p->prox;
    }
    printf("\n");
}

//exibir as chaves existentes em ordem reversa. // percurso de trás pra frente com printf
void exibirInvertida(LISTA* l){
    NO* p = l->cabeca->ant;
    while (p != l->cabeca)
    {
        printf("%i ",p->chave);
        p = p->ant;
    }
    printf("\n");
}

//Insere uma nova chave ch (que pode ser repetida) antes da posição *atual fornecida, criando um novo nó. 
//Lista nunca é vazia e o ponteiro atual sempre aponta pra onde se deve inserir antes dele.
void inserirAntes(int ch, NO* atual){
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = atual;
    novo->ant = atual->ant;

    atual->ant->prox = novo;
    atual->ant = novo;
}

//Lista dupla, circular e com nó cabeça
int main () {
    LISTA l;
    inicializar(&l);
    inserirElemListaOrd(10, &l);
    inserirElemListaOrd(20, &l);
    inserirElemListaOrd(30, &l);
    exibir(&l);

    return 0;
}