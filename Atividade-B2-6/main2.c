/*------------------------------------------------------------------------*/
/*   FATEC - São Caetano do Sul                 Estrutura de Dados        */
/*                                                                        */
/*                           Camille Guillen                              */
/*                Objetivo: Lista Ordenada - Inserir Dados                */
/*                                                                        */
/*                                                       Data: 25/05/2024 */
/*------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirNaLista(No** cabeca, int valor) {
    No* novoNo = criarNo(valor);

    // Se a lista estiver vazia ou o novo valor for menor que o valor do primeiro nó
    if (*cabeca == NULL || (*cabeca)->valor >= valor) {
        novoNo->proximo = *cabeca;
        *cabeca = novoNo;
        return;
    }

    No* atual = *cabeca;
    // Encontrar o ponto de inserção
    while (atual->proximo != NULL && atual->proximo->valor < valor) {
        atual = atual->proximo;
    }

    novoNo->proximo = atual->proximo;
    atual->proximo = novoNo;
}

void imprimirLista(No* no) {
    while (no != NULL) {
        printf("\033[0;34m%d\033[0m ", no->valor);  // Cor azul
        no = no->proximo;
    }
    printf("\n");
}

int main() {
    No* cabeca = criarNo(10);
    cabeca->proximo = criarNo(25);
    cabeca->proximo->proximo = criarNo(40);
    cabeca->proximo->proximo->proximo = criarNo(80);

    int valor = 30;  // Valor a ser inserido

    clock_t inicio, fim;
    double tempo_gasto;

    inicio = clock();
    inserirNaLista(&cabeca, valor);
    fim = clock();

    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // Imprimindo a lista atualizada
    imprimirLista(cabeca);

    printf("\nTempo de processamento: %f segundos\n", tempo_gasto);

    // Liberando a memória alocada
    No* atual = cabeca;
    No* proximo;
    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    return 0;
}
