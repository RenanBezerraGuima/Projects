#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int palindromo(char* texto, int n) {

  for ( int i=0 ; i<n ; i++ )
    {
      if(texto[i] != texto[(n-1)-i]) return 0;
    }

  return 1;
}

int main() {
  printf("\t\tVerificador de palavras palindromas\n");
  printf("\n\tInsira uma palavra: ");

  char* palavra = (char*) malloc(sizeof(char)*20);
  scanf("%s", palavra);

    for (int i = 0; palavra[i] != '\0'; i++) 
    {
      palavra[i] = tolower(palavra[i]);
    }

  if((palindromo(palavra,strlen(palavra)))) printf("A palavra %s eh um palindromo.\n", palavra);
  else printf("A palavra %s nao eh um palindromo", palavra);

  return 0;
}