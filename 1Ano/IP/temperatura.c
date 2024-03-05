#include <stdio.h>

void main () {
    double tempF,tempC;

    printf("Conversor de Celcius para Fahrenheit:\n");
    printf("Insira a temperatura em Celcius: ");
    scanf("%lf", &tempC);

    tempF = 1.8 * tempC + 32;

    printf("\nSua temperatura de %.2lf°C é %.2lf°F\n\n", tempC, tempF);

}