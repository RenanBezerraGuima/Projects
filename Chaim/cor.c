#include <stdio.h>

int cor (int identificador){
    
    switch (identificador)
    {
    case 1 :
        printf("verde\n");
        break;

    case 2 :
        printf("amarelo\n");
        break;
    
    case 3 :
        printf("azul\n");
        break;
    
    case 4 : 
        printf("branco\n");
        break;

    default :
        printf("identificador invalido\n");
    
    }

}

void main (){
    int i;

    scanf("%i", &i);
    cor (i);

}