#include <stdio.h>

int main () {
    int tempC;
    float tempF, tempK;

    scanf("%i", &tempC);
    tempF = (tempC * 1.8) + 32;
    tempK = tempC + 273;

    printf("Akira, a temperatura na Inglaterra em Fahrenheit eh %.1f e a temperatura em Kelvin eh %.1f\n", tempF, tempK);

    return 0;
}