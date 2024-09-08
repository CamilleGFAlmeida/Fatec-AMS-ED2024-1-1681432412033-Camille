/*------------------------------------------------------------------------*/
/*   FATEC - São Caetano do Sul                 Estrutura de Dados        */
/*                                                                        */
/*                           Camille Guillen                              */
/*                Objetivo: Busca Binária (binary_search)                 */
/*                                                                        */
/*                                                       Data: 08/09/2024 */
/*------------------------------------------------------------------------*/

// binary_search.c
#include <stdio.h>

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            return mid;  // Encontrado
        }
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Não encontrado
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 4;
    int result = binary_search(arr, size, target);
    if (result != -1) {
        printf("Elemento encontrado no índice %d\n", result);
    } else {
        printf("Elemento não encontrado\n");
    }
    return 0;
}
