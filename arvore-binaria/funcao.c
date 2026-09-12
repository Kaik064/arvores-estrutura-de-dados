#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funcao.h"


No* criarNo(int valor, const char* nome){
    No* novoNo = malloc(sizeof(No));
    if(novoNo == NULL) return NULL;

    novoNo->chave = valor;
    strncpy(novoNo->nome, nome, TAM - 1);
    novoNo->nome[TAM - 1] = '\0';
    novoNo->dir = NULL;
    novoNo->esq = NULL;

    return novoNo;
}

bool inserir(No** raiz, int valor, const char* nome){
    if(*raiz == NULL){
        *raiz = criarNo(valor,nome);
        return true;
    }

    if(valor < (*raiz)->chave){
        return inserir(&((*raiz)->esq),valor,nome);
    }
    else if(valor > (*raiz)->chave){
        return inserir(&((*raiz)->dir),valor,nome);
    }
    else{
        return false;
    }
    return true;
}

const char* buscarNo(No* raiz, int valor){
    if(raiz == NULL) return NULL;
    
    if(raiz->chave == valor){
        return raiz->nome;
    }

    if(valor < raiz->chave){
        return buscarNo(raiz->esq, valor);
    }
    return buscarNo(raiz->dir,valor);
}

void busca(No* raiz, int valor){
    const char* buscador = buscarNo(raiz,valor);

    if(buscador == NULL){
        printf("Chave nao encontrada **NULL**");
    }
    else{
        printf("Chave encontrada: %s\n",buscador);
    }
}

int retornaMenorChave(No* raiz){
    if(raiz == NULL) return -1;
    No* menor = raiz;

    while(menor && menor->esq != NULL){
        menor = menor->esq;
    }
    return menor->chave;
}

int retornaMaiorChave(No* raiz){
    if(raiz == NULL) return -1;
    
    No* maior = raiz;

    while(maior && maior->dir != NULL){
        maior = maior->dir;
    }
    return maior->chave;
}

No* encontraMenorNo(No* raiz){
    No* menor = raiz;

    while(menor && menor->esq != NULL){
        menor = menor->esq;
    }
    return menor;
}

bool removerNo(No** raiz, int valor){
    if(*raiz == NULL) return false;

    if(valor < (*raiz)->chave){
        return removerNo(&((*raiz)->esq),valor);
    }
    else if(valor > (*raiz)->chave){
        return removerNo(&((*raiz)->dir),valor);
    }
    else{
        if((*raiz)->esq == NULL){
            No* temp = *raiz;
            *raiz = (*raiz)->dir;
            free(temp);
            return true;
        }
        else if((*raiz)->dir == NULL){
            No* temp = *raiz;
            *raiz = (*raiz)->esq;
            free(temp);
            return true;
        }
        else{
            No* temp = encontraMenorNo((*raiz)->dir);
            
            (*raiz)->chave = temp->chave;

            strncpy((*raiz)->nome, temp->nome, TAM - 1);  
            (*raiz)->nome[TAM - 1] = '\0';
            return removerNo(&((*raiz)->dir), temp->chave);
        }
    }
}