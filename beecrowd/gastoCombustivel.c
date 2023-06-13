#include <stdio.h>

int main () {
    int tempo,velocidadeMedia;
    double gasto,distancia;
    scanf("%i %i", &tempo, &velocidadeMedia);

    // 12km /l

    distancia = velocidadeMedia * tempo;

    gasto = distancia / 12;

    printf("%.3lf\n", gasto);

    return 0;
}