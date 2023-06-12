#include <stdio.h>

// Pede ao usuário dois números, e testa se eles são par ou ímpar individualmente, printando os resultados.

void verifica(int numero) {
    if ( numero % 2 == 0) printf("%i é par.\n", numero);
    else printf("%i é ímpar.\n", numero);
}

int main () {
    
    int num1, num2;

    printf("Insira os dois números que deseja testar: \n");
    scanf("%i %i", &num1, &num2);

    verifica(num1);
    verifica(num2);

    return 0;
}