#include <stdio.h>

int main ()
{
    float salario;
    scanf("%f", &salario);

    if (salario>=0 && salario<=400)
    {
        printf("Novo salario: %.2f\n",salario*1.15);
        printf("Reajuste ganho: %.2f\n",salario*0.15);
        printf("Em percentual: %i %%\n",15);
    }
    else if (salario>=400.01 && salario<=800)
    {
        printf("Novo salario: %.2f\n",salario*1.12);
        printf("Reajuste ganho: %.2f\n",salario*0.12);
        printf("Em percentual: %i %%\n",12);
    }
    else if (salario>=800.01 && salario<=1200)
    {
        printf("Novo salario: %.2f\n",salario*1.10);
        printf("Reajuste ganho: %.2f\n",salario*0.1);
        printf("Em percentual: %i %%\n",10);
    }
    else if (salario>=1200.01 && salario<=2000)
    {
        printf("Novo salario: %.2f\n",salario*1.07);
        printf("Reajuste ganho: %.2f\n",salario*0.07);
        printf("Em percentual: %i %%\n", 7);
    }
    else if (salario>2000)
    {
        printf("Novo salario: %.2f\n",salario*1.04);
        printf("Reajuste ganho: %.2f\n",salario*0.04);
        printf("Em percentual: %i %%\n", 4);
    }

    return 0;
}