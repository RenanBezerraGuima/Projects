#include <stdio.h>

void countingSort(int vetor[], int tamanho) {
  int resposta[tamanho];//Vetor de resposta

  // Acha o elemento máximo do vetor
  int max = vetor[0];
  for (int i = 1; i < tamanho; i++) {
    if (vetor[i] > max)
      max = vetor[i];
  }

  // Cria um vetor para contar os elementos
  // e inicializa ele com zeros
  int count[max+1];
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Armazenar a contagem dos numeros do vetor
  for (int i = 0; i < tamanho; i++) {
    count[vetor[i]]++;
  }

  // Armazena a contagem comulativa, conta o atual com o anterior
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Acha o indice de cada elemento do vetor original no vetor count, e
  // coloca eles no vetor resposta
  for (int i = tamanho - 1; i >= 0; i--) {
    resposta[count[vetor[i]] - 1] = vetor[i];
    count[vetor[i]]--;
  }

  // Copia o vetor resposta para o vetor original
  for (int i = 0; i < tamanho; i++) {
    vetor[i] = resposta[i];
  }
}

void printvetor(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho; ++i) {
    printf("%d  ", vetor[i]);
  }
  printf("\n");
}

int main() {
  int vetor[] = {4, 3, 7, 3, 6, 5, 12, 4, 5, 5};
  int n = sizeof(vetor) / sizeof(vetor[0]);
  countingSort(vetor, n);
  printvetor(vetor, n);
}