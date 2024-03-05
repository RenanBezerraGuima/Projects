#include "grafo_matrizadj.h"
#include <stdio.h>

int main()
{
    Grafo g1;
    int numVertices;

    do
    {
        printf("Digite o numero de vertices do grafo\n");
        scanf("%d", &numVertices);
    } while (!inicializaGrafo(&g1, numVertices));

    return 0;
}