#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "funcao.h"

No* criarNo(int chave, const char* nome){
    No* novo = malloc(sizeof(No));
    if(novo == NULL){
        return NULL;
    }
    novo->chave = chave;
    strncpy(novo->nome,nome,TAM - 1);
    novo->nome[TAM - 1] = '\0';
    novo->altura = 1;
    novo->fb = 0;
    novo->dir = NULL;
    novo->esq = NULL;
    
    return novo;
}

int altura(No* raiz){
    if(raiz == NULL){
        return 0;
    }
    return raiz->altura;
}

void atualizarAltura(No* raiz){
    int esq = altura(raiz->esq);
    int dir = altura(raiz->dir);

    if(esq > dir){
        raiz->altura = esq + 1;
    }
    else{
        raiz->altura = dir + 1;
    }
}

int fatorBalanco(No* raiz){
    if(raiz == NULL){
        return 0;
    }
    return altura(raiz->esq) - altura(raiz->dir);
}

No* rotacaoDireita(No* pai){
    No* filhoesq = pai->esq;
    No* aux = filhoesq->dir;

    filhoesq->dir = pai;
    pai->esq = aux;

    atualizarAltura(pai);
    atualizarAltura(filhoesq);

    pai->fb = fatorBalanco(pai);
    filhoesq->fb = fatorBalanco(filhoesq);

    return filhoesq;
}

No* rotacaoEsquerda(No* pai){
    No* filhodir = pai->dir;
    No* aux = filhodir->esq;

    filhodir->esq = pai;
    pai->dir = aux;

    atualizarAltura(pai);
    atualizarAltura(filhodir);

    pai->fb = fatorBalanco(pai);
    filhodir->fb = fatorBalanco(filhodir);

    return filhodir;
}

void balancear(No** raiz){
    if(*raiz == NULL){
        return;
    }

    int fb = (*raiz)->fb;

    if(fb > 1){
        if(fatorBalanco((*raiz)->esq) >= 0){
            *raiz = rotacaoDireita(*raiz);
        }
        else{
            (*raiz)->esq = rotacaoEsquerda((*raiz)->esq);
            *raiz = rotacaoDireita(*raiz);
        }
    }
    else if(fb < -1){
        if(fatorBalanco((*raiz)->dir) <= 0){
            *raiz = rotacaoEsquerda(*raiz);
        }
        else{
            (*raiz)->dir = rotacaoDireita((*raiz)->dir);
            *raiz = rotacaoEsquerda(*raiz);
        }
    }
}

bool inserirNo(No** raiz, int chave, const char* nome){
    if(*raiz == NULL){
        *raiz = criarNo(chave,nome);
        return true;
    }

    bool inseriu = false;
    if(chave < (*raiz)->chave){
        inseriu = inserirNo(&((*raiz)->esq),chave,nome);
    }
    else if(chave > (*raiz)->chave){
        inseriu = inserirNo(&((*raiz)->dir),chave,nome);
    }
    else{
        return false;
    }
    if(inseriu){
        atualizarAltura(*raiz);
        (*raiz)->fb = fatorBalanco(*raiz);
        balancear(raiz);
    }

    return inseriu;
}

const char* procurarNo(No* raiz, int chave){
    if(raiz == NULL){
        return NULL;
    }

    if(chave == raiz->chave){
        return raiz->nome;
    }

    if(chave < raiz->chave){
        return procurarNo(raiz->esq,chave);
    }

    return procurarNo(raiz->dir,chave);
}

void Busca(No* raiz, int chave){
    const char* Buscador = procurarNo(raiz,chave);

    if(Buscador == NULL){
        printf("Valor nao encontrado **NULL**\n");
    }
    else{
        printf("Chave encontrada: %s\n",Buscador);
    }
}

int menorChave(No* raiz){
    if(raiz == NULL){
        return 0;
    }
    No* menor = raiz;

    while(menor && menor->esq != NULL){
        menor = menor->esq;
    }

    return menor->chave;
}

int maiorChave(No* raiz){
    if(raiz == NULL){
        return 0;
    }
    No* maior = raiz;

    while(maior && maior->dir != NULL){
        maior = maior->dir;
    }
    return maior->chave;
}

No* menorNo(No* raiz){
    if(raiz == NULL){
        return NULL;
    }
    No* menor = raiz;

    while(menor && menor->esq != NULL){
        menor = menor->esq;
    }
    return menor;
}

bool removerNo(No** raiz, int chave){
    if(*raiz == NULL){
        return false;
    }

    bool removeu = false;
    if(chave < (*raiz)->chave){
        removeu = removerNo(&((*raiz)->esq),chave);
    }
    else if(chave > (*raiz)->chave){
        removeu = removerNo(&((*raiz)->dir),chave);
    }
    else{
        if((*raiz)->esq == NULL){
            No* temp = *raiz;
            *raiz = (*raiz)->dir;
            free(temp);
            removeu =  true;
        }
        else if((*raiz)->dir == NULL){
            No* temp = *raiz;
            *raiz = (*raiz)->esq;
            free(temp);
            removeu = true;
        }
        else{
            No* temp = menorNo((*raiz)->dir);
            (*raiz)->chave = temp->chave;
            strncpy((*raiz)->nome, temp->nome, TAM - 1);
            (*raiz)->nome[TAM - 1] = '\0';

            removeu = removerNo(&((*raiz)->dir),temp->chave);
        }
    }

    if(removeu && *raiz != NULL){
        atualizarAltura(*raiz);
        (*raiz)->fb = fatorBalanco(*raiz);
        balancear(raiz);
    }

    return removeu;
}