#include <stdio.h>

int main() {
float x,y,z;

printf("Entre com três inteiros:");

scanf("%f %f %f",&x,&y,&z);

if (x > y && x > z) printf("\nO número %.2f é o maior.\n\n",x);
else if (y > x && y > z) printf("\nO número %.2f é o maior.\n\n",y);
else printf("\nO número %.2f é o maior.\n\n",z);

}
