#include <stdio.h>

int main (){
    double cm, cmPolegada, cmPe, cmJarda;

    printf("Insira os centimetro que deseja converter para as unidades imperiais: ");
    scanf("%lf", &cm);

    cmPolegada = cm / 2.54;
    cmPe = cmPolegada / 12;
    cmJarda = cmPe / 3;

    printf("\nSeus dados convertidos são: \n");
    printf("Polegadas: %.2lf\n", cmPolegada);
    printf("Pes: %.2lf\n", cmPe);
    printf("Jardas: %.2lf\n\n", cmJarda);

    return 0;
}