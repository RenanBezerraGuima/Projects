#include <stdio.h>

int main ()
{
    int t,qtd = 0;

    int arranjo[5];

    scanf("%i", &t);

    scanf("%i %i %i %i %i", &arranjo[0], &arranjo[1], &arranjo[2], &arranjo[3], &arranjo[4]);

    for (int i = 0; i < 5; i++)
    {
        if (t == arranjo[i]) qtd ++;
    }
    
    printf("%i\n", qtd);
    return 0;
}