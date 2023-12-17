#include <stdio.h>

void main () {
    
    float salario, imposto, salarioimposto;

    printf("Insira seu salário: ");
    scanf("%f", &salario);

    if ( salario < 1903.98) {
        printf("\nVocê está na faixa1, portanto é isento do imposto de renda\n\n");
        salarioimposto = salario;
        printf("Seu salário pós imposto é: %.2f\n\n", salarioimposto);
    }
    else if ( salario >= 1903.99 && salario < 2826.65 ) {
        printf ("\nVocê está na faixa2, portanto deve 7,5%% de imposto de renda\n\n");
        salarioimposto = salario * 0.925;
        printf("Seu salário pós imposto é: %.2f\n\n", salarioimposto);
    }
    else if ( salario >= 2826.66 && salario < 3751.05 ) {
        printf ("\nVocê está na faixa3, portanto deve 15%% de imposto de renda\n\n");
        salarioimposto = salario * 0.85;
        printf("Seu salário pós imposto é: %.2f\n\n", salarioimposto);
    }
    else if ( salario >= 3751.06 && salario < 4664.68 ) {
        printf ("\nVocê está na faixa4, portanto deve 22,5%% de imposto de renda\n\n");
        salarioimposto = salario * 0.775;
        printf("Seu salário pós imposto é: %.2f\n\n", salarioimposto);
    }
    else {
        
        printf ("\nVocê está na faixa5, portanto deve 27,5%% de imposto de renda\n\n");
        salarioimposto = salario * 0.725;
        printf("Seu salário pós imposto é: %.2f\n\n", salarioimposto);
    }
}