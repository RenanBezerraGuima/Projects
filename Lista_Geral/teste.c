#include <stdio.h>
#include <stdlib.h>

int main () {
  int n;
  int * p;
  
  printf("Insira até que número positivo e inteiro deseja ver: \n");
  scanf("%i", &n);

  if (n<0) printf("Valor negativo\n");
  

  
  p = (int*) malloc(sizeof(int)*n);
  int soma = 0;
  for (int i=0;i<=n;i=i+2){
    p[i]=i;
    soma = soma + p[i];
    printf("%i ",p[i]);
  }
  printf("\n");
  printf("A soma de todos os números são: %i\n",soma);


}