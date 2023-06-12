/*********************************************************************/
/**   ACH2001 - Introducao a Programação                            **/
/**   EACH-USP - Primeiro Semestre de 2022                          **/
/**   Turma 02 - Prof. Marcos Lordello Chaim                        **/
/**                                                                 **/
/**   Primeiro Exercicio-Programa                                   **/
/**                                                                 **/
/**   <Renan Bezerra Guimarães>                   <14605640>        **/
/**                                                                 **/
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int diasNoMes[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

// Verifica se é ou não um ano bissexto.
  //Se for um ano bissexto troca para 29 dias no mês de fevereiro, posição 2 do arranjo.
int verificaAnoBissexto(int a)
{
  if ((a%4 == 0 && a%100 == 0 && a%400 == 0) || (a%4 == 0 && a%100 != 0) )
   {
    diasNoMes[2] = 29;
    return TRUE;
   }

  if (a%4 !=0 || (a%4 == 0 && a%100 == 0 && a%400 != 0)) return FALSE;
  return 0;
}

int verificaDataValida(int d, int m, int a) 
{
    //Verifica se o mês é maior do que 12 OU menor do que 1.
    if(m > 12 || m < 1) return FALSE;

    //Verifica se o dia é menor do que 1.
    if(d < 1) return FALSE;

    //Verifica se o ano é menor do que zero.
    if(a < 0) return FALSE;

    //Vefica se o dia colocado é maior do que a quantidade de dias no mês.
    if ( d > diasNoMes[m] ) return FALSE;

    return TRUE;
}

int proximosEncontros(int d,int m, int a)
{
  int intervalo,n = 1;

  //Descobre o intervalo de dias entre cada reunião.
  while  (!(n%2 == 0 && n%3 == 0 && n%4 == 0 && n%5 == 0 && n%6 == 0)) {
  n++;
  }
  intervalo = n;

  /*Imprime todas as reuniões dentro de um ano.
     1º Soma o intervalo aos dias.
     2º Verifica se o dia é maior do que os dias do dado mês.
     3º Subtrai a quantidade de dias do mês dos dias somados.
     4º Passa para o proximo mês.
  */

  //Imprime todas as datas de reunião dentro de um mês.
  while (m < 12)
   {
    //Soma o intervalo ao dia recebido.
    d = d + intervalo;
    //Realiza a subtração de dias até que chegue ao um mês desejado. 
    while (d > diasNoMes[m]) 
     {
      d = d - diasNoMes[m] ;
      m++;
      //Verifica se o mês é 12 e se tem mais dias do que no mês, para não passar de um ano.
      if (m == 12 && d > diasNoMes[12]) break;
     }
    //Imprime a data da reunião somente se os dias são menores do que o mês.
    if (d < diasNoMes[m]) printf("%i/%i/%i\n", d, m, a);
   }

  return 0;
}

int main() 
  {
    int dia, mes, ano;

    //Recebe o dia, mês e ano do usuário.
    printf("Entre com a data de inicio do ano letivo:\n");
    printf("Entre com o dia: ");
    scanf("%d", &dia);
    printf("Entre com o mes: ");
    scanf("%d", &mes);
    printf("Entre com o ano: ");
    scanf("%d", &ano);

    verificaAnoBissexto(ano);
    //Verifica se as datas estão válidas, se não estevirem válidas retorna FALSE.
    if(verificaDataValida(dia, mes, ano) == FALSE)
      {
        printf("Dados incorretos\n");
        exit(1); // Esta função aborta a execução do programa.
      }

    //Após ter saber se é um ano bissexto e se as datas estão válidas imprime as datas.
    printf("Proximos dias de encontro de todos os clubes:\n");
    proximosEncontros(dia, mes, ano);
    return 0;
  }