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
    //Porque se eu aloco uma quantidade x de caracteres, e no scanf eu passo desse x o programa funciona normal ????
    char** matriz = (char**) malloc(sizeof(char*)*3);

    matriz[0] = (char*) malloc(sizeof(char)*2);
    matriz[1] = (char*) malloc(sizeof(char)*2);
    matriz[2] = (char*) malloc(sizeof(char)*2);

    scanf ("%s", matriz[0]);
    scanf ("%s", matriz[1]);
    scanf ("%s", matriz[2]);

    printf("- Minha funcao - A quantidade de caracteres somados de todas as strings são: %i\n",contaCaracteres(matriz,3));
    int tamanhoTotal = strlen(matriz[0]) + strlen(matriz[1]) + strlen(matriz[2]);
    printf("- Strlen - A quantidade de caracteres somados de todas as strings são: %i\n", tamanhoTotal);
    return 0;
}