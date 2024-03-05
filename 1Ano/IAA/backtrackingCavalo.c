#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Para este programa fora utilizadas diversas variaveis globais
   As duas primeiras (dx e dy) determinam os deslocamentos do cavalo nos eixos.
   A variavel num corresponde a largura e altura do tabuleiro.
   A variavel numQuad corresponde ao total de celulas no tabuleiro.
   A variavel tab corresponde ao tabuleiro (ponteiro para ponteiro de 
     inteiros que representara o tabuleiro como uma matriz de inteiros).
*/

int dx[] = { 2, 1,-1,-2,-2,-1, 1, 2}; // Deslocamentos no eixo x dado um ponto
int dy[] = { 1, 2, 2, 1,-1,-2,-2,-1}; // Deslocamentos no eixo y dado um ponto
int num, numQuad; // Numero de celulas em uma linha ou coluna e numero total de celulas
int** tab; // tabuleiro
  
// Inicializa um tabuleiro nxn 
void inicializa(int n) {
  int i,j;
  num = n;
  numQuad = n * n;
  tab = (int**) malloc(sizeof(int*)*n);
  for (i = 0; i < n; i++)
  {
    tab[i] = (int*) malloc(sizeof(int)*n);
    for (j = 0; j < n; j++) tab[i][j] = 0; // Zera o tabuleiro
  }
}
 
// Verifica se o ponto (x,y) está dentro do tabuleiro e se não foi visitado ainda
bool aceitavel(int x, int y) {
  bool dentroTabuleiro = (x >= 0 && x <= num-1 && y >= 0 && y <= num-1);
  bool naoVisitada = (dentroTabuleiro && tab[x][y] == 0);

  return (naoVisitada);
}

/* Algoritmo de tentativa e erro que tenta movimentar o cavalo a partir da
   posicao atual: x,y. */
bool tenta(int i, int x, int y) {
  int u,v; // destino (u,v)
  int k = 0; // Quantos movimentos a partir de (x,y) foram tentados
  bool feito = (i > numQuad); // Tabuleiro foi marcado completamente?

  while (!feito && k < 8) // Enquanto não terminou o tabuleiro e ainda há movimentos
  {
    u = x + dx[k];
    v = y + dy[k];
    
    if (aceitavel(u,v)) 
    {
      tab[u][v] = i; // Marca o tabuleiro com o movimento
      feito = tenta(i+1, u, v); // Tenta o proximo movimento
      if (!feito) tab[u][v] = 0; // Se não deu certo, desmarca o tabuleiro
    }

    k++; 
  }

  return feito;
}

void imprime() {
  int i, j;  

  for (i = 0; i < num; i++) 
  {
    for (j = 0; j < num; j++) 
      printf("%i\t", tab[i][j]);

    printf("\n");
  }
}

void liberaMemoria() {
  int i;  
  for (i = 0; i < num; i++) free(tab[i]);
  free(tab);
}

// Função incializadora do algoritmo, em que o ponto incial é (x,y)
void passeia(int x, int y) {
  tab[x][y] = 1;
  bool feito = tenta(2, x, y);
  if (feito)
    imprime();
  else
    printf("Nao ha passeio possivel\n");
}

  
int main() {
  printf("\nResolvendo o problema para n=8\n");
  inicializa(8);
  passeia(0, 0);
  liberaMemoria();

  printf("\nResolvendo o problema para n=4\n");
  inicializa(4);
  passeia(0, 0);
  liberaMemoria();

  printf("\nResolvendo o problema para n=7\n");
  inicializa(7);
  passeia(0, 0);
  liberaMemoria();

  printf("\nResolvendo o problema para n=5\n");
  inicializa(5);
  passeia(0, 0);
  liberaMemoria();
}


/* SAIDA

Resolvendo o problema para n=8
1       60      39      34      31      18      9       64
38      35      32      61      10      63      30      17
59      2       37      40      33      28      19      8
36      49      42      27      62      11      16      29
43      58      3       50      41      24      7       20
48      51      46      55      26      21      12      15
57      44      53      4       23      14      25      6
52      47      56      45      54      5       22      13

Resolvendo o problema para n=4
Nao ha passeio possivel

Resolvendo o problema para n=7
1       38      31      8       19      36      15
32      29      20      37      16      7       18
39      2       33      30      9       14      35
28      25      40      21      34      17      6
41      22      3       26      45      10      13
24      27      48      43      12      5       46
49      42      23      4       47      44      11

Resolvendo o problema para n=5
1       6       15      10      21
14      9       20      5       16
19      2       7       22      11
8       13      24      17      4
25      18      3       12      23

*/