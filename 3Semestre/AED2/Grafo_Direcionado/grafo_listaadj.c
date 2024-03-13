#include <stdio.h>
#include <stdlib.h>

#include "grafo_listaadj.h"

/*
    Cria um grafo com n vertices.
    Aloca espaco para o vetor de apontadores
    de listas de adjacencias e, para cada
    vertice, inicializa o apontador de usa
    lista de adjacencia.
    Retorna true se inicializou com sucesso e
    false caso o contrario.
    Vertices vao de 0 a nv-1.
*/
bool inicializaGrafo(Grafo *grafo, int nv)
{
    if (grafo == NULL)
    {
        fprintf(stderr, "ERRO na chamada de inicializaGrafo: grafo == NULL.\n");
        return false;
    }

    if (nv <= 0)
    {
        fprintf(stderr, "ERRO na chamada de inicializaGrafo: Numero de vertices deve ser positivo.\n");
        return false;
    }

    grafo->numVertices = nv;
    if (!(grafo->listaAdj = (Apontador *)calloc(nv, sizeof(Apontador))))
    {
        fprintf(stderr, "ERRO: Falha na alocacao de memoria na funcao inicializaGrafo.\n");
        return false;
    }
    grafo->numArestas = 0;
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

/*
Retorna true se a lista de adjacencia (de vertices adjacentes)
do vertice v é vazia e false c.c.
*/
bool listaAdjVazia(int v, Grafo *grafo)
{
    if (!verificaValidadeVertice(v, grafo))
        return false;
    return (grafo->listaAdj[v] == NULL);
}

Apontador proxListaAdj(int v, Grafo *grafo, Apontador atual)
{
    if (atual == NULL)
    {
        fprintf(stderr, "atual = NULL.\n");
        return VERTICE_INVALIDO;
    }
    return (atual->prox);
}

Apontador primeiroListaAdj(int v, Grafo *grafo)
{
    return (grafo->listaAdj[v]);
}

/*
    Retorna true se existe a aresta (v1, v2)
    no grafo e false c.c.
*/
bool existeAresta(int v1, int v2, Grafo *grafo)
{
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return false;

    Apontador p = grafo->listaAdj[v1];

    while (p)
    {
        if (p->vdest == v2)
            return true;
        p = p->prox;
    }
    return false;
}

/*
Retorna o peso da aresta (v1, v2) do grafo
se ela existir e AN c.c.
*/
Peso obtemPesoAresta(int v1, int v2, Grafo *grafo)
{
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return AN;

    Apontador p = grafo->listaAdj[v1];

    while (p)
    {
        if (p->vdest == v2)
            return p->peso;
        p = p->prox;
    }
    return AN;
}

/*
Insere a aresta (v1, v2) com peso "peso"
no grafo. Nao verifica se a aresta ja
existia (isso deve ser feito pelo usuario
antes, se necessario)
*/
void insereAresta(int v1, int v2, Peso peso, Grafo *grafo)
{
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return;

    Apontador novo = (Apontador)malloc(sizeof(Aresta));
    novo->peso = peso;
    novo->vdest = v2;
    novo->prox = grafo->listaAdj[v1];

    grafo->listaAdj[v1] = novo;
}

/*
Remove a aresta (v1, v2) do grafo.
Se a aresta existia, coloca o peso dessa
aresta em "peso" e retorna true, c.c
retorna false e "peso" é inalterado.
*/
bool removeArestaObtendoPeso(int v1, int v2, Peso *peso, Grafo *grafo)
{
    if (!(verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo)))
        return false;

    Apontador p = grafo->listaAdj[v1];
    Apontador ant = NULL;

    while (p)
    {
        if (p->vdest == v2)
        {
            *peso = p->peso;
            if (ant == NULL)
                grafo->listaAdj[v1] = p->prox;
            else
                ant->prox = p->prox;
            free(p);
            return true;
        }
        ant = p;
        p = p->prox;
    }
    return false;
}

/*
Imprime os vertices e arestas do grafo no
seguinte formato:
v1: (adj11, peso11); (adj12, peso12); ...
v2: (adj21, peso21); (adj22, peso22); ...
*/
void imprimeGrafo(Grafo *grafo)
{
}