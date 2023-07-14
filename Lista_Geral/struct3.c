#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[60];
    int matricula;
    char curso[40];
}novoAluno;

int main (){
   novoAluno alunos[5];

    printf("Insira a informacao de 5 alunos, na ordem (nome matricula curso)\n");
    for (int i=1;i<=2;i++)
    {
        scanf("%s %i %s", alunos[i].nome, &alunos[i].matricula, alunos[i].curso);
    }

    for (int i=1;i<=2;i++)
    {   
        printf("\n\t\tAluno%i\n",i);
        printf("\nNome: \t\t%s\n", alunos[i].nome);
        printf("Matricula: \t%i\n", alunos[i].matricula);
        printf("Curso: \t\t%s\n\n", alunos[i].curso);
    }

    return 0;
}