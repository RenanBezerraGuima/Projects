#include <stdio.h>
#include "grafo_matrizadj.h"

/*
    InicializaGrafo(Grafo* grafo, int nv): Inicializa um grafo com nv vertices
    Vertices vao de 1 a nv
    Preenche as celulas com AN (representando ausencia de aresta)
    Retorna true se inicializou com sucesso e false caso contrario
*/
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

int obtemNrVertices(Grafo *grafo)
{
    if (grafo == NULL)
    {
        return AN;
    }

    return grafo->numVertices;
}

int obtemNrArestas(Grafo *grafo)
{
    if (grafo == NULL)
    {
        return AN;
    }

    return grafo->numArestas;
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
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return;
    grafo->mat[v1][v2] = peso;
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

bool removeArestaObtendoPeso(int v1, int v2, Peso *peso, Grafo *grafo)
{
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return false;

    // Aresta existe
    if (grafo->mat[v1][v2] != AN)
    {
        *peso = grafo->mat[v1][v2];
        grafo->mat[v1][v2] = AN;
        grafo->numArestas--;
        return true;
    }

    // Aresta não existe
    return false;
}

bool removeAresta(int v1, int v2, Grafo *grafo)
{
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return false;

    // Aresta existe
    if (grafo->mat[v1][v2] != AN)
    {
        grafo->mat[v1][v2] = AN;
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

Apontador primeiroListaAdj(int v, Grafo *grafo)
{
    return (proxListaAdj(v, grafo, -1));
}

Apontador proxListaAdj(int v, Grafo *grafo, Apontador atual)
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
            printf("%.1f\t", grafo->mat[i][j]);
        }
        printf("\n");
    }
}

void liberaGrafo(Grafo *grafo) {}

/*
Le o arquivo nomearq e armazena na estrutura Grafo
Layout do arquivo:
    A 1ª linha deve conter o número de vertices e o numero de
    arestas separados por espaço.
    A 2ª linha em diante deve conter a informação de cada aresta,
    que consiste no indice do vertice de origem, indice do vertice
    de destino e o epso da aresta, tambem separados por espaços.
    Observações:
        Os vertices devem ser indexados de 0 a |V| -1
        Os pesos das arestas são números racionais não negativos.

Exemplo: O arquivo abaixo contém um grafo com 4 vertices (0,1,2,3) e
7 arestas.

4 7
0 3 6.3
2 1 5.0
2 0 9
1 3 1.7
0 1 9
3 1 5.6
0 2 7.2

Código de saída:
    1: Leitura bem sucedida
    0: Erro na leitura do arquivo
*/
int leGrafo(char *nomearq, Grafo *grafo)
{
    FILE *fp;
    int nvertices, narestas;
    int v1, v2;
    Peso peso;

    fp = fopen(nomearq, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "ERRO na leitura do arquivo na funcao leGrafo\n");
        return 0;
    }

    if (fscanf(fp, "%d %d", &nvertices, &narestas) != 2)
    {
        fprintf(stderr, "ERRO na primeira linha do arquivo na funcao leGrafo.\n");
        return 0;
    }

    inicializaGrafo(grafo, nvertices);

    for (int i = 0; i < narestas; i++)
    {
        fscanf(fp, "%d %d %f", &v1, &v2, &peso);
        insereAresta(v1, v2, peso, grafo);
    }
    return 1;
}