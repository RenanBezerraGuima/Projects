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

void saida(int MaxAtts, VETOR vetorResp[], FILE* outputFile){

  fprintf(outputFile, "%i", MaxAtts);
  for(int i = 0; i < MaxAtts; i++) fprintf(outputFile, " %i", vetorResp[i].indice+1);
  fprintf(outputFile,"\n");

  fclose(outputFile);
}

// Troca dois valores
void troca(VETOR* a, VETOR* b)
{
	int tempValor = a->valor;
  int tempIndice = a->indice;
	a->valor = b->valor;
  a->indice = b->indice;
	b->valor = tempValor;
  b->indice = tempIndice;
}

// heapify uma subarvore rooted with node i which is an index in arr[].
// N é tamanho do arranjo
void heapify(VETOR* arr[], int N, int i)
{
	// Acha o menor entre a raiz e
	// os filhos esquerdo e direito

	// Inicializa o minimo como a raiz
	int minimum = i;

	int left = 2 * i + 1;

	int right = 2 * i + 2;

	// Se o filho esquerdo é menor que o minimo atual
	if (left < N && arr[left]->valor < arr[minimum]->valor)

		minimum = left;

	// Se o filho direito é menor que o minimo atual
	if (right < N && arr[right]->valor < arr[minimum]->valor)

		minimum = right;

	// Se o minimo foi trocado, ou seja não está 
    // como heap atualmente, troca o atual minimo
    // com o novo e faz o heapfiy novamente
	if (minimum != i) {

		troca(arr[i], arr[minimum]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, minimum);
	}
}

// Constroi o HeapMin do arranjo
void construirHeapMin(VETOR arr[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(&arr, N, i);
}

void insercaoHeap(VETOR* arr[], int* N, int ch)
{
	arr[*N]->valor = ch;
  arr[*N]->indice = *N;
	
	int i = *N;
	//Enquanto o pai for maior que o filho
	while (i>0 && arr[i/2]->valor > arr[i]->valor)
	{
		troca(arr[i], arr[i/2]);
		i = i/2;//Novo pai
	}
	*N = *N + 1;
}

VETOR* remocaoHeap(VETOR* arr[], int* N)
{
	VETOR* resp = arr[0];
	troca(arr[0], arr[*N - 1]);
	*N = *N - 1;
	heapify(arr,*N, 0);

	return resp;
}

//Recebe o vetor atualizacoes já como heap e o vetor de alterações
void resposta2(VETOR atualizacoes[], int tamanhoAtt, ALT alteracoes[], int tamanhoAlt, int duracaototal)
{
  int tempo = 0; //Tempo atual inicializado
  int qtdAtts = 0; // Quantidade de atualizações que entrarão para a saida
  VETOR* vetorResp[100];
  int k = 0;
  while (tempo < duracaototal) //Enquanto tiver tempo 
  {
    if (k < tamanhoAlt && tempo > alteracoes[k].tempo)// Se tiver alguma alteração para fazer
    {
      switch (alteracoes[k].operacao)
      {
        case 'c': //Mudança
          for (int j = 0; j < tamanhoAtt; j++)// Buscar no heap pelo indice
          {
            if (atualizacoes[j].indice + 1 == alteracoes[k].indice)// Quando achar
            {
              atualizacoes[j].valor = alteracoes[k].duracao;// Muda o valor 
            }

            //Mudado ficou menor que o pai
            if (atualizacoes[j].valor < atualizacoes[j/2].valor && j/2>0)
            {
              int w = j;
              while (w>0 && atualizacoes[w].valor < atualizacoes[w/2].valor)
              {
                troca(&atualizacoes[w], &atualizacoes[w/2]);
                w = w/2;//Novo pai
              }
            }

            //Mudado ficou maior que o pai, verifica se o filhos estao corretos
            else if (atualizacoes[j].valor > atualizacoes[j/2].valor && j/2>0)
            {
              heapify(&atualizacoes, tamanhoAtt, j);
            }
          }
          break;
        
        case 'i'://Inserção
          insercaoHeap(&atualizacoes, &tamanhoAtt, alteracoes[k].duracao);
          break;
      }
      k++;
    }

    if (atualizacoes[0].valor + tempo <= duracaototal)
    {
      vetorResp[qtdAtts] = remocaoHeap(&atualizacoes, &tamanhoAtt);
      tempo = tempo + vetorResp[qtdAtts]->valor;
      qtdAtts++;
    }
    break;
  }  

  //Faz o arquivo de saida2.txt e coloca as respostas nele
  FILE *outputFile = fopen("saida2.txt", "w");
  saida(qtdAtts, *vetorResp, outputFile);
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
        FILE *outputFile = fopen("saida1.txt", "w");
        saida(maxAtualizacoes1(atualizacoes, qtdAtts, duracao),atualizacoes, outputFile);
        break;
    
    case 2:
        //Cria um vetor das alterações q devem acontecer
        ALT alteracoes[100];
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
        construirHeapMin(atualizacoes, qtdAtts);
        resposta2(atualizacoes, qtdAtts, alteracoes, i, duracao);
        break;

    default:
        return -1;
        break;
    }

    fclose(fp);
      
    return 0;
}