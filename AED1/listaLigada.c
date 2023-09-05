#include <stdio.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int chave;
    int prox;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int inicio;
    int dispo;
} LISTA;

// Inicialização
void inicializarListaLigadaEstatica(LISTA* l) {
    l->inicio = -1;
    l->dispo = 0;
    for(int i=0; i < MAX - 1; i++)
    l->A[i].prox = i + 1;
    l->A[MAX - 1].prox = -1;
}

// Exibição da lista completa
void exibirLista(LISTA *l) {
    for (int i = l->inicio; i > -1; i = l->A[i].prox) 
    {
        printf("%d ", l->A[i].chave);
    }
    printf("\n");
}

int tamanho(LISTA *l){
    int i = l->inicio;
    int contador=0;
    while(i!=-1)
    {
        contador++;
        i=l->A[i].prox;
    }
    return contador;
}

// Busca sequencial, retornando a posição da chave e do anterior
int buscaSeqOrd(int ch, LISTA l, int* ant) {
    int i = l.inicio;
    *ant= -1;
    while (i != -1) 
    {
        if(l.A[i].chave >= ch) break;
        *ant = i;
        i= l.A[i].prox;
    }
    if(i==-1) return -1;
    if(l.A[i].chave==ch) return(i);
    else return -1;
}

// Obter nó disponível - a lista é alterada
int obterNo(LISTA* l) {
    int result = l->dispo;
    if(l->dispo > -1)  l->dispo = l->A[l->dispo].prox;
    return(result);
}

// Devolver nó p/ dispo – a lista é alterada
void devolverNo(LISTA* l, int j) {
    l->A[j].prox= l->dispo;
    l->dispo = j;
}

// Exclusão do elemento de chave indicada
bool excluirElemListaEnc(int ch, LISTA* l) {
    int ant, i;
    i = buscaSeqOrd(ch, *l, &ant);
    if(i < 0) return(false);
    if(ant == -1) l->inicio = l->A[i].prox;
    else l->A[ant].prox = l->A[i].prox;
    devolverNo(l, i);
    return(true);
}

// inserção em lista ordenada sem duplicações
bool inserirElemListaEncOrd(int ch, LISTA* l) {
    int ant, i;
    i = buscaSeqOrd(ch, *l, &ant);
    if((l->dispo < 0) || (i != -1)) return(false);
    i = obterNo(l);
    l->A[i].chave = ch;
    if(l->inicio<0) 
    {
        // inserção do primeiro elemento de lista vazia
        l->inicio = i;
        l->A[i].prox = -1;
    }
    else 
    {
        if(ant < 0) 
        {
            // inserção no início de lista já existente
            l->A[i].prox = l->inicio;
            l->inicio = i;
        }
        else 
        {
            // inserção entre dois elementos
            l->A[i].prox = l->A[ant].prox;
            l->A[ant].prox = i;
        }
    }
    return(true);
}

bool moverParaFrente(LISTA *l, int i){
    if ((i<0) || (i>MAX-1)) return false;
    int ch=l->A[i].chave;
    int ant;
    buscaSeqOrd(ch, *l, &ant);
    if(ant == -1) return true;
    l->A[ant].prox = l->A[i].prox;
    l->A[i].prox = l->dispo;
    l->dispo = i;
    int novo = l->dispo;
    l->A[novo].chave = ch;
    l->A[novo].prox = l->inicio;
    l->inicio = novo;
    return true;
}

bool moverParaFinal(LISTA *l, int ch){
    int ant, antA, atual, ultimo;
    int i = l->inicio;
    ant = -1;
    atual = -1;
    antA = -1;
    while (i != -1) 
    {
        if(l->A[i].chave == ch)
        {
            atual = i;
            antA = ant;
        } 
        if(l->A[i].prox == -1) ultimo = i;
        ant = i;
        i= l->A[i].prox;
    }
    if (atual == -1) return false; //Não achou a chave
    if (l->A[atual].prox == -1) return true;
    if (antA == -1)  l->inicio = l->A[atual].prox; //Se o elemento buscado for o primeiro
    else l->A[antA].prox = l->A[atual].prox;

    l->A[ultimo].prox = atual;
    l->A[atual].prox = -1;

    return true;
}

int main (){
    LISTA lista;
    inicializarListaLigadaEstatica(&lista);
    inserirElemListaEncOrd(1,&lista);
    inserirElemListaEncOrd(2,&lista);
    inserirElemListaEncOrd(3,&lista);
    inserirElemListaEncOrd(4,&lista);
    inserirElemListaEncOrd(5,&lista);
    inserirElemListaEncOrd(6,&lista);

    exibirLista(&lista);

    excluirElemListaEnc(5,&lista);

    exibirLista(&lista);

    int ant;
    int n6 = buscaSeqOrd(6,lista,&ant);

    moverParaFrente(&lista, n6);

    exibirLista(&lista);

    moverParaFinal(&lista, 7);

    exibirLista(&lista);

    return 0;
}