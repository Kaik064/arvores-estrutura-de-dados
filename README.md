# Árvore Binária de Busca (BST) em C 🌳🔍

Este repositório contém a implementação clássica de uma **Árvore Binária de Busca** (Binary Search Tree). Este projeto serve como fundação para o estudo de estruturas de dados não lineares, focando na organização dos nós na memória e na lógica de navegação por ponteiros.

## 🚀 Diferencial Técnico
O código foi estruturado utilizando boas práticas da linguagem C, isolando a lógica de negócio (`funcao.c` e `funcao.h`) da interface com o usuário (`main.c`). A manipulação da raiz é feita de forma segura utilizando **ponteiros duplos (`No**`)**, garantindo que as modificações de memória reflitam corretamente em toda a aplicação.

## ⚙️ Funcionalidades Implementadas
O sistema conta com um menu interativo no terminal que permite:
- **Inserção Recursiva:** Alocação dinâmica de novos nós seguindo a regra da BST (menores à esquerda, maiores à direita).
- **Busca Eficiente:** Algoritmo recursivo para encontrar uma chave e retornar os dados associados.
- **Consultas Estruturais:** Busca direta pela Maior e Menor chave da árvore.
- **Remoção Completa:** Tratamento robusto para os três casos de remoção (nó folha, nó com 1 filho e o caso complexo de nó com 2 filhos).


# Árvore AVL (Auto-balanceada) em C 🌳⚖️

Este repositório contém a implementação de uma **Árvore AVL**, uma estrutura de dados avançada que mantém seu próprio balanceamento para garantir que as operações de busca, inserção e remoção ocorram sempre na complexidade de tempo `O(log n)`. 

## 🚀 Diferencial Técnico
A lógica de balanceamento implementada descarta a checagem manual e excessiva de chaves, utilizando o conceito matemático de **Fator de Balanço (FB)** (a lógica da "gangorra"). 
Através do uso de **ponteiros duplos (`No**`)** e funções modulares, a árvore atualiza recursivamente as alturas e os fatores de balanço a cada inserção ou remoção, acionando rotações simples ou duplas automaticamente. O resultado é um código extremamente enxuto.

## ⚙️ Funcionalidades Implementadas
O sistema possui um menu interativo com as seguintes operações:
- **Inserção Inteligente:** Insere o nó e retrocede atualizando o Fator de Balanço da base até a raiz.
- **Remoção Complexa:** Remove nós e promove substitutos (menor nó da subárvore direita) sem quebrar as propriedades da AVL.
- **Auto-Balanceamento:**
  - Rotação Simples à Direita
  - Rotação Simples à Esquerda
  - Rotações Duplas gerenciadas dinamicamente pela função `balancear()`.
- **Buscas:** Procurar chaves específicas e identificar a maior e menor chave.


# Árvore Rubro-Negra (Left-Leaning Red-Black Tree) em C 🌳🔴⚫

Este repositório contém a implementação de uma **Árvore Rubro-Negra** utilizando a variação **LLRB (Left-Leaning Red-Black)** proposta por Robert Sedgewick. O projeto foi desenvolvido como parte dos estudos avançados de Algoritmos e Estruturas de Dados.

## 🚀 Diferencial Técnico
Diferente da implementação tradicional (padrão Cormen) que exige múltiplas checagens complexas ("cor do tio") e muitos casos de rotação, este projeto utiliza a abordagem LLRB. 
Isso permitiu manter o código extremamente **curto, limpo e profissional**, utilizando **ponteiros duplos (`No**`)** para manipular as raízes e as rotações de forma direta na memória, reduzindo drasticamente a complexidade ciclomática da função de inserção.

## ⚙️ Funcionalidades Implementadas
O sistema conta com um menu interativo no terminal que permite:
- **Inserção auto-balanceada:** Nós vermelhos caem estritamente para a esquerda, com auto-ajuste de cores e rotações simples.
- **Percursos de Impressão:**
  - Pré-ordem
  - Em-ordem (Garante a impressão ordenada dos elementos)
  - Pós-ordem
- **Consultas Específicas:**
  - Impressão de chaves pares de cor preta.
  - Contagem total de nós com chaves ímpares de cor vermelha.


## 🛠️ Como Compilar e Executar

Certifique-se de ter o compilador `gcc` instalado em sua máquina.

1. Clone o repositório ou baixe os arquivos.
2. Abra o terminal na pasta do projeto.
3. Compile os arquivos C com o comando:
   ```bash
   gcc main.c funcao.c -o programa
```
4. Execute os arquivos com o comando:
```bash
    # Windows (PowerShell/CMD): 
    .\programa.exe

    # Linux/Mac:
    ./programa
```