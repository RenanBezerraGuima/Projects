#include <stdio.h>
#include <stdlib.h>

int** soma3(int** m1, int** m2, int** m3, int lin, int col) {
    int** resultante = (int**) malloc(sizeof(int*)*lin);

    for(int i = 0;i < lin; i++)
    {
        resultante[i] = (int*)malloc(sizeof(int)*col);
    }

    for(int i =0; i< lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            resultante[i][j] = (m1[i][j]+m2[i][j]+m3[i][j]);
        }
    }

  return resultante;
}

int main()
{
  int i, j;
  int lin;
  int col;
  
  printf("Soma de 3 matrizes.\n");
  printf("Insira as linhas e colunas das 3 matrizes: ");
  scanf("%i %i", &lin, &col);

  int** m1 = (int**) malloc(sizeof(int*)*lin);
  for (i=0; i<lin; i++){
    m1[i] = (int*)malloc(sizeof(int)*col);
  }

  int** m2 = (int**) malloc(sizeof(int*)*lin);
  for (i=0; i<lin; i++){
    m2[i] = (int*)malloc(sizeof(int)*col);
  }

  int** m3 = (int**) malloc(sizeof(int*)*lin);
  for (i=0; i<lin; i++){
    m3[i] = (int*)malloc(sizeof(int)*col);
  }

  printf("\nInsira os inteiros da primeira matriz: \n");
  for (int i = 0; i < lin; i++)
  {
    for(int j = 0; j < col; j++)
    {
        scanf("%i", &m1[i][j]);
    }
  }
 
    printf("Insira os inteiros da segunda matriz: \n");
    for (int i = 0; i < lin; i++)
  {
    for(int j = 0; j < col; j++)
    {
        scanf("%i", &m2[i][j]);
    }
  }
  
    printf("Insira os inteiros da terceira matriz: \n");
    for (int i = 0; i < lin; i++)
  {
    for(int j = 0; j < col; j++)
    {
        scanf("%i", &m3[i][j]);
    }
  }

  int** r = soma3(m1,m2,m3,lin,col);

  printf("\nImprimindo a matriz resultante:\n");
  for (i=0; i<lin; i++)
  {
    for (j=0; j<col;j++)
    {
      printf("%3i", r[i][j]);
    }
    printf("\n");
  }
  
  return 0;
}