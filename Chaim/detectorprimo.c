#include <stdio.h>

int main () {

    int n,q;

    printf("Testadora de número primo\nInsira o número que deseja testar: ");
    scanf("%i", &n);
    
    q = n - 1;
    while ( q > 1){
        int resto;

        resto = n % q;

        if ( resto == 0) {
            printf ("%i não é um número primo.\n", n);
            return 0;
        }
        q--;

    }
    printf("%i é um número primo.\n", n );

}