#include <stdio.h>
#include <stdlib.h>

//Dado um arranjo a de tamanho n, ordenado, calcule a mediana, média, o 1º quartil e 3º quartil

void algoritmo(int arranjo[], int tam)
{
    printf("Medidas do Arranjo:\n");
    for (int i=0;i<tam;i++)
    {
      printf("%i ", arranjo[i]);
    }
    printf("\n\n");

    //Média
    double soma = 0, media;
    for ( int i=0; i< tam; i++)
    {
        soma = arranjo[i] + soma;
    }
    media = soma/tam;
    

    //Mediana
    int meio = (tam+1)/2;
    double mediana;
    if ((tam+1)%2 == 0) mediana = arranjo[meio-1];
      else 
      {
        double somaMediana = arranjo[meio] + arranjo[meio-1];
        mediana = somaMediana/2;
      }
    printf("A media eh de %.2lf\n", media);
    printf("A mediana eh de %.2lf\n", mediana);
    printf("\n");
}

int main() {
    int arranjo[] = {1,2,3,4,5,6,7,8,9,10};
    int arranjo2[] = {1,2,3,4,5,6,7,8,9};

    printf("Calculadora de Media e Mediana\n\n");
    algoritmo(arranjo,10);
    algoritmo(arranjo2,9);
  
  return 0;
}