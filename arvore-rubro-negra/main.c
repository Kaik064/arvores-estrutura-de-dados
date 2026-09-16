#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcao.h"

int main(){
    No* raiz = NULL;
    int chave;
    int opcao;

    do{
        printf("--- MENU ---\n");
        printf("1- Inserir No\n");
        printf("2- pre Ordem\n");
        printf("3- Em Ordem\n");
        printf("4- Pos Ordem\n");
        printf("5- Pares pretos\n");
        printf("6- Impares vermelhos\n");
        printf("0 para sair\n");
        printf("Opcao: ");
        while(scanf("%d",&opcao) != 1 || opcao < 0 || opcao > 6){
            printf("Opcao invalida! tente novamente: ");
            while(getchar() != '\n');
        }

        switch (opcao){
            case 1:
                printf("Digite a chave que deseja inserir: ");
                scanf("%d",&chave);
                printf("Inserindo valor na arvore....\n");
    
                if(inserir(&raiz,chave)){
                    printf("Valor inserido com sucesso\n");
                }
                else{
                    printf("O valor ja esta na arvore\n");
                }
                printf("\n");
                break;
            
            case 2:
                if(raiz == NULL){
                    printf("Arvore vazia.\n");
                }
                else{
                    printf("\n--- PRE ORDEM ---\n");
                    preOrdem(raiz);
                }
                printf("\n\n");
                break;
            
            case 3: 
                if(raiz == NULL){
                    printf("Arvore vazia.\n");
                }
                else{
                    printf("\n--- EM ORDEM ---\n");
                    emOrdem(raiz);
                }
                printf("\n\n");
                break;
            
            case 4: 
                if(raiz == NULL){
                    printf("Arvore vazia.\n");
                }
                else{
                    printf("\n--- POS ORDEM ---\n");
                    posOrdem(raiz);
                }
                printf("\n\n");
                break;

            case 5: 
                printf("--- Chave com cor preta e par ---\n");
                paresPretos(raiz);
                printf("\n\n");
                break;
            
            case 6:
                printf("Quantidade de chaves impares na cor vermelha: %d\n",qtdImparesVermelhos(raiz));
                printf("\n\n");
                break;

                case 0: printf("Encerrando....\n"); break;
        }
    }while(opcao != 0);
    return 0;
}