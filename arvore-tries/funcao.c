#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "funcao.h"

No* criarNo(){
    No* novo = malloc(sizeof(No));
    if(novo == NULL){
        return NULL;
    }
    for(int i = 0; i < TAM; i++){
        novo->filhos[i] = NULL;
    }
    novo->fimDePalavra = false;

    return novo;
}

bool inserir(No* raiz, const char* palavra){
    if(raiz == NULL){
        return false;
    }
    No* atual = raiz;
    for(int i = 0; palavra[i] != '\0'; i++){
        int indice = palavra[i] - 'a';
        if(atual->filhos[indice] == NULL){
            atual->filhos[indice] = criarNo();
        }
        atual = atual->filhos[indice];
    }

    if(atual->fimDePalavra){
        return false;
    }

    atual->fimDePalavra = true;
    return true;
}

void converterParaMinusculo(char* palavra){
    for(int i = 0; palavra[i] != '\0'; i++){
        palavra[i] = tolower(palavra[i]);
    }
}

bool ePalavraValida(char* palavra){
    for(int i = 0; palavra[i] != '\0'; i++){
        if(!isalpha(palavra[i])){
            return false;
        }
    }
    return true;
}

bool Buscar(No* raiz, const char* palavra){
    if(raiz == NULL){
        return false;
    }
    No* atual = raiz;

    for(int i = 0; palavra[i] != '\0'; i++){
        int indice = palavra[i] - 'a';

        if(atual->filhos[indice] == NULL){
            return false;
        }
        atual = atual->filhos[indice];
    }

    return atual != NULL && atual->fimDePalavra;
}

bool temFilhos(No* raiz){
    for(int i = 0; i < TAM; i++){
        if(raiz->filhos[i] != NULL){
            return true;
        }
    }
    return false;
}

bool removerRecursivo(No* raiz, const char* palavra, int profundidade){
    if(raiz == NULL){
        return false;
    }
    if(palavra[profundidade] == '\0'){
        if(raiz->fimDePalavra){
            raiz->fimDePalavra = false;
            return !temFilhos(raiz);
        }
        return false;
    }

    int indice = palavra[profundidade] - 'a';

    if(removerRecursivo(raiz->filhos[indice], palavra, profundidade + 1)){
        free(raiz->filhos[indice]);
        raiz->filhos[indice] = NULL;
        return !raiz->fimDePalavra && !temFilhos(raiz);
    }
    return false;
}

bool remover(No* raiz, const char* palavra){
    if(!Buscar(raiz, palavra)){
        return false;
    }
    removerRecursivo(raiz,palavra, 0);
    return true;
}