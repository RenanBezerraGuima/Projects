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

void ordenaPontos(time * timescampeonato, int notimes)
{
  // Adicione seu código para ordenar em ordem decrescente de pontos ganhos
}

// Ordena por saldo de gols

void ordenacao(time * timescampeonato, int notimes)
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

int encontratime(time *timescampeonato, char * nome, int notimes) 
{
  int i;
  for (i = 0; i < notimes; i++) 
  {
    if (strcmp(timescampeonato[i].nome, nome) == 0) return i;
  }
  return -1; 
}

// Cria a lista de times do campeonato a partir dos nojogos

int crialistatimes(time * timescampeonato, jogo * dadosjogos, int numerojogos) {
  int i, j;
  int Notimes = 0;
  int novo_time_casa;
  int novo_time_visitante;

  for(i=0; i<numerojogos; i++)
  {
    novo_time_casa = 1;
    novo_time_visitante = 1;
    for(j=0; j<Notimes; j++)
    {
      if(strcmp(dadosjogos[i].local, timescampeonato[j].nome) == 0){
        novo_time_casa = 0;
        break;
      }   
    }
    if(novo_time_casa)
    {
      strcpy(timescampeonato[Notimes].nome, dadosjogos[i].local);
      Notimes++;
    }
    for (j = 0; j < Notimes; j++) 
    {
      if (strcmp(dadosjogos[i].visitante, timescampeonato[j].nome) == 0) 
      {
         novo_time_visitante = 0;
         break;
      }
    }
      if (novo_time_visitante) 
      {
         strcpy(timescampeonato[Notimes].nome, dadosjogos[i].visitante);
         Notimes++;
      }

  }
  return Notimes; 
}

// Computa dados times
void computadadostimes(time * timescampeonato,int notimes,jogo * dadosjogos,int numerojogos) 
{
  int i;

  for(i=0; i<notimes; i++)
  {
    timescampeonato[i].Vitorias = 0;
    timescampeonato[i].GolsSofridos = 0;
    timescampeonato[i].GolsMarcados = 0;
    timescampeonato[i].SaldoDeGols = 0;
    timescampeonato[i].PontosGanhos = 0;
    timescampeonato[i].GolAverage = 0.0;
  }

  for(i=0; i<notimes; i++)
  {
    int ilocal = encontratime(timescampeonato, dadosjogos[i].local, notimes);
    int ivisitante = encontratime(timescampeonato, dadosjogos[i].visitante, notimes);

    timescampeonato[ilocal].GolsMarcados += dadosjogos[i].golslocal;
    timescampeonato[ilocal].GolsSofridos += dadosjogos[i].golsvisitante;
    timescampeonato[ivisitante].GolsMarcados += dadosjogos[i].golsvisitante;
    timescampeonato[ivisitante].GolsSofridos += dadosjogos[i].golslocal;  

    if(timescampeonato[ilocal].GolsMarcados > timescampeonato[ilocal].GolsSofridos)
    {
      timescampeonato[ilocal].Vitorias++;
      timescampeonato[ilocal].PontosGanhos += 3;
    } else if(timescampeonato[ilocal].GolsMarcados == timescampeonato[ivisitante].GolsMarcados)
    {
      timescampeonato[ilocal].Empates++;
      timescampeonato[ilocal].PontosGanhos++;
      timescampeonato[ivisitante].PontosGanhos++;
    } else
    {
      timescampeonato[ilocal].Derrotas++;
      timescampeonato[ivisitante].Vitorias++;
      timescampeonato[ivisitante].PontosGanhos += 3;
    }
  }

  for(i=0; i<notimes; i++)
  {
    timescampeonato[i].SaldoDeGols = timescampeonato[i].GolsMarcados - timescampeonato[i].GolsSofridos;

    if(timescampeonato[i].GolsSofridos != 0)
    {
      timescampeonato[i].GolAverage = (float)timescampeonato[i].GolsMarcados / timescampeonato[i].GolsSofridos;   
    }
  }
}

// Imprime classificação

void imprimeclassificacao(time * timescampeonato,int notimes){
  ordenacao(timescampeonato,notimes);
 int i;
  printf("Posicao,Nome,Pontos Ganhos,Vitorias,Empates,Derrotas,Saldo de Gols,Gol Average\n");
  for(i=0; i<notimes; i++){
    printf("%d,%s,%d,%d,%d,%d,%d,%.3f\n", i+1,timescampeonato[i].nome,timescampeonato[i].PontosGanhos,timescampeonato[i].Vitorias,timescampeonato[i].Empates,timescampeonato[i].Derrotas,timescampeonato[i].SaldoDeGols,timescampeonato[i].GolAverage);
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
  //   printf("Notimes: %d\n", notimes);
  //   printf("\nTimes:\n");
  //   for(i=0; i < notimes;++i)
  //     printf("%2d:%s\n",i+1,times[i].nome);

  computadadostimes(times,notimes,jogos,nojogos);
  printf("\nResultado da computação dos dados dos jogos:\n");
  for(i=0; i < notimes;++i)
    {
    printf("%d:%s\n",i,times[i].nome);
    printf("Pontos ganhos: %d\n",times[i].PontosGanhos);
    printf("Gols marcados: %d\n",times[i].GolsMarcados);
    printf("Gols sofridos: %d\n",times[i].GolsSofridos);
    printf("Vitorias: %d\n",times[i].Vitorias);
    printf("Saldo de gols: %d\n",times[i].SaldoDeGols);
    printf("Gols average: %2.3f\n",times[i].GolAverage);
  }

  imprimeclassificacao(times,notimes);

  // Opcional
  salvaclassificacao(times,notimes,"campeonatoIP.dat");

}