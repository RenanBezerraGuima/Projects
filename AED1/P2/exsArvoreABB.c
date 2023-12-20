#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define COUNT 10

typedef struct arvore{
    int chave;
    struct arvore* esq;
    struct arvore* dir;
}NO;

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

// EmOrdem inversa (direita - raiz - esquerda)
void print2DUtil(NO* root, int space)
{
    // Caso base
    if (root == NULL)
        return;
 
    // Aumenta a distancia entre niveis
    space += COUNT;
 
    // Começa pela direita
    print2DUtil(root->dir, space);
 
    // Print na raiz atual
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->chave);
 
    // Esquera da arvore
    print2DUtil(root->esq, space);
}
 
// Função para o usuario
void print2D(NO* root)
{
    printf("--------------------\n");
    // Passa o contador inicial como 0
    print2DUtil(root, 0);
}

bool verificaABB(NO* p){
    if (p)
    {
        if(p->esq && p->esq->chave > p->chave) return false;
        if(p->dir && p->dir->chave < p->chave) return false;
        if(!verificaABB(p->esq)) return false;
        if(!verificaABB(p->dir)) return false;
    }
    return true;
}

bool verificaAssimetria(NO* p){
    if(p)
    {
        if(p->esq && p->dir) return false;
        if(!verificaAssimetria(p->esq)) return false;
        if(!verificaAssimetria(p->dir)) return false;
    }
    return true;
}

bool verificaCheia(NO* p){
    if(p)
    {
        if((p->esq && !p->dir) || (p->dir && !p->esq)) return false;
        if(!verificaCheia(p->esq)) return false;
        if(!verificaCheia(p->dir)) return false;
    }
    return true;
}

typedef struct lista{
    int chave;
    struct lista* prox;
}NOL;

void listarMaiores(NO* p, int n, NOL** inicio){
    if(p)
    {
        if(p->chave > n)
        {
            NOL* novo = (NOL*) malloc(sizeof(NOL));
            novo->chave = p->chave;
            novo->prox = *inicio;
            *inicio = novo;
        }
        listarMaiores(p->esq, n, inicio);
        listarMaiores(p->dir, n, inicio);
    }
}

void antecessorABB(NO* p, int ch, int* resp){
    if(p)
    {
        if(p->chave < ch && p->chave > *resp) *resp = p->chave;//Testo a raiz e atualizo
        if(ch > p->chave) antecessorABB(p->dir, ch, resp);
        else antecessorABB(p->esq, ch, resp);
    }
}

void exibirNmaiores(NO* p, int* n){
    if(p)
    {
        exibirNmaiores(p->dir, n);
        if(*n > 0)
        {
            printf("%i ", p->chave);
            *n = *n - 1;
        }
        if(*n > 0) exibirNmaiores(p->esq, n);
    }
}

void espelharArvore(NO* p){
    if(p)
    {
        NO* aux = p->esq;
        p->esq = p->dir;
        p->dir = aux;
        espelharArvore(p->esq);
        espelharArvore(p->dir);
    }
}

typedef struct fila {
    NO* no;
    struct fila* prox;
} FILA;

void enfileirar(FILA** inicio, FILA** fim, NO* no) {
    FILA* novo = (FILA*) malloc(sizeof(FILA));
    novo->no = no;
    novo->prox = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
        *fim = novo;
    } else {
        (*fim)->prox = novo;
        *fim = novo;
    }
}

NO* desenfileirar(FILA** inicio) {
    if (*inicio == NULL) return NULL;

    NO* no = (*inicio)->no;
    FILA* temp = *inicio;
    *inicio = (*inicio)->prox;
    free(temp);

    return no;
}

void exibirNproximosRaiz(NO* raiz, int N){
    if (!raiz) return;

    FILA* inicio = NULL;
    FILA* fim = NULL;
    enfileirar(&inicio, &fim, raiz);

    while (inicio) {
        NO* no = desenfileirar(&inicio);
        if(no->chave != raiz->chave) 
        {
            printf("%i ", no->chave);
            N--;
        }
        
        if (N == 0) break;
        if (no->esq != NULL) 
            enfileirar(&inicio, &fim, no->esq);

        if (no->dir != NULL) 
            enfileirar(&inicio, &fim, no->dir);
    }
}

void paiComum(NO* p, NO* filho, NO** pai){
    if(p)
    {
        if ((p->esq == filho) || (p->dir == filho)) *pai = p;
        paiComum(p->esq, filho, pai);
        paiComum(p->dir, filho, pai);
    }
}

NO* encontrarPaiComum(NO* raiz, int ch){
    if (!raiz) return NULL;
    NO* pai = NULL;
    NO* filho;
    filho = buscaABB(raiz, ch, &pai);
    if (!filho) return NULL;

    pai = NULL;
    paiComum(raiz, filho, &pai);
    return pai;
}

NO* encontrarPaiABB(NO* raiz, int ch) {
    if (!raiz || raiz->chave == ch) return NULL;

    NO* pai = NULL;
    NO* atual = raiz;

    while (atual) 
    {
        if (ch < atual->chave) 
        {
            pai = atual;
            atual = atual->esq;
        } 
        else if (ch > atual->chave) 
        {
            pai = atual;
            atual = atual->dir;
        } 
        else break;
    }
    return pai;
}

