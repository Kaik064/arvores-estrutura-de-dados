#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "funcao.h"

int main(){
    No* raiz = NULL;
    int chave;
    char nome[TAM];
    int opcao;

    do{
        printf("--- MENU ---\n");
        printf("1- Inserir No\n");
        printf("2- procurar No\n");
        printf("3- Menor chave\n");
        printf("4- Maior chave\n");
        printf("5- Remover No\n");
        printf("0 para sair\n");
        printf("Opcao: ");
        while(scanf("%d",&opcao) != 1 || opcao < 0 || opcao > 5){
            printf("Opcao invalida! tente novamente: ");
            while(getchar() != '\n');
        }

        switch (opcao){
            case 1:
                printf("Digite a chave e o nome que deseja inserir: ");
                scanf("%d %s",&chave, nome);
                printf("Inserindo valor na arvore....\n");
    
                if(inserir(&raiz,chave,nome)){
                    printf("Valor inserido com sucesso\n");
                }
                else{
                    printf("O valor ja esta na arvore\n");
                }
                printf("\n");
                break;
            
            case 2:
                printf("Digite a chave que deseja buscar: ");
                scanf("%d",&chave);
                busca(raiz,chave);
                printf("\n\n");
                break;
            
            case 3: 
                if(raiz == NULL){
                    printf("Arvore esta vazia!\n");
                }else{
                    printf("Menor No: %d",retornaMenorChave(raiz));
                }
                printf("\n\n");
                break;
            
            case 4: 
                if(raiz == NULL){
                    printf("Arvore esta vazia!\n");
                }else{
                    printf("Maior No: %d",retornaMaiorChave(raiz));
                }
                printf("\n\n");
                break;

            case 5: 
                printf("Digite a chave que deseja remover: ");
                scanf("%d",&chave);

                if(removerNo(&raiz, chave)){
                    printf("Chave removida.\n");
                }
                else{
                    printf("Chave nao encontrada.\n");
                }
                printf("\n\n");
                break;

                case 0: printf("Encerrando....\n"); break;
                
        }
    }while(opcao != 0);
    return 0;
}