#include <stdio.h>
#include "logistica.h"

int main() {
    Pacote *lista = NULL;
    char conteudo[100], origem[50], destino[50];
    int opcao, id, novoStatus;

    do {
        printf("1. Incluir Pacote\n");
        printf("2. Alterar Status do Pacote\n");
        printf("3. Rastrear Pacote\n");
        printf("4. Mostrar Situação Atual das Entregas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                printf("Digite o conteúdo do pacote: ");
                scanf(" %[^\n]", conteudo);
                printf("Digite a cidade de origem: ");
                scanf(" %[^\n]", origem);
                printf("Digite a cidade de destino: ");
                scanf(" %[^\n]", destino);
                incluirPacote(&lista, conteudo, origem, destino);
                break;
            case 2:
                printf("Digite o ID do pacote: ");
                scanf("%d", &id);
                printf("Digite o novo status do pacote: ");
                scanf("%d", &novoStatus);
                alterarStatus(lista, id, novoStatus);
                break;
            case 3:
                printf("Digite o ID do pacote que deseja rastrear: ");
                scanf("%d", &id);
                rastrearPacote(lista, id);
                break;
            case 4:
                mostrarEntregas(lista);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
