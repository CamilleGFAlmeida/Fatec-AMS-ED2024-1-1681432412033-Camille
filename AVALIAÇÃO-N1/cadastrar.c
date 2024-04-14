#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cadastrar.h"

Produto* criaLista() {
    return NULL;
}

Produto* insereProduto(Produto *lista, int id, char nome[], double preco, int quantidade) {
    Produto *novo = (Produto*)malloc(sizeof(Produto));
    if (novo == NULL) {
        printf("Erro: Não foi possível alocar memória\n");
        exit(1);
    }

    novo->id = id;
    strcpy(novo->nome, nome);
    novo->preco = preco;
    novo->quantidade = quantidade;
    novo->prox = lista;

    return novo;
}
