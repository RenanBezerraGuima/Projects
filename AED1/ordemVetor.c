#include <stdio.h>

//Função que retorna a ordem do vetor 
    //1 crescente
    //-1 decrescente
    //0 sem ordem
    //9 valor único 

int ordem (int v[], int n) {
    int crescente = 0;
    int decrescente = 0;

    for (int i = 0; i<n-1; i++)
    {
        if (v[i+1] > v[i]) crescente = 1;
        else if (v[i+1] < v[i]) decrescente = 1;
    }

    if (crescente == 0 && decrescente == 0) return 9;
    else if (crescente == 1 && decrescente == 1) return 0;
    else if (crescente == 1) return 1;
    else if (decrescente == 1) return -1;
}

int main () {
    printf("Este programa imprime qual a ordem de um dado vetor de 5 elementos\n");
    printf("\tEle retorna: \n\t 1 para crescente \n\t -1 para decrescente \n\t 0 para sem ordem \n\t 9 para um valor unico.\n");

    printf("Insira um vetor de 5 elementos: ");
    int vetor[5];
    scanf("%i %i %i %i %i", &vetor[0], &vetor[1], &vetor[2], &vetor[3], &vetor[4] );

    printf("%i\n", ordem(vetor, 5));

    return 0;
}