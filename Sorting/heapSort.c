#include <stdio.h>
/*O código abaixo é o heapSortMAX (ordena em ordem crescente), ou seja o heapify garante que
o maior elemento do arranjo está na primeira posição, depois
de passar o heapify por todo o arranjo, ele ordena colocando o maior
elemento(achado pelo heapify) no final do arranjo, depois reduzindo
o tamanho do arranjo em 1, fazendo o mesmo processo até ordenar o arranjo*/

// Troca dois valores
void troca(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{
	// Find largest among root,
	// left child and right child

	// Initialize largest as root
	int largest = i;

	// left = 2*i + 1
	int left = 2 * i + 1;

	// right = 2*i + 2
	int right = 2 * i + 2;

	// If left child is larger than root
	if (left < N && arr[left] > arr[largest])

		largest = left;

	// If right child is larger than largest
	// so far
	if (right < N && arr[right] > arr[largest])

		largest = right;

	// troca and continue heapifying
	// if root is not largest
	// If largest is not root
	if (largest != i) {

		troca(&arr[i], &arr[largest]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, largest);
	}
}

// Main function to do heap sort
void heapSort(int arr[], int N)
{

	// Build max heap
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);

	// Heap sort
	for (int i = N - 1; i >= 0; i--) {

		troca(&arr[0], &arr[i]);

		// Heapify root element
		// to get highest element at
		// root again
		heapify(arr, i, 0);
	}
}

// A utility function to print array of size n
void exibir(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int N = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, N);
	printf("Sorted array is\n");
	exibir(arr, N);
}