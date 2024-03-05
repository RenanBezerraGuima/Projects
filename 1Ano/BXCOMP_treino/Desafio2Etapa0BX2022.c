#include <stdio.h>
#include <string.h>

int main () {
   int numTest, qtdEntrega, proporcao;
   char entrega[20];

   scanf("%i", &numTest);

   for (int i = 0; i < numTest; i++)
   {
    scanf("%s %i",entrega, &qtdEntrega);
    if (!strcmp(entrega,"vinho")) 
    {
        proporcao = qtdEntrega/1000;
        printf("%i %i %i %i\n", qtdEntrega, 45*proporcao, 240*proporcao, 500*proporcao);
    }
    else if (!strcmp(entrega,"limao"))
    {
        proporcao = qtdEntrega/45;
        printf("%i %i %i %i\n", 1000*proporcao, qtdEntrega, 240*proporcao, 500*proporcao);
    }
    else if (!strcmp(entrega,"laranja"))
    {
        proporcao = qtdEntrega/240;
        printf("%i %i %i %i\n", 1000*proporcao, 45*proporcao, qtdEntrega, 500*proporcao);
    }
    else if (!strcmp(entrega,"agua"))
    {
        proporcao = qtdEntrega/500;
        printf("%i %i %i %i\n", 1000*proporcao, 45*proporcao, 240*proporcao, qtdEntrega);
    }
   }
    return 0;
}