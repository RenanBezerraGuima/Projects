// #include "grafo_matrizadj.h"
#include "grafo_listaadj.h"
#include <stdio.h>

int main()
{
    Grafo g1;

    // printf("%d\n", leGrafo("entrada.txt", &g1));
    // imprimeGrafo(&g1);

    // // int numVertices;
    // // do
    // // {
    // //     printf("Digite o numero de vertices do grafo: ");
    // //     scanf("%d", &numVertices);
    // // } while (!inicializaGrafo(&g1, numVertices));

    inicializaGrafo(&g1, 10);

    insereAresta(0, 9, 29, &g1);
    insereAresta(9, 0, 20, &g1);
    insereAresta(0, 8, 26, &g1);
    insereAresta(5, 6, 285, &g1);
    insereAresta(7, 3, 22, &g1);
    insereAresta(1, 9, 21, &g1);
    insereAresta(3, 7, 28, &g1);
    insereAresta(2, 8, 27, &g1);
    imprimeGrafo(&g1);

    printf("Existe a aresta (0,9)? %d\n", existeAresta(0, 9, &g1));
    printf("Numero de Arestas %d\n", obtemNrArestas(&g1));
    printf("Numero de Vertices %d\n", obtemNrVertices(&g1));
    printf("Peso da Aresta (0,9) %.1f\n", obtemPesoAresta(0, 9, &g1));

    Peso peso;
    removeArestaObtendoPeso(0, 9, &peso, &g1);
    printf("Removendo Aresta (0,9) que tinha peso %.1f\n", peso);
    printf("Removendo Aresta (7,3)\n");
    removeAresta(7, 3, &g1);
    imprimeGrafo(&g1);
    printf("O vertice 4 tem uma listaAdj vazia? %d\n", listaAdjVazia(4, &g1));
    printf("O vertice 2 tem uma listaAdj vazia? %d\n", listaAdjVazia(2, &g1));

    Apontador primeiro = primeiroListaAdj(5, &g1);
    Apontador proximo = proxListaAdj(5, &g1, primeiro);
    printf("O primeiro da listaADj do 9 eh (9,%d)\n", primeiro->vdest);
    printf("O proximo da listaADj do 9 eh (9,%d)\n", proximo->vdest);

    return 0;
}