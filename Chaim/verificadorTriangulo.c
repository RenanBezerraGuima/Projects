#include <stdio.h>

int verificaTriangulo(double a,double b,double c){
       if ( a+b > c && a+c > b && c+b > a) {
        if (a == b && b== c) {
            printf("\nEh um triangulo equilatero.\n");
            return 0;
        }
        
        if (a == b || b == c || a == c) printf("\nEh um triangulo isosceles.\n"); 
        
        else printf("\nEh um triangulo escaleno.\n");

    }
    else printf("\nNao eh um triangulo.\n");
    return 0;
}

int main () {
    double a,b,c;

    printf("Insira tres numeros reais positivos: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    verificaTriangulo(a,b,c);

    return 0;
}