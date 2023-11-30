#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256 /* tamanho máximo de um nome de arquivo*/

typedef struct {
    int valor;
    int indice;
}VETOR;

typedef struct{
    char operacao;
    int tempo;
    int indice;
    int duracao;
}ALT;

void countingSort(VETOR vetor[], int tamanho) {
  VETOR resposta[tamanho];//Vetor de resposta

  // Acha o elemento máximo do vetor
  int max = vetor[0].valor;
  for (int i = 1; i < tamanho; i++) {
    if (vetor[i].valor > max)
      max = vetor[i].valor;
  }

  // Cria um vetor para contar os elementos
  // e inicializa ele com zeros
  int count[max+1];
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Armazenar a contagem dos numeros do vetor
  for (int i = 0; i < tamanho; i++) {
    count[vetor[i].valor]++;
  }

  // Armazena a contagem comulativa, conta o atual com o anterior
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // Acha o indice de cada elemento do vetor original no vetor count, e
  // coloca eles no vetor resposta
  for (int i = tamanho - 1; i >= 0; i--) {
    resposta[count[vetor[i].valor] - 1].valor = vetor[i].valor;
    resposta[count[vetor[i].valor] - 1].indice = vetor[i].indice;
    count[vetor[i].valor]--;
  }

  // Copia o vetor resposta para o vetor original
  for (int i = 0; i < tamanho; i++) {
    vetor[i].valor = resposta[i].valor;
    vetor[i].indice = resposta[i].indice;
  }
}

void exibirVetor(VETOR vetor[], int tamanho) {
  for (int i = 0; i < tamanho; ++i) {
    printf("%d ", vetor[i].valor);
  }
  printf("\n");
}

// Recebe o vetor das atts ordenado crescentemente por duração
// Cenário 1
int maxAtualizacoes1(VETOR vetor[], int tamanho, int duracaoMax) {
    int numAtts = 0;
    int duracaoAtual = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (duracaoAtual + vetor[i].valor <= duracaoMax)
        {
            duracaoAtual = duracaoAtual + vetor[i].valor;
            numAtts++;
        }
        else return numAtts;
    }
    return numAtts;
}

void resposta1(int MaxAtts, VETOR vetorResp[], int tamanho)
{
    FILE *outputFile = fopen("saida1.txt", "w");

    fprintf(outputFile, "%i", MaxAtts);
    for(int i = 0; i < MaxAtts; i++) fprintf(outputFile, " %i", vetorResp[i].indice+1);
    fprintf(outputFile,"\n");

    fclose(outputFile);
}

int main(int argc, char *argv[]) {
    //argc me diz a quantidade de comandos que recebo pela linha de comando 
    //argv é um vetor com os argumentos com:
    //  argv[0] = nome do programa
    //  argv[1] = duração do período de atts (14,15,...,20) horas
    //  argv[2] = cenário (1 ou 2)
    //  argv[3] = nome do arquivo de entrada (entrada1.txt ou entrada2.txt), conforme o cenário
    if (argc != 4) 
    {
        return -1;
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

    //Recebe a quantidade de Atualizações pelo arquivo de entrada
    int qtdAtts;
    fscanf(fp, "%i", &qtdAtts);

    //Le as atts do arquivo de entrada,
    //cria um vetor e o ordena 
    VETOR atualizacoes[100];
    for(int i = 0; i < qtdAtts; i++)
    {
      fscanf(fp, "%i", &atualizacoes[i].valor);
      atualizacoes[i].indice = i;
    }

    switch (cenario)
    {
    case 1:
        countingSort(atualizacoes, qtdAtts);
        resposta1(maxAtualizacoes1(atualizacoes, qtdAtts, duracao),atualizacoes,qtdAtts);
        break;
    
    case 2:
        //Cria um vetor das alterações q devem acontecer
        ALT alteracoes[100];
        char caractere;
        int i = 0;
        while(1)
        {
          if (feof(fp)) 
          {
            i = i - 1;
            break;
          }
          fscanf(fp, " %c", &alteracoes[i].operacao);
          fscanf(fp, "%i", &alteracoes[i].tempo);
          fscanf(fp, "%i", &alteracoes[i].indice);
          fscanf(fp, "%i", &alteracoes[i].duracao);
          i++;
        }

        break;

    default:
        return -1;
        break;
    }

    fclose(fp);
      
    return 0;
}