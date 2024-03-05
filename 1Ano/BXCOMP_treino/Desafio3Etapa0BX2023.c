#include <stdio.h>

int main () {
    int iteracoes, partidas;

    scanf("%i", &iteracoes);

    int p1 = 0,p2 = 0;
    int vitorias1 = 0, vitorias2 = 0;

    for (int i = 0; i < iteracoes; i++)
    {
        vitorias1=0;
        vitorias2=0;

        scanf("%i", &partidas);
        for (int j = 0; j < partidas; j++)
        {
            scanf("%i %i", &p1, &p2);

            if (p1>p2)
            {
                printf("%i-1 ", p1);
                vitorias1++;
            }
            else if (p2>p1)
            {   
                printf("%i-2 ", p2);
                vitorias2++;
            }
            else if (p2 == p1)
            {
                printf("%i-Empate ", p1);
            }
        }

        if (vitorias1 > vitorias2)
        {
            printf("Resultado:  1\n");
        }
        else if (vitorias2 > vitorias1)
        {   
            printf("Resultado:  2\n");
        }
        else 
        {
            printf("Resultado:  Empate\n");
        }
    }
    return 0;
}