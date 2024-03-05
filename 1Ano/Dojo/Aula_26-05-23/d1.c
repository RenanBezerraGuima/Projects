#include <stdio.h>
#include <stdlib.h>

void arranjoNotas(int N, double* arranjo){
        for (int j = 0; j < N; j++){
            scanf("%lf", &arranjo[j]);
        }
    }

int main (){
    int n;

    printf("Insira a quantidade de notas que estarão no arranjo: \n");
    scanf("%i", &n);

    double* arranjo = (double*) malloc (sizeof(double)*n);

    arranjoNotas(n,arranjo);

    for (int k =0; k < n ; k++ ) printf ("%.2lf ", arranjo[k]);

    printf("\n");

    return 0;
}