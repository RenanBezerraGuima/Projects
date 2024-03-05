#include <stdio.h>
// Escreva uma função recursiva que calcule a soma dos elementos positivos do vetor
// v[ini..fim-1]. O problema faz sentido quando ini é igual a fim? Quanto deve valer a soma
// nesse caso?

// Quando ini é igual a fim então só há

int somaPositivos2 (int vetor[], int vetorTam, int ini, int fim){
    if ((ini == fim-1) && vetor[ini] > 0) return vetor[ini];

    else if (vetor[fim-1] > 0) return vetor[fim-1] + somaPositivos2(vetor, vetorTam, ini, fim-1);
    else if (vetor[fim-1] < 0) return somaPositivos2(vetor, vetorTam, ini, fim-1);

    return -1;
}

int main(){
    printf("Insira o tamanho do vetor que deseja utilizar a funcao: ");

    int tam;
    scanf("%i", &tam);
    if (tam < 0) { 
        printf("Tamanho negativo de vetor\n");
        return -1;
    }
    int vetor[tam];

    printf("Insira os numeros deste vetor com espaco entre os numeros: \n");
    for (int i = 0; i < tam; i++)
    {
        scanf("%i", &vetor[i]);
    }

    printf("%i", somaPositivos2(vetor,tam,0,tam));

    return 0;
}