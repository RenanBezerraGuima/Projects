#include <stdio.h>

#define TRUE 1
#define FALSE 0

int verificaAnoBissexto(int a)
{
  if (a%4 == 0)
  {
    if (a%100 == 0) 
    {
      if (a%400 == 0) 
      {
        diasNoMes[2] = 29;
        return TRUE;
      }
      else return FALSE;
    }
    else 
    {
      diasNoMes[2] = 29;
      return TRUE;
    }
  }
  else return FALSE;
}

int verificaAnoBissexto(int a)
{
  if ((a%4 == 0 && a%100 == 0 && a%400 == 0) || (a%4 == 0 && a%100 != 0) )return TRUE;
  if (a%4 !=0 || (a%4 == 0 && a%100 == 0 && a%400 != 0)) return FALSE;
  return 0;
}

int main ()
{
  int ano;
  scanf("%i", &ano);
  if ( verificaAnoBissexto(ano)==TRUE) printf("Eh bissexto\n");
  else printf("Nao eh bissexto\n");
  return 0;
}