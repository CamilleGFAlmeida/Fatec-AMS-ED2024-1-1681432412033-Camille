/*------------------------------------------------------------------------*/
/*   FATEC - São Caetano do Sul                 Estrutura de Dados        */
/*                                                                        */
/*                           Camille Guillen                              */
/*       Objetivo: Busca Linear em Ordem (ordered_linear_search)          */
/*                                                                        */
/*                                                       Data: 08/09/2024 */
/*------------------------------------------------------------------------*/

// ordered_linear_search.c
#include <stdio.h>

int ordered_linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Encontrado
        }
        if (arr[i] > target) {
            break;  // A lista está ordenada, pode parar se passar o alvo
        }
    }
    return -1;  // Não encontrado
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 4;
    int result = ordered_linear_search(arr, size, target);
    if (result != -1) {
        printf("Elemento encontrado no índice %d\n", result);
    } else {
        printf("Elemento não encontrado\n");
    }
    return 0;
}
