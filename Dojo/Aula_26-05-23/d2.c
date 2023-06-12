#include <stdio.h>

int quadradoPerfeito(int a){
    int b = 1;
    
    for (b = 1; b <= a ; b++) {
        if ( a == b*b ){
            printf("%i é um quadrado perfeito\n", a);
            return 0;
        }
}
    printf("%i não é um quadrado perfeito\n", a);
    return 0;
}

int main () {
    int a;

    printf("Insira o numero que deseja verificar se eh um quadrado perfeito: ");

    scanf("%i", &a);

    quadradoPerfeito(a);

    return 0;
}