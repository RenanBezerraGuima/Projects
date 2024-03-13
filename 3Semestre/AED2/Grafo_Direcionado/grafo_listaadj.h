#include <stdbool.h>

#define VERTICE_INVALIDO NULL // vertice invalido ou ausente
#define AN -1                 // aresta nula

typedef int Peso;

/*
    Tipo estrutura Aresta:
        Vertice destino, peso
        ponteiro para proxima aresta
*/
typedef struct str_aresta
{
    int vdest;
    Peso peso;
    struct str_aresta *prox;
} Aresta;

/*
Apontador é um tipo para manter coerecia
entre as interfaces de lista e matriz
sendo simplismente um vertice adjacente
*/
typedef Aresta *Apontador;

/*
tipo estrutura grafo:
    listaAdj:
        vetor de arestas ligadas, cada
        posicao i contem o ponteiro para
        o inicio da lista de adjacencia do vertice
        i
*/
typedef struct
{
    Apontador *listaAdj;
    int numVertices;
    int numArestas;
} Grafo;

bool inicializaGrafo(Grafo *grafo, int nv);

bool verificaValidadeVertice(int v, Grafo *grafo);

bool listaAdjVazia(int v, Grafo *grafo);

Apontador proxListaAdj(int v, Grafo *grafo, Apontador atual);

Apontador primeiroListaAdj(int v, Grafo *grafo);

bool existeAresta(int v1, int v2, Grafo *grafo);

Peso obtemPesoAresta(int v1, int v2, Grafo *grafo);

void insereAresta(int v1, int v2, Peso peso, Grafo *grafo);

bool removeArestaObtendoPeso(int v1, int v2, Peso *peso, Grafo *grafo);