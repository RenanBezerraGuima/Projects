#include <stdio.h>
#include "grafoND_matrizadj.h"

bool inicializaGrafo(Grafo *grafo, int nv)
{
    int i, j;

    if (nv > MAXNUMVERTICES)
    {
        fprintf(stderr, "ERRO na chamada de inicializaGrafo: Numero de vertices maior que o o maximo perimitido de %d.\n", MAXNUMVERTICES);
        return false;
    }

    if (nv <= 0)
    {
        fprintf(stderr, "ERRO na chamada de inicializaGrafo: Numero de vertices deve ser positivo.\n");
        return false;
    }

    grafo->numVertices = nv;
    grafo->numArestas = 0;
    for (i = 0; i < grafo->numVertices; i++)
    {
        for (j = 0; j < grafo->numVertices; j++)
        {
            grafo->mat[i][j] = AN;
        }
    }
    return true;
}

bool verificaValidadeVertice(int v, Grafo *grafo)
{
    if (v >= grafo->numVertices)
    {
        fprintf(stderr, "ERRO: Numero do vertice %d maior ou igual o numero de vertices %d.\n", v, grafo->numVertices);
        return false;
    }
    if (v < 0)
    {
        fprintf(stderr, "ERRO: Numero do vertice %d deve ser positivo.\n", v);
        return false;
    }
    return true;
}

void insereAresta(int v1, int v2, Peso peso, Grafo *grafo)
{
    if (v1 == v2)
    {
        fprintf(stderr, "ERRO: Self loop em grafo não direcionado nao e permitido.\n");
        return;
    }
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return;
    grafo->mat[v1][v2] = peso;
    grafo->mat[v2][v1] = peso;
    grafo->numArestas++;
}

bool existeAresta(int v1, int v2, Grafo *grafo)
{
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return false;
    if (grafo->mat[v1][v2] != AN)
        return true;
    return false;
}

Peso obtemPesoAresta(int v1, int v2, Grafo *grafo)
{
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return AN;
    return grafo->mat[v1][v2];
}

bool removeAresta(int v1, int v2, Peso *peso, Grafo *grafo)
{
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return false;

    // Aresta existe
    if (grafo->mat[v1][v2] != AN)
    {
        *peso = grafo->mat[v1][v2];
        grafo->mat[v1][v2] = AN;
        grafo->mat[v2][v1] = AN;
        grafo->numArestas--;
        return true;
    }

    // Aresta não existe
    return false;
}

bool listaAdjVazia(int v, Grafo *grafo)
{
    if (!verificaValidadeVertice(v, grafo))
        return true;

    for (int j = 0; j < grafo->numVertices; j++)
        if (grafo->mat[v][j] != AN)
            return false;
    return true;
}

int proxListaAdj(int v, Grafo *grafo, int atual)
{
    if (!verificaValidadeVertice(v, grafo))
        return VERTICE_INVALIDO;

    atual++;
    while ((atual < grafo->numVertices) && (grafo->mat[v][atual] == AN))
        atual++;
    if (atual >= grafo->numVertices)
        return VERTICE_INVALIDO;
    return atual;
}

void liberaGrafo(Grafo *grafo) {}

void imprimeGrafo(Grafo *grafo)
{
    int i, j;

    for (int c = -1; c < grafo->numVertices; c++)
        printf("%d\t", c);
    printf("\n");
    for (i = 0; i < grafo->numVertices; i++)
    {
        printf("%d\t", i);
        for (j = 0; j < grafo->numVertices; j++)
        {
            printf("%d\t", grafo->mat[i][j]);
        }
        printf("\n");
    }
}