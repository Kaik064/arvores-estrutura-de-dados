#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "funcao.h"

int main(){
    No* raiz = criarNo();
    char palavra[TAM];
    int opcao;

    do{
        printf("--- MENU ---\n");
        printf("1- Inserir No\n");
        printf("2- Buscar palavra\n");
        printf("3- Remover No\n");
        printf("0 para sair\n");
        printf("Opcao: ");
        while(scanf("%d",&opcao) != 1 || opcao < 0 || opcao > 3){
            printf("Opcao invalida! tente novamente: ");
            while(getchar() != '\n');
        }

        switch (opcao){
            case 1:
                printf("Digite a palavra que deseja inserir: ");
                while(scanf("%s",palavra) != 1 || !ePalavraValida(palavra)){
                    printf("A palavra possui um caracter invalido, tente novamente: ");
                    while(getchar() != '\n');
                }
                printf("Inserindo palavra na arvore....\n");
                converterParaMinusculo(palavra);
                if(inserir(raiz,palavra)){
                    printf("Palavra inserida com sucesso\n");
                }
                else{
                    printf("A Palavra ja esta na arvore\n");
                }
                printf("\n");
                break;
            
            case 2:
                printf("Digite a palavra que deseja Buscar: ");
                while(scanf("%s",palavra) != 1 || !ePalavraValida(palavra)){
                    printf("A palavra possui um caracter invalido, tente novamente: ");
                    while(getchar() != '\n');
                }
                converterParaMinusculo(palavra);
                if(Buscar(raiz,palavra)){
                    printf("A palavra esta na arvore.");
                }
                else{
                    printf("Palavra inexistente.");
                }
                printf("\n\n");
                break;
            
            case 3: 
                printf("Digite a palavra que deseja remover: ");
                while(scanf("%s",palavra) != 1 || !ePalavraValida(palavra)){
                    printf("A palavra possui um caracter invalido, tente novamente: ");
                    while(getchar() != '\n');
                }
                converterParaMinusculo(palavra);
                if(remover(raiz,palavra)){
                     printf("Palavra removida.");
                }
                else{
                    printf("Nao foi possivel remover a palavra");
                }
                
                printf("\n\n");
                break;

            case 0: printf("Encerrando....\n"); break;
        }
    }while(opcao != 0);
    return 0;
}