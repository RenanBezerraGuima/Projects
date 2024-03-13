#include "grafoND_matrizadj.h"
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

    insereAresta(2, 1, 12, &g1);
    insereAresta(0, 1, 50, &g1);
    insereAresta(2, 0, 9, &g1);

    imprimeGrafo(&g1);

    insereAresta(2, 2, 98, &g1);
    return 0;
}