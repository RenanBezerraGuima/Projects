#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura{
    int chave;
    struct estrutura* esq;
    struct estrutura* dir;
}NO;

typedef struct estruct{
    int chave;
    struct estruct* prox;
}NOL;

//Arvore binária de Busca (Ordenada, esquera é menor que o atual e direita maior)
NO* buscaABB(NO*p, int ch, NO**pai){
    *pai = NULL;
    while(p){
        if(p->chave == ch) return p;
        *pai = p;
        if(p->chave > ch) p = p->esq;
        else p = p->dir;
    }
    return p;
}

bool inserirABB(NO** raiz, int ch){
    NO* pai;
    NO* p = buscaABB(*raiz, ch, &pai);
    if(p) return false;

    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->esq = NULL;
    novo->dir = NULL;

    if(!pai){
        *raiz = novo;
        return true;
    }

    if(novo->chave < pai->chave) pai->esq = novo;
    else pai->dir = novo;
    return true;
}

//Inicializar resp na main
void contador(NO* p, int* resp){
    if(p){
        *resp = *resp + 1;
        contador(p->esq, resp);
        contador(p->dir, resp);
    }
}

int max(int a, int b){
    if (a > b) return a;
    else return b;
}

//Altura da arvore
int altura(NO*p){
    if(!p) return 0;
    if(!p->esq && !p->dir) return 1;//Desnessario, mas mas eficiente
    return(1 + max(altura(p->esq), altura(p->dir)));
}

//Busca geral
void busca(NO* p, NO** resp, int ch){
    if(p){
        if (p->chave == ch) *resp = p;
        if(*resp == NULL) busca(p->esq, resp, ch);
        if(*resp == NULL) busca(p->dir, resp, ch);
    }
}

//Seja uma arvore com chaves repitidas, sem ordem, contar as ocorrências de ch, com limite de 50 elementos.
void contarRepetidas(NO* p, int* qtd, int ch){
    if (p && *qtd < 50)
    {
        if (p->chave == ch) *qtd++;
        contarRepetidas(p->esq, qtd, ch);
        contarRepetidas(p->dir, qtd, ch);
    }
}

void exibir(NO* p){
    if(!p) return;
    exibir(p->esq);
    printf("%i ", p->chave);
    exibir(p->dir);
}

void listarOrdenado(NO* p, NOL** l){
    if(p){
        listarOrdenado(p->dir, l);

        NOL* novo = (NOL*) malloc(sizeof(NOL));
        novo->chave = p->chave;
        if (!l) novo->prox = NULL;
        else novo->prox = *l;
        *l = novo;

        listarOrdenado(p->esq, l);
    }
}

//inicializar o pai como NULL
NO* buscaABBRecursiva(NO*p, int ch, NO**pai){
   if (!p) return NULL;
   if (p->chave == ch) return p;
   //Atualiza o pai
   *pai = p;
   
   if (ch > p->chave) return buscaABBRecursiva(p->dir, ch, pai);
   else return buscaABBRecursiva(p->esq, ch, pai);
}

NO* maior(NO* p, NO** pai)
{
    NO* resp = p;
    while (resp->dir)
    {
        *pai = resp; 
        resp = resp->dir;
    }
    return resp;
}

void excluirABB(NO* p, NO* pai){
    if (!p) return;//Não tem nó

    if (!p->esq)//Caso 1 e 2
    {
        if(pai->esq == p) pai->esq = p->dir;
        else pai->dir = p->dir;
    }

    else if (p->esq && p->dir)//Caso 3
    {
    NO* paiTemp = p;
        NO* temp = maior(p->esq, &paiTemp);
        p->chave = temp->chave;
        excluirABB(temp, paiTemp);
    }
}

int main (){

    return 0;
}