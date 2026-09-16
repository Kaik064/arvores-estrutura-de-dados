#ifndef FUNCAO_H
#include <stdbool.h>
#define TAM 26
typedef struct no No;
struct no{
    No* filhos[TAM];
    bool fimDePalavra;
};

No* criarNo();
bool inserir(No* raiz, const char* palavra);
void converterParaMinusculo(char* palavra);
bool ePalavraValida(char* palavra);
bool Buscar(No* raiz, const char* palavra);
bool temFilhos(No* raiz);
bool removerRecursivo(No* raiz, const char* palavra, int profundidade);
bool remover(No* raiz, const char* palavra); 



#endif