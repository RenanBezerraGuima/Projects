#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int linha;
    char operacao;

    scanf("%i %c",&linha,&operacao);

    //Criação matriz 12x12
    float** matriz = (float**) malloc(sizeof(float*)*12);
    for (int i=0; i<12; i++)
    {
        matriz[i] = (float*) malloc(sizeof(float)*12);
    }
    
    for (int i=0; i<12; i++)
    {
        for (int j=0; j<12; j++)
        {
            scanf("%f", &matriz[i][j]);
        }
    }

    if(operacao == 'S')
    {
        float somaTotal = 0;
        for (int j=0; j<12; j++)
        {
            somaTotal = matriz[linha][j] + somaTotal;
        }
        printf("%.1f\n", somaTotal);
    }
    
    if(operacao == 'M')
    {
        float somaTotal = 0;

        for (int j=0; j<12; j++)
        {
            somaTotal = matriz[linha][j] + somaTotal;
        }
        printf("%.1f\n", somaTotal/12);
    }
    
    return 0;
}