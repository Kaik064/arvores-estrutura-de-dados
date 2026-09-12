#ifndef FUNCAO_H
#include <stdbool.h>
#define TAM 50

typedef struct no No;
struct no{
    No* esq, *dir;
    int chave;
    char nome[TAM];
};

No* criarNo(int valor, const char* nome);
bool inserir(No** raiz, int valor, const char* nome);
const char* buscarNo(No* raiz, int valor);
void busca(No* raiz, int valor);
int retornaMenorChave(No* raiz);
int retornaMaiorChave(No* raiz);
No* encontraMenorNo(No* raiz);
bool removerNo(No** raiz, int valor);



#endif