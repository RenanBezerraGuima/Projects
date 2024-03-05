#include <stdio.h>

int main ()
{
    int n,fatorial;
    scanf("%d", &n);
    fatorial = n;
    while ( n - 1 != 1)
    {
        fatorial = ( n - 1 )* fatorial;
        n = n - 1; 
    }
    printf("%i\n", fatorial);
}