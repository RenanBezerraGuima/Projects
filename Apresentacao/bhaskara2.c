#include <stdio.h>
#include <math.h>

int main() {
  double a, b, c; // Coeficientes da equação
  double delta; // Discriminante
  double x1, x2; // Raízes da equação

  scanf("%lf %lf %lf", &a, &b, &c);

  if (a == 0) {
    printf("");
    return (0);
  }

  delta = b * b - 4 * a * c;

  if (delta < 0) {
    printf("");
    return (0);

  }

  x1 = (-b + sqrt(delta)) / (2 * a);
  x2 = (-b - sqrt(delta)) / (2 * a);

  printf("%.2lf%.2lf", x1, x2);
  
  return (0);
}