#include <stdio.h>
// Escreva uma função recursiva que calcule a soma dos elementos positivos do vetor de
// inteiros v[0..n-1]. O problema faz sentido quando n é igual a 0? Quanto deve valer a soma
// nesse caso?

// Resposta:Quando n é igual a zero não nenhum elemento então se soma 0 aos resto das outras somas


int somaPositivos(int vetor[], int vetorTam){
    if(vetorTam == 0) return 0;

    if (vetor[vetorTam-1] > 0) return vetor[vetorTam-1] + somaPositivos(vetor,vetorTam-1);
    else if (vetor[vetorTam-1] < 0) return somaPositivos(vetor,vetorTam-1);

    return -1;
}

int main (){
    int vetor[] = {-1,2,3,-4,5,-6,7,8,9,-10};

    printf("%i\n",somaPositivos(vetor,10));

    return 0;
}