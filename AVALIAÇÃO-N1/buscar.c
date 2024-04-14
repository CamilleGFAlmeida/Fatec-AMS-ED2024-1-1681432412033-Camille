#include <stdio.h>
#include "buscar.h"

Produto* buscarProduto(Produto *lista, int id) {
    Produto *atual = lista;
    while (atual != NULL) {
        if (atual->id == id) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}
