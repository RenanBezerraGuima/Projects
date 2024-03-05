#include <stdio.h>

void bubbleSort(int v[], int tam)
{
 int ult, i, aux;
 for (ult = tam-1; ult>0; ult--)
 {
    for (i=0; i<ult; i++)
    {
        if (v[i] > v[i+1]) 
        {
            aux = v[i];
            v[i] = v[i+1];
            v[i+1] = aux;
        }
    }
 }
}

int main() {
  int i;
  int v[] = {55, 0, -78, -4, 32, 200, 52, 63, 69, 125, 99, 87, 2, -2, 990, 319813, 223545, 999, 545346, 76666, 1213123, 2331554, 11441, 12131454, 231321314, 21231321, 65421231, 5435131, 53131, 5321213, 451321314, 5135151, 848454, 845646468, 476468486, 7415151, 845151345, 4};
  
  size_t size = sizeof(v) / sizeof(v[0]);
  
  bubbleSort(v,size);
  for (i=0; i < size;i++) printf("%i ",v[i]);
  printf("\n");
  return 0;
}
