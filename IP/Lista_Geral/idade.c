#include <stdio.h>

int main () {
    int idade,anos,dias,meses;
    scanf("%i", &idade);

    anos = idade / 365;
    meses = (idade % 365)/ 30;
    dias = ( idade % 365) % 30;

    printf("%i ano(s)\n", anos);
    printf("%i mes(es)\n", meses);
    printf("%i dia(s)\n", dias);

    return 0;
}