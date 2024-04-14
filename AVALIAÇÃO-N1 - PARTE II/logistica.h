#ifndef LOGISTICA_H
#define LOGISTICA_H

typedef struct Pacote {
    int id;
    char conteudo[100];
    char origem[50];
    char destino[50];
    int status;
    struct Pacote *prox;
} Pacote;

void incluirPacote(Pacote **lista, char conteudo[], char origem[], char destino[]);
void alterarStatus(Pacote *lista, int id, int novoStatus);
void rastrearPacote(Pacote *lista, int id);
void mostrarEntregas(Pacote *lista);

#endif
