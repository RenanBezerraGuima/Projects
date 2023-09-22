#include <stdio.h>

int busca(int v[], int numero)
{
    int indice;

    for (int i = 0; i < 10; i++)
    {
        if (v[i] == numero)
        {
            indice = i
            return indice
        } 
    }
    return -1;
}

int main (){
    int iteracoes;

    int vetor[10];

    scanf("%i", &iteracoes);

    for (int i = 0; i < iteracoes; i++)
    {
        //Coloca o vetor do teste
        for (int j = 0; j < 10; j++)
        {
            scanf("%i", vetor[j]);
        }

        
    }

    return 0;
}