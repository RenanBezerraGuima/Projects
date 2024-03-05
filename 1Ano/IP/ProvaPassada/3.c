#include <stdio.h>

double areaRetangulo(double lado1, double lado2){
    double area;

    area = lado1 * lado2;

    return area;
}

double areaDoQuadrado(double lado){
    double area;

    area = areaRetangulo(lado,lado);

    return area;
}

void main () {
    double lado;

    printf("Insira o lado do quadrado: ");
    scanf("%lf", &lado);

    printf("A area do quadrado é %.2lf\n",areaDoQuadrado(lado));

}