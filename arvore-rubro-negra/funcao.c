#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcao.h"

bool is_red(No* no){
    if(no == NULL){
        return false;
    }
    return no->cor == VERMELHO;
}

void inverterCores(No* raiz){
    raiz->cor == VERMELHO;
    raiz->dir->cor = PRETO;
    raiz->esq->cor = PRETO;
}

void rotacaoEsquerda(No** raiz){
    No* filho = (*raiz)->dir;
    (*raiz)->dir = filho->esq;
    filho->esq = *raiz;
    (*raiz)->cor = VERMELHO;
    *raiz = filho;
}

void rotacaoDireita(No** raiz){
    No* filho = (*raiz)->esq;
    (*raiz)->esq = filho->dir;
    filho->dir = *raiz;
    (*raiz)->cor = VERMELHO;
    *raiz = filho;
}

bool inserirRecursivo(No** raiz, int valor){
    if(*raiz == NULL){
        *raiz = malloc(sizeof(No));
        (*raiz)->chave = valor;
        (*raiz)->cor = VERMELHO;
        (*raiz)->esq = (*raiz)->dir = NULL;
        return true;
    }
    
    bool inseriu = false;
    if(valor < (*raiz)->chave){
        inseriu = inserirRecursivo(&((*raiz)->esq),valor);
    }
    else if(valor > (*raiz)->chave){
        inseriu = inserirRecursivo(&((*raiz)->dir),valor);
    }
    else{
        return false;
    }

    if(is_red((*raiz)->dir) && !is_red((*raiz)->esq)){
        rotacaoEsquerda(raiz);
    }
    
    if(is_red((*raiz)->esq) && is_red((*raiz)->esq->esq)){
        rotacaoDireita(raiz);
    }

    if(is_red((*raiz)->esq) && is_red((*raiz)->dir)){
        inverterCores(*raiz);
    }
    return inseriu;
}

bool inserir(No** raiz, int valor){
    if(inserirRecursivo(raiz,valor)){
        (*raiz)->cor = PRETO;
        return true;
    }
    return false;
}

void preOrdem(No* raiz){
    if(raiz == NULL){
        return;
    }

    printf("%d - %s\n",raiz->chave, raiz->cor == PRETO ? "preto" : "vermelho");
    preOrdem(raiz->esq);
    preOrdem(raiz->dir);
}

void emOrdem(No* raiz){
    if(raiz == NULL){
        return;
    }

    emOrdem(raiz->esq);
    printf("%d - %s\n",raiz->chave, raiz->cor == PRETO ? "preto" : "vermelho");
    emOrdem(raiz->dir);
}

void posOrdem(No* raiz){
    if(raiz == NULL){
        return;
    }

    posOrdem(raiz->esq);
    posOrdem(raiz->dir);
    printf("%d - %s\n",raiz->chave, raiz->cor == PRETO ? "preto" : "vermelho");
}

void paresPretos(No* raiz){
    if(raiz == NULL){
        return;
    }

    if(raiz->chave % 2 == 0 && raiz->cor == PRETO){
        printf("%d ",raiz->chave);
    }
    paresPretos(raiz->esq);
    paresPretos(raiz->dir);
}

int qtdImparesVermelhos(No* raiz){
    if(raiz == NULL){
        return 0;
    }
    int cont = 0;
    if(raiz->chave % 2 != 0 && raiz->cor == VERMELHO){
        cont++;
    }
    
    return cont + qtdImparesVermelhos(raiz->esq) + qtdImparesVermelhos(raiz->dir);
}