NO* ancestralComumABB(NO* raiz, int ch1, int ch2){
    if (!raiz) return NULL;

    NO* pai1 = NULL;
    NO* pai2 = NULL;
    pai1 = encontrarPaiABB(raiz, ch1);
    pai2 = encontrarPaiABB(raiz, ch2);

    while (pai1 != pai2)
    {
        pai1 = encontrarPaiABB(raiz, pai1->chave);
        pai2 = encontrarPaiABB(raiz, pai2->chave);        
    }

    return pai1;
}

int tamanhoFila(FILA* inicio){
    if (!inicio) return -1;
    FILA* p = inicio;

    int contador = 0;
    while(p)
    {
        contador++;
        p = p->prox;
    }
    return contador;
}

void exibirNivelN(NO* raiz, int N){
    if (!raiz) return;

    FILA* inicio = NULL;
    FILA* fim = NULL;
    enfileirar(&inicio, &fim, raiz);
    int nivel = 1;

    while(inicio)
    {
       int tamNivel = tamanhoFila(inicio);//Acho o tamanho do nivel 

       if (nivel == N)
       {
        for(int i = 0; i < tamNivel; i++)//Passo por todos os elementos de um nivel
        {
            NO* no = desenfileirar(&inicio);
            printf("%i ", no->chave);
        }
        printf("\n");
        return;
       }

        for(int i = 0; i < tamNivel; i++)//Enfileiro todos os elementos de um nivel
        {
            NO* no = desenfileirar(&inicio);

            if(no->esq) enfileirar(&inicio, &fim, no->esq);
            if(no->dir) enfileirar(&inicio, &fim, no->dir);
        }
        nivel++;
    }
}

int qtdNiveis(NO* raiz){
    if (!raiz) return 0;

    FILA* inicio = NULL;
    FILA* fim = NULL;
    enfileirar(&inicio, &fim, raiz);

    int nivel = 0;
    while(inicio)
    {
       int tamNivel = tamanhoFila(inicio);//Acho o tamanho do nivel 

        for(int i = 0; i < tamNivel; i++)//Desenfileira o nivel atual e enfileira todos os elementos do proximo
        {
            NO* no = desenfileirar(&inicio);

            if(no->esq) enfileirar(&inicio, &fim, no->esq);
            if(no->dir) enfileirar(&inicio, &fim, no->dir);
        }
        nivel++;
    }
    return nivel;
}

void moverSubArvoreEsq2(NO* raiz, NO* p1, NO* p2){
    NO* pai1 = encontrarPaiComum(raiz, p1->chave);
    if (!pai1) return;

    if(pai1->esq == p1) pai1->esq = NULL;
    else pai1->dir = NULL;

    p2->esq = p1;
}

void excluirFilhosComunas(NO* p){
    if(p)
    {
        excluirFilhosComunas(p->esq);
        excluirFilhosComunas(p->dir);
        if(p->esq && !p->dir)
        {
            free(p->esq);
            p->esq = NULL;
        }
    }
}

void exibirNivel(NO* raiz){
    if (!raiz) return;

    FILA* inicio = NULL;
    FILA* fim = NULL;
    enfileirar(&inicio, &fim, raiz);

    while (inicio) 
    {
        int tamNivel = tamanhoFila(inicio);

        for(int i = 0; i < tamNivel; i++)
        {
            NO* no = desenfileirar(&inicio);
            printf("%i ", no->chave);
            if (no->esq)
                enfileirar(&inicio, &fim, no->esq);
            if (no->dir)
                enfileirar(&inicio, &fim, no->dir);
        }   
        printf("\n");    
    }
}

NO* buscaABBInterna(NO* p, int ch, NO** pai, bool* achou){
	if(p)
	{
		if(p->chave == ch)
		{
			*achou = true;
			return p;
		}
		else if (!*achou) 
		{
			*pai = p;
            NO* temp;
            if (ch > p->chave)
                temp = buscaABBInterna(p->dir, ch, pai, achou);
            else 
                temp = buscaABBInterna(p->esq, ch, pai, achou);
			if(achou) return temp;
		}
	}
    return NULL; 
}

NO* buscaABBRecursiva(NO* raiz, int ch, NO** pai){
	bool achou = false;
	if(!raiz) return NULL;
    
	return (buscaABBInterna(raiz, ch, pai, &achou));
}

int main (){
    NO* raiz = NULL;
    
    inserirABB(&raiz, 11);
    inserirABB(&raiz, 10);
    inserirABB(&raiz, 20);
    inserirABB(&raiz, 15);
    inserirABB(&raiz, 12);
    inserirABB(&raiz, 5);
    inserirABB(&raiz, 6);
    inserirABB(&raiz, 2);
    inserirABB(&raiz, 4);
    inserirABB(&raiz, 3);
    inserirABB(&raiz, 8);
    inserirABB(&raiz, 9);
    inserirABB(&raiz, 7);

    int temp;
    printf("Insira uma chave: ");
    scanf("%i", &temp);
    NO* pai = NULL;
    NO* noTemp = buscaABBRecursiva(raiz, temp, &pai);
    if (!pai) printf("Nao existe o pai\n");
    else printf("A pai de %i eh %i", temp, pai->chave); 

    return 0;
}