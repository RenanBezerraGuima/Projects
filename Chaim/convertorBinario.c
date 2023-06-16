#include <stdio.h>

int main () {
    int quociente;
    
    int num = 484;
     quociente = num / 2; 
    int resto1 = num % 2;
     quociente = quociente / 2;
    int resto2 = quociente % 2;
     quociente = quociente / 2;
    int resto3 = quociente % 2;
     quociente = quociente / 2;
    int resto4 = quociente % 2;
     quociente = quociente / 2;
    int resto5 = quociente % 2;
     quociente = quociente / 2;
    int resto6 = quociente % 2;
     quociente = quociente / 2;
    int resto7 = quociente % 2;
     quociente = quociente / 2;
    int resto8 = quociente % 2;
     quociente = quociente / 2;
    int resto9 = quociente % 2;

    printf("%i%i%i%i%i%i%i%i%i\n", resto9, resto8, resto7, resto6, resto5, resto4, resto3, resto2, resto1);
    return 0;
}