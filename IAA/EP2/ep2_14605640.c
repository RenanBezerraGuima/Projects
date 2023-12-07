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

// heapify a raiz de indice i
// N é tamanho do arranjo
void heapify(VETOR arr[], int N, int i){
	// Acha o menor entre a raiz e
	// os filhos esquerdo e direito

	// Inicializa o minimo como a raiz
	int minimo = i;

	int filhoEsquerdo = 2 * i + 1;

	int filhoDireito = 2 * i + 2;

	// Se o filho esquerdo é menor que o minimo atual
	if (filhoEsquerdo < N && (arr[filhoEsquerdo].valor < arr[minimo].valor || (arr[filhoEsquerdo].valor == arr[minimo].valor && arr[filhoEsquerdo].indice < arr[minimo].indice)))

		minimo = filhoEsquerdo;

	// Se o filho direito é menor que o minimo atual
	if (filhoDireito < N && (arr[filhoDireito].valor < arr[minimo].valor || (arr[filhoDireito].valor == arr[minimo].valor && arr[filhoDireito].indice < arr[minimo].indice)))

		minimo = filhoDireito;

	// Se o minimo foi trocado, ou seja não está 
    // como heap atualmente, troca o atual minimo
    // com o novo e faz o heapfiy novamente
	if (minimo != i) 
  {
		troca(&arr[i], &arr[minimo]);

		// Recursivamente faz o heapify
		heapify(arr, N, minimo);
	}
}

// Constroi o HeapMin do arranjo
void construirHeapMin(VETOR arr[], int N){
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);
}

void insercaoHeap(VETOR arr[], int* N, int ch){
	arr[*N].valor = ch;
  arr[*N].indice = *N + 1;
	
	int i = *N;
	//Enquanto o pai for maior que o filho
	while (i>0 && arr[i/2].valor > arr[i].valor)
	{
		troca(&arr[i], &arr[i/2]);
		i = i/2;//Novo pai
	}
	*N = *N + 1;
}

void remocaoHeap(VETOR arr[], int* N, int* indice, int* valor){
  //Guarda o indice e valor da raiz
	*indice = arr[0].indice;
  *valor = arr[0].valor;
  //Troca a raiz com o ultimo elemento
	troca(&arr[0], &arr[*N - 1]);
  //Diminui o tamanho do heap
	*N = *N - 1;
  //Faz o heapify da raiz
	heapify(arr,*N, 0);
}

//Recebe o vetor atualizacoes já como heap e o vetor de alterações
void resposta2(VETOR atualizacoes[], int tamanhoAtt, ALT alteracoes[], int tamanhoAlt, int duracaototal){
  int tempo = 0; //Tempo atual inicializado
  int qtdAtts = 0; // Quantidade de atualizações que entrarão para a saida
  VETOR vetorResp[100];
  int k = 0; //indice das alterações

  while (tempo < duracaototal) //Enquanto o tempo atual não ultrapassar o tempo total
  {
    while (k < tamanhoAlt && tempo >= alteracoes[k].tempo)// Enquanto tiverem alterações a fazer
    {
      if (alteracoes[k].operacao == 'c') //Operação de mudança
      {
        for (int j = 0; j < tamanhoAtt; j++)// Buscar no heap pelo indice
        {
          if ((atualizacoes[j].indice + 1) == alteracoes[k].indice)// Quando achar
          {
            atualizacoes[j].valor = alteracoes[k].duracao;// Muda o valor 
            construirHeapMin(atualizacoes, tamanhoAtt); // Reconstrói o heap após a mudança
            break; // Sai do loop
          }
        }
      }
  
      else if (alteracoes[k].operacao == 'i') //Operação de inserção
      {
        insercaoHeap(atualizacoes, &tamanhoAtt, alteracoes[k].duracao);//Inserção mantem o heap
      }
      k++; //Aumenta o indice das alterações
    }
      
    if (atualizacoes[0].valor + tempo <= duracaototal) //Verifica se a atualização raiz cabe no tempo total
    {
      int indice;
      int valor;  
      remocaoHeap(atualizacoes, &tamanhoAtt, &indice, &valor); //Remove a raiz do heap e coloca no vetorResposta
      vetorResp[qtdAtts].indice = indice;
      vetorResp[qtdAtts].valor = valor;
      tempo = tempo + vetorResp[qtdAtts].valor;
      qtdAtts++;
    }
  }

  //Faz o arquivo de saida2.txt e coloca as respostas nele
  FILE *outputFile = fopen("saida2.txt", "w");
  saida(qtdAtts, vetorResp, outputFile);
}

int main(int argc, char *argv[]) {
  //argc me diz a quantidade de comandos que recebo pela linha de comando 
  //argv é um vetor com os argumentos com:
  //  argv[0] = nome do programa
  //  argv[1] = duração do período de atts (14,15,...,20) horas
  //  argv[2] = cenário (1 ou 2)
  //  argv[3] = nome do arquivo de entrada (entrada1.txt ou entrada2.txt), conforme o cenário
  if (argc != 4)//Se não tiver 4 argumentos, retorna -1
  {
    return -1;
  }

  //atoi transforma o char do argv em inteiro
  int duracao = atoi(argv[1]);//Recebe a duração da linha de comando
  int cenario = atoi(argv[2]);//Recebe o cenario da lnha de comando

  //Abre o arquivo recebido como argumento, usar fp como arquivo e as funções f(scanf, printf)
  char filename[MAX_FILENAME] = "";
  strcpy(filename, argv[3]);
  FILE* fp = fopen(filename, "r");
  if (fp == NULL)
  {
    fprintf(stderr, "Não foi possível abrir o arquivo %s\n", filename);
    return -1;
  }  

  //Recebe a quantidade de Atualizações pelo arquivo de entrada
  int qtdAtts;
  fscanf(fp, "%i", &qtdAtts);

  //Le as atualizações do arquivo de entrada,
  //e cria um vetor 
  VETOR atualizacoes[100];
  for(int i = 0; i < qtdAtts; i++)
  {
    fscanf(fp, "%i", &atualizacoes[i].valor);
    atualizacoes[i].indice = i;
  }

  switch (cenario)
  {
  case 1:
    //Ordena o vetor de atualizações pelo valor
    countingSort(atualizacoes, qtdAtts);
    //Faz o arquivo de saida1.txt
    FILE *outputFile = fopen("saida1.txt", "w");
    //Chama a função que calcula o numero de atualizações max e faz o arquivo de saida
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
    //Constroi o heapMin do vetor de atualizações
    construirHeapMin(atualizacoes, qtdAtts);
    //Chama a função que faz a resposta do cenário 2
    resposta2(atualizacoes, qtdAtts, alteracoes, i, duracao);
    break;

  default:
    return -1;
    break;
  }

  fclose(fp);
    
  return 0;
}