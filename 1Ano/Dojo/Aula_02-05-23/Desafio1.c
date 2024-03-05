#include <stdio.h>

void main () {
    
    int n1,n2;
    int aux;

    scanf("%i %i", &n1, &n2);

    aux = n1;
    n1 = n2;
    n2 = aux;
    
    printf("%i %i\n", n1, n2);

}