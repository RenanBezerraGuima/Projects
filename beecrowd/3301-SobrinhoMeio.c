#include <stdio.h>

int main ()
{
    int idadeH,idadeZ,idadeL;
    scanf("%i %i %i", &idadeH, &idadeZ, &idadeL);

    if ((idadeH < idadeZ && idadeH > idadeL) || (idadeH > idadeZ && idadeH < idadeL))
    {
        printf("huguinho\n");
    }
    else if ((idadeZ < idadeH && idadeZ > idadeL) || (idadeZ > idadeH && idadeZ < idadeL))
    {
        printf("zezinho\n");
    }
    else if ((idadeL < idadeZ && idadeL > idadeH) || (idadeL > idadeZ && idadeL < idadeH))
    {
        printf("luisinho\n");
    }
    
    return 0;
}