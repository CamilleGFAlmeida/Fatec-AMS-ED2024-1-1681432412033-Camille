#include <stdio.h>
#include <stdlib.h>
#include "baixa.h"

void baixarProduto(Produto *lista, int id, int quantidade) {
    Produto *atual = lista;
    while (atual != NULL) {
        if (atual->id == id) {
            atual->quantidade -= quantidade;
            if (atual->quantidade < 0) {
                atual->quantidade = 0;
            }
            return;
        }
        atual = atual->prox;
    }
    printf("Produto com ID %d não encontrado\n", id);
}
