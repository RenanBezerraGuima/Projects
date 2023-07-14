/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2023                          **/
/**   Turma 02 - Prof. Marcos Lordello Chaim                        **/
/**                                                                 **/
/**   Segundo Exercicio-Programa                                    **/
/**                                                                 **/
/**   <Renan Bezerra Guimarães>                   <14605640>        **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NumeroMaxTimes 20
#define NumeroMaxRodadas 38
#define NumeroMaxJogos NumeroMaxTimes * NumeroMaxRodadas

typedef struct auxtime {
  int PontosGanhos;
  int GolsMarcados;
  int GolsSofridos;
  int SaldoDeGols;
  int Vitorias;
  int Empates;
  int Derrotas;
  float GolAverage;
  char nome[31];
} time;

typedef struct auxjogo {
  char local[30];
  char visitante[30];
  int golslocal;
  int golsvisitante;
} jogo;

void lenometime(char * s) {
  int i;
  s[0] = '\0';
  char c;
  c = getchar();
  for(i = 0; c != ',' && i < 30;++i)
    {
      // if(c == '\n')
      //   continue;
      s[i] = c;
      c = getchar();
    }
  s[i] = '\0';
  //printf("%s\n",s);
}

// Ordena por Pontos

void ordenaPontosEsaldo(time * timescampeonato, int notimes)
{
  // Adicione seu código para ordenar em ordem decrescente de pontos ganhos
  time temp;
   for (int i = 0; i < notimes - 1; i++)
   {
      for (int j = 0; j < notimes - i - 1; j++)
      {
         if (timescampeonato[j].PontosGanhos < timescampeonato[j + 1].PontosGanhos)
         {
            temp = timescampeonato[j];
            timescampeonato[j] = timescampeonato[j + 1];
            timescampeonato[j + 1] = temp;
         }
         else if (timescampeonato[j].PontosGanhos == timescampeonato[j + 1].PontosGanhos)
         {
            if (timescampeonato[j].SaldoDeGols < timescampeonato[j + 1].SaldoDeGols)
            {
               temp = timescampeonato[j];
               timescampeonato[j] = timescampeonato[j + 1];
               timescampeonato[j + 1] = temp;
            }
         }
      }
   }
}

// Encontra se o time já está no arranjo de times do campeonato

int encontratime(time *timescampeonato, char * nome, int notimes) {
  // Retorna a posição do arranjo times de campeonato
  // Adicione seu código

  return -1; // retorna -1 se o time com o nome "nome" não existe
}

// Cria a lista de times do campeonato a partir dos nojogos

int crialistatimes(time * timescampeonato, jogo * dadosjogos, int numerojogos) {
  // Preenche o arranjo timescampeonato com os times
  strcpy(timescampeonato[0].nome,dadosjogos[0].local);
  strcpy(timescampeonato[1].nome,dadosjogos[0].visitante);
  int numTimes = 2;
  
  for (int j = 1; j < numerojogos; j++) {
    int timeLocalExiste = 0;
    int timeVisitanteExiste = 0;

    // Verifica se o time local já existe na lista
    for (int i = 0; i < numTimes; i++) {
        if (strcmp(dadosjogos[j].local, timescampeonato[i].nome) == 0) {
            timeLocalExiste = 1;
            break;
        }
    }

    // Se o time local não existe, adiciona à lista
    if (!timeLocalExiste) {
        strcpy(timescampeonato[numTimes].nome, dadosjogos[j].local);
        numTimes++;
    }

    // Verifica se o time visitante já existe na lista
    for (int i = 0; i < numTimes; i++) {
        if (strcmp(dadosjogos[j].visitante, timescampeonato[i].nome) == 0) {
            timeVisitanteExiste = 1;
            break;
        }
    }

    // Se o time visitante não existe, adiciona à lista
    if (!timeVisitanteExiste) {
        strcpy(timescampeonato[numTimes].nome, dadosjogos[j].visitante);
        numTimes++;
   }
  } 
  return numTimes; // retorna o número de times. O zero é só para compilar
}

// Computa dados times
void computadadostimes(time * timescampeonato,int notimes,jogo * dadosjogos,int numerojogos) {
  // Preenche os campos dos elementos do arranjo timescampeonato: Vitorias,
  // GolsSofridos, GolsMarcados, Golsaverage, SaldoDeGols, PontosGanhos.

  for (int j=0;j<notimes;j++)
  {
    timescampeonato[j].GolsMarcados = 0;
    timescampeonato[j].GolsSofridos = 0;
    timescampeonato[j].Vitorias = 0;
    timescampeonato[j].PontosGanhos = 0;
    timescampeonato[j].Empates = 0;
    timescampeonato[j].Derrotas = 0;
    //Comparar com os times locais e adiciona Vitorias, Derrotas e Empates, GolsMarcados e Sofridos
    for(int i=0;i<numerojogos;i++)
    {
      
      if(strcmp(timescampeonato[j].nome,dadosjogos[i].local) == 0)
      {
        timescampeonato[j].GolsMarcados += dadosjogos[i].golslocal;
        timescampeonato[j].GolsSofridos += dadosjogos[i].golsvisitante;
        if (dadosjogos[i].golslocal > dadosjogos[i].golsvisitante) timescampeonato[j].Vitorias++;
        if (dadosjogos[i].golslocal < dadosjogos[i].golsvisitante) timescampeonato[j].Derrotas++;
        if (dadosjogos[i].golslocal == dadosjogos[i].golsvisitante) timescampeonato[j].Empates++;
      }
    }

    //Compara com os times visitantes e adiciona Vitorias, Derrotas, Empates, GolsMarcados e Sofridos
    for(int i=0;i<numerojogos;i++)
    {
      if(strcmp(timescampeonato[j].nome,dadosjogos[i].visitante) == 0)
      {
        timescampeonato[j].GolsMarcados += dadosjogos[i].golsvisitante;
        timescampeonato[j].GolsSofridos += dadosjogos[i].golslocal;
        if (dadosjogos[i].golsvisitante > dadosjogos[i].golslocal) timescampeonato[j].Vitorias++;
        if (dadosjogos[i].golsvisitante < dadosjogos[i].golslocal) timescampeonato[j].Derrotas++;
        if (dadosjogos[i].golsvisitante == dadosjogos[i].golslocal) timescampeonato[j].Empates++;
      }
    }

    //Calculo da GolAverage
    if (timescampeonato[j].GolsSofridos == 0) timescampeonato[j].GolAverage = timescampeonato[j].GolsMarcados;
      else timescampeonato[j].GolAverage = ((float)timescampeonato[j].GolsMarcados/timescampeonato[j].GolsSofridos);

    //Calculo Saldo de Gols
    timescampeonato[j].SaldoDeGols = (timescampeonato[j].GolsMarcados - timescampeonato[j].GolsSofridos);

    //Calculo PontosGanhos
    timescampeonato[j].PontosGanhos = (timescampeonato[j].Vitorias*3 + timescampeonato[j].Empates);
  }
}

// Imprime classificação

void imprimeclassificacao(time * timescampeonato,int notimes){ 
  printf("Posicao,Nome,Pontos Ganhos,Vitorias,Empates,Derrotas,Saldo de Gols,Gol Average\n");
  for(int i=0;i<notimes;i++)
   {
    printf("%i,%s,",i+1,timescampeonato[i].nome);
    printf("%i,%i,%i,",timescampeonato[i].PontosGanhos,timescampeonato[i].Vitorias,timescampeonato[i].Empates);
    printf("%i,",timescampeonato[i].Derrotas);
    printf("%i,%.3f\n",timescampeonato[i].SaldoDeGols,timescampeonato[i].GolAverage);
   }
}

// Salva os dados da classificação dos tipos em arquivo no disco

void salvaclassificacao(time * timescampeonato,int notimes, char * arquivo){
// Adicione seu código

}

int main() {
  time times[NumeroMaxTimes];
  jogo jogos[NumeroMaxJogos];
  int i, nojogos, golslocal = 0, golsvisitante = 0;
  char local[30],visitante[30];

  printf("Entre os jogos no formato \"time local, time visitante, golslocal, golsvisitante\" (gols local negativo encerra a entrada de dados)\n");
  for(i = 0; i < NumeroMaxJogos; ++i) {
    lenometime(local);
    lenometime(visitante);
    scanf("%d,%d",&golslocal,&golsvisitante);
    getchar(); // consome o enter do scanf
    // printf("local %s visitante %s ", local, visitante);
    // printf("golslocal %d, golsvisitante %d\n", golslocal,golsvisitante);
    if (golslocal < 0)
      break; // termina a entrada de dados

    if(strcmp(local,visitante) == 0)
      continue; // possui o mesmo nome time local e visitante

    strncpy(jogos[i].local,local,30);
    strncpy(jogos[i].visitante,visitante,30);

    jogos[i].golslocal = golslocal;
    jogos[i].golsvisitante = golsvisitante;
  }
  nojogos = i;

  // Confirmando os valores lidos
  // for(i=0; i < nojogos;++i)
  //   printf("%d:%s,%s,%d,%d\n",i+1,jogos[i].local,jogos[i].visitante,jogos[i].golslocal,jogos[i].golsvisitante);

  int notimes = crialistatimes(times,jogos,nojogos);
  // printf("Notimes: %d\n", notimes);
  // printf("\nTimes:\n");
  // for(i=0; i < notimes;++i)
  //   printf("%2d:%s\n",i+1,times[i].nome);

  computadadostimes(times,notimes,jogos,nojogos);
  // printf("\nResultado da computação dos dados dos jogos:\n");
  // for(i=0; i < notimes;++i)
  //   {
  //   printf("%d:%s\n",i,times[i].nome);
  //   printf("Pontos ganhos: %d\n",times[i].PontosGanhos);
  //   printf("Gols marcados: %d\n",times[i].GolsMarcados);
  //   printf("Gols sofridos: %d\n",times[i].GolsSofridos);
  //   printf("Vitorias: %d\n",times[i].Vitorias);
  //   printf("Saldo de gols: %d\n",times[i].SaldoDeGols);
  //   printf("Gols average: %2.3f\n",times[i].GolAverage);
  // }
  ordenaPontosEsaldo(times,notimes);
  imprimeclassificacao(times,notimes);

  // Opcional
  salvaclassificacao(times,notimes,"campeonatoIP.dat");

}