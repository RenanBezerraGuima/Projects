#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct estrutura{
    int chave;
    struct estrutura* esq;
    struct estrutura* dir;
}NO;

typedef struct estruct{
    int chave;
    struct estruct* prox;
}NOL;

typedef struct{
    NOL* inicio;
    NOL* fim;
}FILA;

//Arvore binária de Busca (Ordenada, esquera é menor que o atual e direita maior)
NO* buscaABB(NO*p, int ch, NO**pai){
    *pai = NULL;
    while(p){
        if(p->chave == ch) return p;
        *pai = p;
        if(p->chave > ch) p = p->esq;
        else p = p->dir;
    }
    return p;
}

bool inserirABB(NO** raiz, int ch){
    NO* pai;
    NO* p = buscaABB(*raiz, ch, &pai);
    if(p) return false;

    NO* novo = (NO*) malloc(sizeof(NO));
    novo->chave = ch;
    novo->esq = NULL;
    novo->dir = NULL;

    if(!pai){
        *raiz = novo;
        return true;
    }

    if(novo->chave < pai->chave) pai->esq = novo;
    else pai->dir = novo;
    return true;
}

//Inicializar resp na main
void contador(NO* p, int* resp){
    if(p){
        *resp = *resp + 1;
        contador(p->esq, resp);
        contador(p->dir, resp);
    }
}

int max(int a, int b){
    if (a > b) return a;
    else return b;
}

//Altura da arvore
int altura(NO*p){
    if(!p) return 0;
    if(!p->esq && !p->dir) return 1;//Desnessario, mas mas eficiente
    return(1 + max(altura(p->esq), altura(p->dir)));
}

//Busca geral
void busca(NO* p, NO** resp, int ch){
    if(p){
        if (p->chave == ch) *resp = p;
        if(*resp == NULL) busca(p->esq, resp, ch);
        if(*resp == NULL) busca(p->dir, resp, ch);
    }
}

//Seja uma arvore com chaves repitidas, sem ordem, contar as ocorrências de ch, com limite de 50 elementos.
void contarRepetidas(NO* p, int* qtd, int ch){
    if (p && *qtd < 50)
    {
        if (p->chave == ch) *qtd++;
        contarRepetidas(p->esq, qtd, ch);
        contarRepetidas(p->dir, qtd, ch);
    }
}

void exibir(NO* p){
    if(!p) return;
    exibir(p->esq);
    printf("%i ", p->chave);
    exibir(p->dir);
}

void listarOrdenado(NO* p, NOL** l){
    if(p){
        listarOrdenado(p->dir, l);

        NOL* novo = (NOL*) malloc(sizeof(NOL));
        novo->chave = p->chave;
        if (!l) novo->prox = NULL;
        else novo->prox = *l;
        *l = novo;

        listarOrdenado(p->esq, l);
    }
}

//inicializar o pai como NULL
NO* buscaABBRecursiva(NO*p, int ch, NO**pai){
   if (!p) return NULL;
   if (p->chave == ch) return p;
   //Atualiza o pai
   *pai = p;
   
   if (ch > p->chave) return buscaABBRecursiva(p->dir, ch, pai);
   else return buscaABBRecursiva(p->esq, ch, pai);
}

void excluirABB(NO* p, NO* pai){
    if (!p) return;
    if (!pai)
    {
        free (p);
        p = NULL;
        return;
    }

    
}

void inicializarFila(FILA* f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void entrarFila(int ch, FILA* f) {
    NOL* novo;
    novo = (NOL*) malloc(sizeof(NOL));
    novo->chave = ch;
    novo->prox = NULL;
    if(f->fim) f->fim->prox = novo;
    else f->inicio = novo; 
    f->fim = novo;
}

int sairFila(FILA* f)
{
    NOL* aux;
    int ch;
    if(!f->inicio) return(-1);
    ch = f->inicio->chave;
    aux = f->inicio;
    f->inicio = f->inicio->prox;
    free(aux);
    if(!f->inicio) f->fim = NULL; // fila ficou vazia
    return(ch);
}

int height(NO* node)
{
    if (node == NULL)
        return 0;
    else {
         
        // Compute the height of each subtree
        int lheight = height(node->esq);
        int rheight = height(node->dir);
 
        // Use the larger one
        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
}

void printLevelOrder(NO* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
// Print nodes at a current level
void printCurrentLevel(NO* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->chave);
    else if (level > 1) {
        printCurrentLevel(root->esq, level - 1);
        printCurrentLevel(root->dir, level - 1);
    }
    printf("\n");
}

void exibirNivel(NO* raiz) {
    FILA f;
    NO* p = raiz;
    inicializarFila(&f);
    while( (p) || (f.inicio) ) {
        if(p->esq) entrarFila(p->esq->chave, &f);
        if(p->dir) entrarFila(p->dir->chave, &f);
        printf("%d", p->chave);
        p = NULL;
        if(f.inicio) p->chave = sairFila(&f);
    }
}

int main (){
    NO* raiz = NULL;
    int input;
    int temp;
    

    do
    {
        printf("\nPrograma de Arvore Binária de Busca\n\n");
        printf("\t(-1) - Encerrar o programa\n");
        printf("\t( 1) - Inserir elemento na arvore\n");
        printf("\t( 2) - Excluir elemento na arvore\n");
        printf("\t( 3) - Destruir a arvore\n");
        printf("\t( 4) - Mostar altura da arvore\n");
        printf("\t( 5) - Contar elementos da arvore\n");
        scanf("%i", &input);
        switch (input)
        {
        case 1:
            printf("Insira a chave do elemento: ");
            scanf("%i", &temp);
            inserirABB(&raiz, temp);
            break;
        
        default:
            if (input != -1)
            {
                printf("Comando ( %i) inválido\n", input);
                return -1;
            }
            break;
        }
        printLevelOrder(raiz);
    } while (input != -1);

    return 0;
}