#include <stdio.h>

void maiornumero(float x,float y,float z){
    if (x > y && x > z) printf("\n%.2f É o maior número.",x);
    else if (y > x && y > z) printf("\n%.2f É o maior número.",y);
    else printf("\n%.2f É o maior número.",z);
}

void menornumero(float x,float y,float z){
    if (x < y && x < z) printf(" %.2f É o menor número.\n\n",x);
    else if (y < x && y < z) printf(" %.2f É o menor número.\n\n",y);
    else printf(" %.2f É o menor número.\n\n",z);

}

void main() {
float x,y,z;

printf("Entre com três números racionais:");
scanf("%f %f %f",&x,&y,&z);

maiornumero(x,y,z);
menornumero(x,y,z);

}
