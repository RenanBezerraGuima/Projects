#include <stdio.h>

void main () {
    int n, impar, i, soma, tmp;

    printf("Soma de todos os primeiros n ímpares, insira a quantidade de ímpares que deseja somar: ");
    scanf("%i", &n);

    for ( i = 0, soma = 0, impar = 1; i < n; i++ ) { 
        soma = impar + soma;
        impar = 2 + impar;
    }
    printf("\nA soma dos primeiros %i números ímpares é: %i\n",n ,soma);

}