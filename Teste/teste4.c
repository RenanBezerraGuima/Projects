#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main() {
    int x;
    scanf("%d", &x);
    double resultado = log2(x);
    printf("%.0lf\n", resultado + 1);

    return 0;
}
