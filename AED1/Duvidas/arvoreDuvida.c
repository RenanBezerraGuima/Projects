#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore
typedef struct NO {
    int ch;
    struct NO* esq;
    struct NO* dir;
} NO;

typedef struct node {
    NO* data;
    struct node* next;
} NOF;

typedef struct fila {
    NOF* front;
    NOF* rear;
} Fila;

// Função para criar um novo nó
NOF* newNOF(NO* data) {
    NOF* p = (NOF*) malloc(sizeof(NOF));
    p->data = data;
    p->next = NULL;
    return p;
}

// Função para criar uma fila vazia
Fila* createFila() {
    Fila* q = (Fila*)malloc(sizeof(Fila));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Função para adicionar um elemento à fila
void enFila(Fila* q, NO* data) {
    NOF* temp = newNOF(data);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Função para remover um elemento da fila
NO* deFila(Fila* q) {
    if (q->front == NULL)
        return NULL;

    NOF* temp = q->front;
    NO* data = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);

    return data;
}

// Função para criar um novo nó
NO* criarNo(int ch) {
    NO* novo = (NO*)malloc(sizeof(NO));
    novo->ch = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

// Função para inserir um nó na árvore
NO* inserirNO(NO* raiz, int ch) {
    if (raiz == NULL) raiz = criarNo(ch);

    else if (ch <= raiz->ch) raiz->esq = inserirNO(raiz->esq, ch);

    else raiz->dir = inserirNO(raiz->dir, ch);
    return raiz;
}



// Função de percurso em nível usando fila
void percursoNivel(NO* raiz) {
    if (raiz == NULL) 
    {
        return;
    }

    // Criação de uma fila para armazenar os nós
    Fila* q = createFila();
    int nivelAtual = 1;
    int proximoNivel = 0;

    // Enfileira o nó raiz
    enFila(q, raiz);

    while (q->front != NULL) {
        // Desenfileira o nó atual e imprime seu valor
        NO* atual = deFila(q);
        printf("%d ", atual->ch);
        nivelAtual--;

        // Enfileira os nós filhos, se existirem
        if (atual->esq != NULL) {
            enFila(q, atual->esq);
            proximoNivel++;
        }
        if (atual->dir != NULL) {
            enFila(q, atual->dir);
            proximoNivel++;
        }

        if (nivelAtual == 0) {
            printf("\n");
            nivelAtual = proximoNivel;
            proximoNivel = 0;
        }
    }
    printf("\n");
}

int main() {
    NO* raiz = NULL;

    raiz = inserirNO(raiz, 50);
    raiz = inserirNO(raiz, 30);
    raiz = inserirNO(raiz, 20);
    raiz = inserirNO(raiz, 40);
    raiz = inserirNO(raiz, 70);
    raiz = inserirNO(raiz, 60);
    raiz = inserirNO(raiz, 80);

    printf("Percurso em nivel:\n");
    percursoNivel(raiz);

    return 0;
}
