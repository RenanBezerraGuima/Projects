#include <stdio.h>
#define EOF (-1)

int main ()
{
    int reclamacoes;

    while(scanf("%i", &reclamacoes) != EOF)
    {
        if(reclamacoes > 0 ) printf ("vai ter duas!\n");
        else if (reclamacoes == 0) printf("vai ter copa!\n");
    }
    return 0;
}