#include <stdio.h>

void retangulo (int largura, int altura){
    int b = 0;

    printf("\n");

    while ( b < altura ){
        int i = 0;
        while ( i < largura){
        printf("#");
        i ++;
    }

    printf("\n");
    b ++;
    }
    printf("\n");
    
}

void main () {

    int largura,altura;

    printf("Coloque a largura e altura do retângulo: ");
    scanf("%i %i", &largura, &altura);

    retangulo(largura,altura);

}
