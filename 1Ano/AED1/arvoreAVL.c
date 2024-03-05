#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define COUNT 10

typedef struct estrutura{
    int chave;
    struct estrutura* esq;
    struct estrutura* dir;
    int bal;//Fator de balanceamento (0, -1 ou +1)
}NO;

NO* rotacaoL(NO* p){
    NO* u;
    NO* v;
    u = p->esq;
    if(u->bal == -1)//LL
    {
        p->esq = u->dir;
        u->dir = p;
        p->bal = 0;
        p = u;
    }
    else//LR
    {
        v = u->dir;
        u->dir = v->esq;
        v->esq = u;
        p->esq = v->dir;
        v->dir = p;
        if(v->bal == -1) p->bal = 1;
        else p->bal = 0;
        if(v->bal == 1) u->bal = -1;
        else u->bal = 0;
        p = v;
    }
    p->bal = 0;
    return(p);
}

NO* rotacaoR(NO* p){
    NO* u;
    NO* v;
    u = p->dir;
    if(u->bal == 1) // RR
    {
        p->dir = u->esq;
        u->esq = p;
        p->bal = 0;
        p = u;
    }
    else // RL
    {
        v = u->esq;
        u->esq = v->dir;
        v->dir = u;
        p->dir = v->esq;
        v->esq = p;
        if(v->bal == 1) p->bal = -1;
        else p->bal = 0;
        if(v->bal == -1) u->bal = 1;
        else u->bal = 0;
        p = v;
    }
    p->bal = 0;
    return(p);
}

// Inserção AVL: p é inicializado com raiz e *ajustar com false.
// O retorno da função de mais alto nível é a raiz da árvore, possivelmente
// alterada caso tenha sofrido rotação ou seja a primeira inserção da estrutura.
// Assim, a chamada principal deve ser raiz = inserirAVL(raiz,ch,&ajustar);
NO* inserirAVL(NO* p, int ch, bool* ajustar) {
    if(!p) 
    {
        p = (NO *) malloc(sizeof(NO));
        p->esq = NULL;
        p->dir = NULL;
        p->chave = ch;
        p->bal = 0;
        *ajustar = true;
    }
    else 
    {
        if(ch < p->chave) 
        {
            p->esq = inserirAVL(p->esq, ch, ajustar);
            if(*ajustar)

            switch (p->bal) 
            {
            case 1 : p->bal = 0;
                *ajustar = false;
            break;

            case 0 : p->bal = -1;
            break; // continua verificando

            case -1: p = rotacaoL(p);
                *ajustar = false;
            break;
            }
        }
        else 
        {
            p->dir = inserirAVL(p->dir, ch, ajustar);

            if(*ajustar)
            switch (p->bal) 
            {
            case -1: p->bal = 0;
                *ajustar = false;
            break;

            case 0 : p->bal = 1;
            break; // continua verificando

            case 1 : p = rotacaoR(p);
                *ajustar = false;

            break;
            }
        }
    }
    return (p);
}

void print2DUtil(NO* raiz, int espaco)
{
    // Caso base
    if (raiz == NULL)
        return;
 
    // Aumenta a distancia entre niveis
    espaco += COUNT;
 
    // Começa pela direita
    print2DUtil(raiz->dir, espaco);
 
    // Print na raiz atual
    // count
    printf("\n");
    for (int i = COUNT; i < espaco; i++)
        printf(" ");
    printf("%d\n", raiz->chave);
 
    // Esquera da arvore
    print2DUtil(raiz->esq, espaco);
}
 
// Função para o usuario
void print2D(NO* raiz)
{
    printf("--------------------\n");
    // Passa o contador inicial como 0
    print2DUtil(raiz, 0);
}


int main(){
    NO* raiz = NULL;
    bool ajustar = false;
    raiz = inserirAVL(raiz, 11, &ajustar);
    raiz = inserirAVL(raiz, 10, &ajustar);
    raiz = inserirAVL(raiz, 20, &ajustar);
    raiz = inserirAVL(raiz, 15, &ajustar);
    raiz = inserirAVL(raiz, 12, &ajustar);
    raiz = inserirAVL(raiz, 5, &ajustar);
    raiz = inserirAVL(raiz, 6, &ajustar);
    raiz = inserirAVL(raiz, 2, &ajustar);
    raiz = inserirAVL(raiz, 4, &ajustar);
    raiz = inserirAVL(raiz, 3, &ajustar);
    raiz = inserirAVL(raiz, 8, &ajustar);
    raiz = inserirAVL(raiz, 9, &ajustar);
    raiz = inserirAVL(raiz, 7, &ajustar);

    print2D(raiz);

    return 0;
}