#include <stdio.h>

#define DOLLAR 4
#define EURO 5
#define PESOARGENTINO 0.04

int main(){
    float valorReais, valorConvertido;
    int conversao;

    scanf("%f %i", &valorReais, &conversao);

    switch(conversao){
        case 1:
        valorConvertido = valorReais/DOLLAR;
        break;

        case 2:
        valorConvertido = valorReais/EURO;
        break;

        case 3:
        valorConvertido = valorReais/PESOARGENTINO;
        break;

        default:
        valorConvertido = valorReais*1;
    }
    printf("%.2f\n", valorConvertido);

    return 0;
}