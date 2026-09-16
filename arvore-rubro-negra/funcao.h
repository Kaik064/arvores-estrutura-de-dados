#ifndef FUNCAO_H
#include <stdbool.h>
#define VERMELHO 1
#define PRETO 0
typedef struct no No;
struct no{
    int cor;
    int chave;
    No* esq, *dir;
};

bool is_red(No* no);
void inverterCores(No* raiz);
void rotacaoEsquerda(No** raiz);
void rotacaoDireita(No** raiz);
bool inserirRecursivo(No** raiz, int valor);
bool inserir(No** raiz, int valor);
void preOrdem(No* raiz);
void emOrdem(No* raiz);
void posOrdem(No* raiz);
void paresPretos(No* raiz);
int qtdImparesVermelhos(No* raiz);

#endif