#include "grafo_matrizadj.h"
#include <stdio.h>

int main()
{
    Grafo g1;
    int numVertices;

    do
    {
        printf("Digite o numero de vertices do grafo: ");
        scanf("%d", &numVertices);
    } while (!inicializaGrafo(&g1, numVertices));

    insereAresta(2, 5, 12, &g1);
    imprimeGrafo(&g1);
    printf("%d\n", existeAresta(2, 5, &g1));
    printf("%d\n", existeAresta(0, 1, &g1));

    return 0;
}