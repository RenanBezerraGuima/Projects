#include <stdbool.h>

#define VERTICE_INVALIDO NULL // vertice invalido ou ausente
#define AN -1                 // aresta nula

typedef float Peso;

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
int obtemNrVertices(Grafo *grafo);
int obtemNrArestas(Grafo *grafo);
bool verificaValidadeVertice(int v, Grafo *grafo);
void insereAresta(int v1, int v2, Peso peso, Grafo *grafo);
bool existeAresta(int v1, int v2, Grafo *grafo);
Peso obtemPesoAresta(int v1, int v2, Grafo *grafo);
bool removeArestaObtendoPeso(int v1, int v2, Peso *peso, Grafo *grafo);
bool removeAresta(int v1, int v2, Grafo *grafo);
bool listaAdjVazia(int v, Grafo *grafo);
Apontador primeiroListaAdj(int v, Grafo *grafo);
Apontador proxListaAdj(int v, Grafo *grafo, Apontador atual);
void imprimeGrafo(Grafo *grafo);
void liberaGrafo(Grafo *grafo);
int leGrafo(char *nomearq, Grafo *grafo);