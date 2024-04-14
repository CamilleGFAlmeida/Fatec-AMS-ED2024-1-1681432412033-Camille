#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "logistica.h"

void incluirPacote(Pacote **lista, char conteudo[], char origem[], char destino[]) {
    Pacote *novoPacote = (Pacote*)malloc(sizeof(Pacote));
    static int lastId = 1;

    if (novoPacote == NULL) {
        printf("Erro: Não foi possível alocar memória para o novo pacote.\n");
        return;
    }

    novoPacote->id = lastId + 1;
    lastId = novoPacote->id;
    strcpy(novoPacote->conteudo, conteudo);
    strcpy(novoPacote->origem, origem);
    strcpy(novoPacote->destino, destino);
    novoPacote->status = 1;
    novoPacote->prox = *lista;
    *lista = novoPacote;
}

void alterarStatus(Pacote *lista, int id, int novoStatus) {
    while (lista != NULL) {
        if (lista->id == id) {
            lista->status = novoStatus;
            return;
        }
        lista = lista->prox;
    }
    printf("Pacote com ID %d não encontrado.\n", id);
}

void rastrearPacote(Pacote *lista, int id) {
    while (lista != NULL) {
        if (lista->id == id) {
            printf("ID do Pacote: %d\n", lista->id);
            printf("Conteúdo: %s\n", lista->conteudo);
            printf("Status: %d\n", lista->status);
            return;
        }
        lista = lista->prox;
    }
    printf("Pacote com ID %d não encontrado.\n", id);
}

void mostrarEntregas(Pacote *lista) {
    printf("Situação atual do conjunto de entregas:\n");
    while (lista != NULL) {
        printf("ID do Pacote: %d\n", lista->id);
        printf("Conteúdo: %s\n", lista->conteudo);
        printf("Status: %d\n\n", lista->status);
        lista = lista->prox;
    }
}
