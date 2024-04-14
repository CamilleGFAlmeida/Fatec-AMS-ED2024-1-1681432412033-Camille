#ifndef CADASTRAR_H
#define CADASTRAR_H

struct Produto {
    int id;
    char nome[50];
    double preco;
    int quantidade;
    struct Produto *prox;
};

typedef struct Produto Produto;

Produto* criaLista();
Produto* insereProduto(Produto *lista, int id, char nome[], double preco, int quantidade);

#endif
