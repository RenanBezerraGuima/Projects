#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura{
	int lin;
	int col;
	int info;
	struct estrutura* prox;
}NO;

typedef struct{
	NO* inicio;
	int maxlin;
	int maxcol;
}MATRIZ;

void inicializar(MATRIZ* m){
    m->inicio = NULL;
    m->maxcol = 8;
    m->maxlin = 8;
}

NO* busca(MATRIZ* m, int i,int j, NO* *ant){
    *ant = NULL;
    NO* p = m->inicio;
    while(p){
        if ((p->lin == i) && (p->col == j)) return p;
        else if (p->lin > i) return NULL;
        *ant = p;
        p = p->prox;
    }
    return NULL;
}


void inserir(int info, int i, int j, MATRIZ* m){
    NO* ant = NULL;
    NO* atual = busca(m, i, j, &ant);
    if (atual) return; //Elemento já existe
    NO* novo = (NO*) malloc(sizeof(NO));
    novo->info = info;
    novo->lin = i;
    novo->col = j;
    if(ant){ //Elemento no meio
        novo->prox = ant->prox;
        ant->prox = novo;        
    } else {//Elemento no começo ou lista vazia
        novo->prox = m->inicio;
        m->inicio = novo;
    }    
}

void criarMatriz(int L, int C, int matriz[L][C], MATRIZ* m){
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (matriz[i][j] != 0) 
            {
                inserir(matriz[i][j], i, j, m);
            }
        }
    }
}

void exibir (MATRIZ* m){
    NO* p = m->inicio;
    while (p) 
    {
        printf("%i ", p->info);
        p = p->prox;
    }
    printf("\n");
}

int valor(MATRIZ* m, int i, int j){
    NO* p = m->inicio;
    if (!p) return 0;
    while (p)
    {
        if((p->lin == i) && (p->col == j)) return p->info;
        else if(p->lin > i) return 0;
        else if((p->lin == i) && (p->col > j)) return 0;
        p = p->prox;
    }
    return 0;
}

void zerarDiagonalPrincipal(MATRIZ* m){
    NO* ant = NULL;
    NO* p = m->inicio;
    
    if (!p) return;
    while (p)
    {
        if (p->lin == p->col)
        {
            if (!ant) m->inicio = p->prox;
            else ant->prox = p->prox;

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

int main(){
    MATRIZ m;
    inicializar(&m);
    int matriz[8][8] = 
    {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,10,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,20,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,30,0,0},
        {0,0,0,0,0,0,0,0}
    };

    criarMatriz(8,8, matriz, &m);
    exibir(&m);

    zerarDiagonalPrincipal(&m);
    exibir(&m);
    return 0;
}