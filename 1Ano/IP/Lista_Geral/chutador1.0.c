#include <stdio.h>

void main () {
    int chute;

    // Pede para o usuário o seu chute
    printf("Insira o seu chute: \n");
    scanf("%i", &chute);
    
    // Testa o chute do usuário e printa na tela se o chute é muito alto, baixo ou é o valor escolhido
    while ( chute != 555){
    if ( chute > 555) printf("Chute muito alto\n");
    else printf("Chute muito baixo\n");
    printf("Insira o seu chute: \n");
    scanf("%i", &chute);
    }
    printf("Parábens, você acertou !!!! O número era 555\n");
}