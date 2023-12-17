#include <stdio.h>

//Algoritmo de Euclides iterativo
int mdc(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
//Algoritmo do MMC
int mmc(int a, int b,int c, int d){
    return a * (b / mdc(a, b,c,d));
}
//Testes
int main() {
    printf("MMC\n");
    printf("%d\n", mmc(2,3,4,5));
    return 0;
}
