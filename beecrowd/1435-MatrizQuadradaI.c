#include <stdio.h>
#include <stdlib.h>

void printMatriz (int tam)
{ 
  int num=1;  
  int tamInicial = tam;
  int ** Matriz = (int**) malloc(sizeof(int*)*tam);
  
  for ( int i = 0; i < tam; i++)
  {
    Matriz[i] = (int*) malloc(sizeof(int)*tam);
    for (int j = 0; j < tam; j++)
    { 
      Matriz[i][j] = num;
    }
  }

  int contador=1;
  while ((tam - 2) > 0 )
  {
    num++;
    tam = tam - 2;
    
    for (int i = 0; i < tam; i++)
    {
      for (int j = 0; j < tam; j++)
      { 
        Matriz[i+contador][j+contador] = num;
      }
    }
    contador++;
  }

  for ( int i = 0; i < tamInicial; i++)
  {
    for (int j = 0; j < tamInicial; j++)
    { 
      printf("%3i",Matriz[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main ()
{
    int numMatriz,contador = 0;
    int * arranjoTamMatriz = (int*) malloc(sizeof(int)*101);

//Pega todos os scans do usuario até o zero, e os guarda no arranjoTamMatriz.
    do
    {
      scanf("%i", &numMatriz);
      arranjoTamMatriz[contador] = numMatriz;
      contador++;
    } while (numMatriz != 0);
    
//Faz e printa todas as matrizes quadrados com o lado de acordo com o item no arranjo.
    for (int i = 0; i < contador - 1; i++)
    {
      printMatriz(arranjoTamMatriz[i]);
    }
    return 0;
}