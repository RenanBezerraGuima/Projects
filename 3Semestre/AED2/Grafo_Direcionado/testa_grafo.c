// #include "grafo_matrizadj.h"
#include "grafo_listaadj.h"
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

    insereAresta(2, 5, 98, &g1);
    printf("Inseri uma aresta (2,5) com peso 98.\n");
    printf("Inseri uma aresta (2,3) com peso 28.\n");
    printf("A aresta (2,5) existe? %d.\n", existeAresta(2, 5, &g1));
    printf("O peso da aresta (2,5) eh %d.\n", obtemPesoAresta(2, 5, &g1));
    printf("A lista adj de 2 eh vazia? %d.\n", listaAdjVazia(2, &g1));
    printf("A lista adj de 5 eh vazia? %d.\n", listaAdjVazia(5, &g1));
    printf("O primeiro da lista adj de 2 vai para %d.\n", primeiroListaAdj(2, &g1)->vdest);
    Peso peso;
    printf("Remove aresta (2,5) deu certo? %d, se sim ela tinha peso %d.\n", removeArestaObtendoPeso(2, 5, &peso, &g1), peso);
    // printf("A primeira aresta da lista de adjacencia eh %d.\n", primeiroListaAdj(2, &g1)->vdest);

    // printf("Existe a aresta (%d, %d) ? %d", 2, 5, existeAresta(2, 5, &g1));
    return 0;
}