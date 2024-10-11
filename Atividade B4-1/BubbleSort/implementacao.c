/*------------------------------------------------------------------------*/
/*   FATEC - São Caetano do Sul                 Estrutura de Dados        */
/*                                                                        */
/*                           Camille Guillen                              */
/*      Objetivo: Aprender os conceitos Bubble Sort e implementação       */
/*                                                                        */
/*                                                       Data: 10/10/2024 */
/*------------------------------------------------------------------------*/

#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int trocado; // Variável para verificar se houve troca em uma iteração

    for (i = 0; i < n - 1; i++) {
        trocado = 0;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocado = 1;
            }
        }
        // Se não houve troca em uma iteração, o array já está ordenado
        if (trocado == 0)
            break;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    printf("Digite o número de elementos: ");
    scanf("%d", &n);

    int arr[n];
    printf("Digite os elementos:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array original:\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}