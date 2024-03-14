#include <stdbool.h>

#define MAXNUMVERTICES 100
#define AN -1
#define VERTICE_INVALIDO -1

typedef int Peso;
typedef struct
{
    Peso mat[MAXNUMVERTICES][MAXNUMVERTICES];
    int numVertices;
    int numArestas;
} Grafo;

typedef int Apontador;

bool inicializaGrafo(Grafo *grafo, int nv);

bool verificaValidadeVertice(int v, Grafo *grafo);

void insereAresta(int v1, int v2, Peso peso, Grafo *grafo);

bool existeAresta(int v1, int v2, Grafo *grafo);

Peso obtemPesoAresta(int v1, int v2, Grafo *grafo);

bool removeArestaObtendoPeso(int v1, int v2, Peso *peso, Grafo *grafo);

bool listaAdjVazia(int v, Grafo *grafo);

Apontador proxListaAdj(int v, Grafo *grafo, Apontador atual);

Apontador primeiroListaAdj(int v, Grafo *grafo);

void liberaGrafo(Grafo *grafo);

void imprimeGrafo(Grafo *grafo);