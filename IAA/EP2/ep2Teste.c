#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Implementar estas mudanças no arquivo original do EP

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

void exibirVetor(VETOR vetor[], int tamanho) {
  for (int i = 0; i < tamanho; ++i) {
    printf("%d ", vetor[i].valor);
  }
  printf("\n");
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
void heapify(VETOR arr[], int N, int i)
{
	// Acha o menor entre a raiz e
	// os filhos esquerdo e direito

	// Inicializa o minimo como a raiz
	int minimum = i;

	int left = 2 * i + 1;

	int right = 2 * i + 2;

	// Se o filho esquerdo é menor que o minimo atual
	if (left < N && (arr[left].valor < arr[minimum].valor || (arr[left].valor == arr[minimum].valor && arr[left].indice < arr[minimum].indice)))

		minimum = left;

	// Se o filho direito é menor que o minimo atual
	if (right < N && (arr[right].valor < arr[minimum].valor || (arr[right].valor == arr[minimum].valor && arr[right].indice < arr[minimum].indice)))

		minimum = right;

	// Se o minimo foi trocado, ou seja não está 
    // como heap atualmente, troca o atual minimo
    // com o novo e faz o heapfiy novamente
	if (minimum != i) {

		troca(&arr[i], &arr[minimum]);

		// Recursively heapify the affected
		// sub-tree
		heapify(arr, N, minimum);
	}
}

// Constroi o HeapMin do arranjo
void construirHeapMin(VETOR arr[], int N)
{
	for (int i = N / 2 - 1; i >= 0; i--)
		heapify(arr, N, i);
}

void insercaoHeap(VETOR arr[], int* N, int ch)
{
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

void remocaoHeap(VETOR arr[], int* N, int* indice, int* valor)
{
	*indice = arr[0].indice;
    *valor = arr[0].valor;
	troca(&arr[0], &arr[*N - 1]);
	*N = *N - 1;
	heapify(arr,*N, 0);
}

//Recebe o vetor atualizacoes já como heap e o vetor de alterações
void resposta2(VETOR atualizacoes[], int tamanhoAtt, ALT alteracoes[], int tamanhoAlt, int duracaototal){
  int tempo = 0; //Tempo atual inicializado
  int qtdAtts = 0; // Quantidade de atualizações que entrarão para a saida
  VETOR vetorResp[100];
  int k = 0;
  while (tempo < duracaototal) //Enquanto tiver tempo 
  {
    while (k < tamanhoAlt && tempo >= alteracoes[k].tempo)// Se tiver alguma alteração para fazer
    {
        if (alteracoes[k].operacao == 'c') //Mudança
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
            
        else if (alteracoes[k].operacao == 'i') //Inserção
        {
            insercaoHeap(atualizacoes, &tamanhoAtt, alteracoes[k].duracao);
        }
            
        k++;
    }
      

      if (atualizacoes[0].valor + tempo <= duracaototal)
      {
        int indice;
        int valor;  
        remocaoHeap(atualizacoes, &tamanhoAtt, &indice, &valor);
        vetorResp[qtdAtts].indice = indice;
        vetorResp[qtdAtts].valor = valor;
        tempo = tempo + vetorResp[qtdAtts].valor;
        qtdAtts++;
      }
    }

    //Faz o arquivo de saida2.txt e coloca as respostas nele
    FILE *outputFile = fopen("saida2Teste.txt", "w");
    saida(qtdAtts, vetorResp, outputFile);
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

    exibirVetor(atualizacoes, qtdAtts);

    for (int j = 0; j < i; j++)
    {
        printf("%c ", alteracoes[j].operacao);
        printf("%i ", alteracoes[j].tempo);
        printf("%i ", alteracoes[j].indice);
        printf("%i", alteracoes[j].duracao);
        printf("\n");
    }

    construirHeapMin(atualizacoes, qtdAtts);
    exibirVetor(atualizacoes, qtdAtts);
    
    resposta2(atualizacoes, qtdAtts, alteracoes, i, duracao);

    fclose(fp);
      
    return 0;
}