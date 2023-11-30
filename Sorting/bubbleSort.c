#include <stdbool.h>
#include <stdio.h>

void troca(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	bool trocado;
	for (i = 0; i < n - 1; i++) {
		trocado = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				troca(&arr[j], &arr[j + 1]);
				trocado = true;
			}
		}

		// Se nenhum dos elementos foram trocados,
		// então break
		if (trocado == false) break;
	}
}

void exibir(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}

int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Arranjo original: \n");
	exibir(arr, n);

	bubbleSort(arr, n);
	printf("Arranjo ordenado: \n");
	exibir(arr, n);
	return 0;
}