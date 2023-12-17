#include <stdio.h>
#include <stdlib.h>

double* somaPolinomios(double* p, double* q, int n) {

double* p3 = (double*) malloc(sizeof(double)*n);

for (int i= 0; i < n; i++){

    p3[i] = p[i] + q[i];

}
return (p3);
}

int main(){
  int i, j;
  double* p1, * p2, * r;
  int n = 5;
  p1 = (double*) malloc(sizeof(double)*n);
  p2 = (double*) malloc(sizeof(double)*n);
  p1[0] = 1;
  p1[1] = 0;
  p1[2] = 2;
  p1[3] = 0;
  p1[4] = 4;

  p2[0] = 3;
  p2[1] = 2;
  p2[2] = 3;
  p2[3] = -2;
  p2[4] = 3;

  r = somaPolinomios(p1,p2,n);
  for (i=0;i<n;i++){
    if (r[i]>=0) printf(" +");
    else printf(" ");
    printf("%.2f*x^%i", r[i], i);
  }
  printf("\n");
  
  return 0;
}


/* SAIDA:
 +4.00*x^0 +2.00*x^1 +5.00*x^2 -2.00*x^3 +7.00*x^4
*/