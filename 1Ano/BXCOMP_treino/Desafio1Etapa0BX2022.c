#include <stdio.h>
#define IDEAL 0.14

int main (){
    int iteracoes;

    float l1, l2;
    float pa1, pa2;
    float alcoolFinal, paFinal;

    scanf("%i", &iteracoes);

    for (int i = 0; i < iteracoes; i++)
    {
        scanf("%f %f %f %f", &l1, &pa1, &l2, &pa2);

        alcoolFinal = ((l1*pa1) + (l2*pa2));
        paFinal = alcoolFinal/(l1 + l2);

        if (paFinal < IDEAL) printf("Mo comedia essa mistura, presta nao\n"); 
        else if (paFinal == IDEAL) printf("Bao demais que esse ta no ponto, vai ate esquentar\n");
        else if (paFinal > IDEAL)
        {
            if (pa1 > pa2) printf("Arriegua tonhao, mistura tudo, o que sobrar de 1 vou estourar na garganta\n");
            if (pa2 > pa1) printf("Arriegua tonhao, mistura tudo, o que sobrar de 2 vou estourar na garganta\n");
        }
    }

    return 0;
}