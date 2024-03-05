#include <stdio.h>
#include <math.h>

int main(){
    float a, b, c, x1, x2, delta;
    a = 2, b = 9, c = 7;
    delta = b*b - 4*a*c;
    x1 = (-b + sqrt(delta)) / (2*a);
    x2 = (-b - sqrt(delta)) / (2*a);

    if (delta < 0 ) printf("A equação não possui raizes reais");

    if (delta == 0 ) printf("A equação possui apenas uma raíz real: %.2f", x1);

    if (delta > 0 ) {
        printf("O valor de x1: %.2f\n", x1);
        printf("O valor de x2: %.2f\n", x2);
    }
    return 0;
}