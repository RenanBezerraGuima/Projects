#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256 /* tamanho máximo de um nome de arquivo*/

int main(int argc, char *argv[]) {
    //argc me diz a quantidade de comandos que recebo pela linha de comando 
    //argv é um vetor com os argumentos com:
    //  argv[0] = nome do programa
    //  argv[1] = duração do período de atts (14,15,...,20) horas
    //  argv[2] = cenário (1 ou 2)
    //  argv[3] = nome do arquivo de entrada (entrada1.txt ou entrada2.txt), conforme o cenário
    if (argc != 4) 
    {
        exit(1);
    }

    int duracao = atoi(argv[1]);//Esse comando transforma o char do argv em inteiro
    int cenario = atoi(argv[2]);

    //Abre o arquivo recebido como argumento, usar fp como arquivo e as funções f(scanf, printf)
    char filename[MAX_FILENAME] = "";
    strcpy(filename, argv[3]);
    FILE* fp = fopen(filename, "r");
    if (fp == NULL){
        fprintf(stderr, "Não foi possível abrir o arquivo %s\n", filename);
        return -1;
    }  


    //Abaixo um Exemplo da abertura do arquivo "saida.txt" e uma serie de printfs nele

    // FILE *outputFile = fopen("saida.txt", "w");

    // for (int i = 0; i < resultado; i++) 
    // {
    //    fprintf(outputFile, "%dx%d %d %d\n", matrizResultados[i][0], matrizResultados[i][0], matrizResultados[i][1], matrizResultados[i][2]);
    // }
   
    // fclose(outputFile);
}