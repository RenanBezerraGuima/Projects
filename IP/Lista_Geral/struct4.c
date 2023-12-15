#include <stdio.h>
#include <string.h>

typedef struct {    
    char nome[60];
    int matricula;
    double p1;
    double p2;
    double p3;
    double media;
    int aprovacao;
}novoAluno;

int maiorNotaP1 (novoAluno* alunos)
{   
    double max = alunos[0].p1;
    int pos = 0;
    for (int i=1;i<5;i++)
    {
        if (alunos[i].p1 > max) 
        {
            max = alunos[i].p1;
            pos = i;
        }
    }
    return pos+1;
}

int main (){
    novoAluno alunos[5];
    
    //Entradada dos Dados
    printf("Insira a informacao de 5 alunos, na ordem (nome matricula p1 p2 p3)\n");
    for (int i=0;i<5;i++)
    {
        scanf("%s %i %lf %lf %lf", alunos[i].nome, &alunos[i].matricula, &alunos[i].p1, &alunos[i].p2, &alunos[i].p3);
    }

    //Calculo da media 
    for(int i=0;i<5;i++)
    {
        alunos[i].media = (alunos[i].p1 + alunos[i].p2 + alunos[i].p3)/3;
    }

    //Impresão dos Dados
    for (int i=0;i<5;i++)
    {   
        printf("\n\t\tAluno%i\n",i+1);
        printf("\nNome: \t\t%s\n", alunos[i].nome);
        printf("Matricula: \t%i\n", alunos[i].matricula);
        printf("Prova1: \t%.2lf\n", alunos[i].p1);
        printf("Prova2: \t%.2lf\n", alunos[i].p2);
        printf("Prova3: \t%.2lf\n", alunos[i].p3);
        printf("Media: \t%.2lf\n", alunos[i].media);
        if (alunos[i].media >= 5){
            alunos[i].aprovacao = 1;
            printf("Foi aprovado\n");
        }
            else {
                alunos[i].aprovacao = 0;
                printf("Nao foi aprovado\n");
            }
    }

    //Impressão do maior nota P1
    printf("\nO Aluno%i tem a maior nota na Prova1\n", maiorNotaP1(alunos));

    //Maior media
    double maiorMedia = alunos[0].media;
    int posMaiorMedia = 0;
    for (int i=1;i<5;i++)
    {
        if (alunos[i].media > maiorMedia)
        {
            maiorMedia = alunos[i].media;
            posMaiorMedia = i;
        }
    }
    printf("\nO Aluno%i tem a maior media\n", posMaiorMedia+1);

    //Menor media
    double menorMedia = alunos[0].media;
    int posMenorMedia = 0;
    for (int i=1;i<5;i++)
    {
        if (alunos[i].media < menorMedia)
        {
            menorMedia = alunos[i].media;
            posMenorMedia = i;
        }
    }
    printf("\nO Aluno%i tem a menor media\n", posMenorMedia+1);

    return 0;
}

//Para teste de entrada, copie e cole isto:
// Renan 14605640 7.3 8.7 6.7 Joao 14597220 6.7 5.6 2.3 Jose 2589200 2.3 4.5 5.7 Fernando 12368987 2.3 1.5 7.2 Anna 1459782 7.2 8.3 10.0