#include <stdbool.h>

#define MAXNUMVERTICES 100
#define AN -1

typedef int Peso;
typedef struct
{
    Peso mat[MAXNUMVERTICES][MAXNUMVERTICES];
    int numVertices;
    int numArestas;
} Grafo;