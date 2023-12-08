#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
    Programa iterativo para visualizar como a fila funciona e sua estrutura básica,
    podendo adicionar elementos ao fim da fila e excluir elementos do inicio da fila.

    Sempre após cada operção mostrando a fila atualizada.
*/

typedef struct estrutura{
    int chave;
    struct estrutura* prox;
}NO;

typedef struct{
    NO* inicio;
    NO* fim;
}FILA;

void inicializarFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

//Sempre entra no fim da fila e se torna o novo fim
void entrarFila(int ch, FILA* f) {
    NO* novo;
    novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->prox = NULL;
    if(f->fim) f->fim->prox = novo;//Caso haja um fim
    else f->inicio = novo; //Caso seja uma lista vazia
    f->fim = novo;
}

//Sempre sai do inicio da fila e se torna o novo inicio
int sairFila(FILA* f){
    NO* aux;
    int ch;
    if(!f->inicio) return(-1);//Lista vazia
    ch = f->inicio->chave;
    aux = f->inicio;
    f->inicio = f->inicio->prox;//Passa o inicio para o proximo elemento
    free(aux);
    if(!f->inicio) f->fim = NULL; // fila ficou vazia, pq so tinha 1 elemento
    return(ch);
}

int main (){
    FILA f;
    inicializarFila(&f);

    int input;
    int temp;
    do
    {
        printf("\nPrograma de Fila\n\n");
        printf("\t(-1) - Encerrar o programa\n");
        printf("\t( 1) - Inserir elemento na fila\n");
        printf("\t( 2) - Excluir elemento na fila\n");
        scanf("%i", &input);
        switch (input)
        {
        case 1:
            printf("Insira a chave do elemento: ");
            scanf("%i", &temp);
            entrarFila(temp, &f);
            break;
        
        case 2:
            temp = sairFila(&f);
            if (temp) printf("Primeiro elemento excluido e sua chave: %i\n", temp);
            else printf("Fila vazia\n");
            break;

        default:
            if (input != -1)
            {
                printf("Comando ( %i) inválido\n", input);
                return -1;
            }
            break;
        }

        printf("Fila: \n");
        printf("Inicio-> ");
        NO* p = f.inicio;
        if (!p) printf("NULL");
        while (p)
        {
            printf("%i", p->chave);
            if(p->prox) printf(" -> ");
            p = p->prox;
        }
        printf(" <-Fim\n");
    } while (input != -1);
    
    return 0;
}