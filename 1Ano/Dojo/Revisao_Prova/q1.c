#include <stdio.h>
#include <stdlib.h>

void insereNota(int* notas){
    int temp;
    for ( int i=0; i<5; i++){
        scanf("%i",&notas[i]);
    }
}

int notasInvalidas(int* notas){
    int qtdNotasInvalidas = 0;

    for( int j=0; j<5; j++){
        if (notas[j] < 0) qtdNotasInvalidas++;
    }
    return qtdNotasInvalidas;
}

int main () {
    int* notas = (int*)malloc(5*(sizeof(int)));

    insereNota(notas);

    printf("Quantidade de notas inválidas: %i\n", notasInvalidas(notas));

    for(int x=0; x<5; x++){
        printf("%i\n",notas[x]);
    }

    free(notas);
    return 0;
}