#include <stdio.h>

void troca(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;

	// Move um por um o começo do arranjo desordenado
	for (i = 0; i < n-1; i++)
	{
		// Acha o elemento mínimo
		min_idx = i;
		for (j = i+1; j < n; j++)
		if (arr[j] < arr[min_idx])
			min_idx = j;

		// troca o minimo achado com o primeiro 
        //;lemento do arranjo desordenado
		if(min_idx != i)
			troca(&arr[min_idx], &arr[i]);
	}
}

void exibir(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Teste
int main()
{
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
    printf("Arranjo original: \n");
    exibir(arr, n);
    
	selectionSort(arr, n);
	printf("Arranjo ordenado: \n");
	exibir(arr, n);
	return 0;
}
