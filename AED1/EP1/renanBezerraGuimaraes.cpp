#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

// ######### ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("14605640");
}

// ######### ESCREVA SEU NOME AQUI
char* nome() {
    return("Renan Bezerra Guimaraes");
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

    // Percorre a lista 1 comparando com a lista 2 e excluindo os elementos iguais (mesmo endereço)
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

    // Transforma as listas em listas circulares
    pl1 = (*p1);
    pl2 = (*p2);

    while (pl1->prox){
    pl1 = pl1->prox;
    }
    pl1->prox = (*p1);
    
    while (pl2->prox){
      pl2 = pl2->prox;
    }
    pl2->prox = (*p2);
}