#include <stdio.h>

typedef struct {
    int idade;
    char nome[50];
    char endereco[70];
}RG;

int main ()
{
    RG rg1;

    printf("Insira o seu nome: ");
    scanf("%s", rg1.nome);

    printf("Insira sua idade: ");
    scanf("%d", &rg1.idade);

    printf("Insira seu endereço: ");
    scanf("%s", rg1.endereco);

    printf("\n\nNome: %s \nIdade: %i \nEndereco: %s\n", rg1.nome, rg1.idade, rg1.endereco);
}