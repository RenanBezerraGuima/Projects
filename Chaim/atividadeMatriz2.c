#include <stdio.h>
#include <stdlib.h>

int** soma3(int** m1, int** m2, int** m3, int lin, int col) {
    int** resposta = (int**) malloc(sizeof(int*)*lin);

    for(int i = 0;i < lin; i++)
    {
        resposta[i] = (int*)malloc(sizeof(int)*col);
    }

    for(int i =0; i< lin; i++)
    {
        for (int j = 0; j < col; j++)
        {
            resposta[i][j] = (m1[i][j]+m2[i][j]+m3[i][j]);
        }
    }

  return resposta;
}

int main()
{
  int i, j;
  int lin = 2;
  int col = 3;

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

  m1[0][0] = 1;
  m1[0][1] = 2;
  m1[0][2] = 3;
  m1[1][0] = 4;
  m1[1][1] = 5;
  m1[1][2] = 6;

  m2[0][0] = 11;
  m2[0][1] = 12;
  m2[0][2] = 13;
  m2[1][0] = 14;
  m2[1][1] = 15;
  m2[1][2] = 16;

  m3[0][0] = 21;
  m3[0][1] = 22;
  m3[0][2] = 23;
  m3[1][0] = 24;
  m3[1][1] = 25;
  m3[1][2] = 26;

  int** r = soma3(m1,m2,m3,lin,col);

  printf("Imprimindo a matriz resultante:\n");
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


/* SAIDA:
Imprimindo a matriz resultante:
 33 36 39
 42 45 48
*/
