#include <stdio.h>
#include <stdbool.h> 

#define MAX 10

typedef struct {
    int chave;
} registro;

typedef struct {
    registro a[MAX];
    int numElementos;
} listaSeq;

void inicializa(listaSeq* l){
    l->numElementos = 0;
}

void exibir(listaSeq* l){
    for (int i = 0; i < l->numElementos; i++)
    {
        printf("%i ", l->a[i].chave);
    }
    printf("\n");
}

bool anexar(listaSeq* l, int ch){
    if (l->numElementos == MAX) return false; //lista cheia

    l->a[l->numElementos].chave = ch;
    l->numElementos++;
    return true;
}

// A função abaixo recebe uma lista l e um inteiro ch que será buscado e
// retorna o indice se for achado, se não for encontrado retorna -1
int buscaSeq(listaSeq* l, int ch){
    for (int i = 0; i < l->numElementos; i++){
        if (l->a[i].chave == ch) return i;
    }
    return -1;//Não encontrou
}

// A função abaixo recebe uma lista l e o inteiro ch que deseja excluir da lista
// ela retorna true se ocorreu corretamente e false se ch não está na lista
bool excluir(listaSeq* l, int ch){
    int atual = buscaSeq(l,ch);
    if (atual == -1) return false;
    for (int i = atual; i < l->numElementos-1; i++){
        l->a[i] = l->a[i+1];
    }
    l->numElementos--;
    return true;
}

//Tudo da int main é para teste
int main () {
listaSeq lista;
inicializa(&lista);

for (int i = 0; i < 10; i++) {
 anexar(&lista, i+1); 
}

exibir(&lista);
printf("A lista tem %i elementos\n", lista.numElementos);

if(buscaSeq(&lista, 15) == -1) printf("Nao tem\n");
else printf("A posicao eh %i\n", buscaSeq(&lista, 7));

excluir(&lista, 4);

exibir(&lista);
printf("A lista tem %i elementos\n", lista.numElementos);

return 0;
}