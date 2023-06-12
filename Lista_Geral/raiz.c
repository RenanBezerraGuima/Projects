#include <stdio.h>
#include <math.h>

double raiz(double a){
return sqrt(a);
}

int main () {
	double a;
	printf("Insira o número que deseja saber a raiz: ");
	scanf("%lf", &a);
	printf("A raiz de %.2lf é: %.2lf", a, raiz(a));
}