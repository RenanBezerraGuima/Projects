#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contaCaracteres(char** palavras, int n)
{
    int total = 0;

    for (int i=0; i<n ; i++)
    {
        for ( int j = 0; palavras[i][j] != '\0'; j++)
        {
            total++;
        }
    }
    return total;
}

int main() {
  char** nomes2 = (char**) malloc(sizeof(char*)*4);
  nomes2[0] = (char*) malloc(sizeof(char)*10);
  nomes2[1] = (char*) malloc(sizeof(char)*6);
  nomes2[2] = (char*) malloc(sizeof(char)*6);
  nomes2[3] = (char*) malloc(sizeof(char)*9);
  
  nomes2[0] = "Alvenaria";
  nomes2[1] = "Vinil";
  nomes2[2] = "Fibra";
  nomes2[3] = "Plastico";

printf("Total de caracteres (minha funcao): %i\n", contaCaracteres(nomes2,4));
int tamanhoStrlen = strlen(nomes2[0]) + strlen(nomes2[1]) + strlen(nomes2[2]) + strlen(nomes2[3]);
printf("Total de caracteres (strlen): %i\n", tamanhoStrlen);
  
  return 0;
}