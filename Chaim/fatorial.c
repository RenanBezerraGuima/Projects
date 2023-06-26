#include <stdio.h>

unsigned long long int calcularFatorial(int numero) {
    unsigned long long int fatorial = 1;

    for (int i = 1; i <= numero; i++) {
        fatorial *= i;
    }

    return fatorial;
}

int main() {
    int numero;

    printf("Digite um numero: ");
    scanf("%d", &numero);

    if (numero < 0) {
        printf("O fatorial não pode ser calculado para numeros negativos.\n");
    } else {
        unsigned long long int resultado = calcularFatorial(numero);
        printf("O fatorial de %d eh: %lld\n", numero, resultado);
    }

    return 0;
}
