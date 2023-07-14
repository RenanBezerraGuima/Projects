#include <stdio.h>

void bubbleSort(int arr[], int tam)
{
  int ult,i,aux;

  for(ult =tam-1; ult>0; ult--)
  {
    for (i=0;i<ult;i++)
    {
      if(arr[i] > arr[i+1])
      {
        aux = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = aux;
      }
    }
  }
}

int main ()
{
    int arranjo[] = {55,0,-78,-4,32,200,52,63,69,125};
    bubbleSort(arranjo,10);

    for(int i=0;i<10;i++) printf("%i ", arranjo[i]);
    printf("\n");
    return 0;
}