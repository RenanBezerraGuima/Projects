#include <stdio.h>

double areaTrapezio(double baseMaior, double baseMenor, double altura)
{
    double area = 0;
    if (baseMenor != baseMaior) 
    {
        area = ((baseMenor + baseMaior) * altura ) / 2;
        printf("Area do trapézio: ");
    }
    else 
    {
        area = baseMaior * altura;
    }
	return area;
}

double areaRetangulo(double base, double altura)
{
   double area = areaTrapezio(base,base,altura);
   printf("Area do retangulo: %.2f\n", area);
   return area;
}

double areaQuadrado(double lado)
{
    double area = 0;
	area = lado * lado;
    printf("Area do quadrado: ");
    return area;
}

int main()
{
    printf("%.2f\n",areaTrapezio(3,2,1));
    areaRetangulo(11,27);
    printf("%.2f\n",areaQuadrado(5));
    return 0;
}