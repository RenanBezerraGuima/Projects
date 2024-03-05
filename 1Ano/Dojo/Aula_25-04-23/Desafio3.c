#include <stdio.h>
#define pi 3.14159

int main () {
    double a,b,c;
    double areatrianguloretangulo, areacirculo, areatrapezio, areaquadrado, arearetangulo;

    scanf("%lf %lf %lf", &a, &b, &c);
    areatrianguloretangulo = (a * c) / 2;
    areacirculo = pi * c * c;
    areatrapezio = ((a + b) * c) / 2;
    areaquadrado = b * b;
    arearetangulo = a * b;

    printf("TRIANGULO: %.2f\n", areatrianguloretangulo);
    printf("CIRCULO: %.2f\n", areacirculo);
    printf("TRAPEZIO: %.2f\n", areatrapezio);
    printf("QUADRADO: %.2f\n", areaquadrado);
    printf("RETANGULO: %.2f\n", arearetangulo);


    return 0;
}