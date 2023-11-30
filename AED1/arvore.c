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

// void excluirABB(NO* p, NO* pai){
//     if(p)
//     {
//         if(pai)
//         {
//             if(!p->esq && !p->dir)//Caso 1
//             {
//                 if (pai->esq == p) pai->esq = NULL;
//                 else pai->dir = NULL;
//                 free(p);
//             }
//             else if (!p->esq || !p->dir)//Caso 2
//             {
//                 if (pai->esq == p)
//                 {
//                     if (p->esq) pai->esq = p->esq;
//                     else pai->esq = p->dir;
//                 }
//                 else 
//                 {
//                     if (p->esq) pai->dir = p->esq;
//                     else pai->dir = p->dir;
//                 }
//                 free(p);
//             }
//             else //Caso 3
//             {

//             }
//         }

//         else //Raiz não existe
//         {
//             if (!p->esq && !p->dir)
//             {
//                 free (p);
//                 p = NULL;
//             }
//             if (!p->esq || !p->dir)
//             {
//                 NO* aux = p;
//                 if (p->esq) p = p->esq;
//                 else p = p->dir;
//                 free(aux);
//             }
//         }
//     }
//     return p;
// }

void excluirABB(NO* p, NO* pai){
    if (!p) return;
    if (!pai)
    {
        free (p);
        p = NULL;
        return;
    }

    
}

int main (){
    NO* raiz = NULL;
    inserirABB(&raiz, 100);
    inserirABB(&raiz, 200);
    inserirABB(&raiz, 20);
    inserirABB(&raiz, 179);
    inserirABB(&raiz, 75);
    exibir(raiz);
    printf("\n");

    NO* pai = NULL;
    printf("valor procurado %i\n", buscaABBRecursiva(raiz, 200, &pai)->chave);
    printf("valor do pai %i\n", pai->chave);

    return 0;
}