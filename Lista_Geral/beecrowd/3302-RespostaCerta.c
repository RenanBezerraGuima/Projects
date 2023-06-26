#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int N,numPergunta = 1;
    scanf("%i", &N);

    int* matriz = (int*) malloc(sizeof(int)*N);

    for (int i = 0; i < N; i++)
    {
        scanf("%i", &matriz[i]);
    }

    for (int i = 0; i < N; i++)
    {
        printf("resposta %i: %i\n", numPergunta, matriz[i]);
        numPergunta++;
    }

    return 0;
}