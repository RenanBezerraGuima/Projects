#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>//Lembrar de colocar para Ariane que estou usando a math.h

#define MAX_FILENAME 256 /* tamanho máximo de um nome de arquivo*/

// Função principal que conta os quadrantes e os coloca na matriz resultados
void countarQuadrantes(int **matriz, int size, int **matrizResultados, int posicao) {
    int soma = 0;
    int total = size*size;
    //Soma de todos os pixeis da matriz
    for (int i = 0; i < size; i++) 
    {
        for (int j = 0; j < size; j++) 
        {
            soma = matriz[i][j] + soma;
        }
    }
    
    //Se a soma for igual ao total, todos os pixeis são 1, logo o quadrante é branco
    if (soma == total) 
    {
        matrizResultados[posicao][1]++;
    }
    //Se a soma for igual a 0, todos os pixeis são 0, logo o quadrante é preto
    else if (soma == 0)
    {
        matrizResultados[posicao][2]++;
    }
    //Casos em que o quadrante não é totalmente branco ou preto, chamada recursiva, dividir e conquistar
    else
    {
        int newSize = size/2;
        //Criação das 4 matrizes que representam os 4 quadrantes
        int **matriz1 = (int **) malloc (newSize*sizeof(int*));
        int **matriz2 = (int **) malloc (newSize*sizeof(int*));
        int **matriz3 = (int **) malloc (newSize*sizeof(int*));
        int **matriz4 = (int **) malloc (newSize*sizeof(int*));
        for (int i = 0; i < newSize; i++) 
        {
            matriz1[i] = (int *) malloc (newSize*sizeof(int));
            matriz2[i] = (int *) malloc (newSize*sizeof(int));
            matriz3[i] = (int *) malloc (newSize*sizeof(int));
            matriz4[i] = (int *) malloc (newSize*sizeof(int));
        }

        //Preenchimento das 4 matrizes com os valores dos quadrantes
        for (int i = 0; i < newSize; i++) 
        {
            for (int j = 0; j < newSize; j++) 
            {
                matriz1[i][j] = matriz[i][j];
                matriz2[i][j] = matriz[i][j+newSize];
                matriz3[i][j] = matriz[i+newSize][j];
                matriz4[i][j] = matriz[i+newSize][j+newSize];
            }
        }

        //Chamada recursiva para cada um dos 4 quadrantes
        countarQuadrantes(matriz1, newSize, matrizResultados, posicao+1);
        countarQuadrantes(matriz2, newSize, matrizResultados, posicao+1);
        countarQuadrantes(matriz3, newSize, matrizResultados, posicao+1);
        countarQuadrantes(matriz4, newSize, matrizResultados, posicao+1);
    }

}



int main(int argc, char *argv[]) {
    if (argc != 3) 
    {
        printf("Uso: %s <dimensao> <arquivo_entrada>\n", argv[0]);
        exit(1);
    }

    int size = atoi(argv[1]);

    // Verificando se a dimensão é uma potência de 2
    if (size % 2 != 0 || size < 2 || size > 1024) 
    {
        printf("A dimensao deve ser uma potencia de 2 e no maximo 1024.\n");
        return 1;
    }

    char filename[MAX_FILENAME] = "";
    strcpy(filename, argv[2]);
    FILE* fp = fopen(filename, "r");
    if (fp == NULL){
        fprintf(stderr, "Não foi possível abrir o arquivo %s\n", filename);
        return -1;
    }  

    //Criação da Matriz a partir do arquivo passado pelo argumento
    int **matrizEst = (int **) malloc (size*sizeof(int*));
    for (int i = 0; i < size; i++) 
    {
        matrizEst[i] = (int *) malloc (size*sizeof(int));
        for (int j = 0; j < size; j++) 
        {
            fscanf(fp, "%1d", &matrizEst[i][j]);
        }
    }

    //Criando matriz Resultado
    double resultado = log2(size) + 1;
    int** matrizResultados = (int **) malloc (size*sizeof(int*));
    for (int i = 0; i < (int)resultado; i++) 
    {
       matrizResultados[i] = (int *) malloc (3*sizeof(int));
    }

    int count = size*2;
    for (int i = 0; i < resultado; i++)
    {
       for (int j=0; j < 3; j++) 
       {    
           if (j == 0) {
            count = count/2;
            matrizResultados[i][j] = count;
           }
           else matrizResultados[i][j] = 0;
       }
    }

    countarQuadrantes(matrizEst, size, matrizResultados, 0);

    FILE *outputFile = fopen("saida.txt", "w");

    for (int i = 0; i < resultado; i++) 
    {
       fprintf(outputFile, "%dx%d %d %d\n", matrizResultados[i][0], matrizResultados[i][0], matrizResultados[i][1], matrizResultados[i][2]);
    }
   
    fclose(outputFile);

    return 0;
}