#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define COUNT 10


typedef struct estrutura{
    int chave;
    struct estrutura* esq;
    struct estrutura* dir;
}NO;

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


void exibir(NO* p){
    if(!p) return;
    exibir(p->esq);
    printf("%i ", p->chave);
    exibir(p->dir);
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

void percursoNivel(NO* raiz) {
    if (raiz == NULL) 
    {
        return;
    }

    // Criação de uma fila para armazenar os nós
    NO* fila[100];
    int inicio = 0;
    int fim = 0;
    int nivelAtual = 1;
    int proximoNivel = 0;

    // Enfileira o nó raiz
    fila[fim++] = raiz;

    while (inicio < fim) {
        // Desenfileira o nó atual e imprime seu valor
        NO* atual = fila[inicio++];
        printf("%d ", atual->chave);
        nivelAtual--;

        // Enfileira os nós filhos, se existirem
        if (atual->esq != NULL) {
            fila[fim++] = atual->esq;
            proximoNivel++;
        }
        if (atual->dir != NULL) {
            fila[fim++] = atual->dir;
            proximoNivel++;
        }

        if (nivelAtual == 0) {
            printf("\n");
            nivelAtual = proximoNivel;
            proximoNivel = 0;
        }
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
        printf("\t( 6) - Exibir arvore Avançado\n");
        printf("\t( 7) - Exibir arvore em nivel Simples\n");
        scanf("%i", &input);
        switch (input)
        {
        case 1:
            printf("Insira a chave do elemento: ");
            scanf("%i", &temp);
            inserirABB(&raiz, temp);
            break;
        
        case 2:
            printf("Insira a chave do elemento: ");
            scanf("%i", &temp);
            NO* pai;
            NO* p = buscaABB(raiz, temp, &pai);
            if (p) excluirABB(p, pai);
            else printf("Elemento não encontrado\n");
            break;

        case 3:
            printf("Insira a chave do elemento: ");
            scanf("%i", &temp);
            NO* paitemp = NULL;
            paitemp = buscaABBRecursiva(raiz, temp, &pai);
            if (paitemp) excluirABB(paitemp, pai);
            else printf("Não existe essa chave\n");
            break;
            
        case 6:
            print2D(raiz);
            break;

        case 7:
            printf("\n");
            percursoNivel(raiz);
            break;

        default:
            if (input != -1)
            {
                printf("Comando ( %i) inválido\n", input);
                return -1;
            }
            break;
        }
        
    } while (input != -1);

    return 0;
}