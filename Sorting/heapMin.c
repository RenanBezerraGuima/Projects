#include <stdio.h>
#include <stdlib.h>
/*
    Adaptar a estrutura de heap, sem ordenar, ou seja
    implementar as funções de inserção de um elemento generico, 
    remoção da raiz (menor elemento) e mudar o valor de um elemento 

    Esta estrutura sera feita pensando no EP2
    [Resolvido, usar realloc e alocar o vetor com malloc]

    To-do 
    Inserção [V]
    Remoção  [V]
    Mudança  []
*/

// Troca dois valores
void troca(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// heapify uma subarvore rooted with node i which is an index in arr[].
// N é tamanho do arranjo
void heapify(int arr[], int N, int i)
{
	// Acha o menor entre a raiz e
	// os filhos esquerdo e direito

	// Inicializa o minimo como a raiz
	int minimum = i;

	int left = 2 * i + 1;

	int right = 2 * i + 2;

	// Se o filho esquerdo é menor que o minimo atual
	if (left < N && arr[left] < arr[minimum])

		minimum = left;

	// Se o filho direito é menor que o minimo atual
	if (right < N && arr[right] < arr[minimum])

		minimum = right;

	// Se o minimo foi trocado, ou seja não está 
    // como heap atualmente, troca o atual minimo
    // com o novo e faz o heapfiy novamente
	if (minimum != i) {

		troca(&arr[i], &arr[minimum]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, minimum);
	}
}

// Constroi o HeapMin do arranjo
void construirHeapMin(int arr[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);
}

void insercaoHeap(int arr[], int* N, int ch)
{
	arr = realloc(arr, (*N+1)*sizeof(int));
	arr[*N] = ch;
	
	int i = *N;
	//Enquanto o pai for maior que o filho
	while (i>0 && arr[i/2] > arr[i])
	{
		troca(&arr[i], &arr[i/2]);
		i = i/2;//Novo pai
	}
	*N = *N + 1;
}

int remocaoHeap(int arr[], int* N)
{
	int resp = arr[0];
	troca(&arr[0], &arr[*N - 1]);
	*N = *N - 1;
	heapify(arr,*N, 0);

	return resp;
}

void mudancaHeap(int arr[], int N, )

void exibir(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int N = 7;
	int* arr = (int*) malloc(N*sizeof(int));
	arr[0] = 7;
	arr[1] = 8;
	arr[2] = 5;
	arr[3] = 25;
	arr[4] = 30;
	arr[5] = 4;
	arr[6] = 1;

    printf("Arranjo original: \n");
    exibir(arr, N);
	construirHeapMin(arr, N);
	printf("Arranjo pos heapfiy: \n");
	exibir(arr, N);

	printf("Elemento removido %i\n", remocaoHeap(arr, &N));
	exibir(arr, N);

	return 0;
}