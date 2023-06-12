#include <stdio.h>

int main () {
    float salariofinal, salariofixo, vendas;
    
    scanf("%f %f", &salariofixo, &vendas);
    salariofinal = salariofixo + vendas * 0.15;
    printf("O salario da Heleninha eh R$ %.2f\n", salariofinal);

    return 0;
}