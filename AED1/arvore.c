#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define COUNT 10

typedef struct estrutura{
    int chave;
    struct estrutura* esq;
    struct estrutura* dir;
}NO;

typedef struct estruturaLista{
    int chave;
    struct estruturaLista* prox;
}NOL;

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
        if (p->chave == ch) *qtd = *qtd + 1;
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

NO* maior(NO* p, NO** pai)
{
    NO* resp = p;
    while (resp->dir)
    {
        *pai = resp; 
        resp = resp->dir;
    }
    return resp;
}

void excluirABB(NO* p, NO* pai){
    if (!p) return;//Não tem nó

    if (!p->esq)//Caso 1 e 2
    {
        if(pai->esq == p) pai->esq = p->dir;
        else pai->dir = p->dir;
    }

    else if (p->esq && p->dir)//Caso 3
    {
    NO* paiTemp = p;
        NO* temp = maior(p->esq, &paiTemp);
        p->chave = temp->chave;
        excluirABB(temp, paiTemp);
    }
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

void printLevelOrder(NO* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
bool verificaABB(NO* p){
    if (p)
    {
        if(p->esq && p->esq->chave > p->chave) return false;
        if(p->dir && p->dir->chave < p->chave) return false;
        if(!verificaABB(p->esq)) return false;
        if(!verificaABB(p->dir)) return false;
    }
    return true;
}

bool verificaAssimetria(NO* p){
    if (p)
    {
        if(p->esq && p->dir) return false;
        if(!verificaAssimetria(p->esq)) return false;
        if(!verificaAssimetria(p->dir)) return false;
    }
    return true;

}

bool verificaCheia(NO* p){
    if (p)
    {
        if((p->esq && !p->dir) || (!p->esq && p->dir)) return false;
        if(!verificaCheia(p->esq)) return false;
        if(!verificaCheia(p->dir)) return false;
    }
    return true;
}

// Dá pra melhorar
void listarMaiores(NO* p, int ch, NOL** l){
    if(p){
        if(p->chave > ch){
            NOL* novo = (NOL*) malloc(sizeof(NOL));
            novo->chave = p->chave;
            if (!l) novo->prox = NULL;
            else novo->prox = *l;
            *l = novo;
        }
        listarMaiores(p->dir, ch, l);
        listarMaiores(p->esq, ch, l);
    }
}

void antecessorOrdemABB(NO* p, int ch, int* resp){
   if (p)
   {
    if (p->chave < ch && p->chave > *resp) *resp = p->chave;
    
    if (ch > p->chave) antecessorOrdemABB(p->dir, ch, resp);//Se ch for maior procura na direita
    else antecessorOrdemABB(p->esq, ch, resp);//Se ch for menor ou igual ao atual procura na esquerda
   }
}

// EmOrdem inversa (direita - raiz - esquerda)
void print2DUtil(NO* root, int space)
{
    // Caso base
    if (root == NULL)
        return;
 
    // Aumenta a distancia entre niveis
    space += COUNT;
 
    // Começa pela direita
    print2DUtil(root->dir, space);
 
    // Print na raiz atual
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->chave);
 
    // Esquera da arvore
    print2DUtil(root->esq, space);
}
 
// Função para o usuario
void print2D(NO* root)
{
    printf("--------------------\n");
    // Passa o contador inicial como 0
    print2DUtil(root, 0);
}

//Essa função está com problema
void encontrarPaiComumInterno(NO* p, int ch, NO** pai, int* achou){
    if (*achou == 1) return;
    if(p)
    {
     if (p->chave == ch) 
     {
        *achou = 1;
        return;
     }
     else (*pai) = p;
     encontrarPaiComumInterno(p->esq, ch, pai, achou);
     encontrarPaiComumInterno(p->dir, ch, pai, achou);
    }
}

//resposta inicializada como NULL
NO* encontrarPaiComum(NO* raiz, int ch){
    NO* pai = NULL;
    int achou = 0;
    encontrarPaiComumInterno(raiz, ch, &pai, &achou);
    return pai;
}

int main (){
    NO* raiz = NULL;
    NO* pai = NULL;
    int temp;

    inserirABB(&raiz, 11);
    inserirABB(&raiz, 10);
    inserirABB(&raiz, 20);
    inserirABB(&raiz, 15);
    inserirABB(&raiz, 12);
    inserirABB(&raiz, 5);
    inserirABB(&raiz, 6);
    inserirABB(&raiz, 2);
    inserirABB(&raiz, 4);
    inserirABB(&raiz, 3);
    inserirABB(&raiz, 8);
    inserirABB(&raiz, 9);
    inserirABB(&raiz, 7);

    print2D(raiz);
    
    // if(verificaABB(raiz)) printf("É ABB\n");
    // else printf("Não é ABB\n");

    // if(verificaAssimetria(raiz)) printf("É assimetrica\n");
    // else printf("Não é assimetrica\n");

    // if(verificaCheia(raiz)) printf("É cheia\n");
    // else printf("Não é cheia\n");

    // int resp = INT_MIN;
    // printf("Antecessor de: ");
    // scanf("%i", &temp);
    // antecessorOrdemABB(raiz, temp, &resp);
    // printf("eh %i\n", resp);

    // NOL* l = NULL;
    // printf("Listando os maiores de ");
    // scanf("%i", &temp);
    // printf(" inicio");
    // listarMaiores(raiz, temp, &l);
    // NOL* p = l;
    // while(p){
    //     printf("-> %i", p->chave);
    //     p = p->prox;
    // }
    // printf("-> NULL\n");

    // printf("Encontrando o pai de: ");
    // scanf("%i", &temp);
    // pai = encontrarPaiComum(raiz, temp);
    // if (pai) printf("Pai eh %i", pai->chave);
    // else printf("Eh a raiz\n");

    NOL* lista = NULL;
    listarOrdenado(raiz, &lista);
    NOL* ponteiro = lista;
    while(ponteiro){
        printf("-> %i", ponteiro->chave);
        ponteiro = ponteiro->prox;
    }

    return 0;
}