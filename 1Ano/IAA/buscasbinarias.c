#include <stdio.h>

int buscaBinaria(int vetor[], int item, int vetorTam)
{
    int begin = 0;
    int end = vetorTam - 1;

    while (begin <= end) {  /* Condição de parada */

        int i = (begin + end) / 2;  /* Calcula o meio do sub-vetor */

        if (vetor[i] == item) {  /* Item encontrado no meio */
            return i;
        }

        else if (vetor[i] < item) {  /* Item está no sub-vetor à direita */
            begin = i + 1;
        } else {  /* vector[i] > item. Item está no sub-vetor à esquerda */
            end = i;
        }
    }

    return -1;
}

int buscaBinariaRecursiva(int vetor[], int item, int vetorTam, int begin)
{
    int end = vetorTam - 1; //Cria o final do arranjo
    int i = (begin + end) / 2; //i = meio, e o begin foi passado como parametro
    
    if (begin > end) return -1;

    if (vetor[i] == item) return i; // verifica se o item está no meio
    else if (item > vetor[i]) return buscaBinariaRecursiva(vetor, item, vetorTam, i+1); //O item está a direita do meio
    else return buscaBinariaRecursiva(vetor, item, i, begin);//O item está a esquerda do meio
    return -1;
}


int main () {
    int vetor[] = {1,2,3,4,5,6,7,8,9,10};

    printf("A busca binaria comum retorna a posicao %i\n",buscaBinaria(vetor,6,10));
    printf("A busca binaria recursiva retorna a posicao %i\n",buscaBinariaRecursiva(vetor,6,10,0));

    return 0;
}