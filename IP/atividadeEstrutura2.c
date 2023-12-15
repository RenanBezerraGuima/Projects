#include <stdio.h>

typedef struct {
  int nusp;
  float nota;
} ALUNO;

typedef struct {
  ALUNO A[5];
} TURMA;

void imprimir(TURMA t){
  for (int i=0;i<5;i++){
    printf("NUSP: %5i, nota: %5.2f\n", t.A[i].nusp, t.A[i].nota);
  }
}

int contagemNotas(TURMA t, float nota){
  int cont = 0;

  for (int i=0;i<5;i++)
  {
    if(t.A[i].nota >= nota) cont++;
  }

  return cont;
}



int main() {
  TURMA T04;
  T04.A[0].nusp = 12;
  T04.A[1].nusp = 111;
  T04.A[2].nusp = 222;
  T04.A[3].nusp = 333;
  T04.A[4].nusp = 444;

  T04.A[0].nota = 4.5;
  T04.A[1].nota = 6;
  T04.A[2].nota = 10;
  T04.A[3].nota = 7;
  T04.A[4].nota = 7.5;

  imprimir(T04);

  printf("\nAlunos com nota 7 ou mais: %i\n", contagemNotas(T04,7));

  printf("Alunos com nota 5 ou mais: %i\n", contagemNotas(T04,5));
  
  return 0;
}