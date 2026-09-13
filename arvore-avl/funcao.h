#ifndef FUNCAO_H
#include <stdbool.h>
#define TAM 50
typedef struct no No;
struct no{
    int chave, fb, altura;
    char nome[TAM];
    No* esq, *dir;
};

No* criarNo(int chave, const char* nome);
int altura(No* raiz);
void atualizarAltura(No* raiz);
int fatorBalanco(No* raiz);
No* rotacaoDireita(No* raiz);
No* rotacaoEsquerda(No* raiz);
void balancear(No** raiz);
bool inserirNo(No** raiz, int chave, const char* nome);
const char* procurarNo(No* raiz, int chave);
void Busca(No* raiz, int chave);
int menorChave(No* raiz);
int maiorChave(No* raiz);
No* menorNo(No* raiz);
bool removerNo(No** raiz, int chave);

#endif