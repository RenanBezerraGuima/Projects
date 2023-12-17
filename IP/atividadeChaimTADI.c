#include <stdio.h>
#include <stdlib.h>

//Arranjo ordenado: 
  // Média V
  // Mediana V
  // 1º e 3º quartil 
    
//Dado um arranjo a de tamanho n, ordenado, calcule a mediana, média, o 1º quartil e 3º quartil

void algoritmo(int arranjo[], int tam)
{
  int inicio = 0;
  int fim = tam;
  
  //Média
  float soma = 0, media;
  for ( int i=0; i< tam; i++)
  {
      soma = arranjo[i] + soma;
  }
  media = soma/tam;

  //Mediana
  int mediana = arranjo[tam/2];

  //1º Quartil
  
  
  
  
  

  printf("\nA media eh de %.2f\n", media);
  printf("A mediana eh de %i\n", mediana);
  

}

int main() {
    int arranjo[] = {1,2,3,4,5,6,7,8,9};

    algoritmo(arranjo,9);

    int arranjo2[] = {1,2,3,4,5,6,7,8,9,10};

    algoritmo(arranjo2,10);

  return 0;
}