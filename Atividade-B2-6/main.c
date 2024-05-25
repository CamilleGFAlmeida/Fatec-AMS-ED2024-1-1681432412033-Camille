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

#define ARRAY_SIZE 4
#define MIDDLE_INDEX 2

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[ARRAY_SIZE + 1] = {10, 25, 40, 80}; // Inicia com o espaço extra
    int size = ARRAY_SIZE;
    int value;
    char option;

    clock_t start_time, end_time;
    double cpu_time_used;

    // Início do tempo de processamento
    start_time = clock();

    while (1) {
        printf("Escolha uma opção:\n");
        printf("\n1. Digitar um número entre 26 e 39\n");
        printf("2. Adicionar automaticamente o número 30\n");
        printf("\nOpção: ");
        scanf(" %c", &option);

        if (option == '1') {
            printf("\nDigite um número entre 26 e 39: ");
            scanf("%d", &value);
            if (value < 26 || value > 39) {
                printf("\nErro: Número fora do intervalo permitido. Tente novamente.\n");
                continue;
            }
        } else if (option == '2') {
            value = 30;
        } else {
            printf("\nErro: Opção inválida. Escolha novamente.\n");
            continue;
        }
        break;
    }

    // Move os elementos para inserir o novo valor no meio
    for (int i = size; i > MIDDLE_INDEX; i--) {
        array[i] = array[i - 1];
    }
    array[MIDDLE_INDEX] = value;
    size++;

    // Imprime o array resultante
    printf("\nArray atualizado: ");
    printArray(array, size);

    // Fim do tempo de processamento
    end_time = clock();
    cpu_time_used = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("\nTempo de processamento: %f segundos\n", cpu_time_used);
    printf("\nFim do programa...\n");

    return 0;
}
