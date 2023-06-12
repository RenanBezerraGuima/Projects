#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int contaCaracteres(char** palavras, int n)
{
    int contador = 0;
    for (int i=0; i<n ; i++)
    {
        for ( int j = 0; palavras[i][j] != '\0'; j++)
        {
            contador++;
        }
    }
    return contador;
}

int main ()
{
    char **matriz = (char**) malloc(sizeof(char*)*3);

    matriz[0] = (char*) malloc(sizeof(char)*7);
    matriz[1] = (char*) malloc(sizeof(char)*5);
    matriz[2] = (char*) malloc(sizeof(char)*6);

    matriz[0] = "Tackle";
    matriz[1] = "Ruck";
    matriz[2] = "Scrum";

    printf("Minha funcao: %i\n",contaCaracteres(matriz,3));
    int tamanhoTotal = strlen(matriz[0]) + strlen(matriz[1]) + strlen(matriz[2]);
    printf("Strlen : %i\n", tamanhoTotal);
    printf("Esse foi mais dos exercicios.\n");
    return 0;
}