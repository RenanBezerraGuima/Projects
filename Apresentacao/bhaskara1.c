#include <stdio.h>
#include <math.h>

int main() {
  double a, b, c; // Coeficientes da equação
  double delta; // Discriminante
  double x1, x2; // Raízes da equação


  printf("\n\t Calculadora das raízes da equação quadrática\n");
  printf("\t Uma equação quadrática tem esse modelo:\n\t ax^2 + bx + c\n\n");
  printf("Digite os valores de a, b e c separados por espaços:\n");
  scanf("%lf %lf %lf", &a, &b, &c);

  if (a == 0) {
    printf("Não é uma equação quadrática, o ""a"" é igual a 0.\n");
    return (0);
  }

  delta = b * b - 4 * a * c;

  if (delta < 0) {
    printf("Não há raizes reais para essa equacão.\n");
    return (0);

  }

  x1 = (-b + sqrt(delta)) / (2 * a);
  x2 = (-b - sqrt(delta)) / (2 * a);

  if ( x1 == x2 ) {
    printf("O delta é igual a 0, portanto só tem uma raiz, que é: %2.lf\n", x1);
    return (0);
  }

  printf("As raízes da equação são: %.2lf e %.2lf\n", x1, x2);
  
  return (0);
}