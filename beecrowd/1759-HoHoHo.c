#include <stdio.h>

int main ()
{
    int qtd;
    scanf("%i", &qtd);

    for(int i=0; i<qtd; i++)
    {
        if( i == qtd-1)
        {
            printf("Ho!\n");
        }
        else printf("Ho ");
    }
    return 0;
}
