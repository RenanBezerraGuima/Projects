#include <stdio.h>

int valor = 0, numeros = 3;

void vezes10(int valor){
    valor = valor*10;
}

int vezes1000(int valor1){
    numeros = 1000;
    valor1 = valor1*numeros;
    return valor1;
}

int main() {
    int quantidade = 10, inserir = 9;

    vezes10(quantidade);
    vezes1000(valor);
    inserir = vezes1000(inserir);
    printf("Valor: %i\n",valor);
    printf("Quantidade: %i\n",quantidade);
    printf("Números: %i\n",numeros);
    printf("Inserir: %i\n",inserir);
    return 0;
}