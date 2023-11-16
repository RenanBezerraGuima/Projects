#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ######### ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("14605640");
}

// ######### ESCREVA SEU NOME AQUI
char* nome() {
    return("Renan Bezerra Guimarães");
}

// elemento da lista
typedef struct estr {
        int chave;
        struct estr* prox;
} NO;

void removerCompartilhados(NO* *p1, NO* *p2) {
	NO* pl1 = (*p1);
    NO* antl1 = NULL;
    NO* pl2 = (*p2);
    NO* antl2 = NULL;

    while (pl1) 
    {
        pl2 = (*p2);
        while (pl2) 
        {
            if (pl1 == pl2)
            {
                if (antl1) antl1->prox = pl1->prox;
                else (*p1) = pl1->prox; 
                if (antl2) antl2->prox = pl2->prox;
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

// por favor nao inclua nenhum codigo a ser entregue abaixo deste ponto

//----------------------------------------------------------------
// use main() apenas para fazer chamadas de teste ao seu programa
//----------------------------------------------------------------
int main() {

	NO* p1_1 = (NO*) malloc(sizeof(NO));
    p1_1->chave = 10;
    NO* p1_2 = (NO*) malloc(sizeof(NO));
    p1_2->chave = 20;
    p1_1->prox = p1_2;
    NO* p1_3 = (NO*) malloc(sizeof(NO));
    p1_3->chave = 30;
    p1_2->prox = p1_3;
    p1_3->prox = NULL;

	NO* p2_1 = (NO*) malloc(sizeof(NO));
    p2_1->chave = 10;
    NO* p2_2 = (NO*) malloc(sizeof(NO));
    p2_2->chave = 20;
    p2_1->prox = p2_2;
    p2_2->prox = NULL;

    NO* p3 = (NO*) malloc(sizeof(NO));
    p3->chave = 99;
    p3->prox = NULL;
    p1_3->prox = p3;
    p2_2->prox = p3;

    NO* p4 = (NO*) malloc(sizeof(NO));
    p4->chave = 99;
    p4->prox = NULL;
    p3->prox = p4;
    
	removerCompartilhados(&p1_1, &p2_1);
    return 0;
}

