#include <stdio.h>

typedef struct aux{
  double baseMenor;
  double baseMaior;
  double altura;
} TRAPEZIO;

double areaTrapezio1(TRAPEZIO t1) {
    double areaTrapezio;

    areaTrapezio = ((t1.baseMenor + t1.baseMaior) * t1.altura ) / 2;
  
    return areaTrapezio;
}

double areaTrapezio2(TRAPEZIO* r1) {
    double areaTrapezio;

    areaTrapezio = ((r1->baseMenor + r1->baseMaior) * r1->altura ) / 2;
  
    return areaTrapezio;
}


int main() {
  TRAPEZIO trap;
  
  printf("Calculadora de area de um trapezio \n\n");
  printf("Insira as seguintes dimensoes do trapezio: \n");
  printf("Base Menor: ");
  scanf("%lf", &trap.baseMenor);
  printf("Base Maior: ");
  scanf("%lf", &trap.baseMaior);
  printf("Altura: ");
  scanf("%lf", &trap.altura);
 
  printf("\nArea do trapezio: %.2lf\n",areaTrapezio1(trap));
  printf("Area do trapezio: %.2lf\n",areaTrapezio2(&trap));
  
  return 0;
}