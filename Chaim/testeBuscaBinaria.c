#include <stdio.h>
#include <stdlib.h>

//Dado um arranjo a de tamanho n, ordenado, calcule a mediana, média, o 1º quartil e 3º quartil

void algoritmo(int arranjo[], int tam)
{
    int inicio = 0;
    int fim = tam;
    int meio = (fim + inicio) / 2;
    
    //Média
    float soma = 0, media;
    for ( int i=0; i< tam; i++)
    {
        soma = arranjo[i] + soma;
    }
    media = soma/tam;

    //Mediana
    int mediana = arranjo[meio];

    printf("%f\n", media);
    printf("%i\n", meio);

}

int buscaBin(int arr[],int tam, int el)
{
  int fim = tam-1;
  int ini = 0;
  while (ini <= fim)
  {
    int meio = (fim + ini)/2;
    if (arr[meio] < el)
    ini = meio + 1;
    else 
    {
        if (arr[meio] > el)
        fim = meio - 1;
        else return meio;
    }
  }
  return -1;
}

int main() {
    int arranjo[] = {1,2,3,4,5,6,7,8,9,10};

    algoritmo(arranjo,10);
  
  return 0;
}