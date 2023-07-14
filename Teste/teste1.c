#include <stdio.h>

int main() {
    int tamanho;
    printf("Digite o tamanho do arranjo: ");
    scanf("%d", &tamanho);

    int arranjo[tamanho];

    for (int i=0;i<tamanho;i++) scanf("%i", &arranjo[i]);
    for (int i=0;i<tamanho;i++) printf("%i ", arranjo[i]);
    return 0;
}