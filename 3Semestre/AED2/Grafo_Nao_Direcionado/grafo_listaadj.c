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
    if (v1 == v2)
    {
        fprintf(stderr, "ERRO na insereAresta, self-loop nao eh permitido em grafo nao direcionado.\n");
        return;
    }

    Apontador novo1;
    Apontador novo2;
    if (!(novo1 = (Apontador)malloc(sizeof(Aresta))))
    {
        fprintf(stderr, "ERRO: Falha na alocacao de memoria na funcao insereAresta\n");
        return;
    }

    novo1->peso = peso;
    novo1->vdest = v2;
    novo1->prox = grafo->listaAdj[v1];
    grafo->listaAdj[v1] = novo1;

    if (!(novo2 = (Apontador)malloc(sizeof(Aresta))))
    {
        fprintf(stderr, "ERRO: Falha na alocacao de memoria na funcao insereAresta\n");
        return;
    }

    novo2->peso = peso;
    novo2->vdest = v1;
    novo2->prox = grafo->listaAdj[v2];
    grafo->listaAdj[v2] = novo2;

    grafo->numArestas++;
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
Remove a aresta (v1, v2) do grafo.
Se a aresta existia, coloca o peso dessa
aresta em "peso" e retorna true, c.c
retorna false e "peso" é inalterado.
*/
bool removeArestaObtendoPeso(int v1, int v2, Peso *peso, Grafo *grafo)
{
    bool removed1 = false, removed2 = false;

    if (verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo))
    {
        Apontador p = grafo->listaAdj[v1];
        Apontador ant = NULL;

        while (p)
        {
            if (p->vdest == v2)
            {
                if (ant != NULL)
                    ant->prox = p->prox;
                else
                    grafo->listaAdj[v1] = p->prox;
                *peso = p->peso;
                free(p);
                p = NULL;
                removed1 = true;
                break;
            }
            ant = p;
            p = p->prox;
        }

        p = grafo->listaAdj[v2];
        ant = NULL;

        while (p)
        {
            if (p->vdest == v1)
            {
                if (ant != NULL)
                    ant->prox = p->prox;
                else
                    grafo->listaAdj[v2] = p->prox;
                free(p);
                p = NULL;
                removed2 = true;
                break;
            }
            ant = p;
            p = p->prox;
        }
    }

    return removed1 && removed2;
}

bool removeAresta(int v1, int v2, Grafo *grafo)
{
    bool removed1 = false, removed2 = false;

    if (verificaValidadeVertice(v1, grafo) && verificaValidadeVertice(v2, grafo))
    {
        Apontador p = grafo->listaAdj[v1];
        Apontador ant = NULL;

        while (p)
        {
            if (p->vdest == v2)
            {
                if (ant != NULL)
                    ant->prox = p->prox;
                else
                    grafo->listaAdj[v1] = p->prox;
                free(p);
                p = NULL;
                removed1 = true;
                break;
            }
            ant = p;
            p = p->prox;
        }

        p = grafo->listaAdj[v2];
        ant = NULL;

        while (p)
        {
            if (p->vdest == v1)
            {
                if (ant != NULL)
                    ant->prox = p->prox;
                else
                    grafo->listaAdj[v2] = p->prox;
                free(p);
                p = NULL;
                removed2 = true;
                break;
            }
            ant = p;
            p = p->prox;
        }
    }

    return removed1 && removed2;
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

Apontador primeiroListaAdj(int v, Grafo *grafo)
{
    return (grafo->listaAdj[v]);
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

/*
Imprime os vertices e arestas do grafo no
seguinte formato:
v1: (adj11, peso11); (adj12, peso12); ...
v2: (adj21, peso21); (adj22, peso22); ...
*/
void imprimeGrafo(Grafo *grafo)
{
    int i;
    Apontador p;

    for (i = 0; i < grafo->numVertices; i++)
    {
        printf("v%d:", i);
        p = grafo->listaAdj[i];
        while (p)
        {
            printf(" (%d, %.1f);", p->vdest, p->peso);
            p = p->prox;
        }
        printf("\n");
    }
}

void liberaGrafo(Grafo *grafo)
{
    Apontador p;

    // libera a lista de adjacencia de cada vertice
    for (int vertice = 0; vertice < grafo->numVertices; vertice++)
    {
        while ((p = grafo->listaAdj[vertice]) != NULL)
        {
            grafo->listaAdj[vertice] = p->prox;
            p->prox = NULL;
            free(p);
        }
    }
    grafo->numArestas = 0;

    free(grafo->listaAdj);
    grafo->listaAdj = NULL;
}

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
