#include <stdio.h>

int main () {
    int n;

    printf("Insira um numero natural: ");
    scanf("%i", &n);

    if (n < 0) {
        printf("Nao eh um numero natural.\n");
        return 0;
    }

    int soma = 0,resto,dividendo = n;

    while ( resto != 0) {
        resto = dividendo % 10;
        soma = resto + soma;
        dividendo = dividendo / 10; 
    }
    printf("A soma dos algarismos deste numero natural sao: %i\n", soma);
    return 0;
}