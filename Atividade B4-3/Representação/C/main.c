/*------------------------------------------------------------------------*/
/*   FATEC - São Caetano do Sul                 Estrutura de Dados        */
/*                                                                        */
/*                           Camille Guillen                              */
/*              Objetivo: Conceitos de Árvore Binária de Busca            */
/*                                                                        */
/*                                                       Data: 06/11/2024 */
/*------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó
struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
};

// Função para criar um novo nó
struct No* criarNo(int dado) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    if (novoNo) {
        novoNo->dado = dado;
        novoNo->esquerda = NULL;
        novoNo->direita = NULL;
        printf("Nó criado com valor %d\n", dado);
    }
    return novoNo;
}

// Função para inserir um novo nó na BST
struct No* inserir(struct No* raiz, int dado) {
    if (raiz == NULL) {
        return criarNo(dado);
    }
    if (dado < raiz->dado) {
        raiz->esquerda = inserir(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = inserir(raiz->direita, dado);
    }
    return raiz;
}

// Função para imprimir a árvore binária em formato ASCII
void imprimirArvore(struct No* raiz, int espaco) {
    if (raiz == NULL)
        return;

    espaco += 5;

    // Imprime a subárvore direita
    imprimirArvore(raiz->direita, espaco);

    // Imprime o nó atual
    printf("\n");
    for (int i = 5; i < espaco; i++)
        printf(" ");
    printf("%d\n", raiz->dado);

    // Imprime a subárvore esquerda
    imprimirArvore(raiz->esquerda, espaco);
}

// Função para buscar um valor na árvore
struct No* buscar(struct No* raiz, int dado) {
    printf("Buscando o valor %d...\n", dado);
    if (raiz == NULL) {
        printf("Nó %d não encontrado.\n", dado);
        return NULL;
    }
    if (raiz->dado == dado) {
        printf("Nó %d encontrado.\n", dado);
        return raiz;
    }
    if (dado < raiz->dado) {
        printf("Descendo para a esquerda do nó %d\n", raiz->dado);
        return buscar(raiz->esquerda, dado);
    } else {
        printf("Descendo para a direita do nó %d\n", raiz->dado);
        return buscar(raiz->direita, dado);
    }
}

// Função para encontrar o nó mínimo
struct No* encontrarMinimo(struct No* raiz) {
    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

// Função para remover um nó da BST
struct No* removerNo(struct No* raiz, int dado) {
    if (raiz == NULL) {
        return raiz;
    }
    if (dado < raiz->dado) {
        raiz->esquerda = removerNo(raiz->esquerda, dado);
    } else if (dado > raiz->dado) {
        raiz->direita = removerNo(raiz->direita, dado);
    } else {
        printf("Removendo o nó com valor %d\n", dado);
        if (raiz->esquerda == NULL) {
            struct No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            struct No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        struct No* temp = encontrarMinimo(raiz->direita);
        raiz->dado = temp->dado;
        raiz->direita = removerNo(raiz->direita, temp->dado);
    }
    return raiz;
}

int main() {
    struct No* raiz = NULL;

    // Inserindo valores na árvore
    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 6);
    raiz = inserir(raiz, 14);
    raiz = inserir(raiz, 4);
    raiz = inserir(raiz, 7);

    // Inserindo o nó 13 e mostrando a criação
    raiz = inserir(raiz, 13);

    // Imprimindo a árvore após inserções
    printf("\nÁrvore após inserção dos nós:\n");
    imprimirArvore(raiz, 0);

    // Realizando uma busca pelo valor 6
    buscar(raiz, 6);

    // Removendo o nó com valor 10
    raiz = removerNo(raiz, 10);

    // Imprimindo a árvore após a remoção
    printf("\nÁrvore após remoção do nó com valor 10:\n");
    imprimirArvore(raiz, 0);

    return 0;
}
